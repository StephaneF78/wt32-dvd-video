// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.6
// Project name: SmartwatchSC01

#include "ui.h"
#include <Arduino.h> // ajout sbi


void luminosite(lv_event_t * e)
{
	//
}

void enregistrer(lv_event_t * e)
{
	// Your code here
	Serial.println("Enregistrer la conf");    
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * btn = lv_event_get_target(e);
    if(event_code == LV_EVENT_PRESSED) {
        static uint8_t cnt = 0;
        cnt++;
        //saveConfigFile();
        Serial.println("Enregistrer via Event Pressed  la conf appel depuis ui_event");
        // saveConfigFile();
        startLittleFS();
        /*Get the first child of the button which is the label and change its text*/
        //lv_obj_t * label = lv_obj_get_child(ui_bpenregistrer, 0);
        //lv_label_set_text_fmt(label, "Enreg: %d", cnt);
    }
   
}


void validerWifi(lv_event_t * e)
{
	// Your code here
    Serial.println("Valider et Enregistrer validationWifi");
}
