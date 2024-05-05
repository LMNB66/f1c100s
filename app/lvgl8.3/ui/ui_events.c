// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#include "ui.h"
#include "../app/lora_uart.h"
#include "../app/mysql_client.h"
#include "../app/back_light.h"


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



static int roller_index = 1;

void lora_switch(lv_event_t * e)
{
	// Your code here
	bool status;
	lv_obj_t * target = lv_event_get_target(e);
	status = lv_obj_has_state(ui_Switch1, LV_STATE_CHECKED);
	printf("switch status: %d\n", status);

	lora_send_switch(0);
	usleep(100000);
	lora_send_switch(status);

	if(status)
	{
		usleep(100000);
		lora_send_time(roller_index);
	}
}

void lora_set_time(lv_event_t * e)
{
	// Your code here
	lv_obj_t * target = lv_event_get_target(e);
	roller_index = lv_roller_get_selected(target);
	printf("select index: %d\n", roller_index);

	lora_send_time(roller_index);
	usleep(100000);
	lora_send_time(roller_index);
}

void set_backlight(lv_event_t * e)
{
	// Your code here
	lv_obj_t * target = lv_event_get_target(e);
	set_bl(lv_slider_get_value(target));
}

void set_volume(lv_event_t * e)
{
	// Your code here
}

void co2_select_sql(lv_event_t * e)
{
	// Your code here
	char data[50][10];
	int i, len;
	len = my_client_select("co2", data);

	lv_coord_t val = 0;
	int min_val = 65535, max_val = 0;

	
	if(len<0)
		return;
	printf("len: %d\n", len);
	i=len;
	while(i--)
	{
		val = atoi(data[i]);
		printf("%d\n", val);
		lv_chart_set_next_value(ui_Chart3, ui_Chart3_series_1, val);

		if(val <= min_val) min_val = val;
		if(val >= max_val) max_val = val;
	}
	printf("min_val: %d\n", min_val);
	printf("max_val: %d\n", max_val);
	if(min_val == max_val && max_val)  
	{
		min_val -= 50;
		max_val += 50;
		min_val = min_val<=0 ? 0 : min_val;
	}
	lv_chart_set_range(ui_Chart3, LV_CHART_AXIS_PRIMARY_Y, min_val, max_val);
}

void light_select_sql(lv_event_t * e)
{
	// Your code here
	char data[50][10];
	int i, len;
	len = my_client_select("light", data);

	lv_coord_t val = 0;
	int min_val = 65535, max_val = 0;

	
	if(len<0)
		return;
	printf("len: %d\n", len);
	i=len;
	while(i--)
	{
		val = atoi(data[i]);
		printf("%d\n", val);
		lv_chart_set_next_value(ui_Chart2, ui_Chart2_series_1, val);

		if(val <= min_val) min_val = val;
		if(val >= max_val) max_val = val;
	}
	printf("min_val: %d\n", min_val);
	printf("max_val: %d\n", max_val);
	if(min_val == max_val && max_val)  
	{
		min_val -= 50;
		max_val += 50;
		min_val = min_val<=0 ? 0 : min_val;
	}
	lv_chart_set_range(ui_Chart2, LV_CHART_AXIS_PRIMARY_Y, min_val, max_val);
}

void tmp_selsect_sql(lv_event_t * e)
{
	// Your code here
	char data[50][10];
	int i, len;
	len = my_client_select("temp", data);

	lv_coord_t val = 0;
	int min_val = 65535, max_val = 0;

	
	if(len<0)
		return;
	printf("len: %d\n", len);
	i=len;
	while(i--)
	{
		val = atoi(data[i]);
		printf("%d\n", val);
		lv_chart_set_next_value(ui_Chart4, ui_Chart4_series_1, val);

		if(val <= min_val) min_val = val;
		if(val >= max_val) max_val = val;
	}
	printf("min_val: %d\n", min_val);
	printf("max_val: %d\n", max_val);
	if(min_val == max_val && max_val)  
	{
		min_val -= 50;
		max_val += 50;
		min_val = min_val<=0 ? 0 : min_val;
	}
	lv_chart_set_range(ui_Chart4, LV_CHART_AXIS_PRIMARY_Y, min_val, max_val);
}

void soil_select_sql(lv_event_t * e)
{
	// Your code here
	char data[50][10];
	int i, len;
	len = my_client_select("soil", data);

	lv_coord_t val = 0;
	int min_val = 65535, max_val = 0;

	
	if(len<0)
		return;
	printf("len: %d\n", len);
	i=len;
	while(i--)
	{
		val = atoi(data[i]);
		printf("%d\n", val);
		lv_chart_set_next_value(ui_Chart6, ui_Chart6_series_1, val);

		if(val <= min_val) min_val = val;
		if(val >= max_val) max_val = val;
	}
	printf("min_val: %d\n", min_val);
	printf("max_val: %d\n", max_val);
	if(min_val == max_val && max_val)  
	{
		min_val -= 50;
		max_val += 50;
		min_val = min_val<=0 ? 0 : min_val;
	}
	lv_chart_set_range(ui_Chart6, LV_CHART_AXIS_PRIMARY_Y, min_val, max_val);
}

void hum_select_sql(lv_event_t * e)
{
	// Your code here
	char data[50][10];
	int i, len;
	len = my_client_select("hum", data);

	lv_coord_t val = 0;
	int min_val = 65535, max_val = 0;

	
	if(len<0)
		return;
	printf("len: %d\n", len);
	i=len;
	while(i--)
	{
		val = atoi(data[i]);
		printf("%d\n", val);
		lv_chart_set_next_value(ui_Chart5, ui_Chart5_series_1, val);

		if(val <= min_val) min_val = val;
		if(val >= max_val) max_val = val;
	}
	printf("min_val: %d\n", min_val);
	printf("max_val: %d\n", max_val);
	if(min_val == max_val && max_val)  
	{
		min_val -= 50;
		max_val += 50;
		min_val = min_val<=0 ? 0 : min_val;
	}
	lv_chart_set_range(ui_Chart5, LV_CHART_AXIS_PRIMARY_Y, min_val, max_val);
}