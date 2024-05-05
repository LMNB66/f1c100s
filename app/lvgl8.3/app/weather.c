#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include "tcp_client.h"
#include "cJSON.h"
#include "ui/ui.h"
#include "weather.h"

/* 请求包 */
#define REQUEST_PKG \
    "GET https://api.seniverse.com/v3/weather/%s.json?key=%s&location=%s&language=zh-Hans&unit=c\r\n"

/* 心知天气 API key */
#define API_KEY "SNiBIqGHhKpGBWMiv"

/* 天气数据类型 */
#define DAILY "daily"

/* 地点 */
#define WUHAN "guangzhou"


static int client_fd = 0;
static pthread_t weather_update_ui_thread_id;
static weather_t weather_daily;

static int cJSON_Parse_Weather_Daily(char *JSON, weather_t *results)
{
    cJSON *json, *arrayItem, *object, *subobject, *item, *sub_child_object, *child_Item;

    json = cJSON_Parse(JSON);
    if (json == NULL)
    {
        return cJSON_False;
    }
    else
    {
        if ((arrayItem = cJSON_GetObjectItem(json, "results")) != NULL)
        {

            if ((object = cJSON_GetArrayItem(arrayItem, 0)) != NULL)
            {
                /* 匹配 location */
                if ((subobject = cJSON_GetObjectItem(object, "location")) != NULL)
                {
                    if ((item = cJSON_GetObjectItem(subobject, "name")) != NULL)
                    {
                        /* 匹配 name */
                        memcpy(results->name, item->valuestring, strlen(item->valuestring));
                    }
                }
                /* 匹配 daily */
                if ((subobject = cJSON_GetObjectItem(object, "daily")) != NULL)
                {
                    int sub_array_size = cJSON_GetArraySize(subobject);
                    for (int i = 0; i < sub_array_size; i++)
                    {
                        if ((sub_child_object = cJSON_GetArrayItem(subobject, i)) != NULL)
                        {
                            /* 匹配日期 */
                            if ((child_Item = cJSON_GetObjectItem(sub_child_object, "date")) != NULL)
                            {
                                memcpy(results->date[i], child_Item->valuestring, strlen(child_Item->valuestring));
                            }
                            /* 匹配白天天气现象文字 */
                            if ((child_Item = cJSON_GetObjectItem(sub_child_object, "text_day")) != NULL)
                            {
                                memcpy(results->text_day[i], child_Item->valuestring, strlen(child_Item->valuestring));
                            }
                            /* 匹配白天天气现象代码 */
                            if ((child_Item = cJSON_GetObjectItem(sub_child_object, "code_day")) != NULL)
                            {
                                memcpy(results->code_day[i], child_Item->valuestring, strlen(child_Item->valuestring));
                            }
                            /* 匹配夜间天气现象文字 */
                            if ((child_Item = cJSON_GetObjectItem(sub_child_object, "text_night")) != NULL)
                            {
                                memcpy(results->text_night[i], child_Item->valuestring, strlen(child_Item->valuestring));
                            }
                            /* 匹配夜间天气现象代码 */
                            if ((child_Item = cJSON_GetObjectItem(sub_child_object, "code_night")) != NULL)
                            {
                                memcpy(results->code_night[i], child_Item->valuestring, strlen(child_Item->valuestring));
                            }
                            /* 匹配当天最高温度 */
                            if ((child_Item = cJSON_GetObjectItem(sub_child_object, "high")) != NULL)
                            {
                                memcpy(results->high[i], child_Item->valuestring, strlen(child_Item->valuestring));
                            }
                            /* 匹配当天最低温度 */
                            if ((child_Item = cJSON_GetObjectItem(sub_child_object, "low")) != NULL)
                            {
                                memcpy(results->low[i], child_Item->valuestring, strlen(child_Item->valuestring));
                            }
                            /* 匹配降水量 */
                            if ((child_Item = cJSON_GetObjectItem(sub_child_object, "rainfall")) != NULL)
                            {
                                memcpy(results->rainfall[i], child_Item->valuestring, strlen(child_Item->valuestring));
                            }
                            /* 匹配降水概率 */
                            if ((child_Item = cJSON_GetObjectItem(sub_child_object, "precip")) != NULL)
                            {
                                memcpy(results->precip[i], child_Item->valuestring, strlen(child_Item->valuestring));
                            }
                            /* 匹配风向文字 */
                            if ((child_Item = cJSON_GetObjectItem(sub_child_object, "wind_direction")) != NULL)
                            {
                                memcpy(results->wind_direction[i], child_Item->valuestring, strlen(child_Item->valuestring));
                            }
                            /* 匹配风向角度 */
                            if ((child_Item = cJSON_GetObjectItem(sub_child_object, "wind_direction_degree")) != NULL)
                            {
                                memcpy(results->wind_direction_degree[i], child_Item->valuestring, strlen(child_Item->valuestring));
                            }
                            /* 匹配风速 */
                            if ((child_Item = cJSON_GetObjectItem(sub_child_object, "wind_speed")) != NULL)
                            {
                                memcpy(results->wind_speed[i], child_Item->valuestring, strlen(child_Item->valuestring));
                            }
                            /* 匹配风力等级 */
                            if ((child_Item = cJSON_GetObjectItem(sub_child_object, "wind_scale")) != NULL)
                            {
                                memcpy(results->wind_scale[i], child_Item->valuestring, strlen(child_Item->valuestring));
                            }
                            /* 匹配相对湿度 */
                            if ((child_Item = cJSON_GetObjectItem(sub_child_object, "humidity")) != NULL)
                            {
                                memcpy(results->humidity[i], child_Item->valuestring, strlen(child_Item->valuestring));
                            }
                        }
                    }
                }
                /* 匹配 last_update */
                if ((subobject = cJSON_GetObjectItem(object, "last_update")) != NULL)
                {
                    memcpy(results->last_update, subobject->valuestring, strlen(subobject->valuestring));
                }
            }
        }
    }

    cJSON_Delete(json);

    return 0;
}

