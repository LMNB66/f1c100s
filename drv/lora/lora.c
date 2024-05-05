
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/gpio.h>
#include <linux/device.h>
#include <linux/errno.h>
#include <linux/uaccess.h>

static unsigned lora_md0 = 130;
static unsigned lora_md1 = 131;

static struct gpio_desc *md0_gpiod = NULL, *md1_gpiod = NULL;
static int major = 0;
static struct class *lora_class;

#define lora_name	"lora"


static ssize_t lora_write(struct file *filp, const char __user *buf,
			 size_t count, loff_t *ppos)
{
	char val;
    int err;
	err = copy_from_user(&val, buf, 1);
	printk("val: %d\n", val);
	switch (val)
	{
		case 2:
		case '2':
			gpiod_direction_output(md0_gpiod, 1);
			gpiod_direction_output(md1_gpiod, 1);
			printk("pown down\n");
			break;
		case 1:
		case '1':
			gpiod_direction_output(md0_gpiod, 0);
			gpiod_direction_output(md1_gpiod, 1);
			printk("work\n");
			break;
		default:
			gpiod_direction_output(md0_gpiod, 0);
			gpiod_direction_output(md1_gpiod, 0);
			printk("config\n");
			break;
	}
	
	return 1;
}



static struct file_operations lora_fops = {
	.owner	 = THIS_MODULE,
	.write	 = lora_write,
};

static int __init lora_init(void)
{
	printk("%s %s %d\n", __FILE__, __FUNCTION__, __LINE__);
	
	md0_gpiod = gpio_to_desc(lora_md0);
	if(!md0_gpiod)
	{
		printk("lora_md0: %d get fail!", lora_md0);
		return -1;
	}
	md1_gpiod = gpio_to_desc(lora_md1);
	if(!md1_gpiod)
	{
		printk("lora_md1: %d get fail!", lora_md1);
		return -1;
	}

	major = register_chrdev(0, lora_name, &lora_fops);

	lora_class = class_create(THIS_MODULE, lora_name);
	if (IS_ERR(lora_class)) 
	{
		printk("%s %s line %d\n", __FILE__, __FUNCTION__, __LINE__);
		unregister_chrdev(major, lora_name);
		return PTR_ERR(lora_class);
	}

	device_create(lora_class, NULL, MKDEV(major, 0), NULL, lora_name);
	
	return 0;
}

static void __exit lora_exit(void)
{
	printk("%s %s line %d\n", __FILE__, __FUNCTION__, __LINE__);

	device_destroy(lora_class, MKDEV(major, 0));
	class_destroy(lora_class);
	unregister_chrdev(major, lora_name);
}

module_init(lora_init);
module_exit(lora_exit);
MODULE_LICENSE("GPL");


