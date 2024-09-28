/*
   MIT License

  Copyright (c) 2022 Felix Biego

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.

  ______________  _____
  ___  __/___  /_ ___(_)_____ _______ _______
  __  /_  __  __ \__  / _  _ \__  __ `/_  __ \
  _  __/  _  /_/ /_  /  /  __/_  /_/ / / /_/ /
  /_/     /_.___/ /_/   \___/ _\__, /  \____/
                              /____/

*/

#define LGFX_USE_V1

#include <Arduino.h>
#include "main.h"
#include <lvgl.h>
#include <LovyanGFX.hpp>

// SD CARD - SPI
#define SDSPI_HOST_ID SPI3_HOST
#define SD_MISO       GPIO_NUM_38 
#define SD_MOSI       GPIO_NUM_40
#define SD_SCLK       GPIO_NUM_39
#define SD_CS         GPIO_NUM_41


#include <ESP32Time.h>
#include <Timber.h>

//#ifdef USE_UI
#include "ui/ui.h"
//#endif


#include <WIFI.h>
#include <WiFiClientSecure.h>
#include <Preferences.h>
#include <FS.h>
#include <LittleFS.h>
#include <SPIFFS.h>               // SPI Flash Syetem Library 
#include <WiFiManager.h>
#include <NTPClient.h>            // pour client NTP
#include <WiFiUdp.h>              // pour client NTP
#include "time.h"                 // ajouté pour Source : https://randomnerdtutorials.com/esp32-date-time-ntp-client-server-arduino/
#include <ArduinoJson.h>          // Ajouté pour API EDF 
#include <HTTPClient.h>           // Ajouté pour Weather, utile pour les résultats API
#include "back/var.h"
#include "back/initWIFI.h"
#include "back/horloge.h"           // structure pour l'horloge Accès au serveur de temps et affichage
#include "back/accesRTE.h"           // Fonctions d'accès aux données RTE
#include "back/moto.h"
#include "back/meteo.h"

// On va déclarer LGFX plus haut dans vt
#ifdef PLUS
#define SCR 30
class LGFX : public lgfx::LGFX_Device
{

  lgfx::Panel_ST7796 _panel_instance;
  lgfx::Bus_Parallel8 _bus_instance;
  lgfx::Light_PWM _light_instance;
  lgfx::Touch_FT5x06 _touch_instance;

public:
  LGFX(void)
  {
    {
      auto cfg = _bus_instance.config();

      cfg.port = 0; //sbi mis en commentaire
      cfg.freq_write = 40000000;
      cfg.pin_wr = 47; // pin number connecting WR
      cfg.pin_rd = -1; // pin number connecting RD
      cfg.pin_rs = 0;  // Pin number connecting RS(D/C)
      cfg.pin_d0 = 9;  // pin number connecting D0
      cfg.pin_d1 = 46; // pin number connecting D1
      cfg.pin_d2 = 3;  // pin number connecting D2
      cfg.pin_d3 = 8;  // pin number connecting D3
      cfg.pin_d4 = 18; // pin number connecting D4
      cfg.pin_d5 = 17; // pin number connecting D5
      cfg.pin_d6 = 16; // pin number connecting D6
      cfg.pin_d7 = 15; // pin number connecting D7

      _bus_instance.config(cfg);              // Apply the settings to the bus.
      _panel_instance.setBus(&_bus_instance); // Sets the bus to the panel.
    }

    {                                      // Set display panel control.
      auto cfg = _panel_instance.config(); // Get the structure for display panel settings.

      cfg.pin_cs = -1;   // Pin number to which CS is connected (-1 = disable)
      cfg.pin_rst = 4;   // pin number where RST is connected (-1 = disable)
      cfg.pin_busy = -1; // pin number to which BUSY is connected (-1 = disable)

      // * The following setting values ​​are set to general default values ​​for each panel, and the pin number (-1 = disable) to which BUSY is connected, so please try commenting out any unknown items.

      cfg.memory_width = 320;  // Maximum width supported by driver IC
      cfg.memory_height = 480; // Maximum height supported by driver IC
      cfg.panel_width = 320;   // actual displayable width
      cfg.panel_height = 480;  // actual displayable height
      cfg.offset_x = 0;        // Panel offset in X direction
      cfg.offset_y = 0;        // Panel offset in Y direction
#ifdef PORTRAIT
      cfg.offset_rotation = 2;
#else
      cfg.offset_rotation = 3;
#endif
      cfg.dummy_read_pixel = 8;
      cfg.dummy_read_bits = 1;
      cfg.readable = false;
      cfg.invert = true;
      cfg.rgb_order = false;
      cfg.dlen_16bit = false;
      cfg.bus_shared = false;    // sbi false à la place de true

      _panel_instance.config(cfg);
    }

    {                                      // Set backlight control. (delete if not necessary)
      auto cfg = _light_instance.config(); // Get the structure for backlight configuration.

      cfg.pin_bl = 45;     // pin number to which the backlight is connected 45 modifié en 23
      cfg.invert = false;  // true to invert backlight brightness
      cfg.freq = 44100;    // 44100 -> backlight PWM frequency
      cfg.pwm_channel = 7; // PWM channel number to use SBI 7 à la place de 0)

      _light_instance.config(cfg);
      _panel_instance.setLight(&_light_instance); // Sets the backlight to the panel.
    }

    { // Configure settings for touch screen control. (delete if not necessary)
      auto cfg = _touch_instance.config();

      cfg.x_min = 0;   // Minimum X value (raw value) obtained from the touchscreen
      cfg.x_max = 319; // Maximum X value (raw value) obtained from the touchscreen
      cfg.y_min = 0;   // Minimum Y value obtained from touchscreen (raw value)
      cfg.y_max = 479; // Maximum Y value (raw value) obtained from the touchscreen
      cfg.pin_int = 7; // pin number to which INT is connected
      cfg.bus_shared = false;
      cfg.offset_rotation = 0;

      // For I2C connection
      cfg.i2c_port = 0;    // Select I2C to use (0 or 1) SBI de 0 à 1
      cfg.i2c_addr = 0x38; // I2C device address number
      cfg.pin_sda = 6;     // pin number where SDA is connected
      cfg.pin_scl = 5;     // pin number to which SCL is connected
      cfg.freq = 400000;   // set I2C clock

      _touch_instance.config(cfg);
      _panel_instance.setTouch(&_touch_instance); // Set the touchscreen to the panel.
    }

    setPanel(&_panel_instance); // Sets the panel to use.
  }
};