static void weather_show_data(weather_t *results)
{
    printf("--- %s 三天天气情况 --- \r\n", results->name);

    for(int i = 0; i < 3; i++)
    {
        printf("\r\n日期: %s \r\n", results->date[i]);
        printf("白天: %s(%s) \r\n夜晚: %s(%s) \r\n", 
               results->text_day[i], results->code_day[i],
               results->text_night[i], results->code_night[i]); 
        printf("温度: %s ~ %s ℃ \r\n", results->low[i], results->high[i]); 
        printf("降水量: %s mm \r\n降水概率: %s %%\r\n", 
               results->rainfall[i], results->precip[i]);
        printf("风向: %s(%s) %s 级 \r\n风速: %s km/h \r\n",
               results->wind_direction[i], results->wind_direction_degree[i], 
               results->wind_scale[i], results->wind_speed[i]);
        printf("湿度: %s %% \r\n", results->humidity[i]); 
    }
    printf("\r\n数据更新时间: %s \r\n", results->last_update);
    printf("\r\n");
}

static void weather_update_ui_img(int code)
{
#if 1
    switch (code)
    {
    case 0: lv_img_set_src(ui_Image3, &ui_img_0); break;
    case 1: lv_img_set_src(ui_Image3, &ui_img_1); break;
    case 2: lv_img_set_src(ui_Image3, &ui_img_2); break; 
    case 3: lv_img_set_src(ui_Image3, &ui_img_3); break;
    case 4: lv_img_set_src(ui_Image3, &ui_img_4); break;
    case 5: lv_img_set_src(ui_Image3, &ui_img_5); break; 
    case 6: lv_img_set_src(ui_Image3, &ui_img_6); break;
    case 7: lv_img_set_src(ui_Image3, &ui_img_7); break;
    case 8: lv_img_set_src(ui_Image3, &ui_img_8); break; 
    case 9: lv_img_set_src(ui_Image3, &ui_img_9); break;

    case 10: lv_img_set_src(ui_Image3, &ui_img_10); break;
    case 11: lv_img_set_src(ui_Image3, &ui_img_11); break; 
    case 12: lv_img_set_src(ui_Image3, &ui_img_12); break;
    case 13: lv_img_set_src(ui_Image3, &ui_img_13); break;
    case 14: lv_img_set_src(ui_Image3, &ui_img_14); break; 
    case 15: lv_img_set_src(ui_Image3, &ui_img_15); break;
    case 16: lv_img_set_src(ui_Image3, &ui_img_16); break;
    case 17: lv_img_set_src(ui_Image3, &ui_img_17); break; 
    case 18: lv_img_set_src(ui_Image3, &ui_img_18); break;
    case 19: lv_img_set_src(ui_Image3, &ui_img_19); break;

    case 20: lv_img_set_src(ui_Image3, &ui_img_20); break;
    case 21: lv_img_set_src(ui_Image3, &ui_img_21); break; 
    case 22: lv_img_set_src(ui_Image3, &ui_img_22); break;
    case 23: lv_img_set_src(ui_Image3, &ui_img_23); break;
    case 24: lv_img_set_src(ui_Image3, &ui_img_24); break; 
    case 25: lv_img_set_src(ui_Image3, &ui_img_25); break;
    case 26: lv_img_set_src(ui_Image3, &ui_img_26); break;
    case 27: lv_img_set_src(ui_Image3, &ui_img_27); break; 
    case 28: lv_img_set_src(ui_Image3, &ui_img_28); break;
    case 29: lv_img_set_src(ui_Image3, &ui_img_29); break;

    case 30: lv_img_set_src(ui_Image3, &ui_img_30); break;
    case 31: lv_img_set_src(ui_Image3, &ui_img_31); break; 
    case 32: lv_img_set_src(ui_Image3, &ui_img_32); break;
    case 33: lv_img_set_src(ui_Image3, &ui_img_33); break;
    case 34: lv_img_set_src(ui_Image3, &ui_img_34); break; 
    case 35: lv_img_set_src(ui_Image3, &ui_img_35); break;
    case 36: lv_img_set_src(ui_Image3, &ui_img_36); break;
    case 37: lv_img_set_src(ui_Image3, &ui_img_37); break; 
    case 38: lv_img_set_src(ui_Image3, &ui_img_38); break;
    case 99: lv_img_set_src(ui_Image3, &ui_img_99); break;
    default: break;
    }
#endif
}

