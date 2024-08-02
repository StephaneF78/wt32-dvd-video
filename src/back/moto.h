// On prend ici le certificat racine du site mongo

const char* root_ca_moto =\
                           "-----BEGIN CERTIFICATE-----\n" \
                          "MIICCTCCAY6gAwIBAgINAgPlwGjvYxqccpBQUjAKBggqhkjOPQQDAzBHMQswCQYD\n" \
                          "VQQGEwJVUzEiMCAGA1UEChMZR29vZ2xlIFRydXN0IFNlcnZpY2VzIExMQzEUMBIG\n" \
                          "A1UEAxMLR1RTIFJvb3QgUjQwHhcNMTYwNjIyMDAwMDAwWhcNMzYwNjIyMDAwMDAw\n" \
                          "WjBHMQswCQYDVQQGEwJVUzEiMCAGA1UEChMZR29vZ2xlIFRydXN0IFNlcnZpY2Vz\n" \
                          "IExMQzEUMBIGA1UEAxMLR1RTIFJvb3QgUjQwdjAQBgcqhkjOPQIBBgUrgQQAIgNi\n" \
                          "AATzdHOnaItgrkO4NcWBMHtLSZ37wWHO5t5GvWvVYRg1rkDdc/eJkTBa6zzuhXyi\n" \
                          "QHY7qca4R9gq55KRanPpsXI5nymfopjTX15YhmUPoYRlBtHci8nHc8iMai/lxKvR\n" \
                          "HYqjQjBAMA4GA1UdDwEB/wQEAwIBhjAPBgNVHRMBAf8EBTADAQH/MB0GA1UdDgQW\n" \
                          "BBSATNbrdP9JNqPV2Py1PsVq8JQdjDAKBggqhkjOPQQDAwNpADBmAjEA6ED/g94D\n" \
                          "9J+uHXqnLrmvT/aDHQ4thQEd0dlq7A/Cr8deVl5c1RxYIigL9zC2L7F8AjEA8GE8\n" \
                          "p/SgguMh1YQdc4acLa/KNJvxn7kjNuK8YAOdgLOaVsjh4rsUecrNIdSUtUlD\n" \
                          "-----END CERTIFICATE-----\n";