#else
#define SCR 8
class LGFX : public lgfx::LGFX_Device
{

  lgfx::Panel_ST7796 _panel_instance;

  lgfx::Bus_SPI _bus_instance;

  lgfx::Light_PWM _light_instance;

  lgfx::Touch_FT5x06 _touch_instance;

public:
  LGFX(void)
  {
    {
      auto cfg = _bus_instance.config(); // Get the structure for bus configuration.

      // SPI bus settings
      cfg.spi_host = VSPI_HOST; // Select the SPI to use ESP32-S2,C3 : SPI2_HOST or SPI3_HOST / ESP32 : VSPI_HOST or HSPI_HOST
      // * With the ESP-IDF version upgrade, VSPI_HOST and HSPI_HOST descriptions are deprecated, so if an error occurs, use SPI2_HOST and SPI3_HOST instead.
      cfg.spi_mode = 3;                  // Set SPI communication mode (0 ~ 3)
      cfg.freq_write = 40000000;         // SPI clock when sending (up to 80MHz, rounded to 80MHz divided by an integer)
      cfg.freq_read = 6000000;           // SPI clock when receiving
      cfg.spi_3wire = false;             // set to true if receiving on MOSI pin
      cfg.use_lock = true;               // set to true to use transaction lock
      cfg.dma_channel = SPI_DMA_CH_AUTO; // Set the DMA channel to use (0=not use DMA / 1=1ch / 2=ch / SPI_DMA_CH_AUTO=auto setting)
      // * With the ESP-IDF version upgrade, SPI_DMA_CH_AUTO (automatic setting) is recommended for the DMA channel. Specifying 1ch and 2ch is deprecated.
      cfg.pin_sclk = 14; // set SPI SCLK pin number
      cfg.pin_mosi = 13; // Set MOSI pin number for SPI
      cfg.pin_miso = -1; // set SPI MISO pin number (-1 = disable)
      cfg.pin_dc = 21;   // Set SPI D/C pin number (-1 = disable)

      _bus_instance.config(cfg);              // Apply the settings to the bus.
      _panel_instance.setBus(&_bus_instance); // Sets the bus to the panel.
    }

    {                                      // Set display panel control.
      auto cfg = _panel_instance.config(); // Get the structure for display panel settings.

      cfg.pin_cs = 15;   // Pin number to which CS is connected (-1 = disable)
      cfg.pin_rst = 22;  // pin number where RST is connected (-1 = disable)
      cfg.pin_busy = -1; // pin number to which BUSY is connected (-1 = disable)

      // * The following setting values ​​are set to general default values ​​for each panel, and the pin number (-1 = disable) to which BUSY is connected, so please try commenting out any unknown items.

      cfg.memory_width = 320;  // Maximum width supported by driver IC
      cfg.memory_height = 480; // Maximum height supported by driver IC
      cfg.panel_width = 320;   // actual displayable width
      cfg.panel_height = 480;  // actual displayable height
      cfg.offset_x = 0;        // Panel offset in X direction
      cfg.offset_y = 0;        // Panel offset in Y direction
#ifdef PORTRAIT
      cfg.offset_rotation = 0;
#else
      cfg.offset_rotation = 1;
#endif
      cfg.dummy_read_pixel = 8;
      cfg.dummy_read_bits = 1;
      cfg.readable = false;
      cfg.invert = false;
      cfg.rgb_order = false;
      cfg.dlen_16bit = false;
      cfg.bus_shared = false;

      _panel_instance.config(cfg);
    }

    {                                      // Set backlight control. (delete if not necessary)
      auto cfg = _light_instance.config(); // Get the structure for backlight configuration.

      cfg.pin_bl = 23;     // pin number to which the backlight is connected
      cfg.invert = false;  // true to invert backlight brightness
      cfg.freq = 44100;    // backlight PWM frequency
      cfg.pwm_channel = 1; // PWM channel number to use

      _light_instance.config(cfg);
      _panel_instance.setLight(&_light_instance); // Sets the backlight to the panel.
    }

    { // Configure settings for touch screen control. (delete if not necessary)
      auto cfg = _touch_instance.config();

      cfg.x_min = 0;    // Minimum X value (raw value) obtained from the touchscreen
      cfg.x_max = 319;  // Maximum X value (raw value) obtained from the touchscreen
      cfg.y_min = 0;    // Minimum Y value obtained from touchscreen (raw value)
      cfg.y_max = 479;  // Maximum Y value (raw value) obtained from the touchscreen
      cfg.pin_int = 39; // pin number to which INT is connected
      cfg.bus_shared = false;
      cfg.offset_rotation = 0;

      // For I2C connection
      cfg.i2c_port = 1;    // Select I2C to use (0 or 1)
      cfg.i2c_addr = 0x38; // I2C device address number
      cfg.pin_sda = 18;    // pin number where SDA is connected
      cfg.pin_scl = 19;    // pin number to which SCL is connected
      cfg.freq = 400000;   // set I2C clock

      _touch_instance.config(cfg);
      _panel_instance.setTouch(&_touch_instance); // Set the touchscreen to the panel.
    }

    setPanel(&_panel_instance); // Sets the panel to use.
  }
};

