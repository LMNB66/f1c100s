#include "app.h"
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "lora_uart.h"
#include "../ui/ui.h"
#include <sys/time.h>
#include "weather.h"
#include "date.h"
#include "back_light.h"




measure_t mea;
static int t_flag = 15;

static pthread_mutex_t g_tMutex  = PTHREAD_MUTEX_INITIALIZER;


static void *lora_thread (void *e)
{
	char str[30];
	
	while (1)
	{
		pthread_mutex_lock(&g_tMutex);

		lora_parse(&mea);
		t_flag = 0;

		sprintf(str, "%d", mea.co2);
		lv_label_set_text(ui_Label6, str);

		sprintf(str, "%.1f", mea.light);
		lv_label_set_text(ui_Label4, str);

		sprintf(str, "%.1f℃", mea.temperature);
		lv_label_set_text(ui_Label10, str);
		lv_bar_set_value(ui_Bar3, (int32_t)mea.temperature, LV_ANIM_OFF);
		
		sprintf(str, "%.1f%%", mea.humidity);
		lv_label_set_text(ui_Label9, str);
		lv_bar_set_value(ui_Bar2, (int32_t)mea.humidity, LV_ANIM_OFF);
		

		sprintf(str, "%.1f", mea.soil);
		lv_label_set_text(ui_Label7, str);

		pthread_mutex_unlock(&g_tMutex);

		if(lv_obj_has_state(ui_Switch1, LV_STATE_CHECKED))
		{
			if(mea.temperature > mea.temp_up)
			{
				lv_label_set_text(ui_Label31, "警告,温度超过上限!");
				lv_obj_clear_flag(ui_Panel27, LV_OBJ_FLAG_HIDDEN);
				continue;
			}
			else
			{
				lv_obj_add_flag(ui_Panel27, LV_OBJ_FLAG_HIDDEN);
			}

			if(mea.temperature < mea.temp_down)
			{
				lv_label_set_text(ui_Label31, "警告,温度超过下限!");
				lv_obj_clear_flag(ui_Panel27, LV_OBJ_FLAG_HIDDEN);
				continue;
			}
			else
			{
				lv_obj_add_flag(ui_Panel27, LV_OBJ_FLAG_HIDDEN);
			}

			if(mea.soil > mea.soil_up)
			{
				lv_label_set_text(ui_Label31, "警告,土壤湿度超过上限!");
				lv_obj_clear_flag(ui_Panel27, LV_OBJ_FLAG_HIDDEN);
				continue;
			}
			else
			{
				lv_obj_add_flag(ui_Panel27, LV_OBJ_FLAG_HIDDEN);
			}

			if(mea.soil < mea.soil_down)
			{
				lv_label_set_text(ui_Label31, "警告,土壤湿度超过下限!");
				lv_obj_clear_flag(ui_Panel27, LV_OBJ_FLAG_HIDDEN);
				continue;
			}
			else
			{
				lv_obj_add_flag(ui_Panel27, LV_OBJ_FLAG_HIDDEN);
			}
		}
	}

	lora_exit();
	back_light_exit();

	return NULL;
}

static void *date_thread(void *e)
{
    time_t now;
    struct tm *local;
    char date[20];
    char times[10];

    date_modify();

    while(1)
    {
        time(&now);
        local = localtime(&now);

		snprintf(date, sizeof(date), "%d年%d月%d日", local->tm_year + 1900, local->tm_mon + 1, local->tm_mday);
		snprintf(times, sizeof(times), "%02d:%02d:%02d", local->tm_hour, local->tm_min, local->tm_sec);

        lv_label_set_text(ui_date, date);
        lv_label_set_text(ui_time, times);
        t_flag++;
        if(t_flag > 15)
        {
        	lv_label_set_text(ui_devices_status, "离线");
    		lv_obj_set_style_text_color(ui_devices_status, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        else
        {
        	lv_label_set_text(ui_devices_status, "在线");
    		lv_obj_set_style_text_color(ui_devices_status, lv_color_hex(0x00FF00), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        
        usleep(999999);
    }

    return NULL;
}


void my_demo(void)
{
#if 1
	pthread_t tid1, tid2;
	memset(&mea, 0, sizeof(measure_t));

	back_light_init();
    lora_init();

    mea.soil_up = 90;
    mea.soil_down = 40;
    mea.temp_up = 40;
    mea.temp_down = 10;

	pthread_create(&tid1, NULL, lora_thread, NULL);
	pthread_create(&tid2, NULL, date_thread, NULL);
#endif
	weather_init();
}





