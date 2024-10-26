#define ESP_DRD_USE_SPIFFS true
#define JSON_CONFIG_FILE "/config.json"  // JSON configuration file

// Gestion du WIFI
// Déclaration des constantes
const char *ssid = "Bbox-3FA5475C";
const char *password = "A6D169EE453122AA5D7A4E7D523CEF"; // F

//const char *ssid1 = "Freebox-146FB3";
//const char *password1 = "protis6#-fodito-quomque-ericum";

// Constantes pour Google
const char* root_ca_googleAPI =\
                          "-----BEGIN CERTIFICATE-----\n" \
                          "MIIFVzCCAz+gAwIBAgINAgPlk28xsBNJiGuiFzANBgkqhkiG9w0BAQwFADBHMQsw\n" \
                          "CQYDVQQGEwJVUzEiMCAGA1UEChMZR29vZ2xlIFRydXN0IFNlcnZpY2VzIExMQzEU\n" \
                          "MBIGA1UEAxMLR1RTIFJvb3QgUjEwHhcNMTYwNjIyMDAwMDAwWhcNMzYwNjIyMDAw\n" \
                          "MDAwWjBHMQswCQYDVQQGEwJVUzEiMCAGA1UEChMZR29vZ2xlIFRydXN0IFNlcnZp\n" \
                          "Y2VzIExMQzEUMBIGA1UEAxMLR1RTIFJvb3QgUjEwggIiMA0GCSqGSIb3DQEBAQUA\n" \
                          "A4ICDwAwggIKAoICAQC2EQKLHuOhd5s73L+UPreVp0A8of2C+X0yBoJx9vaMf/vo\n" \
                          "27xqLpeXo4xL+Sv2sfnOhB2x+cWX3u+58qPpvBKJXqeqUqv4IyfLpLGcY9vXmX7w\n" \
                          "Cl7raKb0xlpHDU0QM+NOsROjyBhsS+z8CZDfnWQpJSMHobTSPS5g4M/SCYe7zUjw\n" \
                          "TcLCeoiKu7rPWRnWr4+wB7CeMfGCwcDfLqZtbBkOtdh+JhpFAz2weaSUKK0Pfybl\n" \
                          "qAj+lug8aJRT7oM6iCsVlgmy4HqMLnXWnOunVmSPlk9orj2XwoSPwLxAwAtcvfaH\n" \
                          "szVsrBhQf4TgTM2S0yDpM7xSma8ytSmzJSq0SPly4cpk9+aCEI3oncKKiPo4Zor8\n" \
                          "Y/kB+Xj9e1x3+naH+uzfsQ55lVe0vSbv1gHR6xYKu44LtcXFilWr06zqkUspzBmk\n" \
                          "MiVOKvFlRNACzqrOSbTqn3yDsEB750Orp2yjj32JgfpMpf/VjsPOS+C12LOORc92\n" \
                          "wO1AK/1TD7Cn1TsNsYqiA94xrcx36m97PtbfkSIS5r762DL8EGMUUXLeXdYWk70p\n" \
                          "aDPvOmbsB4om3xPXV2V4J95eSRQAogB/mqghtqmxlbCluQ0WEdrHbEg8QOB+DVrN\n" \
                          "VjzRlwW5y0vtOUucxD/SVRNuJLDWcfr0wbrM7Rv1/oFB2ACYPTrIrnqYNxgFlQID\n" \
                          "AQABo0IwQDAOBgNVHQ8BAf8EBAMCAYYwDwYDVR0TAQH/BAUwAwEB/zAdBgNVHQ4E\n" \
                          "FgQU5K8rJnEaK0gnhS9SZizv8IkTcT4wDQYJKoZIhvcNAQEMBQADggIBAJ+qQibb\n" \
                          "C5u+/x6Wki4+omVKapi6Ist9wTrYggoGxval3sBOh2Z5ofmmWJyq+bXmYOfg6LEe\n" \
                          "QkEzCzc9zolwFcq1JKjPa7XSQCGYzyI0zzvFIoTgxQ6KfF2I5DUkzps+GlQebtuy\n" \
                          "h6f88/qBVRRiClmpIgUxPoLW7ttXNLwzldMXG+gnoot7TiYaelpkttGsN/H9oPM4\n" \
                          "7HLwEXWdyzRSjeZ2axfG34arJ45JK3VmgRAhpuo+9K4l/3wV3s6MJT/KYnAK9y8J\n" \
                          "ZgfIPxz88NtFMN9iiMG1D53Dn0reWVlHxYciNuaCp+0KueIHoI17eko8cdLiA6Ef\n" \
                          "MgfdG+RCzgwARWGAtQsgWSl4vflVy2PFPEz0tv/bal8xa5meLMFrUKTX5hgUvYU/\n" \
                          "Z6tGn6D/Qqc6f1zLXbBwHSs09dR2CQzreExZBfMzQsNhFRAbd03OIozUhfJFfbdT\n" \
                          "6u9AWpQKXCBfTkBdYiJ23//OYb2MI3jSNwLgjt7RETeJ9r/tSQdirpLsQBqvFAnZ\n" \
                          "0E6yove+7u7Y/9waLd64NnHi/Hm3lCXRSHNboTXns5lndcEZOitHTtNCjv0xyBZm\n" \
                          "2tIMPNuzjsmhDYAPexZ3FL//2wmUspO8IFgV6dtxQ/PeEMMA3KgqlbbC1j+Qa3bb\n" \
                          "bP6MvPJwNQzcmRk13NfIRmPVNnGuV/u3gm3c\n" \
                          "-----END CERTIFICATE-----\n";

 
