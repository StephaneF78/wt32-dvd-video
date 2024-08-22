// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.6
// Project name: SmartwatchSC01

#ifndef _SMARTWATCHSC01_UI_H
#define _SMARTWATCHSC01_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

#include "ui_helpers.h"
#include "components/ui_comp.h"
#include "components/ui_comp_hook.h"
#include "ui_events.h"

void sec_Animation(lv_obj_t * TargetObject, int delay);
void min_Animation(lv_obj_t * TargetObject, int delay);
void hour_Animation(lv_obj_t * TargetObject, int delay);
void left_Animation(lv_obj_t * TargetObject, int delay);
void right_Animation(lv_obj_t * TargetObject, int delay);
void opa_on_Animation(lv_obj_t * TargetObject, int delay);
void dots_Animation(lv_obj_t * TargetObject, int delay);
void top_Animation(lv_obj_t * TargetObject, int delay);
void cloud_Animation(lv_obj_t * TargetObject, int delay);
void blood2_Animation(lv_obj_t * TargetObject, int delay);
void blood1_Animation(lv_obj_t * TargetObject, int delay);
void heart_Animation(lv_obj_t * TargetObject, int delay);
// SCREEN: ui_watch_analog
void ui_watch_analog_screen_init(void);
void ui_event_watch_analog(lv_event_t * e);
extern lv_obj_t * ui_watch_analog;
extern lv_obj_t * ui_bg_2;
void ui_event_bg_3(lv_event_t * e);
extern lv_obj_t * ui_bg_3;
extern lv_obj_t * ui_clock;
extern lv_obj_t * ui_dots;
void ui_event_jaugeCharge(lv_event_t * e);
extern lv_obj_t * ui_jaugeCharge;
extern lv_obj_t * ui_ChargePCT;
extern lv_obj_t * ui_ChargePCT1;
extern lv_obj_t * ui_Panel1;
void ui_event_BPTempo1(lv_event_t * e);
extern lv_obj_t * ui_BPTempo1;
void ui_event_BPTempo2(lv_event_t * e);
extern lv_obj_t * ui_BPTempo2;
void ui_event_date_group2(lv_event_t * e);
extern lv_obj_t * ui_date_group2;
void ui_event_day2(lv_event_t * e);
extern lv_obj_t * ui_day2;
extern lv_obj_t * ui_month2;
extern lv_obj_t * ui_year2;
extern lv_obj_t * ui_weather_title_group_2;
extern lv_obj_t * ui_weather_group_5;
extern lv_obj_t * ui_degree_7;
extern lv_obj_t * ui_cloud_fog_3;
void ui_event_button_down1_buttondown(lv_event_t * e);
extern lv_obj_t * ui_button_down1;
extern lv_obj_t * ui_clock_group;
extern lv_obj_t * ui_hour;
extern lv_obj_t * ui_min;
void ui_event_sec(lv_event_t * e);
extern lv_obj_t * ui_sec;
extern lv_obj_t * ui_dots_group;
extern lv_obj_t * ui_dot16;
extern lv_obj_t * ui_dot17;
// SCREEN: ui_Conso_EDF
void ui_Conso_EDF_screen_init(void);
void ui_event_Conso_EDF(lv_event_t * e);
extern lv_obj_t * ui_Conso_EDF;
extern lv_obj_t * ui_bg_1;
void ui_event_Edf(lv_event_t * e);
extern lv_obj_t * ui_Edf;
extern lv_obj_t * ui_ConsoClic;
void ui_event_button_down_buttondown(lv_event_t * e);
extern lv_obj_t * ui_button_down;
// SCREEN: ui_weather_1
void ui_weather_1_screen_init(void);
void ui_event_weather_1(lv_event_t * e);
extern lv_obj_t * ui_weather_1;
extern lv_obj_t * ui_bg_4;
extern lv_obj_t * ui_city_gruop_1;
extern lv_obj_t * ui_weather_title_group_3;
extern lv_obj_t * ui_label_degree;
extern lv_obj_t * ui_rain_group;
extern lv_obj_t * ui_rain_icon;
extern lv_obj_t * ui_rain_percent;
extern lv_obj_t * ui_pression_group1;
extern lv_obj_t * ui_Pression_icone;
extern lv_obj_t * ui_Pression;
extern lv_obj_t * ui_wind_group;
extern lv_obj_t * ui_wind_icon;
extern lv_obj_t * ui_wind_speed;
extern lv_obj_t * ui_weather_dots_group;
extern lv_obj_t * ui_dot1;
extern lv_obj_t * ui_dot2;
extern lv_obj_t * ui_weather_image_group;
extern lv_obj_t * ui_sun;
extern lv_obj_t * ui_clouds;
void ui_event_button_down3_buttondown(lv_event_t * e);
extern lv_obj_t * ui_button_down3;
// SCREEN: ui_weather_2
void ui_weather_2_screen_init(void);
void ui_event_weather_2(lv_event_t * e);
extern lv_obj_t * ui_weather_2;
extern lv_obj_t * ui_bg5;
extern lv_obj_t * ui_weather_dots_group1;
extern lv_obj_t * ui_dot3;
extern lv_obj_t * ui_dot4;
extern lv_obj_t * ui_content;
extern lv_obj_t * ui_city_gruop_2;
extern lv_obj_t * ui_todady_weather_content;
extern lv_obj_t * ui_today_weather_group;
extern lv_obj_t * ui_today_weather_group1;
extern lv_obj_t * ui_today_weather_group2;
extern lv_obj_t * ui_today_weather_group3;
extern lv_obj_t * ui_today_weather_group4;
extern lv_obj_t * ui_days_forecast;
extern lv_obj_t * ui_week_weather_group;
extern lv_obj_t * ui_forecast_group;
extern lv_obj_t * ui_forecast_group1;
extern lv_obj_t * ui_forecast_group2;
void ui_event_button_down4_buttondown(lv_event_t * e);
extern lv_obj_t * ui_button_down4;
// SCREEN: ui_LogErreurs
void ui_LogErreurs_screen_init(void);
void ui_event_LogErreurs(lv_event_t * e);
extern lv_obj_t * ui_LogErreurs;
extern lv_obj_t * ui_bg_5;
void ui_event_button_down2_buttondown(lv_event_t * e);
extern lv_obj_t * ui_button_down2;
extern lv_obj_t * ui_Log;
// SCREEN: ui_Moto
void ui_Moto_screen_init(void);
void ui_event_Moto(lv_event_t * e);
extern lv_obj_t * ui_Moto;
extern lv_obj_t * ui_bg_6;
extern lv_obj_t * ui_BgZero;
extern lv_obj_t * ui_priseCharge;
extern lv_obj_t * ui_flashAlim;
void ui_event_button_down5_buttondown(lv_event_t * e);
extern lv_obj_t * ui_button_down5;
extern lv_obj_t * ui_labelCharge;
void ui_event_jaugeCharge1(lv_event_t * e);
extern lv_obj_t * ui_jaugeCharge1;
extern lv_obj_t * ui_ChargePCT2;
extern lv_obj_t * ui_ChargePCT3;
extern lv_obj_t * ui_enCharge;
extern lv_obj_t * ui_analyseMoto;
extern lv_obj_t * ui_labelAutoRest;
void ui_event____initial_actions0(lv_event_t * e);
extern lv_obj_t * ui____initial_actions0;


