// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: ebike_demo

#include "../ui.h"

void ui_Settings_screen_init(void)
{
    ui_Settings = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Settings, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_flex_flow(ui_Settings, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_Settings, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_set_style_bg_color(ui_Settings, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Settings, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Settings, &ui_img_settings_bg_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Group_Header1 = lv_obj_create(ui_Settings);
    lv_obj_set_height(ui_Group_Header1, 24);
    lv_obj_set_width(ui_Group_Header1, lv_pct(100));
    lv_obj_set_align(ui_Group_Header1, LV_ALIGN_TOP_MID);
    lv_obj_set_flex_flow(ui_Group_Header1, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Group_Header1, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Group_Header1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Group_Header1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Group_Header1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Head_Group2 = lv_obj_create(ui_Group_Header1);
    lv_obj_set_height(ui_Head_Group2, lv_pct(110));
    lv_obj_set_flex_grow(ui_Head_Group2, 1);
    lv_obj_set_align(ui_Head_Group2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Head_Group2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Head_Group2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Head_Group2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Head_Group2, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Head_Group2, 55, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Head_Group2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Head_Group2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_Time2 = lv_label_create(ui_Head_Group2);
    lv_obj_set_width(ui_Label_Time2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_Time2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_Time2, -28);
    lv_obj_set_y(ui_Label_Time2, 0);
    lv_obj_set_align(ui_Label_Time2, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_Label_Time2, "11:45");
    lv_obj_set_style_text_color(ui_Label_Time2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Time2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Time2, &ui_font_Medium, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabeL_PM1 = lv_label_create(ui_Head_Group2);
    lv_obj_set_width(ui_LabeL_PM1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabeL_PM1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabeL_PM1, -7);
    lv_obj_set_y(ui_LabeL_PM1, 0);
    lv_obj_set_align(ui_LabeL_PM1, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_LabeL_PM1, "PM");
    lv_obj_set_style_text_color(ui_LabeL_PM1, lv_color_hex(0x94AEB4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabeL_PM1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabeL_PM1, &ui_font_Small, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_Temp1 = lv_label_create(ui_Head_Group2);
    lv_obj_set_width(ui_Label_Temp1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_Temp1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_Temp1, -100);
    lv_obj_set_y(ui_Label_Temp1, 0);
    lv_obj_set_align(ui_Label_Temp1, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_Label_Temp1, "+24.7");
    lv_obj_set_style_text_color(ui_Label_Temp1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Temp1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Temp1, &ui_font_Medium, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_Celsius1 = lv_label_create(ui_Head_Group2);
    lv_obj_set_width(ui_Label_Celsius1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_Celsius1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_Celsius1, -84);
    lv_obj_set_y(ui_Label_Celsius1, 0);
    lv_obj_set_align(ui_Label_Celsius1, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_Label_Celsius1, "°C");
    lv_obj_set_style_text_color(ui_Label_Celsius1, lv_color_hex(0x94AEB4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Celsius1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Celsius1, &ui_font_Small, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_Battery1 = lv_label_create(ui_Head_Group2);
    lv_obj_set_width(ui_Label_Battery1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_Battery1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label_Battery1, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Label_Battery1, "Battery");
    lv_obj_set_style_text_color(ui_Label_Battery1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Battery1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Battery1, &ui_font_Medium, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Settings_Content = lv_obj_create(ui_Settings);
    lv_obj_set_height(ui_Settings_Content, 131);
    lv_obj_set_width(ui_Settings_Content, lv_pct(100));
    lv_obj_set_align(ui_Settings_Content, LV_ALIGN_TOP_MID);
    lv_obj_set_flex_flow(ui_Settings_Content, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Settings_Content, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Settings_Content, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Settings_Content, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Settings_Content, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Roller = ui_Roller_create(ui_Settings_Content);
    lv_obj_set_height(ui_Roller, 100);
    lv_obj_set_flex_grow(ui_Roller, 1);
    lv_obj_set_x(ui_Roller, 0);
    lv_obj_set_y(ui_Roller, 0);

    lv_obj_set_align(ui_comp_get_child(ui_Roller, UI_COMP_ROLLER_LABEL_ROLLER), LV_ALIGN_TOP_MID);

    lv_roller_set_options(ui_comp_get_child(ui_Roller, UI_COMP_ROLLER_ROLLER2), "Eco\nCity\nMontain\nRace",
                          LV_ROLLER_MODE_INFINITE);
    lv_obj_set_height(ui_comp_get_child(ui_Roller, UI_COMP_ROLLER_ROLLER2), 65);
    lv_obj_set_width(ui_comp_get_child(ui_Roller, UI_COMP_ROLLER_ROLLER2), lv_pct(100));

    lv_obj_set_style_bg_color(ui_comp_get_child(ui_Roller, UI_COMP_ROLLER_ROLLER2), lv_color_hex(0x3179CD),
                              LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_Roller, UI_COMP_ROLLER_ROLLER2), 255, LV_PART_SELECTED | LV_STATE_DEFAULT);

    ui_Roller1 = ui_Roller_create(ui_Settings_Content);
    lv_obj_set_height(ui_Roller1, 100);
    lv_obj_set_flex_grow(ui_Roller1, 1);
    lv_obj_set_x(ui_Roller1, 0);
    lv_obj_set_y(ui_Roller1, 0);

    lv_obj_set_align(ui_comp_get_child(ui_Roller1, UI_COMP_ROLLER_LABEL_ROLLER), LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_comp_get_child(ui_Roller1, UI_COMP_ROLLER_LABEL_ROLLER), "Speed Limit");

    lv_roller_set_options(ui_comp_get_child(ui_Roller1, UI_COMP_ROLLER_ROLLER2), "30 km/h\n40 km/h\n50 km/h\n60 km/h",
                          LV_ROLLER_MODE_INFINITE);
    lv_obj_set_height(ui_comp_get_child(ui_Roller1, UI_COMP_ROLLER_ROLLER2), 65);
    lv_obj_set_width(ui_comp_get_child(ui_Roller1, UI_COMP_ROLLER_ROLLER2), lv_pct(100));

    lv_obj_set_style_text_font(ui_comp_get_child(ui_Roller1, UI_COMP_ROLLER_ROLLER2), &ui_font_Medium,
                               LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_comp_get_child(ui_Roller1, UI_COMP_ROLLER_ROLLER2), lv_color_hex(0x3179CD),
                              LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_comp_get_child(ui_Roller1, UI_COMP_ROLLER_ROLLER2), 255,
                            LV_PART_SELECTED | LV_STATE_DEFAULT);

    ui_Brightness_Group = lv_obj_create(ui_Settings_Content);
    lv_obj_set_height(ui_Brightness_Group, 100);
    lv_obj_set_flex_grow(ui_Brightness_Group, 1);
    lv_obj_set_align(ui_Brightness_Group, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Brightness_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Brightness_Group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Brightness_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Brightness_Group, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Brightness_Group, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Brightness_Group, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Brightness_Group, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Brightness_Label = lv_label_create(ui_Brightness_Group);
    lv_obj_set_width(ui_Brightness_Label, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Brightness_Label, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Brightness_Label, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_Brightness_Label, "Volume");
    lv_obj_set_style_text_color(ui_Brightness_Label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Brightness_Label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Brightness_Label, &ui_font_Big, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Slider2 = lv_slider_create(ui_Brightness_Group);
    lv_slider_set_value(ui_Slider2, 50, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_Slider2) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_Slider2, 0, LV_ANIM_OFF);
    lv_obj_set_height(ui_Slider2, 10);
    lv_obj_set_width(ui_Slider2, lv_pct(90));
    lv_obj_set_x(ui_Slider2, 0);
    lv_obj_set_y(ui_Slider2, 27);
    lv_obj_set_align(ui_Slider2, LV_ALIGN_CENTER);
    lv_obj_set_style_radius(ui_Slider2, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Slider2, lv_color_hex(0x4A6573), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Slider2, 50, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Slider2, lv_color_hex(0x3392FF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider2, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Slider2, 50, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Slider2, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider2, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Slider2, lv_color_hex(0x000000), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Slider2, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Slider2, 20, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Slider2, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Slider2, 4, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Slider2, 4, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Slider2, 4, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Slider2, 4, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Brightness_Percent = lv_label_create(ui_Brightness_Group);
    lv_obj_set_width(ui_Brightness_Percent, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Brightness_Percent, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Brightness_Percent, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Brightness_Percent, "50%");
    lv_obj_set_style_text_color(ui_Brightness_Percent, lv_color_hex(0xFFE69C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Brightness_Percent, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Brightness_Percent, &ui_font_Big, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Volum_On = lv_img_create(ui_Brightness_Group);
    lv_img_set_src(ui_Volum_On, &ui_img_volume_on_png);
    lv_obj_set_width(ui_Volum_On, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Volum_On, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Volum_On, -7);
    lv_obj_set_y(ui_Volum_On, 0);
    lv_obj_set_align(ui_Volum_On, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_Volum_On, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Volum_On, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Volume_Off = lv_img_create(ui_Brightness_Group);
    lv_img_set_src(ui_Volume_Off, &ui_img_volume_off_png);
    lv_obj_set_width(ui_Volume_Off, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Volume_Off, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Volume_Off, 7);
    lv_obj_set_y(ui_Volume_Off, 0);
    lv_obj_set_align(ui_Volume_Off, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_Volume_Off, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Volume_Off, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Chart_Group = lv_obj_create(ui_Settings);
    lv_obj_set_width(ui_Chart_Group, lv_pct(100));
    lv_obj_set_flex_grow(ui_Chart_Group, 1);
    lv_obj_set_x(ui_Chart_Group, -7);
    lv_obj_set_y(ui_Chart_Group, 0);
    lv_obj_set_align(ui_Chart_Group, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Chart_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Chart_Group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Chart_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Chart_Label = lv_label_create(ui_Chart_Group);
    lv_obj_set_width(ui_Chart_Label, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Chart_Label, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Chart_Label, 14);
    lv_obj_set_y(ui_Chart_Label, -1);
    lv_label_set_text(ui_Chart_Label, "Speed statistic");
    lv_obj_set_style_text_color(ui_Chart_Label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Chart_Label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Chart_Label, &ui_font_Big, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel1 = lv_obj_create(ui_Chart_Group);
    lv_obj_set_height(ui_Panel1, 95);
    lv_obj_set_width(ui_Panel1, lv_pct(100));
    lv_obj_set_align(ui_Panel1, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_flex_flow(ui_Panel1, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Panel1, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_END);
    lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Panel1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Chart2 = lv_chart_create(ui_Panel1);
    lv_obj_set_height(ui_Chart2, 82);
    lv_obj_set_flex_grow(ui_Chart2, 1);
    lv_obj_set_align(ui_Chart2, LV_ALIGN_BOTTOM_MID);
    lv_chart_set_type(ui_Chart2, LV_CHART_TYPE_BAR);
    lv_chart_set_point_count(ui_Chart2, 50);
    lv_chart_set_range(ui_Chart2, LV_CHART_AXIS_PRIMARY_Y, 0, 70);
    lv_chart_set_div_line_count(ui_Chart2, 7, 20);
    lv_chart_set_zoom_x(ui_Chart2, 512);
    lv_chart_set_zoom_y(ui_Chart2, 256);
    lv_chart_set_axis_tick(ui_Chart2, LV_CHART_AXIS_PRIMARY_X, 1, 1, 1, 1, false, 50);
    lv_chart_set_axis_tick(ui_Chart2, LV_CHART_AXIS_PRIMARY_Y, 1, 5, 1, 2, false, 50);
    lv_chart_set_axis_tick(ui_Chart2, LV_CHART_AXIS_SECONDARY_Y, 0, 5, 0, 2, false, 25);
    lv_chart_series_t * ui_Chart2_series_1 = lv_chart_add_series(ui_Chart2, lv_color_hex(0x3392FF),
                                                                 LV_CHART_AXIS_PRIMARY_Y);
    static lv_coord_t ui_Chart2_series_1_array[] = { 10, 12, 18, 31, 25, 36, 40, 55, 40, 32, 12, 25, 55, 45, 43, 10, 22, 23, 25, 26, 27, 25, 21, 20, 26, 28, 32, 35, 34, 36, 31, 44, 50, 30, 34, 32, 38, 25, 25, 26, 25, 24, 21, 23, 27, 12, 13, 15, 10, 2 };
    lv_chart_set_ext_y_array(ui_Chart2, ui_Chart2_series_1, ui_Chart2_series_1_array);
    lv_obj_set_style_bg_color(ui_Chart2, lv_color_hex(0x080808), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Chart2, 70, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui_Chart2, lv_color_hex(0x293031), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui_Chart2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui_Chart2, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui_Chart2, true, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Chart2, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Chart2, 4, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Chart2, lv_color_hex(0xFFFFFF), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Chart2, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Chart2, lv_color_hex(0x000000), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Chart2, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Chart2, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Chart2, 5, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Chart2, 5, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Chart2, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Chart2, 3, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    lv_obj_set_style_line_width(ui_Chart2, 3, LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui_Chart2, true, LV_PART_ITEMS | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Chart2, 50, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_Panel2 = lv_obj_create(ui_Panel1);
    lv_obj_set_width(ui_Panel2, 100);
    lv_obj_set_height(ui_Panel2, lv_pct(100));
    lv_obj_set_align(ui_Panel2, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Panel2, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_Panel2, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Group_Max_Speed1 = lv_obj_create(ui_Panel2);
    lv_obj_set_width(ui_Group_Max_Speed1, 80);
    lv_obj_set_height(ui_Group_Max_Speed1, 40);
    lv_obj_set_align(ui_Group_Max_Speed1, LV_ALIGN_RIGHT_MID);
    lv_obj_clear_flag(ui_Group_Max_Speed1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Group_Max_Speed1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Group_Max_Speed1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Group_Max_Speed1, lv_color_hex(0x4A6573), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Group_Max_Speed1, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Group_Max_Speed1, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Group_Max_Speed1, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Group_Max_Speed1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Group_Max_Speed1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Group_Max_Speed1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Group_Max_Speed1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_Max_Speed1 = lv_label_create(ui_Group_Max_Speed1);
    lv_obj_set_width(ui_Label_Max_Speed1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_Max_Speed1, LV_SIZE_CONTENT);    /// 1
    lv_label_set_text(ui_Label_Max_Speed1, "MAX. SPEED");
    lv_obj_set_style_text_color(ui_Label_Max_Speed1, lv_color_hex(0x94AEB4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Max_Speed1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Max_Speed1, &ui_font_Small, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_Max_Speed_Number1 = lv_label_create(ui_Group_Max_Speed1);
    lv_obj_set_width(ui_Label_Max_Speed_Number1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_Max_Speed_Number1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_Max_Speed_Number1, 2);
    lv_obj_set_y(ui_Label_Max_Speed_Number1, 6);
    lv_obj_set_align(ui_Label_Max_Speed_Number1, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Label_Max_Speed_Number1, "42.7");
    lv_obj_set_style_text_color(ui_Label_Max_Speed_Number1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Max_Speed_Number1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Max_Speed_Number1, &ui_font_Big, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_kmh4 = lv_label_create(ui_Group_Max_Speed1);
    lv_obj_set_width(ui_Label_kmh4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_kmh4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_kmh4, -6);
    lv_obj_set_y(ui_Label_kmh4, -5);
    lv_obj_set_align(ui_Label_kmh4, LV_ALIGN_BOTTOM_RIGHT);
    lv_label_set_text(ui_Label_kmh4, "km/h");
    lv_obj_set_style_text_color(ui_Label_kmh4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_kmh4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_kmh4, &ui_font_Small, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Group_AVG_Speed1 = lv_obj_create(ui_Panel2);
    lv_obj_set_width(ui_Group_AVG_Speed1, 80);
    lv_obj_set_height(ui_Group_AVG_Speed1, 40);
    lv_obj_set_align(ui_Group_AVG_Speed1, LV_ALIGN_LEFT_MID);
    lv_obj_clear_flag(ui_Group_AVG_Speed1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Group_AVG_Speed1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Group_AVG_Speed1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Group_AVG_Speed1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Group_AVG_Speed1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Group_AVG_Speed1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Group_AVG_Speed1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_AVG_Speed1 = lv_label_create(ui_Group_AVG_Speed1);
    lv_obj_set_width(ui_Label_AVG_Speed1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_AVG_Speed1, LV_SIZE_CONTENT);    /// 1
    lv_label_set_text(ui_Label_AVG_Speed1, "AVG. SPEED");
    lv_obj_set_style_text_color(ui_Label_AVG_Speed1, lv_color_hex(0x94AEB4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_AVG_Speed1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_AVG_Speed1, &ui_font_Small, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_AVG_Speed_Number1 = lv_label_create(ui_Group_AVG_Speed1);
    lv_obj_set_width(ui_Label_AVG_Speed_Number1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_AVG_Speed_Number1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_AVG_Speed_Number1, 2);
    lv_obj_set_y(ui_Label_AVG_Speed_Number1, 6);
    lv_obj_set_align(ui_Label_AVG_Speed_Number1, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Label_AVG_Speed_Number1, "18.3");
    lv_obj_set_style_text_color(ui_Label_AVG_Speed_Number1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_AVG_Speed_Number1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_AVG_Speed_Number1, &ui_font_Big, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_kmh5 = lv_label_create(ui_Group_AVG_Speed1);
    lv_obj_set_width(ui_Label_kmh5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_kmh5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_kmh5, -6);
    lv_obj_set_y(ui_Label_kmh5, -5);
    lv_obj_set_align(ui_Label_kmh5, LV_ALIGN_BOTTOM_RIGHT);
    lv_label_set_text(ui_Label_kmh5, "km/h");
    lv_obj_set_style_text_color(ui_Label_kmh5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_kmh5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_kmh5, &ui_font_Small, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_Number6 = lv_label_create(ui_Chart_Group);
    lv_obj_set_width(ui_Label_Number6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_Number6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_Number6, -101);
    lv_obj_set_y(ui_Label_Number6, 9);
    lv_obj_set_align(ui_Label_Number6, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_Label_Number6, "max. 70#94aeb4  km/h");
    lv_label_set_recolor(ui_Label_Number6, "true");
    lv_obj_set_style_text_color(ui_Label_Number6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Number6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Number6, &ui_font_Small, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Menu1 = lv_img_create(ui_Settings);
    lv_img_set_src(ui_Menu1, &ui_img_settings_corner_png);
    lv_obj_set_width(ui_Menu1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Menu1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Menu1, LV_ALIGN_TOP_RIGHT);
    lv_obj_add_flag(ui_Menu1, LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_FLOATING);     /// Flags
    lv_obj_clear_flag(ui_Menu1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_BTN_Settings1 = lv_btn_create(ui_Menu1);
    lv_obj_set_width(ui_BTN_Settings1, 35);
    lv_obj_set_height(ui_BTN_Settings1, 30);
    lv_obj_set_align(ui_BTN_Settings1, LV_ALIGN_TOP_RIGHT);
    lv_obj_add_flag(ui_BTN_Settings1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_BTN_Settings1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_BTN_Settings1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BTN_Settings1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_BTN_Settings1, &ui_img_icn_x2_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Slider2, ui_event_Slider2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Volum_On, ui_event_Volum_On, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Volume_Off, ui_event_Volume_Off, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_BTN_Settings1, ui_event_BTN_Settings1, LV_EVENT_ALL, NULL);

}