#endif

// Create an instance of the prepared class.
LGFX tft;

static lv_disp_draw_buf_t draw_buf;
static lv_disp_drv_t disp_drv;

static lv_color_t disp_draw_buf[screenWidth * SCR];
static lv_color_t disp_draw_buf2[screenWidth * SCR];

/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
  if (tft.getStartCount() == 0)
  {
    tft.endWrite();
  }

  tft.pushImageDMA(area->x1, area->y1, area->x2 - area->x1 + 1, area->y2 - area->y1 + 1, (lgfx::swap565_t *)&color_p->full);

  lv_disp_flush_ready(disp); /* tell lvgl that flushing is done */
}

/*Read the touchpad*/
void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{
  uint16_t touchX, touchY;

  bool touched = tft.getTouch(&touchX, &touchY);

  if (!touched)
  {
    data->state = LV_INDEV_STATE_REL;
  }
  else
  {
    data->state = LV_INDEV_STATE_PR;

    /*Set the coordinates*/
    data->point.x = touchX;
    data->point.y = touchY;
  }
}

void logCallback(Level level, unsigned long time, String message)
{
  Serial.print(message);

  switch (level)
  {
  case ERROR:
    // maybe save only errors to local storage
    break;
  }
}

// Déclaration CB IHM LVGL
static void luminosite_event_cb(lv_event_t * e)
{
    lv_obj_t * Luminosite = lv_event_get_target(e);
    char buf[8];
    lv_snprintf(buf, sizeof(buf), "%d%%", (int)lv_slider_get_value(ui_Luminosite));
    lv_label_set_text(ui_LabelLuminosite, buf);
    tft.setBrightness((int) lv_slider_get_value(ui_Luminosite));
   
}