/*
                          "-----BEGIN CERTIFICATE-----\n" \
                          "MIIDnzCCA0SgAwIBAgIQUV7GYfw2r5MTnjsLdDPs2DAKBggqhkjOPQQDAjA7MQsw\n" \
                          "CQYDVQQGEwJVUzEeMBwGA1UEChMVR29vZ2xlIFRydXN0IFNlcnZpY2VzMQwwCgYD\n" \
                          "VQQDEwNXRTEwHhcNMjQwNzI3MjI1NzEwWhcNMjQxMDI1MjI1NzA5WjAUMRIwEAYD\n" \
                          "VQQDEwlicm9uby5jb20wWTATBgcqhkjOPQIBBggqhkjOPQMBBwNCAAQeEwrSszyP\n" \
                          "4QirQ4YDxOxis7ZrUotnwhHPpmL/OQ+LutePw9EeqtNBJSSxUqsj54Zu+6Io/i5P\n" \
                          "8W0NugRmdla1o4ICTzCCAkswDgYDVR0PAQH/BAQDAgeAMBMGA1UdJQQMMAoGCCsG\n" \
                          "AQUFBwMBMAwGA1UdEwEB/wQCMAAwHQYDVR0OBBYEFEEqjz9Kez9IDh2w3FNPLiQe\n" \
                          "9nA/MB8GA1UdIwQYMBaAFJB3kjVnxP+ozKnme9mAeXvMk/k4MF4GCCsGAQUFBwEB\n" \
                          "BFIwUDAnBggrBgEFBQcwAYYbaHR0cDovL28ucGtpLmdvb2cvcy93ZTEvVVY0MCUG\n" \
                          "CCsGAQUFBzAChhlodHRwOi8vaS5wa2kuZ29vZy93ZTEuY3J0MCEGA1UdEQQaMBiC\n" \
                          "CWJyb25vLmNvbYILKi5icm9uby5jb20wEwYDVR0gBAwwCjAIBgZngQwBAgEwNgYD\n" \
                          "VR0fBC8wLTAroCmgJ4YlaHR0cDovL2MucGtpLmdvb2cvd2UxLzZsZXh3ZkQ4cGVR\n" \
                          "LmNybDCCAQQGCisGAQQB1nkCBAIEgfUEgfIA8AB3AHb/iD8KtvuVUcJhzPWHujS0\n" \
                          "pM27KdxoQgqf5mdMWjp0AAABkPagesYAAAQDAEgwRgIhAL9O3oTiSizVxChzLFIw\n" \
                          "BV15/kH1a5ZEHzCH8vv7EzZNAiEAiWEFfqLrljWPYriQH/xCkiawVzz5fdTTnh2K\n" \
                          "+lKFOk0AdQDatr9rP7W2Ip+bwrtca+hwkXFsu1GEhTS9pD0wSNf7qwAAAZD2oHrP\n" \
                          "AAAEAwBGMEQCIDo4wYScZ+Ds8ByaXjzM0QNpge0Y/egZhvVzGqzhnXqQAiAnQ3n5\n" \
                          "sUDF44kE+Zda2znTkar8l3Yl9D42hQN7DqiA0zAKBggqhkjOPQQDAgNJADBGAiEA\n" \
                          "4f+T8Ycc2UJzcCdiWC4S3DTxB66s0PrWR89JvKoiJh4CIQDPOkIk9aCjtjRqlMpT\n" \
                          "vf6HHLpmJXSamSJ1tUcigOR4tg==\n" \
                          "-----END CERTIFICATE-----\n";
*/
                          /* Certificat racine

                          "-----BEGIN CERTIFICATE-----\n" \
                          "MIICCTCCAY6gAwIBAgINAgPlwGjvYxqccpBQUjAKBggqhkjOPQQDAzBHMQswCQYD\n" \
                          "VQQGEwJVUzEiMCAGA1UEChMZR29vZ2xlIFRydXN0IFNlcnZpY2VzIExMQzEUMBIG\n" \
                          "A1UEAxMLR1RTIFJvb3QgUjQwHhcNMTYwNjIyMDAwMDAwWhcNMzYwNjIyMDAwMDAw\n" \
                          "WjBHMQswCQYDVQQGEwJVUzEiMCAGA1UEChMZR29vZ2xlIFRydXN0IFNlcnZpY2Vz\n" \
                          "IExMQzEUMBIGA1UEAxMLR1RTIFJvb3QgUjQwdjAQBgcqhkjOPQIBBgUrgQQAIgNi\n" \
                          "AATzdHOnaItgrkO4NcWBMHtLSZ37wWHO5t5GvWvVYRg1rkDdc/eJkTBa6zzuhXyi\n" \
                          "QHY7qca4R9gq55KRanPpsXI5nymfopjTX15YhmUPoYRlBtHci8nHc8iMai/lxKvR\n" \
                          "HYqjQjBAMA4GA1UdDwEB/wQEAwIBhjAPBgNVHRMBAf8EBTADAQH/MB0GA1UdDgQW\n" \
                          "BBSATNbrdP9JNqPV2Py1PsVq8JQdjDAKBggqhkjOPQQDAwNpADBmAjEA6ED/g94D\n" \
                          "9J+uHXqnLrmvT/aDHQ4thQEd0dlq7A/Cr8deVl5c1RxYIigL9zC2L7F8AjEA8GE8\n" \
                          "p/SgguMh1YQdc4acLa/KNJvxn7kjNuK8YAOdgLOaVsjh4rsUecrNIdSUtUlD\n" \
                          "-----END CERTIFICATE-----\n";
*/



