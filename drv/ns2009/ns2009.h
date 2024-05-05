#ifndef _NS2009_H
#define _NS2009_H

#define READ_X_ADC 		0xc0
#define READ_Y_ADC 		0xd0
#define READ_Z1_ADC 	0xe0
#define READ_Z2_ADC 	0xf0

struct ns_event{
	u16 x;
	u16 y;
	u16 z1, z2;
};
struct ns2009{
	struct input_dev	*input;
	struct i2c_client	*client;
	int 				gpio;
	int 				irq;
	wait_queue_head_t	wait;
	struct mutex		mlock;
	bool stopped;
	unsigned long		poll_period;
	struct ns_event 	ns_e;
};


#endif