static void enregistrer_event_cb(lv_event_t * e) //ui_event_button_down6_buttondown
{
    Serial.println("Enregistrer la conf depuis appel main");    
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * btn = lv_event_get_target(e);
    if(event_code == LV_EVENT_PRESSED) {
        static uint8_t cnt = 0;
        cnt++;
        //saveConfigFile();
        Serial.println("Enregistrer via Event Pressed  la conf");
        /*Get the first child of the button which is the label and change its text*/
        lv_obj_t * label = lv_obj_get_child(ui_bpenregistrer, 0);
        lv_label_set_text_fmt(label, "Enreg: %d", cnt);
    }
   
}


// exemple arduino pour Pour implementation SD : https://github.com/espressif/arduino-esp32/blob/master/libraries/SD/examples/SD_Test/SD_Test.ino


#define FORMAT_LITTLEFS_IF_FAILED true

void readFile(fs::FS &fs, const char *path) {
  Serial.printf("Reading file: %s\r\n", path);

  File file = fs.open(path);
  if (!file || file.isDirectory()) {
    Serial.println("- failed to open file for reading");
    return;
  }

  Serial.println("- read from file:");
  while (file.available()) {
    Serial.write(file.read());
  }
  file.close();
}

void writeFile(fs::FS &fs, const char *path, const char *message) {
  Serial.printf("Writing file: %s\r\n", path);

  File file = fs.open(path, FILE_WRITE);
  if (!file) {
    Serial.println("- failed to open file for writing");
    return;
  }
  if (file.print(message)) {
    Serial.println("- file written");
   
  } else {
    Serial.println("- write failed");
  }
  file.close();
}

void appendFile(fs::FS &fs, const char *path, const char *message) {
  Serial.printf("Appending to file: %s\r\n", path);

  File file = fs.open(path, FILE_APPEND);
  if (!file) {
    Serial.println("- failed to open file for appending");
    return;
  }
  if (file.print(message)) {
    Serial.println("- message appended");
  } else {
    Serial.println("- append failed");
  }
  file.close();
}

void startLittleFS() {                     
  // https://github.com/espressif/arduino-esp32/blob/master/libraries/LittleFS/examples/LITTLEFS_test/LITTLEFS_test.ino#L16                                                                                  // Start the LittleFS and list all contents
    //LittleFS.begin();
    if (!LittleFS.begin(FORMAT_LITTLEFS_IF_FAILED)) {
      Serial.println("LittleFS Mount Failed");
      return;
    }
    Serial.println("LittleFS started. Contents:");
    writeFile(LittleFS, "/config.json", "Hello worl \n and good luck \n");
    readFile(LittleFS, "/config.json");
    appendFile(LittleFS, "/config.json", "\n and asta la vista !\r\n");
    readFile(LittleFS, "/config.json");
}


