#ifndef _LORA_UART_H
#define _LORA_UART_H


#define LORA_REG_VERSION		0x00
#define LORA_REG_CPS			0x06
#define LORA_REG_MODE			0x07
#define LORA_REG_SLEEP			0x14
#define LORA_REG_AWAKEN			0x17
#define LORA_REG_LGROUP			0x18
#define LORA_REG_LADDR			0x19
#define LORA_REG_TGROUP			0x1a
#define LORA_REG_TADDR			0x1b
#define LORA_REG_RESET			0x22

typedef struct{
	unsigned short co2;
	unsigned char soil_up;
	unsigned char soil_down;
	unsigned char temp_up;
	unsigned char temp_down;
	float humidity;
	float temperature;
	float soil;
	float light;
}measure_t;

int lora_parse(measure_t *mea);
int lora_init(void);
void lora_exit(void);
void lora_send_switch(unsigned char sw);
void lora_send_time(unsigned char index);




#endif