// Pour le WIFI Manager
bool shouldSaveConfig = true;    // Flag for saving data wifimanager
char testString[50] = "test value";     // Variables to hold data from custom textboxes
int testNumber = 1234;


// Pour gestion paramétré du WIFI
Preferences preferences;
const char * wifiSSID = "Montre-meteo-tempo";

constexpr size_t tailleMaxTexte = 50;
const char* parametresDesc[] = {"longueur", "largeur", "hauteur"};
const size_t nbParams = sizeof parametresDesc / sizeof * parametresDesc;
char parametresTxt[nbParams][tailleMaxTexte] = {"10", "20", "30"};
long parametres[nbParams];

WiFiManager wm;                         // Define WiFiManager Object
WiFiManagerParameter wmParameters[nbParams];
// Fin variables pour wifiManager

// ----------------------------------------------------------------
// WiFi Manager et Préférences
// ----------------------------------------------------------------

void printConfig() {
  Serial.println("\n---------------\nConfiguration Enregistrée:");
  for (size_t i = 0; i < nbParams; i++) {
    Serial.print(parametresDesc[i]); Serial.print(" -> \""); Serial.print(parametresTxt[i]); Serial.print("\" -> "); Serial.println(parametres[i]);
  }
  Serial.println();
}

void callbackParametres () {
  if (preferences.begin("parametres", false)) {
    for (size_t i = 0; i < nbParams; i++) {
      const char * vTxt = wmParameters[i].getValue();
      char * ptr = nullptr;
      long v = strtol(vTxt, &ptr, 10); // base 10
      if (ptr && *ptr == '\0') {
        // le parsing s'est bien passé on définit la valeur textuelle et numérique
        parametres[i] = v;
        snprintf(parametresTxt[i], tailleMaxTexte, "%s", vTxt);
        preferences.putString(parametresDesc[i], parametresTxt[i]); // on sauve pour la prochaine fois
      } else {
        // ça s'est mal passsé on ne modifie pas
        Serial.print("erreur format pour ");
        Serial.println(parametresTxt[i]);
      }
    }
    preferences.end();
  } else {
    Serial.println("Error writing Prefernces");
  }
  printConfig();
}

// ----------------------------------------------------------------

void initWIFIManager(){
    // Documentation wifimanager littlefs : https://github.com/tzapu/WiFiManager/issues/1437
    // avec SPFSS https://github.com/zhouhan0126/WIFIMANAGER-ESP32/blob/master/examples/OnDemandConfigPortal/OnDemandConfigPortal.ino


   // on lit les valeurs de configuration
  if (preferences.begin("parametres", false)) {

    for (size_t i = 0; i < nbParams; i++) {
      char * ptr = nullptr;
      char vTxt[tailleMaxTexte];
      snprintf(vTxt, tailleMaxTexte, "%s", preferences.getString(parametresDesc[i], parametresTxt[i]).c_str());
      long v = strtol(vTxt, &ptr, 10); // base 10

      if (ptr && *ptr == '\0') {
        // le parsing s'est bien passé on définit la valeur textuelle et numérique
        parametres[i] = v;
        snprintf(parametresTxt[i], tailleMaxTexte, "%s", vTxt);
      } else {
        // ça s'est mal passsé
        Serial.println("erreur parsing");
        parametres[i] = atoi(parametresTxt[i]); // on prend la valeur par défaut
        preferences.putString(parametresDesc[i], parametresTxt[i]); // on sauve pour la prochaine fois
      }
    }
    preferences.end();
  } else {
    Serial.println("Erreur Preferences");
  }

  // gestion portail config
  WiFi.mode(WIFI_STA); //  esp par défaut sur STA+AP (ou mettre WIFI_AP)

  wm.setDebugOutput(false);

  for (size_t i = 0; i < nbParams; i++) { // on créee les champs spécifiques
    new (&(wmParameters[i])) WiFiManagerParameter(parametresDesc[i], parametresDesc[i], parametresTxt[i], tailleMaxTexte);
    wm.addParameter(&(wmParameters[i]));
  }
  wm.setConfigPortalBlocking(false);
  wm.setSaveParamsCallback(callbackParametres);

  std::vector<const char *> menu = {"param", "sep", "restart", "exit"};
  // wm.setMenu(menu);
  wm.startConfigPortal(wifiSSID);

  wm.setTimeout(50);
  if(!wm.autoConnect("AutoConnectAP")) {
    Serial.println("failed to connect and hit timeout");
    delay(3000);
    //reset and try again, or maybe put it to deep sleep
    ESP.restart();
    delay(5000);
  } 
  Serial.print("\nSystème prêt. Accédez au réseau Wi-Fi "); Serial.println(wifiSSID);
  printConfig();
}