static void *weather_update_ui_thread(void *arg)
{
    weather_t *results = (weather_t *)arg;
    char buffer[64] = {0};
    int day = 0;

    while(1)
    {
#if 1
        memset(buffer, 0, 64);
        sprintf(buffer, "%s / %s", results->text_day[day], results->text_night[day]);

        lv_label_set_text(ui_Label14, buffer);

        sprintf(buffer, "%s~%s℃", results->low[day], results->high[day]);
        lv_label_set_text(ui_Label13, buffer);

        sprintf(buffer, "%s %%", results->precip[day]);
        lv_label_set_text(ui_Label16, &buffer[2]);

        sprintf(buffer, "%s km/h", results->wind_speed[day]);
        lv_label_set_text(ui_Label15, buffer);

        weather_update_ui_img(atoi(results->code_day[day]));
        sleep(30);
        weather_update_ui_img(atoi(results->code_night[day]));
        sleep(30);

        cJSON_Parse_Weather_Daily(buffer, &weather_daily);

		/*
        if(++day == 3)
        {
            day = 0;
        }
        */
#endif
		sleep(2);
    }

    client_close_socket(client_fd);
    return NULL;
}

static int weather_update_ui(weather_t *results)
{
    pthread_create(&weather_update_ui_thread_id, NULL, 
                weather_update_ui_thread, results);
    return 0;
}

int weather_init(void)
{
    char buffer[2048] = {0};
    int json_size = 0;

    /* 创建客户端 */
    client_fd = client_init_socket();

    /* 组合请求包 */
    sprintf(buffer, REQUEST_PKG, DAILY, API_KEY, WUHAN);
    printf("\r\n%s \r\n", buffer);

    /* 向心知天气服务端发送请求 */
    client_send_data(client_fd, buffer, strlen(buffer));

    /* 清空缓存准备接收天气数据 */
    memset(buffer, 0, sizeof(buffer));

    /* 接收天气数据 JSON 格式 */
    client_receive_data(client_fd, buffer, &json_size);
    printf("\r\n%s \r\n", buffer);

    /* 解析天气数据到 weather_daily 中 */
    cJSON_Parse_Weather_Daily(buffer, &weather_daily);

    /* 打印天气信息 */
    weather_show_data(&weather_daily);

    /* 更新天气显示 */
    weather_update_ui(&weather_daily);

    /* 关闭客户端 */
    //client_close_socket(client_fd);

    return 0;
}
