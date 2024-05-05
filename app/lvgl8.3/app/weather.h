#ifndef __WEATHER_H__
#define __WEATHER_H__

/* 天气数据结构体 */
typedef struct weather
{
    /* 实况天气数据 */
    char id[32];              // 城市 ID
    char name[32];            // 城市中文名
    char country[32];         // 国家
    char path[32];            // 完整城市地址
    char timezone[32];        // 时区
    char timezone_offset[32]; // 时差
    char text[32];            // 天气预报文字
    char code[32];            // 天气预报代码
    char temperature[32];     // 温度
    char last_update[32];     // 数据更新时间

    /* 三天天气数据 */
    char date[3][32];                   // 日期
    char text_day[3][64];               // 白天天气现象文字
    char code_day[3][32];               // 白天天气现象代码
    char text_night[3][64];             // 晚间天气现象文字
    char code_night[3][32];             // 晚间天气现象代码
    char high[3][32];                   // 当天最高温度
    char low[3][32];                    // 当天最低温度
    char rainfall[3][32];               // 降水量，单位 mm
    char precip[3][32];                 // 降水概率，范围 0~100，单位百分比
    char wind_direction[3][32];         // 风向文字
    char wind_direction_degree[3][32];  // 风向角度，范围 0~360
    char wind_speed[3][32];             // 风速，单位 km/h（当 unit = c 时）、mph（当 unit = f 时）
    char wind_scale[3][32];             // 风力等级
    char humidity[3][32];               // 相对湿度，0~100，单位为百分比
} weather_t;


int weather_init(void);

#endif