void initWIFI(){
 // **************************** Debut Setup WIFI **********************************************
  // 
  //WiFi.mode(WIFI_AUTH_WEP);
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


String get_encryption_type(wifi_auth_mode_t encryptionType) {
    switch (encryptionType) {
        case (WIFI_AUTH_OPEN):
            return "Open";
        case (WIFI_AUTH_WEP):
            return "WEP";
        case (WIFI_AUTH_WPA_PSK):
            return "WPA_PSK";
        case (WIFI_AUTH_WPA2_PSK):
            return "WPA2_PSK";
        case (WIFI_AUTH_WPA_WPA2_PSK):
            return "WPA_WPA2_PSK";
        case (WIFI_AUTH_WPA2_ENTERPRISE):
            return "WPA2_ENTERPRISE";
    }
    return("Rien");
}

void scanWifi() {
  Serial.println("[*] Scanning WiFi network");
  WiFi.mode(WIFI_STA);

  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  String listeSSID;
  Serial.println("[*] Scan done");
  if (n == 0) {
      Serial.println("[-] No WiFi networks found");
      
    } else {
        Serial.println((String)"[+] " + n + " WiFi networks found\n");
        for (int i = 0; i < n; ++i) {
            // Print SSID, RSSI and WiFi Encryption for each network found
            
              Serial.print(i + 1);
              Serial.print(": ");
              Serial.print(WiFi.SSID(i));
              listeSSID += WiFi.SSID(i);
              listeSSID += "\n";
              Serial.print(" (");
              Serial.print(WiFi.RSSI(i));
              Serial.print(" dB) [");
              Serial.print(get_encryption_type(WiFi.encryptionType(i)));
              Serial.println("]");
              delay(10);
          
        }
      }
    //return(true);
    Serial.println(listeSSID);
    lv_dropdown_set_options(ui_ssid, listeSSID.c_str());
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
 
  if(!SPIFFS.begin(true)){
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

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
  bool forceConfig = true;
 
  bool spiffsSetup = loadConfigFile();
  if (!spiffsSetup)
  {
    Serial.println(F("Forcing config mode as there is no saved config"));
    forceConfig = true;
  }
 
  // Explicitly set WiFi mode
  WiFi.mode(WIFI_STA);
  
  
  // wm.resetSettings();                               // Reset settings (only for development)
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


String getLocation() {
  // clé API google : AIzaSyDlvY0t6dF8ik8u-ll_34Qi1Sdg0AV70ZY
  /*
  {
  "location": {
    "lat": 46.1570048,
    "lng": -1.3238272
  },
  "accuracy": 1364.7858494926766
  }
  */
  const char* googleApiKey = "AIzaSyDlvY0t6dF8ik8u-ll_34Qi1Sdg0AV70ZY";

  String googleURI = "https://www.googleapis.com/geolocation/v1/geolocate?key=";
  googleURI += googleApiKey;
  client1->setCACert(root_ca_googleAPI);    // positionne le certificat racine
  Serial.println("*** Meteo *** Avant https1.begin ");
  https1.begin(*client1, googleURI); // prépare l'appel à l'url 


  //HTTPClient http;
  // https1.begin(googleURI);
  https1.addHeader("Content-Type", "application/json");

  String requestBody = "{\"considerIp\": \"true\"}";

  int httpReponseCode = https1.POST(requestBody);
  String reponse = "";

  if (httpReponseCode > 0) {
    reponse = https1.getString();
    Serial.print(" *** GOOGLE location *** Localisation : ");
    Serial.println(httpReponseCode);
    Serial.println(reponse);
    StaticJsonDocument<128> doc;

    DeserializationError error = deserializeJson(doc, reponse);

    if (error) {
      Serial.print(" *** location google *** deserializeJson() failed: ");
      Serial.println(error.c_str());
      return "error";
    }
    location_lat = (double)doc["location"]["lat"]; // 46.1570048
    location_lng = (double)doc["location"]["lng"]; // -1.3238272
    //location_lat = location_lat * 10000000;
    //location_lng = location_lng * 10000000;
    dtostrf(location_lat,2,7,location_latChar);
    dtostrf(location_lng,2,7,location_lngChar);  // dtostrf( [doubleVar] , [sizeBeforePoint] , [sizeAfterPoint] , [WhereToStoreIt] )

    Serial.print(" *** location google *** Lat =");
    Serial.println(location_lat);
    Serial.print(" *** location google *** Long =");
    Serial.println(location_lng);
    Serial.print(" *** location google *** LatChar =");
    Serial.println(location_latChar);
    Serial.print(" *** location google *** LongChar =");
    Serial.println(location_lngChar);
    
  } else {
    Serial.print(" *** GOOGLE *** Erreur dans l'envoi de la requête: ");
    Serial.println(httpReponseCode);
  }
  https1.end();
  client1->stop();
  return reponse;
}


