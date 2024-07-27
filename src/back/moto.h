
// On prend ici le certificat racine du site mongo
const char* root_ca_moto =\
                          "-----BEGIN CERTIFICATE-----\n"\
                          "MIIFWjCCA0KgAwIBAgIQbkepxUtHDA3sM9CJuRz04TANBgkqhkiG9w0BAQwFADBH\n" \
                          "MQswCQYDVQQGEwJVUzEiMCAGA1UEChMZR29vZ2xlIFRydXN0IFNlcnZpY2VzIExM\n" \
                          "QzEUMBIGA1UEAxMLR1RTIFJvb3QgUjEwHhcNMTYwNjIyMDAwMDAwWhcNMzYwNjIy\n" \
                          "MDAwMDAwWjBHMQswCQYDVQQGEwJVUzEiMCAGA1UEChMZR29vZ2xlIFRydXN0IFNl\n" \
                          "cnZpY2VzIExMQzEUMBIGA1UEAxMLR1RTIFJvb3QgUjEwggIiMA0GCSqGSIb3DQEB\n" \
                          "AQUAA4ICDwAwggIKAoICAQC2EQKLHuOhd5s73L+UPreVp0A8of2C+X0yBoJx9vaM\n" \
                          "f/vo27xqLpeXo4xL+Sv2sfnOhB2x+cWX3u+58qPpvBKJXqeqUqv4IyfLpLGcY9vX\n" \
                          "mX7wCl7raKb0xlpHDU0QM+NOsROjyBhsS+z8CZDfnWQpJSMHobTSPS5g4M/SCYe7\n" \
                          "zUjwTcLCeoiKu7rPWRnWr4+wB7CeMfGCwcDfLqZtbBkOtdh+JhpFAz2weaSUKK0P\n" \
                          "fyblqAj+lug8aJRT7oM6iCsVlgmy4HqMLnXWnOunVmSPlk9orj2XwoSPwLxAwAtc\n" \
                          "vfaHszVsrBhQf4TgTM2S0yDpM7xSma8ytSmzJSq0SPly4cpk9+aCEI3oncKKiPo4\n" \
                          "Zor8Y/kB+Xj9e1x3+naH+uzfsQ55lVe0vSbv1gHR6xYKu44LtcXFilWr06zqkUsp\n" \
                          "zBmkMiVOKvFlRNACzqrOSbTqn3yDsEB750Orp2yjj32JgfpMpf/VjsPOS+C12LOO\n" \
                          "Rc92wO1AK/1TD7Cn1TsNsYqiA94xrcx36m97PtbfkSIS5r762DL8EGMUUXLeXdYW\n" \
                          "k70paDPvOmbsB4om3xPXV2V4J95eSRQAogB/mqghtqmxlbCluQ0WEdrHbEg8QOB+\n" \
                          "DVrNVjzRlwW5y0vtOUucxD/SVRNuJLDWcfr0wbrM7Rv1/oFB2ACYPTrIrnqYNxgF\n" \
                          "lQIDAQABo0IwQDAOBgNVHQ8BAf8EBAMCAQYwDwYDVR0TAQH/BAUwAwEB/zAdBgNV\n" \
                          "HQ4EFgQU5K8rJnEaK0gnhS9SZizv8IkTcT4wDQYJKoZIhvcNAQEMBQADggIBADiW\n" \
                          "Cu49tJYeX++dnAsznyvgyv3SjgofQXSlfKqE1OXyHuY3UjKcC9FhHb8owbZEKTV1\n" \
                          "d5iyfNm9dKyKaOOpMQkpAWBz40d8U6iQSifvS9efk+eCNs6aaAyC58/UEBZvXw6Z\n" \
                          "XPYfcX3v73svfuo21pdwCxXu11xWajOl40k4DLh9+42FpLFZXvRq4d2h9mREruZR\n" \
                          "gyFmxhE+885H7pwoHyXa/6xmld01D1zvICxi/ZG6qcz8WpyTgYMpl0p8WnK0OdC3\n" \
                          "d8t5/Wk6kjftbjhlRn7pYL15iJdfOBL07q9bgsiG1eGZbYwE8na6SfZu6W0eX6Dv\n" \
                          "J4J2QPim01hcDyxC2kLGe4g0x8HYRZvBPsVhHdljUEn2NIVq4BjFbkerQUIpm/Zg\n" \
                          "DdIx02OYI5NaAIFItO/Nis3Jz5nu2Z6qNuFoS3FJFDYoOj0dzpqPJeaAcWErtXvM\n" \
                          "+SUWgeExX6GjfhaknBZqlxi9dnKlC54dNuYvoS++cJEPqOba+MSSQGwlfnuzCdyy\n" \
                          "F62ARPBopY+Udf90WuioAnwMCeKpSwughQtiue+hMZL77/ZRBIls6Kl0obsXs7X9\n" \
                          "SQ98POyDGCBDTtWTurQ0sR8WNh8M5mQ5Fkzc4P4dyKliPUDqysU0ArSuiYgzNdws\n" \
                          "E3PYJ/HQcu51OyLemGhmW/HGY0dVHLqlCFF1pkgl\n" \
                          "-----END CERTIFICATE-----\n";

/* Certificat racine de mongo .... à reporter
"-----BEGIN CERTIFICATE-----\n"\
"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\n" \
"-----END CERTIFICATE-----\n" \;
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
  int codeReponseHTTP;
  bool requeteOK = true;
  char reponseMoto[2000];
  String reponseMotoString;
  DynamicJsonDocument doc1(2000);
  

  if (WiFi.status() != WL_CONNECTED) {
    return false;
  }
  WiFiClientSecure client; // ouvre un client sécurisé
  HTTPClient http;
  client.setCACert(root_ca_moto);    // positionne le certificat racine
  Serial.print("Avant http.begin ");
  http.begin(client, mongolURI); // prépare l'appel à l'url 
  // Specify content-type header
  http.addHeader("Content-Type", "application/x-www-form-urlencoded"); //Je sais pas s'il faut cette conf ????????
  // Send HTTP POST request
  codeReponseHTTP = http.POST(nullptr, 0);
  Serial.println("après post ");
  lv_textarea_set_text(ui_Log, "Voila une reponse completement vide");

  if (codeReponseHTTP == HTTP_CODE_OK) {
      reponseMotoString = http.getString();
      Serial.println("aprèsaffectation http ");
      char *  reponseMotoPointerChar;
      Serial.println("avant strlcpy ");
      strlcpy(reponseMotoPointerChar,reponseMotoString.c_str(),reponseMotoString.length()); 
      Serial.println("après strlcpy ");
      //lv_textarea_set_text(ui_Log, reponseMotoString.c_str());
      doc1.clear();
      DeserializationError error;
      error = deserializeJson(doc1,reponseMotoPointerChar);
      if (error) {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());
        //lv_textarea_set_text(ui_Log, error.c_str());
        return false;
      }
      JsonObject root_0 = doc1[0];
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
      int  soc = root_0["soc"]; // 72
      int  charging = root_0["charging"]; // 0
      int  chargecomplete = root_0["chargecomplete"]; // 0
      int  pluggedin = root_0["pluggedin"]; // 0
      int  chargingtimeleft = root_0["chargingtimeleft"]; // 0
      int  storage = root_0["storage"]; // 0
      lv_textarea_set_text(ui_Log, (char *)soc);
        
  }
   else {    
    requeteOK = false;
   }
  http.end();
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
