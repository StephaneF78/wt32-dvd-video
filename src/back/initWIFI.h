#define ESP_DRD_USE_SPIFFS true
#define JSON_CONFIG_FILE "/test_config.json"  // JSON configuration file

// Gestion du WIFI
// Déclaration des constantes
const char *ssid = "Bbox-3FA5475C";
const char *password = "A6D169EE453122AA5D7A4E7D523CEF";
 
// Pour le WIFI Manager
bool shouldSaveConfig = false;    // Flag for saving data wifimanager
char testString[50] = "test value";     // Variables to hold data from custom textboxes
int testNumber = 1234;
WiFiManager wm;                         // Define WiFiManager Object
// Fin variables pour wifiManager

void initWIFI(){
 // **************************** Debut Setup WIFI **********************************************
  WiFi.begin(ssid, password);
  // lcd.setCursor(15,5);
  // à mapper lvgl lcd.printf("Wifi");
  while (WiFi.status() != WL_CONNECTED) {
   // à mapper LVGL  lcd.print(".");
    delay(1000);
  }
  String ip_esp32 = WiFi.localIP().toString();  
  //lcd.setCursor(100,5);
  // à mapper lvgl lcd.printf(" : %s", ip_esp32);
 // **************************** FIN Setup WIFI *********************************************
}




// ************************ Sauvegarde la config 
void saveConfigFile()
// Save Config in JSON format
{
  Serial.println(F("Saving configuration..."));
  
  // Create a JSON document
  StaticJsonDocument<200> json;
  json["testString"] = testString;
  json["testNumber"] = testNumber;
 
  // Open config file
  File configFile = SPIFFS.open(JSON_CONFIG_FILE, "w");
  if (!configFile)
  {
    // Error, file did not open
    Serial.println("failed to open config file for writing");
  }
 
  // Serialize JSON data to write to file
  serializeJsonPretty(json, Serial);
  if (serializeJson(json, configFile) == 0)
  {
    // Error writing file
    Serial.println(F("Failed to write to file"));
  }
  // Close file
  configFile.close();
}
 

// ********************  Chargement de la config sauvée 
bool loadConfigFile()
// Load existing configuration file
{
  // Uncomment if we need to format filesystem
  // SPIFFS.format();
 
  // Read configuration from FS json
  Serial.println("Mounting File System...");
 
  // May need to make it begin(true) first time you are using SPIFFS
  if (SPIFFS.begin(false) || SPIFFS.begin(true))
  {
    Serial.println("mounted file system");
    if (SPIFFS.exists(JSON_CONFIG_FILE))
    {
      // The file exists, reading and loading
      Serial.println("reading config file");
      File configFile = SPIFFS.open(JSON_CONFIG_FILE, "r");
      if (configFile)
      {
        Serial.println("Opened configuration file");
        StaticJsonDocument<500> json;
        DeserializationError error = deserializeJson(json, configFile);
        serializeJsonPretty(json, Serial);
        if (!error)
        {
          Serial.println("Parsing JSON");
 
          strcpy(testString, json["testString"]);
          testNumber = json["testNumber"].as<int>();
 
          return true;
        }
        else
        {
          // Error loading JSON data
          Serial.println("Failed to load json config");
        }
      }
    }
  }
  else
  {
    // Error mounting file system
    Serial.println("Failed to mount FS");
  }
 
  return false;
}
 
 
void saveConfigCallback()
// Callback notifying us of the need to save configuration
{
  Serial.println("Should save config");
  shouldSaveConfig = true;
}
 
void configModeCallback(WiFiManager *myWiFiManager)
// Called when config mode launched
{
  Serial.println("Entered Configuration Mode");
 
  Serial.print("Config SSID: ");
  Serial.println(myWiFiManager->getConfigPortalSSID());
 
  Serial.print("Config IP Address: ");
  Serial.println(WiFi.softAPIP());
}
 
void callWIFIManager() // tiré de l'exemple https://dronebotworkshop.com/wifimanager/
{
  // Change to true when testing to force configuration every time we run
  bool forceConfig = false;
 
  bool spiffsSetup = loadConfigFile();
  if (!spiffsSetup)
  {
    Serial.println(F("Forcing config mode as there is no saved config"));
    forceConfig = true;
  }
 
  // Explicitly set WiFi mode
  WiFi.mode(WIFI_STA);
  
  
  wm.resetSettings();                               // Reset settings (only for development)
  wm.setSaveConfigCallback(saveConfigCallback);     // Set config save notify callback
  wm.setAPCallback(configModeCallback);             // Set callback that gets called when connecting to previous WiFi fails, and enters Access Point mode
 
  // ********  Custom elements   *******
 
  // Text box (String) - 50 characters maximum
  WiFiManagerParameter custom_text_box("key_text", "Enter your string here", testString, 50);
  
  // Need to convert numerical input to string to display the default value.
  char convertedValue[6];
  sprintf(convertedValue, "%d", testNumber); 
  
  // Text box (Number) - 7 characters maximum
  WiFiManagerParameter custom_text_box_num("key_num", "Enter your number here", convertedValue, 7); 
 
  // Add all defined parameters
  wm.addParameter(&custom_text_box);
  wm.addParameter(&custom_text_box_num);
 
  if (forceConfig)
    // Run if we need a configuration
  {
    if (!wm.startConfigPortal("NEWTEST_AP", "password"))
    {
      Serial.println("failed to connect and hit timeout");
      delay(3000);
      //reset and try again, or maybe put it to deep sleep
      ESP.restart();
      delay(5000);
    }
  }
  else
  {
    if (!wm.autoConnect("NEWTEST_AP", "password"))
    {
      Serial.println("failed to connect and hit timeout");
      delay(3000);
      // if we still have not connected restart and try all over again
      ESP.restart();
      delay(5000);
    }
  }
 
  // If we get here, we are connected to the WiFi
 
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
 
  // Lets deal with the user config values
 
  // Copy the string value
  strncpy(testString, custom_text_box.getValue(), sizeof(testString));
  Serial.print("testString: ");
  Serial.println(testString);
 
  //Convert the number value
  testNumber = atoi(custom_text_box_num.getValue());
  Serial.print("testNumber: ");
  Serial.println(testNumber);
 
 
  // Save the custom parameters to FS
  if (shouldSaveConfig)
  {
    saveConfigFile();
  }
}
 