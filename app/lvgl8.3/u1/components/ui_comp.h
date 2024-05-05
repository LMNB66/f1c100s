// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: ebike_demo

#ifndef _UI_COMP__H
#define _UI_COMP__H

#include "../ui.h"

#ifdef __cplusplus
extern "C" {
#endif

void get_component_child_event_cb(lv_event_t * e);
void del_component_child_event_cb(lv_event_t * e);

lv_obj_t * ui_comp_get_child(lv_obj_t * comp, uint32_t child_idx);
extern uint32_t LV_EVENT_GET_COMP_CHILD;
#include "ui_comp_dropdown.h"
#include "ui_comp_roller.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