LV_IMG_DECLARE(ui_img_fondmulticolor_png);    // assets/FondMulticolor.png
LV_IMG_DECLARE(ui_img_192753598);    // assets/RollexCadranPaint-RemoveBG.png
LV_IMG_DECLARE(ui_img_bptempobleu_50_png);    // assets/BPTempoBleu_50.png
LV_IMG_DECLARE(ui_img_ampoulebleu_png);    // assets/AmpouleBleu.png
LV_IMG_DECLARE(ui_img_bptemporouge50_png);    // assets/BPTempoRouge50.png
LV_IMG_DECLARE(ui_img_weather_sun_cloud_png);    // assets/weather_sun_cloud.png
LV_IMG_DECLARE(ui_img_weather_png);    // assets/weather.png
LV_IMG_DECLARE(ui_img_btn_bg_3_png);    // assets/btn_bg_3.png
LV_IMG_DECLARE(ui_img_275344589);    // assets/RollexHeure-removebg-preview.png
LV_IMG_DECLARE(ui_img_710189694);    // assets/RollexMin-removebg-preview.png
LV_IMG_DECLARE(ui_img_610538489);    // assets/RollexSec-removebg-preview.png
LV_IMG_DECLARE(ui_img_house_png);    // assets/house.png
LV_IMG_DECLARE(ui_img_rain_png);    // assets/rain.png
LV_IMG_DECLARE(ui_img_pression_png);    // assets/pression.png
LV_IMG_DECLARE(ui_img_wind_png);    // assets/wind.png
LV_IMG_DECLARE(ui_img_sun_png);    // assets/sun.png
LV_IMG_DECLARE(ui_img_50d2x_png);    // assets/50d2x.png
LV_IMG_DECLARE(ui_img_weather_sun_png);    // assets/weather_sun.png
LV_IMG_DECLARE(ui_img_01d2x_png);    // assets/01d2x.png
LV_IMG_DECLARE(ui_img_02d2x_png);    // assets/02d2x.png
LV_IMG_DECLARE(ui_img_02n2x_png);    // assets/02n2x.png
LV_IMG_DECLARE(ui_img_03d2x_png);    // assets/03d2x.png
LV_IMG_DECLARE(ui_img_03n2x_png);    // assets/03n2x.png
LV_IMG_DECLARE(ui_img_04d2x_png);    // assets/04d2x.png
LV_IMG_DECLARE(ui_img_weather_cloud_png);    // assets/weather_cloud.png
LV_IMG_DECLARE(ui_img_zerotrans1_png);    // assets/ZeroTrans1.png
LV_IMG_DECLARE(ui_img_prise100trans_png);    // assets/prise100trans.png
LV_IMG_DECLARE(ui_img_flash_png);    // assets/flash.png
LV_IMG_DECLARE(ui_img_01n2x_png);    // assets/01n2x.png
LV_IMG_DECLARE(ui_img_04n2x_png);    // assets/04n2x.png
LV_IMG_DECLARE(ui_img_09d2x_png);    // assets/09d2x.png
LV_IMG_DECLARE(ui_img_09n2x_png);    // assets/09n2x.png
LV_IMG_DECLARE(ui_img_10d2x_png);    // assets/10d2x.png
LV_IMG_DECLARE(ui_img_10n2x_png);    // assets/10n2x.png
LV_IMG_DECLARE(ui_img_11d2x_png);    // assets/11d2x.png
LV_IMG_DECLARE(ui_img_11n2x_png);    // assets/11n2x.png
LV_IMG_DECLARE(ui_img_13d2x_png);    // assets/13d2x.png
LV_IMG_DECLARE(ui_img_13n2x_png);    // assets/13n2x.png
LV_IMG_DECLARE(ui_img_50n2x_png);    // assets/50n2x.png
LV_IMG_DECLARE(ui_img_ampouleblanche_png);    // assets/AmpouleBlanche.png
LV_IMG_DECLARE(ui_img_ampoulerouge_png);    // assets/AmpouleRouge.png
LV_IMG_DECLARE(ui_img_arrow_png);    // assets/arrow.png
LV_IMG_DECLARE(ui_img_bg1_png);    // assets/bg1.png
LV_IMG_DECLARE(ui_img_bg2_png);    // assets/bg2.png
LV_IMG_DECLARE(ui_img_bg3_png);    // assets/bg3.png
LV_IMG_DECLARE(ui_img_boutontemporouge_png);    // assets/BoutonTempoRouge.png
LV_IMG_DECLARE(ui_img_boutontemporouge50_png);    // assets/BoutonTempoRouge50.png
LV_IMG_DECLARE(ui_img_boutontemporouge70_png);    // assets/BoutonTempoRouge70.png
LV_IMG_DECLARE(ui_img_boutontemporougefondnoir_png);    // assets/BoutonTempoRougefondNoir.png
LV_IMG_DECLARE(ui_img_bptempoblanc_50_png);    // assets/BPTempoBlanc 50.png
LV_IMG_DECLARE(ui_img_btn_bg_1_png);    // assets/btn_bg_1.png
LV_IMG_DECLARE(ui_img_btn_bg_2_png);    // assets/btn_bg_2.png
LV_IMG_DECLARE(ui_img_clockwise_hour_png);    // assets/clockwise_hour.png
LV_IMG_DECLARE(ui_img_clockwise_min_png);    // assets/clockwise_min.png
LV_IMG_DECLARE(ui_img_clockwise_sec_png);    // assets/clockwise_sec.png
LV_IMG_DECLARE(ui_img_clouds_png);    // assets/clouds.png
LV_IMG_DECLARE(ui_img_fondmulticolor1_png);    // assets/FondMulticolor1.png
LV_IMG_DECLARE(ui_img_grid_png);    // assets/grid.png
LV_IMG_DECLARE(ui_img_heart_png);    // assets/heart.png
LV_IMG_DECLARE(ui_img_heart2_png);    // assets/heart2.png
LV_IMG_DECLARE(ui_img_mask_png);    // assets/mask.png
LV_IMG_DECLARE(ui_img_measure_png);    // assets/measure.png
LV_IMG_DECLARE(ui_img_mute_png);    // assets/mute.png
LV_IMG_DECLARE(ui_img_rollexmin_png);    // assets/RollexMin.png
LV_IMG_DECLARE(ui_img_rollexsec_png);    // assets/RollexSec.png
LV_IMG_DECLARE(ui_img_rollexsec1_png);    // assets/RollexSec1.png
LV_IMG_DECLARE(ui_img_s1_png);    // assets/s1.png
LV_IMG_DECLARE(ui_img_s2_png);    // assets/s2.png
LV_IMG_DECLARE(ui_img_s4_png);    // assets/s4.png
LV_IMG_DECLARE(ui_img_s5_png);    // assets/s5.png
LV_IMG_DECLARE(ui_img_sec_dot_png);    // assets/sec_dot.png
LV_IMG_DECLARE(ui_img_step_png);    // assets/step.png
LV_IMG_DECLARE(ui_img_wave1_png);    // assets/wave1.png
LV_IMG_DECLARE(ui_img_wave2_png);    // assets/wave2.png
LV_IMG_DECLARE(ui_img_weather_cloud_fog_png);    // assets/weather_cloud_fog.png
LV_IMG_DECLARE(ui_img_1027436578);    // assets/WT32-SC01-bg1.png
LV_IMG_DECLARE(ui_img_299354449);    // assets/WT32-SC01-bg2.png
LV_IMG_DECLARE(ui_img_1381083628);    // assets/WT32-SC01-bg3.png
LV_IMG_DECLARE(ui_img_x_png);    // assets/x.png



LV_FONT_DECLARE(ui_font_H1);
LV_FONT_DECLARE(ui_font_Number_big);
LV_FONT_DECLARE(ui_font_Number_extra);
LV_FONT_DECLARE(ui_font_Subtitle);
LV_FONT_DECLARE(ui_font_Title);



void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
