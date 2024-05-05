// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

#include "ui_helpers.h"
#include "ui_events.h"
#include "image.h"

// SCREEN: ui_home

extern lv_chart_series_t * ui_Chart3_series_1;
extern lv_chart_series_t * ui_Chart2_series_1;
extern lv_chart_series_t * ui_Chart4_series_1;
extern lv_chart_series_t * ui_Chart5_series_1;
extern lv_chart_series_t * ui_Chart6_series_1;



void ui_home_screen_init(void);
extern lv_obj_t * ui_home;
extern lv_obj_t * ui_Panel4;
extern lv_obj_t * ui_status;
extern lv_obj_t * ui_device;
extern lv_obj_t * ui_devices_status;
extern lv_obj_t * ui_weather;
extern lv_obj_t * ui_Image3;
extern lv_obj_t * ui_Label1;
extern lv_obj_t * ui_Panel3;
extern lv_obj_t * ui_Label2;
extern lv_obj_t * ui_Label11;
extern lv_obj_t * ui_Label16;
extern lv_obj_t * ui_Label15;
extern lv_obj_t * ui_Label14;
extern lv_obj_t * ui_Label13;
void ui_event_CO2(lv_event_t * e);
extern lv_obj_t * ui_CO2;
extern lv_obj_t * ui_Image_co2;
extern lv_obj_t * ui_Label5;
extern lv_obj_t * ui_Label6;
void ui_event_light(lv_event_t * e);
extern lv_obj_t * ui_light;
extern lv_obj_t * ui_Image_light;
extern lv_obj_t * ui_Label3;
extern lv_obj_t * ui_Label4;
void ui_event_temperature(lv_event_t * e);
extern lv_obj_t * ui_temperature;
extern lv_obj_t * ui_Image_temperature;
extern lv_obj_t * ui_Bar3;
extern lv_obj_t * ui_Label10;
void ui_event_soil(lv_event_t * e);
extern lv_obj_t * ui_soil;
extern lv_obj_t * ui_Image_soil;
extern lv_obj_t * ui_Label7;
extern lv_obj_t * ui_Label8;
void ui_event_humidity(lv_event_t * e);
extern lv_obj_t * ui_humidity;
extern lv_obj_t * ui_Image_humidity;
extern lv_obj_t * ui_Bar2;
extern lv_obj_t * ui_Label9;
extern lv_obj_t * ui_info;
extern lv_obj_t * ui_Label17;
extern lv_obj_t * ui_Label23;
extern lv_obj_t * ui_Panel2;
void ui_event_Button3(lv_event_t * e);
extern lv_obj_t * ui_Button3;
extern lv_obj_t * ui_time_bar;
extern lv_obj_t * ui_date;
extern lv_obj_t * ui_time;
extern lv_obj_t * ui_Panel27;
extern lv_obj_t * ui_Image1;
extern lv_obj_t * ui_Label31;
extern lv_obj_t * ui_Panel5;
extern lv_obj_t * ui_Panel1;
void ui_event_Panel6(lv_event_t * e);
extern lv_obj_t * ui_Panel6;
extern lv_obj_t * ui_Image2;
extern lv_obj_t * ui_Label12;
extern lv_obj_t * ui_Panel9;
void ui_event_Switch1(lv_event_t * e);
extern lv_obj_t * ui_Switch1;
extern lv_obj_t * ui_Label24;
extern lv_obj_t * ui_Panel23;
void ui_event_Roller1(lv_event_t * e);
extern lv_obj_t * ui_Roller1;
extern lv_obj_t * ui_Label25;
extern lv_obj_t * ui_Panel24;
extern lv_obj_t * ui_Image9;
extern lv_obj_t * ui_Image10;
void ui_event_Slider1(lv_event_t * e);
extern lv_obj_t * ui_Slider1;
void ui_event_Slider3(lv_event_t * e);
extern lv_obj_t * ui_Slider3;
extern lv_obj_t * ui_Label26;
extern lv_obj_t * ui_Label28;
extern lv_obj_t * ui_Panel25;
extern lv_obj_t * ui_Panel26;
extern lv_obj_t * ui_Label27;
void ui_event_Slider2(lv_event_t * e);
extern lv_obj_t * ui_Slider2;
extern lv_obj_t * ui_Label29;
extern lv_obj_t * ui_Panel28;
extern lv_obj_t * ui_Label32;
void ui_event_Slider5(lv_event_t * e);
extern lv_obj_t * ui_Slider5;
extern lv_obj_t * ui_Label30;
extern lv_obj_t * ui_Panel29;
extern lv_obj_t * ui_Label33;
void ui_event_Slider6(lv_event_t * e);
extern lv_obj_t * ui_Slider6;
extern lv_obj_t * ui_Label34;
extern lv_obj_t * ui_Panel30;
extern lv_obj_t * ui_Label35;
void ui_event_Slider7(lv_event_t * e);
extern lv_obj_t * ui_Slider7;
extern lv_obj_t * ui_Label36;
extern lv_obj_t * ui_Dropdown1;
extern lv_obj_t * ui_Panel10;
extern lv_obj_t * ui_Panel7;
void ui_event_Panel8(lv_event_t * e);
extern lv_obj_t * ui_Panel8;
extern lv_obj_t * ui_Image4;
extern lv_obj_t * ui_Label18;
extern lv_obj_t * ui_Chart3;
extern lv_obj_t * ui_Panel11;
extern lv_obj_t * ui_Panel12;
void ui_event_Panel13(lv_event_t * e);
extern lv_obj_t * ui_Panel13;
extern lv_obj_t * ui_Image5;
extern lv_obj_t * ui_Label19;
extern lv_obj_t * ui_Chart2;
extern lv_obj_t * ui_Panel14;
extern lv_obj_t * ui_Panel15;
void ui_event_Panel16(lv_event_t * e);
extern lv_obj_t * ui_Panel16;
extern lv_obj_t * ui_Image6;
extern lv_obj_t * ui_Label20;
extern lv_obj_t * ui_Chart4;
extern lv_obj_t * ui_Panel17;
extern lv_obj_t * ui_Panel18;
void ui_event_Panel19(lv_event_t * e);
extern lv_obj_t * ui_Panel19;
extern lv_obj_t * ui_Image7;
extern lv_obj_t * ui_Label21;
extern lv_obj_t * ui_Chart5;
extern lv_obj_t * ui_Panel20;
extern lv_obj_t * ui_Panel21;
void ui_event_Panel22(lv_event_t * e);
extern lv_obj_t * ui_Panel22;
extern lv_obj_t * ui_Image8;
extern lv_obj_t * ui_Label22;
extern lv_obj_t * ui_Chart6;
extern lv_obj_t * ui____initial_actions0;


