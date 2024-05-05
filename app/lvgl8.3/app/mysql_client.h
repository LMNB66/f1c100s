#ifndef __MYSQL_CLIENT_H__
#define __MYSQL_CLIENT_H__

#include "lora_uart.h"

int my_client_init(void);
int my_client_insert(measure_t *mea);
int my_client_select(char *tn, char data[][10]);
void my_client_exit(void);

#endif