void setup()
{
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  Serial.println();
  // while(!Serial); // Reste en attente d'une connexion
  Serial.print("Serial OK ");
  bool error;
  Timber.setLogCallback(logCallback);

  tft.init();
  tft.initDMA();
  tft.startWrite();
  int screen_brightness = 50;
  tft.setBrightness(screen_brightness);

  lv_init();

  // SBI Param backlight
  /*
  #define BACKLIGHT_CHANNEL 0
  #define BACKLIGHT_FREQUENCY 12000
  #define BACKLIGHT_RESOLUTION_BITS 8
  #define TFT_LITE 33
  pinMode(TFT_LITE, OUTPUT);
  ledcSetup(BACKLIGHT_CHANNEL, BACKLIGHT_FREQUENCY, BACKLIGHT_RESOLUTION_BITS);
  float percent = 0.75;
  int dutyCycle = (int) round(255 * percent);
  ledcWrite(BACKLIGHT_CHANNEL, dutyCycle);
  */

  Timber.i("Width %d\tHeight %d", screenWidth, screenHeight);

  if (!disp_draw_buf)
  {
    Timber.e("LVGL disp_draw_buf allocate failed!");
  }
  else
  {


    lv_disp_draw_buf_init(&draw_buf, disp_draw_buf, disp_draw_buf2, screenWidth * SCR);

    /* Initialize the display */
    lv_disp_drv_init(&disp_drv);
    /* Change the following line to your display resolution */
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    /* Initialize the input device driver */
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read;
    lv_indev_drv_register(&indev_drv);

#ifdef USE_UI
    ui_init();
#else
    lv_obj_t *label1 = lv_label_create(lv_scr_act());
    lv_obj_align(label1, LV_ALIGN_TOP_MID, 0, 100);
    lv_label_set_long_mode(label1, LV_LABEL_LONG_WRAP);
    lv_obj_set_width(label1, screenWidth - 30);
    lv_label_set_text(label1, "Hello there! You have not included UI files, add you UI files and "
                              "uncomment this line\n'//#define USE_UI' in include/main.h\n"
                              "You should be able to move the slider below");

    /*Create a slider below the label*/
    lv_obj_t *slider1 = lv_slider_create(lv_scr_act());
    lv_obj_set_width(slider1, screenWidth - 40);
    lv_obj_align_to(slider1, label1, LV_ALIGN_OUT_BOTTOM_MID, 0, 50);
#endif

    Timber.i("Setup done");
  }

  lv_obj_add_event_cb(ui_Luminosite, luminosite_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
  //scanWifi();
  startLittleFS();
//  initWIFIManager(); // ajout pour WIFI Manager
  initWIFI();   // oubien on part sur la connection directe avec SSID en dur
  initWIFIManager(); // ajout pour WIFI Manager
  // ************ fin init WIFI ****************
  initTimeNTP(); // Démarre la lecture de l'heure  ntp
  printLocalTime(); // Récupère NTP et affiche l'heure sur l'écran
  //setupMontreRonde();
  setSynchroDate();
  getLocation(); // retrouve la localisation via google et le WIFI et stocke ds var globales
  getRTEData();   // lecture RTE couleurs du jour et lendemain
  getMOTOData();  // Récup des données moto dispo
  getMETEOData(); // Récupère la météo locale
  tft.setBrightness(screen_brightness);    // Ca fonctionne pas
  //callWIFIManager();
  //initSDCard();
  


}

void loop()
{
  wm.process(); // WifiManager

  lv_timer_handler(); /* let the GUI do its work */
  // reprise du code arduino
  static uint32_t p_milli = 0;
  uint32_t milli = lgfx::millis() % 1000; //

  if (p_milli < milli) count +=        (milli - p_milli);
  else                 count += 1000 + (milli - p_milli); // + 1s
  p_milli = milli;
  
  int32_t tmp = (count % 1000) >> 3;
  // count += 60000;  // Pour accélérer pour le debug
  if ( count > oneday ) {
     //printf("JourSuivant"); printf("%i",count);
     count -= oneday; 
     }

  mototimerCurrent= lgfx::millis(); // ttes les 10'
  if ( (mototimerCurrent-mototimerPrevious) > 1000 * 60 * 10) { //15' = 1000ms * 60 * 15 et 30' 1000*60*30
      mototimerPrevious = mototimerCurrent;
      Serial.println(&timeinfo, "GetMOTOData : %A, %B %d %Y %H:%M:%S");
      getMOTOData();
    }

  meteotimerCurrent= lgfx::millis(); // ttes les 15'
  if ( (meteotimerCurrent-meteotimerPrevious) > 1000 * 60 * 15) { //15' = 1000ms * 60 * 15 et 30' 1000*60*30
      meteotimerPrevious = meteotimerCurrent;
      Serial.println(&timeinfo, "GetMETEOData : %A, %B %d %Y %H:%M:%S");
      getMETEOData();
    }

uint32_t meteotimerCurrent=0; // Pour inclure un évènement dans la boucle timer 
uint32_t meteotimerPrevious=0;

  heuretimerCurrent= lgfx::millis();
  if ( (heuretimerCurrent-heuretimerPrevious) > 1000) { //1" = 1000ms * 60 * 15 et 30' 1000*60*30
      heuretimerPrevious = heuretimerCurrent; 
      count=setSynchroHour(); // Resynchro avec l'heure NTP
      // surveiller le Heap
      //Serial.printf("\nStack:%d,Heap:%lu\n", uxTaskGetStackHighWaterMark(NULL), (unsigned long)ESP.getFreeHeap());
      // tft.setBrightness(20);    // Ca fonctionne pas

    }

  RTEtimerCurrent= lgfx::millis();
  if ( (RTEtimerCurrent-RTEtimerPrevious) > 1000 * 60 * 15) { //15' = 1000ms * 60 * 15 et 30' 1000*60*30
      RTEtimerPrevious = RTEtimerCurrent; 
      Serial.println(&timeinfo, "GetRTE : %A, %B %d %Y %H:%M:%S");
      getRTEData(); // mise à jour
    }
  delay(5);
}

