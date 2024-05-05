
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/input.h>
#include <linux/interrupt.h>
#include <linux/i2c.h>
#include <linux/of_device.h>
#include <linux/of_gpio.h>
#include "ns2009.h"

static u16 ns2009_xfer(struct ns2009 *ns, u8 cmd)
{
	s32 data;
	u16 val;
	data = i2c_smbus_read_word_data(ns->client, cmd);
	val = swab16(data) >> 4;
	return val;
}

static void ns2009_read_values(struct ns2009 *ns, struct ns_event *ns_e)
{
	ns_e->z1 = ns2009_xfer(ns, READ_Z1_ADC);
	ns_e->x = ns2009_xfer(ns, READ_X_ADC);
	ns_e->y = ns2009_xfer(ns, READ_Y_ADC);
}


static irqreturn_t ns2009_soft_irq(int irq, void *handle)
{
	struct ns2009 *ns = handle;
	struct input_dev *input = ns->input;
	struct ns_event *ns_e = &(ns->ns_e);

	//printk("ns2009: %s\n", __FUNCTION__);
	
	while (!ns->stopped && !gpio_get_value(ns->gpio))
	{
		mutex_lock(&ns->mlock);
		ns2009_read_values(ns, ns_e);
		mutex_unlock(&ns->mlock);
		
		if(!ns_e->z1 && gpio_get_value(ns->gpio))break;

		if(ns_e->z1 > 30)
		{
			input_report_key(input, BTN_TOUCH, 1);
			input_report_abs(input, ABS_X, ns_e->x);
			input_report_abs(input, ABS_Y, ns_e->y);
			input_report_abs(input, ABS_PRESSURE, ns_e->z1);
			input_sync(input);
		}
		//printk("x: %4d, y: %4d, z: %4d\n", ns_e->x, ns_e->y, ns_e->z);
		
		wait_event_timeout(ns->wait, ns->stopped, ns->poll_period);
	}

	input_report_key(input, BTN_TOUCH, 0);
	input_report_abs(input, ABS_PRESSURE, 0);
	input_sync(input);

	return IRQ_HANDLED;
}

static irqreturn_t ns2009_hard_irq(int irq, void *handle)
{
	struct ns2009 *ns = handle;
	if(!gpio_get_value(ns->gpio))
		return IRQ_WAKE_THREAD;
	
	return IRQ_HANDLED;
}

static void ns2009_stop(struct ns2009 *ns)
{
	ns->stopped = true;
	mb();
	wake_up(&ns->wait);

	disable_irq(ns->irq);
}

static int ns2009_open(struct input_dev *input)
{
	struct ns2009 *ns = input_get_drvdata(input);

	printk("ns2009: %s\n", __FUNCTION__);
	
	ns->stopped = false;
	mb();

	enable_irq(ns->irq);

	return 0;
}

static void ns2009_close(struct input_dev *input)
{
	struct ns2009 *ns = input_get_drvdata(input);
	printk("ns2009: %s\n", __FUNCTION__);
	ns2009_stop(ns);
}


static int ns2009_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	int err;
	struct ns2009 *ns;
	struct input_dev *input;
	struct device_node *np = client->dev.of_node;
	
	printk("ns2009: %s\n", __FUNCTION__);

	/*1. 检查i2c的Algorithm是否支持需要的功能*/
	if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_READ_WORD_DATA))
	{
		printk("The Algorithm does not support the functions required by the adapter driver!");
		return -EIO;
	}
		

	/*2. 为ns对象分配内存，生命周期同i2c设备*/
	ns = devm_kzalloc(&client->dev, sizeof(struct ns2009), GFP_KERNEL);
	if (!ns)
	{
		printk("Failed to allocate memory for ns object!");
		return -ENOMEM;
	}		
	

	/*3. 从设备树获取中断引脚*/
	ns->gpio = of_get_gpio(np, 0);
	if(ns->gpio < 0)
	{
		printk("There is no definition of this pin in the device tree!");
		return -EINVAL;
	}	


	/*4. 配置输入子系统*/
	input = devm_input_allocate_device(&client->dev);
	if (!input)
		return -ENOMEM;
	input->name = "NS2009 Touchscreen";
	input->open = ns2009_open;
	input->close = ns2009_close;

	input_set_drvdata(input, ns);//在open close需要用到，所以设为私有数据

	input_set_capability(input, EV_KEY, BTN_TOUCH);
	input_set_abs_params(input, ABS_X, 0, 4095, 0, 0);
	input_set_abs_params(input, ABS_Y, 0, 4095, 0, 0);
	input_set_abs_params(input, ABS_PRESSURE, 0, 4095, 0, 0);


	/*5. 初始化ns对象*/
	ns->client = client;
	ns->input = input;
	ns->irq = client->irq;
	ns->poll_period = msecs_to_jiffies(1);
	printk("poll_period: %ld\n", ns->poll_period);

	/*6. 初始化等待队列，互斥*/
	init_waitqueue_head(&ns->wait);
	mutex_init(&ns->mlock);
	
	
	/*7. 注册中断*/
	err = devm_request_threaded_irq(&client->dev, ns->irq,
					ns2009_hard_irq, ns2009_soft_irq,
					IRQF_ONESHOT,
					client->dev.driver->name, ns);
	if (err)
	{
		printk("Interrupt enrollment failed!");
		return err;
	}	
	
	ns2009_stop(ns);//关闭中断，开启休眠，等打开此设备才开启中断

	/*7. 注册输入子系统*/
	err = input_register_device(input);
	if (err)
	{
		printk("Failed to register the input subsystem!");
		return err;
	}
		
	
	return 0;
}


static const struct of_device_id ns2009_of_match[] = {
	{.compatible = "lmnb,ns2009"},
};

static struct i2c_driver ns2009_driver = {
	.probe = ns2009_probe,
	.driver = {
		.name = "ns2009",
		.of_match_table = ns2009_of_match,
	},
};

static int __init ns2009_init(void)
{
	int err;
	printk("ns2009: %s\n", __FUNCTION__);
	err = i2c_add_driver(&ns2009_driver);
	return err;
}

static void __exit ns2009_exit(void)
{
	printk("ns2009: %s\n", __FUNCTION__);
	i2c_del_driver(&ns2009_driver);

}

module_init(ns2009_init);
module_exit(ns2009_exit);
MODULE_LICENSE("GPL");