/* Information pour la moto 
url : https://mongol.brono.com/mongol/api.php?commandname=get_last_transmit&format=json&user=stephane.biaggini@gmail.com&pass=Sbi@19650913&unitnumber=798776



Certificat racine : 2a575471e31340bc21581cbd2cf13e158463203ece94bcf9d3cc196bf09a5472
Clé public : 871a9194f4eed5b312ff40c84c1d524aed2f778bbff25f138cf81f680a7adc67

Certificat	1b70dbaf49699b07a6f2676d4f00656cdc6d8aa586fb258666aeec3faf84f416
Clé publique 	065b9302e4fe597d367a094127270ff1bb5ffc5a39b4689a88bfab71c9d72670
*/

const char* mongolURI =          "https://mongol.brono.com/mongol/api.php?commandname=get_last_transmit&format=json&user=stephane.biaggini@gmail.com&pass=Sbi@19650913&unitnumber=798776";

bool getMOTOData() {
  //String reponseMoto;
  bool requeteOK = true;
  const char* reponseMoto[2000];
  StaticJsonDocument<2000> doc1;
  
  if (WiFi.status() != WL_CONNECTED) {
    return false;
  }
  // WiFiClientSecure client; // ouvre un client sécurisé
  // HTTPClient http;
  client->setCACert(root_ca_moto);    // positionne le certificat racine
  Serial.println("Avant http.begin ");
  https.begin(*client, mongolURI); // prépare l'appel à l'url 
  // Specify content-type header
  //http.addHeader("accept", "application/json");
  https.addHeader("Content-Type", "application/x-www-form-urlencoded"); //Je sais pas s'il faut cette conf ????????
  // Send HTTP POST request
  //int codeReponseHTTP = http.POST(nullptr, 0);
  int codeReponseHTTP = https.GET();
  if (codeReponseHTTP > 0) {
      // HTTP header has been send and Server response header has been handled
      Serial.printf("[HTTPS] GET... code: %d\n\n", codeReponseHTTP);

    if (codeReponseHTTP == HTTP_CODE_OK || codeReponseHTTP == HTTP_CODE_MOVED_PERMANENTLY) {
      String payload = https.getString(); // La réponse
      // strlcpy(*reponseMoto, char* payload.c_str(),payload.length);
      //lv_textarea_set_text(ui_Log, payload.c_str() );
      Serial.println(payload); 
      doc1.clear();
      Serial.println("Avant deserialization");
      *reponseMoto = payload.c_str(); // convertir un string en char *
      Serial.println("*reponseMoto=");
      Serial.println(*reponseMoto);
      DeserializationError error = deserializeJson(doc1, *reponseMoto); /////////////////////////////////////
      Serial.println("Apres deserialisation");
      if (error) {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());
        lv_textarea_set_text(ui_Log, "Erreur de désérialisation");                                    //lv_textarea_set_text(ui_Log, error.c_str());
        return false;
      }
      Serial.println("Avant JSON ");
      //JsonObject root_0 = doc1[0];
      //JsonObject root_0 = doc1[0];
      JsonObject root_0 = doc1.as<JsonObject>();  
      const char*  mileage = root_0["mileage"]; // "25583.1"
      const char*  logic_state = root_0["logic_state"]; // "1"
      const char*  reason = root_0["reason"]; // "5"
      const char*  response = root_0["response"]; // "0"
      float  longitude = root_0["longitude"]; // 2.1315
      float  latitude = root_0["latitude"]; // 48.7836
      const char*  altitude = root_0["altitude"]; // "173"
      const char*  satellites = root_0["satellites"]; // "6"
      const char*  velocity = root_0["velocity"]; // "16"
      const char*  heading = root_0["heading"]; // "240"
      const char*  emergency = root_0["emergency"]; // "0"
      const char*  shock = root_0["shock"]; // nullptr
      float  main_voltage = root_0["main_voltage"]; // 13.28
      const char*  datetime_utc = root_0["datetime_utc"]; // "20240722153050"
      const char*  address = root_0["address"]; // "BUC, Sente du Haras"
      int  intSoc = root_0["soc"];
      const char*  soc = root_0["soc"]; // 72
      
      int  charging = root_0["charging"]; // 0
      int  chargecomplete = root_0["chargecomplete"]; // 0
      int  pluggedin = root_0["pluggedin"]; // 0
      int  chargingtimeleft = root_0["chargingtimeleft"]; // 0
      int  storage = root_0["storage"]; // 0
      char charSoc[4] ={"99"};
      Serial.println("Apres JSON ");
      //int16_t intSoc = 88;
      //charSoc[0] = *soc;
      //sscanf(charSoc,"%s",soc); // copie la const dans char
      
      //sscanf(intSoc,"%d",soc);
      
      //itoa(soc,*charSoc,10);
      //Serial.println("Avant TextArea soc=");
      //Serial.print(*constCharSoc);
      //const char* data = reinterpret_cast<const char*>(&val); //convert to a char pointer
      // String Temp;
      //sprintf(*charSoc, "%d", soc);

      //snprintf ( *charSoc), 2, "%s", soc);
      // snprintf(MinuteTimezoneH, 4, "%s", MinuteTimezone);       // résultat +01 Convertir la chaine +0100 en +01:00 pour concaténation

      //itoa(soc, *charSoc, 10);
      //*charSoc = itoa(soc, charSoc, 10);
    
     
      int16_t int16Soc;
      int16Soc = (int16_t)intSoc;
      Serial.print("intSoc="); Serial.printf("%d\n", &intSoc);
      Serial.print("int16Soc="); Serial.println(int16Soc);
      //Serial.print("soc=");    Serial.printf("%s\n", soc);
      lv_arc_set_value(ui_jaugeCharge, int16Soc);
      Serial.println("Apres ARC"); 
      lv_label_set_text(ui_ChargePCT, charSoc );
      Serial.println("Apres charge PCT"); 
      lv_textarea_set_text(ui_Log, *reponseMoto);
      Serial.println("Apres LOG"); 
    }

  } else 
      { Serial.printf("[HTTPS] GET... failed, error: %s\n", https.errorToString(codeReponseHTTP).c_str()); 
        requeteOK = false;
      }       
  https.end();
  // client.stop();
  return requeteOK;
}

      //int  tipover = root_0["tipover"]; // 0
      //const char*  datetime_actual = root_0["datetime_actual"]; // "20240722153049"
      //const char*  perimeter = root_0["perimeter"]; // nullptr
      //int  color = root_0["color"]; // 2
      //const char*  fuel = root_0["fuel"]; // nullptr
      //float  analog3 = root_0["analog3"]; // 0.09
      //const char*  siren = root_0["siren"]; // "0"
      //const char*  lock = root_0["lock"]; // "0"
      //const char*  int_lights = root_0["int_lights"]; // "0"

      //const char*  driver = root_0["driver"]; // "0"
      //const char*  gps_valid = root_0["gps_valid"]; // "1"
      //const char*  gps_connected = root_0["gps_connected"]; // "1"
      //const char*  ignition = root_0["ignition"]; // "0"
      //const char*  door = root_0["door"]; // "0"
      //const char*  hood = root_0["hood"]; // "0"
      //const char*  volume = root_0["volume"]; // "0"
      //const char*  water_temp = root_0["water_temp"]; // nullptr
      //const char*  oil_pressure = root_0["oil_pressure"]; // "0"

      //const char*  software_version = root_0["software_version"]; // "221208"

      //const char*  unitnumber = root_0["unitnumber"]; // "798776"
      //const char*  name = root_0["name"]; // "538ZFBZ70LCL13898"
      //const char*  unittype = root_0["unittype"]; // "5"
      //const char*  unitmodel = root_0["unitmodel"]; // "6"
      //float  analog1 = root_0["analog1"]; // 0.09
      //float  analog2 = root_0["analog2"]; // 0.09
      //int  battery = root_0["battery"]; // 100