LV_IMG_DECLARE(ui_img_bg_png);    // assets/bg.png
LV_IMG_DECLARE(ui_img_1287868244);    // assets/icons8-co2-30.png
LV_IMG_DECLARE(ui_img_232707142);    // assets/icons8-sun-30.png
LV_IMG_DECLARE(ui_img_1026557178);    // assets/icons8-temperature-30.png
LV_IMG_DECLARE(ui_img_242428017);    // assets/icons8-soil-30.png
LV_IMG_DECLARE(ui_img_902424251);    // assets/icons8-dew-point-30.png
LV_IMG_DECLARE(ui_img_83633437);    // assets/icons8-settings-30.png
LV_IMG_DECLARE(ui_img_72425762);    // assets/icons8-general-warning-sign-80.png
LV_IMG_DECLARE(ui_img_453075344);    // assets/icons8-return-30.png
LV_IMG_DECLARE(ui_img_1656800463);    // assets/icons8-automatic-brightness-30.png
LV_IMG_DECLARE(ui_img_1895014438);    // assets/icons8-voice-30.png
LV_IMG_DECLARE(ui_img_364366452);    // assets/icons8-graph-30.png
LV_IMG_DECLARE(ui_img_1909428037);    // assets/icons8-home-30.png
LV_IMG_DECLARE(ui_img_213399634);    // assets/icons8-place-marker-30.png



LV_FONT_DECLARE(ui_font_sonti_14);
LV_FONT_DECLARE(ui_font_sonti_16);
LV_FONT_DECLARE(ui_font_sonti_18);



void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
