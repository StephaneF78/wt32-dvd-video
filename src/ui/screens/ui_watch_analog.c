// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.6
// Project name: SmartwatchSC01

#include "../ui.h"

void ui_watch_analog_screen_init(void)
{
    ui_watch_analog = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_watch_analog, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_watch_analog, lv_color_hex(0x101010), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_watch_analog, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bg_2 = lv_img_create(ui_watch_analog);
    lv_img_set_src(ui_bg_2, &ui_img_fondmulticolor1_png);
    lv_obj_set_width(ui_bg_2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_bg_2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_bg_2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_bg_2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_bg_2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_zoom(ui_bg_2, 255);
    lv_obj_set_style_bg_color(ui_bg_2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_bg_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_bg_2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_bg_2, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bg_3 = lv_img_create(ui_watch_analog);
    lv_img_set_src(ui_bg_3, &ui_img_192753598);
    lv_obj_set_width(ui_bg_3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_bg_3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_bg_3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_bg_3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_bg_3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_zoom(ui_bg_3, 128);
    lv_obj_set_style_bg_grad_dir(ui_bg_3, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_clock = lv_label_create(ui_watch_analog);
    lv_obj_set_width(ui_clock, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_clock, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_clock, -4);
    lv_obj_set_y(ui_clock, 96);
    lv_obj_set_align(ui_clock, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_clock, "03 : 27");
    lv_obj_set_style_text_color(ui_clock, lv_color_hex(0xAD1111), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_clock, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_clock, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_clock, &lv_font_montserrat_38, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_dots = lv_label_create(ui_watch_analog);
    lv_obj_set_width(ui_dots, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_dots, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_dots, -3);
    lv_obj_set_y(ui_dots, 95);
    lv_obj_set_align(ui_dots, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_dots, ":");
    lv_obj_set_style_text_color(ui_dots, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_dots, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_dots, &ui_font_H1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_jaugeCharge = lv_arc_create(ui_watch_analog);
    lv_obj_set_width(ui_jaugeCharge, 80);
    lv_obj_set_height(ui_jaugeCharge, 88);
    lv_obj_set_x(ui_jaugeCharge, -193);
    lv_obj_set_y(ui_jaugeCharge, -60);
    lv_obj_set_align(ui_jaugeCharge, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_jaugeCharge, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_scrollbar_mode(ui_jaugeCharge, LV_SCROLLBAR_MODE_OFF);
    lv_arc_set_value(ui_jaugeCharge, 30);
    lv_obj_set_style_arc_color(ui_jaugeCharge, lv_color_hex(0xDCFAD2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_jaugeCharge, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_jaugeCharge, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui_jaugeCharge, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_jaugeCharge, lv_color_hex(0x55D914), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_jaugeCharge, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_jaugeCharge, 20, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui_jaugeCharge, true, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_opa(ui_jaugeCharge, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_ChargePCT = lv_label_create(ui_jaugeCharge);
    lv_obj_set_width(ui_ChargePCT, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ChargePCT, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ChargePCT, 2);
    lv_obj_set_y(ui_ChargePCT, -5);
    lv_obj_set_align(ui_ChargePCT, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ChargePCT, "50");
    lv_obj_set_style_text_color(ui_ChargePCT, lv_color_hex(0x52DA10), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ChargePCT, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ChargePCT, &ui_font_Subtitle, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChargePCT1 = lv_label_create(ui_jaugeCharge);
    lv_obj_set_width(ui_ChargePCT1, LV_SIZE_CONTENT);   /// 8
    lv_obj_set_height(ui_ChargePCT1, LV_SIZE_CONTENT);    /// 8
    lv_obj_set_x(ui_ChargePCT1, 1);
    lv_obj_set_y(ui_ChargePCT1, 17);
    lv_obj_set_align(ui_ChargePCT1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ChargePCT1, "%");
    lv_obj_clear_flag(ui_ChargePCT1, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_color(ui_ChargePCT1, lv_color_hex(0x52DA10), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ChargePCT1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ChargePCT1, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel1 = lv_obj_create(ui_watch_analog);
    lv_obj_set_width(ui_Panel1, 107);
    lv_obj_set_height(ui_Panel1, 52);
    lv_obj_set_x(ui_Panel1, -177);
    lv_obj_set_y(ui_Panel1, 122);
    lv_obj_set_align(ui_Panel1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel1, lv_color_hex(0x282323), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BPTempo1 = lv_imgbtn_create(ui_Panel1);
    lv_imgbtn_set_src(ui_BPTempo1, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_bptempobleu_50_png, NULL);
    lv_imgbtn_set_src(ui_BPTempo1, LV_IMGBTN_STATE_PRESSED, NULL, &ui_img_ampoulebleu_png, NULL);
    lv_obj_set_width(ui_BPTempo1, 45);
    lv_obj_set_height(ui_BPTempo1, 45);
    lv_obj_set_x(ui_BPTempo1, -28);
    lv_obj_set_y(ui_BPTempo1, -1);
    lv_obj_set_align(ui_BPTempo1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_BPTempo1, LV_OBJ_FLAG_EVENT_BUBBLE);     /// Flags
    lv_obj_clear_flag(ui_BPTempo1, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_CHAIN);      /// Flags
    lv_obj_set_style_blend_mode(ui_BPTempo1, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_BPTempo1, 160, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BPTempo2 = lv_imgbtn_create(ui_Panel1);
    lv_imgbtn_set_src(ui_BPTempo2, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_bptemporouge50_png, NULL);
    lv_imgbtn_set_src(ui_BPTempo2, LV_IMGBTN_STATE_PRESSED, NULL, &ui_img_ampoulebleu_png, NULL);
    lv_obj_set_width(ui_BPTempo2, 45);
    lv_obj_set_height(ui_BPTempo2, 45);
    lv_obj_set_x(ui_BPTempo2, 25);
    lv_obj_set_y(ui_BPTempo2, -2);
    lv_obj_set_align(ui_BPTempo2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_BPTempo2, LV_OBJ_FLAG_EVENT_BUBBLE);     /// Flags
    lv_obj_clear_flag(ui_BPTempo2, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_CHAIN);      /// Flags
    lv_obj_set_style_blend_mode(ui_BPTempo2, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_BPTempo2, 160, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_date_group2 = lv_obj_create(ui_watch_analog);
    lv_obj_set_width(ui_date_group2, 121);
    lv_obj_set_height(ui_date_group2, 90);
    lv_obj_set_x(ui_date_group2, 179);
    lv_obj_set_y(ui_date_group2, 11);
    lv_obj_set_align(ui_date_group2, LV_ALIGN_TOP_MID);
    lv_obj_set_flex_flow(ui_date_group2, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_date_group2, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_date_group2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_date_group2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_date_group2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_day2 = lv_label_create(ui_date_group2);
    lv_obj_set_width(ui_day2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_day2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_day2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_day2, "MON");
    lv_obj_set_style_text_color(ui_day2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_day2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_day2, &ui_font_Subtitle, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_month2 = lv_label_create(ui_date_group2);
    lv_obj_set_width(ui_month2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_month2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_month2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_month2, "18 FEB");
    lv_obj_set_style_text_color(ui_month2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_month2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_month2, &ui_font_Title, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_year2 = lv_label_create(ui_date_group2);
    lv_obj_set_width(ui_year2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_year2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_year2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_year2, "2022");
    lv_obj_set_style_text_color(ui_year2, lv_color_hex(0x6B6B6B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_year2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_year2, &ui_font_Title, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_weather_title_group_2 = ui_titlegroup_create(ui_watch_analog);
    lv_obj_set_x(ui_weather_title_group_2, -167);
    lv_obj_set_y(ui_weather_title_group_2, -270);
    lv_obj_set_align(ui_weather_title_group_2, LV_ALIGN_BOTTOM_MID);

    lv_label_set_text(ui_comp_get_child(ui_weather_title_group_2, UI_COMP_TITLEGROUP_TITLE), "Partly Cloudy");
    lv_label_set_recolor(ui_comp_get_child(ui_weather_title_group_2, UI_COMP_TITLEGROUP_TITLE), "true");
    lv_obj_set_style_text_color(ui_comp_get_child(ui_weather_title_group_2, UI_COMP_TITLEGROUP_TITLE),
                                lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_comp_get_child(ui_weather_title_group_2, UI_COMP_TITLEGROUP_TITLE), 255,
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_comp_get_child(ui_weather_title_group_2, UI_COMP_TITLEGROUP_TITLE),
                                  lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_comp_get_child(ui_weather_title_group_2, UI_COMP_TITLEGROUP_TITLE), 255,
                                LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_label_set_text(ui_comp_get_child(ui_weather_title_group_2, UI_COMP_TITLEGROUP_SUBTITLE), "Max: 18° Min: 12°");
    lv_label_set_recolor(ui_comp_get_child(ui_weather_title_group_2, UI_COMP_TITLEGROUP_SUBTITLE), "true");

    ui_weather_group_5 = lv_obj_create(ui_watch_analog);
    lv_obj_set_width(ui_weather_group_5, 82);
    lv_obj_set_height(ui_weather_group_5, 76);
    lv_obj_set_x(ui_weather_group_5, -68);
    lv_obj_set_y(ui_weather_group_5, 15);
    lv_obj_set_align(ui_weather_group_5, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_weather_group_5, LV_FLEX_FLOW_COLUMN_REVERSE);
    lv_obj_set_flex_align(ui_weather_group_5, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_weather_group_5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_weather_group_5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_weather_group_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_weather_group_5, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_weather_group_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_degree_7 = lv_label_create(ui_weather_group_5);
    lv_obj_set_width(ui_degree_7, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_degree_7, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_degree_7, 53);
    lv_obj_set_y(ui_degree_7, -5);
    lv_obj_set_align(ui_degree_7, LV_ALIGN_CENTER);
    lv_label_set_text(ui_degree_7, "25°");
    lv_obj_set_style_text_color(ui_degree_7, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_degree_7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_degree_7, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_cloud_fog_3 = lv_img_create(ui_weather_group_5);
    lv_img_set_src(ui_cloud_fog_3, &ui_img_weather_sun_cloud_png);
    lv_obj_set_width(ui_cloud_fog_3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_cloud_fog_3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_cloud_fog_3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_cloud_fog_3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_cloud_fog_3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_button_down1 = ui_buttondown_create(ui_watch_analog);
    lv_obj_set_x(ui_button_down1, 182);
    lv_obj_set_y(ui_button_down1, 110);



    ui_clock_group = lv_obj_create(ui_watch_analog);
    lv_obj_set_width(ui_clock_group, 320);
    lv_obj_set_height(ui_clock_group, 320);
    lv_obj_set_align(ui_clock_group, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_clock_group, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_clock_group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_clock_group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_hour = lv_img_create(ui_clock_group);
    lv_img_set_src(ui_hour, &ui_img_275344589);
    lv_obj_set_width(ui_hour, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_hour, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_hour, 0);
    lv_obj_set_y(ui_hour, -52);
    lv_obj_set_align(ui_hour, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_hour, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_hour, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_pivot(ui_hour, 24, 146);
    lv_img_set_angle(ui_hour, 1800);
    lv_img_set_zoom(ui_hour, 150);

    ui_min = lv_img_create(ui_clock_group);
    lv_img_set_src(ui_min, &ui_img_710189694);
    lv_obj_set_width(ui_min, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_min, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_min, 2);
    lv_obj_set_y(ui_min, -74);
    lv_obj_set_align(ui_min, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_min, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_min, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_pivot(ui_min, 16, 195);
    lv_img_set_angle(ui_min, 2800);
    lv_img_set_zoom(ui_min, 136);

    ui_sec = lv_img_create(ui_clock_group);
    lv_img_set_src(ui_sec, &ui_img_610538489);
    lv_obj_set_width(ui_sec, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_sec, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_sec, -3);
    lv_obj_set_y(ui_sec, -60);
    lv_obj_set_align(ui_sec, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_sec, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_sec, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_pivot(ui_sec, 18, 182);
    lv_img_set_angle(ui_sec, 2800);
    lv_img_set_zoom(ui_sec, 158);

    ui_dots_group = lv_obj_create(ui_watch_analog);
    lv_obj_set_width(ui_dots_group, 20);
    lv_obj_set_height(ui_dots_group, 50);
    lv_obj_set_x(ui_dots_group, -45);
    lv_obj_set_y(ui_dots_group, -5);
    lv_obj_set_align(ui_dots_group, LV_ALIGN_RIGHT_MID);
    lv_obj_set_flex_flow(ui_dots_group, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_dots_group, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_dots_group, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_dots_group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_dots_group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_dots_group, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_dots_group, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_dot16 = lv_obj_create(ui_dots_group);
    lv_obj_set_width(ui_dot16, 15);
    lv_obj_set_height(ui_dot16, 15);
    lv_obj_set_align(ui_dot16, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_dot16, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_dot16, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_dot17 = lv_obj_create(ui_dots_group);
    lv_obj_set_width(ui_dot17, 6);
    lv_obj_set_height(ui_dot17, 6);
    lv_obj_set_align(ui_dot17, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_dot17, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_dot17, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_dot17, lv_color_hex(0x676767), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_dot17, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_bg_3, ui_event_bg_3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_jaugeCharge, ui_event_jaugeCharge, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_BPTempo1, ui_event_BPTempo1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_BPTempo2, ui_event_BPTempo2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_day2, ui_event_day2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_date_group2, ui_event_date_group2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_button_down1, ui_event_button_down1_buttondown, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_sec, ui_event_sec, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_watch_analog, ui_event_watch_analog, LV_EVENT_ALL, NULL);

}
