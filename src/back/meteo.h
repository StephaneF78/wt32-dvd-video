
// http://api.openweathermap.org/geo/1.0/direct?q={city name},{state code},{country code}&limit={limit}&appid={b82014a1d736ba529fdf749c6d916706}
// https://api.openweathermap.org/data/2.5/weather?lat=48.8035403&lon=2.1266886&appid=5c7bd1cf8e3e40c166f24d9b0bfabe89

// https://api.openweathermap.org/data/2.5/history/city?lat=48.8035403&lon=2.1266886&appid=5c7bd1cf8e3e40c166f24d9b0bfabe89

/*        },
        "lat": 48.8035403,
        "lon": 2.1266886,
        "country": "FR",
        "state": "Ile-de-France"
        */

// https://history.openweathermap.org/data/2.5/history/city?lat={lat}&lon={lon}&type=hour&start={start}&end={end}&appid={API key}
// https://history.openweathermap.org/data/2.5/history/city?lat=48.8035403&lon=2.1266886&type=day&appid=5c7bd1cf8e3e40c166f24d9b0bfabe89

/* Fonctionne sans abo : https://api.openweathermap.org/data/2.5/forecast?lat=48.8035403&&cnt=18&lang=fr&units=metric&type=hour&lon=2.1266886&appid=5c7bd1cf8e3e40c166f24d9b0bfabe89
Versailles sur 2 jours pour plus augmenter cnt
aide : https://openweathermap.org/forecast5

*/

// https://api.openweathermap.org/data/3.0/onecall?lat=48.8035403&lon=2.1266886&exclude=minutly,alerts&appid=5c7bd1cf8e3e40c166f24d9b0bfabe89

/* exclude 
    current
    minutely
    hourly
    daily
    alerts
*/

const char* root_ca_meteo =\
                          "-----BEGIN CERTIFICATE-----\n" \
                          "MIIF3jCCA8agAwIBAgIQAf1tMPyjylGoG7xkDjUDLTANBgkqhkiG9w0BAQwFADCB\n" \
                          "iDELMAkGA1UEBhMCVVMxEzARBgNVBAgTCk5ldyBKZXJzZXkxFDASBgNVBAcTC0pl\n" \
                          "cnNleSBDaXR5MR4wHAYDVQQKExVUaGUgVVNFUlRSVVNUIE5ldHdvcmsxLjAsBgNV\n" \
                          "BAMTJVVTRVJUcnVzdCBSU0EgQ2VydGlmaWNhdGlvbiBBdXRob3JpdHkwHhcNMTAw\n" \
                          "MjAxMDAwMDAwWhcNMzgwMTE4MjM1OTU5WjCBiDELMAkGA1UEBhMCVVMxEzARBgNV\n" \
                          "BAgTCk5ldyBKZXJzZXkxFDASBgNVBAcTC0plcnNleSBDaXR5MR4wHAYDVQQKExVU\n" \
                          "aGUgVVNFUlRSVVNUIE5ldHdvcmsxLjAsBgNVBAMTJVVTRVJUcnVzdCBSU0EgQ2Vy\n" \
                          "dGlmaWNhdGlvbiBBdXRob3JpdHkwggIiMA0GCSqGSIb3DQEBAQUAA4ICDwAwggIK\n" \
                          "AoICAQCAEmUXNg7D2wiz0KxXDXbtzSfTTK1Qg2HiqiBNCS1kCdzOiZ/MPans9s/B\n" \
                          "3PHTsdZ7NygRK0faOca8Ohm0X6a9fZ2jY0K2dvKpOyuR+OJv0OwWIJAJPuLodMkY\n" \
                          "tJHUYmTbf6MG8YgYapAiPLz+E/CHFHv25B+O1ORRxhFnRghRy4YUVD+8M/5+bJz/\n" \
                          "Fp0YvVGONaanZshyZ9shZrHUm3gDwFA66Mzw3LyeTP6vBZY1H1dat//O+T23LLb2\n" \
                          "VN3I5xI6Ta5MirdcmrS3ID3KfyI0rn47aGYBROcBTkZTmzNg95S+UzeQc0PzMsNT\n" \
                          "79uq/nROacdrjGCT3sTHDN/hMq7MkztReJVni+49Vv4M0GkPGw/zJSZrM233bkf6\n" \
                          "c0Plfg6lZrEpfDKEY1WJxA3Bk1QwGROs0303p+tdOmw1XNtB1xLaqUkL39iAigmT\n" \
                          "Yo61Zs8liM2EuLE/pDkP2QKe6xJMlXzzawWpXhaDzLhn4ugTncxbgtNMs+1b/97l\n" \
                          "c6wjOy0AvzVVdAlJ2ElYGn+SNuZRkg7zJn0cTRe8yexDJtC/QV9AqURE9JnnV4ee\n" \
                          "UB9XVKg+/XRjL7FQZQnmWEIuQxpMtPAlR1n6BB6T1CZGSlCBst6+eLf8ZxXhyVeE\n" \
                          "Hg9j1uliutZfVS7qXMYoCAQlObgOK6nyTJccBz8NUvXt7y+CDwIDAQABo0IwQDAd\n" \
                          "BgNVHQ4EFgQUU3m/WqorSs9UgOHYm8Cd8rIDZsswDgYDVR0PAQH/BAQDAgEGMA8G\n" \
                          "A1UdEwEB/wQFMAMBAf8wDQYJKoZIhvcNAQEMBQADggIBAFzUfA3P9wF9QZllDHPF\n" \
                          "Up/L+M+ZBn8b2kMVn54CVVeWFPFSPCeHlCjtHzoBN6J2/FNQwISbxmtOuowhT6KO\n" \
                          "VWKR82kV2LyI48SqC/3vqOlLVSoGIG1VeCkZ7l8wXEskEVX/JJpuXior7gtNn3/3\n" \
                          "ATiUFJVDBwn7YKnuHKsSjKCaXqeYalltiz8I+8jRRa8YFWSQEg9zKC7F4iRO/Fjs\n" \
                          "8PRF/iKz6y+O0tlFYQXBl2+odnKPi4w2r78NBc5xjeambx9spnFixdjQg3IM8WcR\n" \
                          "iQycE0xyNN+81XHfqnHd4blsjDwSXWXavVcStkNr/+XeTWYRUc+ZruwXtuhxkYze\n" \
                          "Sf7dNXGiFSeUHM9h4ya7b6NnJSFd5t0dCy5oGzuCr+yDZ4XUmFF0sbmZgIn/f3gZ\n" \
                          "XHlKYC6SQK5MNyosycdiyA5d9zZbyuAlJQG03RoHnHcAP9Dc1ew91Pq7P8yF1m9/\n" \
                          "qS3fuQL39ZeatTXaw2ewh0qpKJ4jjv9cJ2vhsE/zB+4ALtRZh8tSQZXq9EfX7mRB\n" \
                          "VXyNWQKV3WKdwrnuWih0hKWbt5DHDAff9Yk2dDLWKMGwsAvgnEzDHNb842m1R0aB\n" \
                          "L6KCq9NjRHDEjf8tM7qtj3u1cIiuPhnPQCjY/MiQu12ZIvVS5ljFH4gxQ+6IHdfG\n" \
                          "jjxDah2nGN59PRbxYvnKkKj9\n" \
                          "-----END CERTIFICATE-----\n";



const char* meteoURI =          "https://api.openweathermap.org/data/2.5/forecast?lat=48.8035403&&cnt=18&lang=fr&units=metric&type=hour&lon=2.1266886&appid=5c7bd1cf8e3e40c166f24d9b0bfabe89";

bool getMETEOData() {
  Serial.println("******* METEO ********");

  const char* reponseMeteo[13000];  // const 
  DynamicJsonDocument doc(12300); // 12288
  bool requeteOK = true;

  if (WiFi.status() != WL_CONNECTED) {
    return false;
  }

  client1->setCACert(root_ca_meteo);    // positionne le certificat racine
  Serial.println("*** Meteo *** Avant https1.begin ");

  https1.begin(*client1, meteoURI); // prépare l'appel à l'url 
  // Specify content-type header
  //http.addHeader("accept", "application/json");
  https1.addHeader("Content-Type", "application/x-www-form-urlencoded"); //Je sais pas s'il faut cette conf ????????
  // Send HTTP POST request
  int codeReponseHTTP = https1.GET();
  if (codeReponseHTTP > 0) {
      // HTTP header has been send and Server response header has been handled
      Serial.printf("*** METEO *** [HTTP] GET... code: %d\n\n", codeReponseHTTP);

    if (codeReponseHTTP == HTTP_CODE_OK || codeReponseHTTP == HTTP_CODE_MOVED_PERMANENTLY) {
        String payload = https1.getString(); // La réponse
        // strlcpy(*reponseMoto, char* payload.c_str(),payload.length);
        //lv_textarea_set_text(ui_Log, payload.c_str() );
        Serial.println(payload); 
        doc.clear();
        Serial.println("*** METEO *** Avant deserialization");
        *reponseMeteo = payload.c_str(); // convertir un string en char *
        Serial.println("*** METEO **** *reponseMeteo=");
        Serial.println(*reponseMeteo);
        DeserializationError error = deserializeJson(doc, *reponseMeteo, 12288);

        if (error) {
            Serial.print("*** METEO *** deserializeJson() failed: ");
            Serial.println(error.c_str());
            return false;
        }

        const char* cod = doc["cod"]; // "200"
        int message = doc["message"]; // 0
        int cnt = doc["cnt"]; // 18

        JsonArray list = doc["list"];

        JsonObject list_0 = list[0];
        long list_0_dt = list_0["dt"]; // 1723366800

        JsonObject list_0_main = list_0["main"];
        float list_0_main_temp = list_0_main["temp"]; // 22.68 rempl float par char*
        char buffer [5];
        String temperatureString;
        dtostrf(list_0_main_temp,1,1,buffer); // on limite à une décimale le float    
        temperatureString = String(buffer); temperatureString += "°";
        lv_label_set_text(ui_label_degree, temperatureString.c_str());
        Serial.println("temp acuelle = "); Serial.println(temperatureString.c_str());
        float list_0_main_feels_like = list_0_main["feels_like"]; // 22.57
        float list_0_main_temp_min = list_0_main["temp_min"]; // 22.68
        float list_0_main_temp_max = list_0_main["temp_max"]; // 26.13
        String temperatureMinMaxString = "Max ";
        dtostrf(list_0_main_temp_max,1,1,buffer); // on limite à une décimale le float    
        temperatureMinMaxString += String(buffer); temperatureMinMaxString += "° - Min ";
        dtostrf(list_0_main_temp_min,1,1,buffer); // on limite à une décimale le float    
        temperatureMinMaxString += String(buffer); temperatureMinMaxString += "°";
        lv_label_set_text(ui_comp_get_child(ui_weather_title_group_3, UI_COMP_TITLEGROUP_SUBTITLE), temperatureMinMaxString.c_str());
        int list_0_main_pressure = list_0_main["pressure"]; // 1019
        int list_0_main_sea_level = list_0_main["sea_level"]; // 1019
        int list_0_main_grnd_level = list_0_main["grnd_level"]; // 1006
        int list_0_main_humidity = list_0_main["humidity"]; // 60 
        String humidite; itoa(list_0_main_humidity, buffer,10); humidite += buffer; humidite+="%";
        lv_label_set_text(ui_rain_percent, humidite.c_str()); //humidité ou pluie ?
        float list_0_main_temp_kf = list_0_main["temp_kf"]; // -3.45
        JsonObject list_0_weather_0 = list_0["weather"][0];
        int list_0_weather_0_id = list_0_weather_0["id"]; // 800
        const char* list_0_weather_0_main = list_0_weather_0["main"]; // "Clear"
        const char* list_0_weather_0_description = list_0_weather_0["description"]; // "ciel dégagé"
        lv_label_set_text(ui_comp_get_child(ui_weather_title_group_3, UI_COMP_TITLEGROUP_TITLE), list_0_weather_0_description);
        const char* list_0_weather_0_icon = list_0_weather_0["icon"]; // "01d"

        int list_0_clouds_all = list_0["clouds"]["all"]; // 0
        JsonObject list_0_wind = list_0["wind"];
        float list_0_wind_speed = list_0_wind["speed"]; // 3.56
        String windString = "Max ";
        dtostrf(list_0_wind_speed,1,1,buffer); // on limite à une décimale le float    
        windString += String(buffer); windString += " kmm/h";

        lv_label_set_text(ui_wind_speed, windString.c_str());


        int list_0_wind_deg = list_0_wind["deg"]; // 79
        float list_0_wind_gust = list_0_wind["gust"]; // 5.46

        int list_0_visibility = list_0["visibility"]; // 10000
        int list_0_pop = list_0["pop"]; // 0

        const char* list_0_sys_pod = list_0["sys"]["pod"]; // "d"

        const char* list_0_dt_txt = list_0["dt_txt"]; // "2024-08-11 09:00:00"
        lv_label_set_text(ui_comp_get_child(ui_city_gruop_1, UI_COMP_TITLEGROUP_SUBTITLE), list_0_dt_txt);


        JsonObject list_1 = list[1];
        long list_1_dt = list_1["dt"]; // 1723377600

        JsonObject list_1_main = list_1["main"];
        float list_1_main_temp = list_1_main["temp"]; // 25.32
        float list_1_main_feels_like = list_1_main["feels_like"]; // 25.24
        float list_1_main_temp_min = list_1_main["temp_min"]; // 25.32
        float list_1_main_temp_max = list_1_main["temp_max"]; // 30.59
        int list_1_main_pressure = list_1_main["pressure"]; // 1019
        int list_1_main_sea_level = list_1_main["sea_level"]; // 1019
        int list_1_main_grnd_level = list_1_main["grnd_level"]; // 1005
        int list_1_main_humidity = list_1_main["humidity"]; // 51
        float list_1_main_temp_kf = list_1_main["temp_kf"]; // -5.27

        JsonObject list_1_weather_0 = list_1["weather"][0];
        int list_1_weather_0_id = list_1_weather_0["id"]; // 800
        const char* list_1_weather_0_main = list_1_weather_0["main"]; // "Clear"
        const char* list_1_weather_0_description = list_1_weather_0["description"]; // "ciel dégagé"
        const char* list_1_weather_0_icon = list_1_weather_0["icon"]; // "01d"

        int list_1_clouds_all = list_1["clouds"]["all"]; // 10

        JsonObject list_1_wind = list_1["wind"];
        float list_1_wind_speed = list_1_wind["speed"]; // 4.35
        int list_1_wind_deg = list_1_wind["deg"]; // 87
        float list_1_wind_gust = list_1_wind["gust"]; // 5.57

        int list_1_visibility = list_1["visibility"]; // 10000
        int list_1_pop = list_1["pop"]; // 0

        const char* list_1_sys_pod = list_1["sys"]["pod"]; // "d"

        const char* list_1_dt_txt = list_1["dt_txt"]; // "2024-08-11 12:00:00"

        JsonObject list_2 = list[2];
        long list_2_dt = list_2["dt"]; // 1723388400

        JsonObject list_2_main = list_2["main"];
        float list_2_main_temp = list_2_main["temp"]; // 28.45
        float list_2_main_feels_like = list_2_main["feels_like"]; // 28.23
        float list_2_main_temp_min = list_2_main["temp_min"]; // 28.45
        float list_2_main_temp_max = list_2_main["temp_max"]; // 31.33
        int list_2_main_pressure = list_2_main["pressure"]; // 1017
        int list_2_main_sea_level = list_2_main["sea_level"]; // 1017
        int list_2_main_grnd_level = list_2_main["grnd_level"]; // 1003
        int list_2_main_humidity = list_2_main["humidity"]; // 42
        float list_2_main_temp_kf = list_2_main["temp_kf"]; // -2.88

        JsonObject list_2_weather_0 = list_2["weather"][0];
        int list_2_weather_0_id = list_2_weather_0["id"]; // 803
        const char* list_2_weather_0_main = list_2_weather_0["main"]; // "Clouds"
        const char* list_2_weather_0_description = list_2_weather_0["description"]; // "nuageux"
        const char* list_2_weather_0_icon = list_2_weather_0["icon"]; // "04d"

        int list_2_clouds_all = list_2["clouds"]["all"]; // 64

        JsonObject list_2_wind = list_2["wind"];
        float list_2_wind_speed = list_2_wind["speed"]; // 4.44
        int list_2_wind_deg = list_2_wind["deg"]; // 103
        float list_2_wind_gust = list_2_wind["gust"]; // 5.58

        int list_2_visibility = list_2["visibility"]; // 10000
        int list_2_pop = list_2["pop"]; // 0

        const char* list_2_sys_pod = list_2["sys"]["pod"]; // "d"

        const char* list_2_dt_txt = list_2["dt_txt"]; // "2024-08-11 15:00:00"

        JsonObject list_3 = list[3];
        long list_3_dt = list_3["dt"]; // 1723399200

        JsonObject list_3_main = list_3["main"];
        float list_3_main_temp = list_3_main["temp"]; // 29.41
        float list_3_main_feels_like = list_3_main["feels_like"]; // 29.35
        float list_3_main_temp_min = list_3_main["temp_min"]; // 29.41
        float list_3_main_temp_max = list_3_main["temp_max"]; // 29.41
        int list_3_main_pressure = list_3_main["pressure"]; // 1014
        int list_3_main_sea_level = list_3_main["sea_level"]; // 1014
        int list_3_main_grnd_level = list_3_main["grnd_level"]; // 1001
        int list_3_main_humidity = list_3_main["humidity"]; // 43
        int list_3_main_temp_kf = list_3_main["temp_kf"]; // 0

        JsonObject list_3_weather_0 = list_3["weather"][0];
        int list_3_weather_0_id = list_3_weather_0["id"]; // 804
        const char* list_3_weather_0_main = list_3_weather_0["main"]; // "Clouds"
        const char* list_3_weather_0_description = list_3_weather_0["description"]; // "couvert"
        const char* list_3_weather_0_icon = list_3_weather_0["icon"]; // "04d"

        int list_3_clouds_all = list_3["clouds"]["all"]; // 98

        JsonObject list_3_wind = list_3["wind"];
        float list_3_wind_speed = list_3_wind["speed"]; // 4.16
        int list_3_wind_deg = list_3_wind["deg"]; // 103
        float list_3_wind_gust = list_3_wind["gust"]; // 5.8

        int list_3_visibility = list_3["visibility"]; // 10000
        int list_3_pop = list_3["pop"]; // 0

        const char* list_3_sys_pod = list_3["sys"]["pod"]; // "d"

        const char* list_3_dt_txt = list_3["dt_txt"]; // "2024-08-11 18:00:00"

        JsonObject list_4 = list[4];
        long list_4_dt = list_4["dt"]; // 1723410000

        JsonObject list_4_main = list_4["main"];
        float list_4_main_temp = list_4_main["temp"]; // 26.47
        float list_4_main_feels_like = list_4_main["feels_like"]; // 26.47
        float list_4_main_temp_min = list_4_main["temp_min"]; // 26.47
        float list_4_main_temp_max = list_4_main["temp_max"]; // 26.47
        int list_4_main_pressure = list_4_main["pressure"]; // 1014
        int list_4_main_sea_level = list_4_main["sea_level"]; // 1014
        int list_4_main_grnd_level = list_4_main["grnd_level"]; // 1001
        int list_4_main_humidity = list_4_main["humidity"]; // 56
        int list_4_main_temp_kf = list_4_main["temp_kf"]; // 0

        JsonObject list_4_weather_0 = list_4["weather"][0];
        int list_4_weather_0_id = list_4_weather_0["id"]; // 803
        const char* list_4_weather_0_main = list_4_weather_0["main"]; // "Clouds"
        const char* list_4_weather_0_description = list_4_weather_0["description"]; // "nuageux"
        const char* list_4_weather_0_icon = list_4_weather_0["icon"]; // "04n"

        int list_4_clouds_all = list_4["clouds"]["all"]; // 72

        JsonObject list_4_wind = list_4["wind"];
        float list_4_wind_speed = list_4_wind["speed"]; // 3.18
        int list_4_wind_deg = list_4_wind["deg"]; // 87
        float list_4_wind_gust = list_4_wind["gust"]; // 8.51

        int list_4_visibility = list_4["visibility"]; // 10000
        int list_4_pop = list_4["pop"]; // 0

        const char* list_4_sys_pod = list_4["sys"]["pod"]; // "n"

        const char* list_4_dt_txt = list_4["dt_txt"]; // "2024-08-11 21:00:00"

        JsonObject list_5 = list[5];
        long list_5_dt = list_5["dt"]; // 1723420800

        JsonObject list_5_main = list_5["main"];
        float list_5_main_temp = list_5_main["temp"]; // 24.37
        float list_5_main_feels_like = list_5_main["feels_like"]; // 24.59
        float list_5_main_temp_min = list_5_main["temp_min"]; // 24.37
        float list_5_main_temp_max = list_5_main["temp_max"]; // 24.37
        int list_5_main_pressure = list_5_main["pressure"]; // 1012
        int list_5_main_sea_level = list_5_main["sea_level"]; // 1012
        int list_5_main_grnd_level = list_5_main["grnd_level"]; // 999
        int list_5_main_humidity = list_5_main["humidity"]; // 66
        int list_5_main_temp_kf = list_5_main["temp_kf"]; // 0

        JsonObject list_5_weather_0 = list_5["weather"][0];
        int list_5_weather_0_id = list_5_weather_0["id"]; // 802
        const char* list_5_weather_0_main = list_5_weather_0["main"]; // "Clouds"
        const char* list_5_weather_0_description = list_5_weather_0["description"]; // "partiellement nuageux"
        const char* list_5_weather_0_icon = list_5_weather_0["icon"]; // "03n"

        int list_5_clouds_all = list_5["clouds"]["all"]; // 49

        JsonObject list_5_wind = list_5["wind"];
        float list_5_wind_speed = list_5_wind["speed"]; // 1.96
        int list_5_wind_deg = list_5_wind["deg"]; // 87
        float list_5_wind_gust = list_5_wind["gust"]; // 6.3

        int list_5_visibility = list_5["visibility"]; // 10000
        int list_5_pop = list_5["pop"]; // 0

        const char* list_5_sys_pod = list_5["sys"]["pod"]; // "n"

        const char* list_5_dt_txt = list_5["dt_txt"]; // "2024-08-12 00:00:00"

        JsonObject list_6 = list[6];
        long list_6_dt = list_6["dt"]; // 1723431600

        JsonObject list_6_main = list_6["main"];
        float list_6_main_temp = list_6_main["temp"]; // 22.66
        float list_6_main_feels_like = list_6_main["feels_like"]; // 23.02
        float list_6_main_temp_min = list_6_main["temp_min"]; // 22.66
        float list_6_main_temp_max = list_6_main["temp_max"]; // 22.66
        int list_6_main_pressure = list_6_main["pressure"]; // 1011
        int list_6_main_sea_level = list_6_main["sea_level"]; // 1011
        int list_6_main_grnd_level = list_6_main["grnd_level"]; // 998
        int list_6_main_humidity = list_6_main["humidity"]; // 78
        int list_6_main_temp_kf = list_6_main["temp_kf"]; // 0

        JsonObject list_6_weather_0 = list_6["weather"][0];
        int list_6_weather_0_id = list_6_weather_0["id"]; // 800
        const char* list_6_weather_0_main = list_6_weather_0["main"]; // "Clear"
        const char* list_6_weather_0_description = list_6_weather_0["description"]; // "ciel dégagé"
        const char* list_6_weather_0_icon = list_6_weather_0["icon"]; // "01n"

        int list_6_clouds_all = list_6["clouds"]["all"]; // 7

        JsonObject list_6_wind = list_6["wind"];
        float list_6_wind_speed = list_6_wind["speed"]; // 1.79
        int list_6_wind_deg = list_6_wind["deg"]; // 108
        float list_6_wind_gust = list_6_wind["gust"]; // 4.71

        int list_6_visibility = list_6["visibility"]; // 10000
        int list_6_pop = list_6["pop"]; // 0

        const char* list_6_sys_pod = list_6["sys"]["pod"]; // "n"

        const char* list_6_dt_txt = list_6["dt_txt"]; // "2024-08-12 03:00:00"

        JsonObject list_7 = list[7];
        long list_7_dt = list_7["dt"]; // 1723442400

        JsonObject list_7_main = list_7["main"];
        float list_7_main_temp = list_7_main["temp"]; // 23.22
        float list_7_main_feels_like = list_7_main["feels_like"]; // 23.63
        float list_7_main_temp_min = list_7_main["temp_min"]; // 23.22
        float list_7_main_temp_max = list_7_main["temp_max"]; // 23.22
        int list_7_main_pressure = list_7_main["pressure"]; // 1011
        int list_7_main_sea_level = list_7_main["sea_level"]; // 1011
        int list_7_main_grnd_level = list_7_main["grnd_level"]; // 998
        int list_7_main_humidity = list_7_main["humidity"]; // 78
        int list_7_main_temp_kf = list_7_main["temp_kf"]; // 0

        JsonObject list_7_weather_0 = list_7["weather"][0];
        int list_7_weather_0_id = list_7_weather_0["id"]; // 800
        const char* list_7_weather_0_main = list_7_weather_0["main"]; // "Clear"
        const char* list_7_weather_0_description = list_7_weather_0["description"]; // "ciel dégagé"
        const char* list_7_weather_0_icon = list_7_weather_0["icon"]; // "01d"

        int list_7_clouds_all = list_7["clouds"]["all"]; // 5

        JsonObject list_7_wind = list_7["wind"];
        float list_7_wind_speed = list_7_wind["speed"]; // 1.62
        int list_7_wind_deg = list_7_wind["deg"]; // 161
        float list_7_wind_gust = list_7_wind["gust"]; // 3.4

        int list_7_visibility = list_7["visibility"]; // 10000
        int list_7_pop = list_7["pop"]; // 0

        const char* list_7_sys_pod = list_7["sys"]["pod"]; // "d"

        const char* list_7_dt_txt = list_7["dt_txt"]; // "2024-08-12 06:00:00"

        JsonObject list_8 = list[8];
        long list_8_dt = list_8["dt"]; // 1723453200

        JsonObject list_8_main = list_8["main"];
        float list_8_main_temp = list_8_main["temp"]; // 30.87
        float list_8_main_feels_like = list_8_main["feels_like"]; // 30.35
        float list_8_main_temp_min = list_8_main["temp_min"]; // 30.87
        float list_8_main_temp_max = list_8_main["temp_max"]; // 30.87
        int list_8_main_pressure = list_8_main["pressure"]; // 1010
        int list_8_main_sea_level = list_8_main["sea_level"]; // 1010
        int list_8_main_grnd_level = list_8_main["grnd_level"]; // 997
        int list_8_main_humidity = list_8_main["humidity"]; // 37
        int list_8_main_temp_kf = list_8_main["temp_kf"]; // 0

        JsonObject list_8_weather_0 = list_8["weather"][0];
        int list_8_weather_0_id = list_8_weather_0["id"]; // 800
        const char* list_8_weather_0_main = list_8_weather_0["main"]; // "Clear"
        const char* list_8_weather_0_description = list_8_weather_0["description"]; // "ciel dégagé"
        const char* list_8_weather_0_icon = list_8_weather_0["icon"]; // "01d"

        int list_8_clouds_all = list_8["clouds"]["all"]; // 10

        JsonObject list_8_wind = list_8["wind"];
        float list_8_wind_speed = list_8_wind["speed"]; // 3.54
        int list_8_wind_deg = list_8_wind["deg"]; // 208
        float list_8_wind_gust = list_8_wind["gust"]; // 6.19

        int list_8_visibility = list_8["visibility"]; // 10000
        int list_8_pop = list_8["pop"]; // 0

        const char* list_8_sys_pod = list_8["sys"]["pod"]; // "d"

        const char* list_8_dt_txt = list_8["dt_txt"]; // "2024-08-12 09:00:00"

        JsonObject list_9 = list[9];
        long list_9_dt = list_9["dt"]; // 1723464000

        JsonObject list_9_main = list_9["main"];
        float list_9_main_temp = list_9_main["temp"]; // 34.37
        float list_9_main_feels_like = list_9_main["feels_like"]; // 33.43
        float list_9_main_temp_min = list_9_main["temp_min"]; // 34.37
        float list_9_main_temp_max = list_9_main["temp_max"]; // 34.37
        int list_9_main_pressure = list_9_main["pressure"]; // 1009
        int list_9_main_sea_level = list_9_main["sea_level"]; // 1009
        int list_9_main_grnd_level = list_9_main["grnd_level"]; // 997
        int list_9_main_humidity = list_9_main["humidity"]; // 28
        int list_9_main_temp_kf = list_9_main["temp_kf"]; // 0

        JsonObject list_9_weather_0 = list_9["weather"][0];
        int list_9_weather_0_id = list_9_weather_0["id"]; // 802
        const char* list_9_weather_0_main = list_9_weather_0["main"]; // "Clouds"
        const char* list_9_weather_0_description = list_9_weather_0["description"]; // "partiellement nuageux"
        const char* list_9_weather_0_icon = list_9_weather_0["icon"]; // "03d"

        int list_9_clouds_all = list_9["clouds"]["all"]; // 30

        JsonObject list_9_wind = list_9["wind"];
        float list_9_wind_speed = list_9_wind["speed"]; // 4.45
        int list_9_wind_deg = list_9_wind["deg"]; // 218
        float list_9_wind_gust = list_9_wind["gust"]; // 6.34

        int list_9_visibility = list_9["visibility"]; // 10000
        int list_9_pop = list_9["pop"]; // 0

        const char* list_9_sys_pod = list_9["sys"]["pod"]; // "d"

        const char* list_9_dt_txt = list_9["dt_txt"]; // "2024-08-12 12:00:00"

        JsonObject list_10 = list[10];
        long list_10_dt = list_10["dt"]; // 1723474800

        JsonObject list_10_main = list_10["main"];
        float list_10_main_temp = list_10_main["temp"]; // 35.71
        float list_10_main_feels_like = list_10_main["feels_like"]; // 34.85
        float list_10_main_temp_min = list_10_main["temp_min"]; // 35.71
        float list_10_main_temp_max = list_10_main["temp_max"]; // 35.71
        int list_10_main_pressure = list_10_main["pressure"]; // 1008
        int list_10_main_sea_level = list_10_main["sea_level"]; // 1008
        int list_10_main_grnd_level = list_10_main["grnd_level"]; // 996
        int list_10_main_humidity = list_10_main["humidity"]; // 26
        int list_10_main_temp_kf = list_10_main["temp_kf"]; // 0

        JsonObject list_10_weather_0 = list_10["weather"][0];
        int list_10_weather_0_id = list_10_weather_0["id"]; // 802
        const char* list_10_weather_0_main = list_10_weather_0["main"]; // "Clouds"
        const char* list_10_weather_0_description = list_10_weather_0["description"]; // "partiellement nuageux"
        const char* list_10_weather_0_icon = list_10_weather_0["icon"]; // "03d"

        int list_10_clouds_all = list_10["clouds"]["all"]; // 36

        JsonObject list_10_wind = list_10["wind"];
        float list_10_wind_speed = list_10_wind["speed"]; // 4.53
        int list_10_wind_deg = list_10_wind["deg"]; // 208
        float list_10_wind_gust = list_10_wind["gust"]; // 5.67

        int list_10_visibility = list_10["visibility"]; // 10000
        int list_10_pop = list_10["pop"]; // 0

        const char* list_10_sys_pod = list_10["sys"]["pod"]; // "d"

        const char* list_10_dt_txt = list_10["dt_txt"]; // "2024-08-12 15:00:00"

        JsonObject list_11 = list[11];
        long list_11_dt = list_11["dt"]; // 1723485600

        JsonObject list_11_main = list_11["main"];
        float list_11_main_temp = list_11_main["temp"]; // 32.82
        float list_11_main_feels_like = list_11_main["feels_like"]; // 32.55
        float list_11_main_temp_min = list_11_main["temp_min"]; // 32.82
        float list_11_main_temp_max = list_11_main["temp_max"]; // 32.82
        int list_11_main_pressure = list_11_main["pressure"]; // 1008
        int list_11_main_sea_level = list_11_main["sea_level"]; // 1008
        int list_11_main_grnd_level = list_11_main["grnd_level"]; // 996
        int list_11_main_humidity = list_11_main["humidity"]; // 35
        int list_11_main_temp_kf = list_11_main["temp_kf"]; // 0

        JsonObject list_11_weather_0 = list_11["weather"][0];
        int list_11_weather_0_id = list_11_weather_0["id"]; // 801
        const char* list_11_weather_0_main = list_11_weather_0["main"]; // "Clouds"
        const char* list_11_weather_0_description = list_11_weather_0["description"]; // "peu nuageux"
        const char* list_11_weather_0_icon = list_11_weather_0["icon"]; // "02d"

        int list_11_clouds_all = list_11["clouds"]["all"]; // 22

        JsonObject list_11_wind = list_11["wind"];
        float list_11_wind_speed = list_11_wind["speed"]; // 3.07
        int list_11_wind_deg = list_11_wind["deg"]; // 220
        float list_11_wind_gust = list_11_wind["gust"]; // 5.37

        int list_11_visibility = list_11["visibility"]; // 10000
        int list_11_pop = list_11["pop"]; // 0

        const char* list_11_sys_pod = list_11["sys"]["pod"]; // "d"

        const char* list_11_dt_txt = list_11["dt_txt"]; // "2024-08-12 18:00:00"

        JsonObject list_12 = list[12];
        long list_12_dt = list_12["dt"]; // 1723496400

        JsonObject list_12_main = list_12["main"];
        int list_12_main_temp = list_12_main["temp"]; // 27
        float list_12_main_feels_like = list_12_main["feels_like"]; // 28.01
        int list_12_main_temp_min = list_12_main["temp_min"]; // 27
        int list_12_main_temp_max = list_12_main["temp_max"]; // 27
        int list_12_main_pressure = list_12_main["pressure"]; // 1009
        int list_12_main_sea_level = list_12_main["sea_level"]; // 1009
        int list_12_main_grnd_level = list_12_main["grnd_level"]; // 997
        int list_12_main_humidity = list_12_main["humidity"]; // 59
        int list_12_main_temp_kf = list_12_main["temp_kf"]; // 0

        JsonObject list_12_weather_0 = list_12["weather"][0];
        int list_12_weather_0_id = list_12_weather_0["id"]; // 800
        const char* list_12_weather_0_main = list_12_weather_0["main"]; // "Clear"
        const char* list_12_weather_0_description = list_12_weather_0["description"]; // "ciel dégagé"
        const char* list_12_weather_0_icon = list_12_weather_0["icon"]; // "01n"

        int list_12_clouds_all = list_12["clouds"]["all"]; // 3

        JsonObject list_12_wind = list_12["wind"];
        float list_12_wind_speed = list_12_wind["speed"]; // 4.31
        int list_12_wind_deg = list_12_wind["deg"]; // 329
        float list_12_wind_gust = list_12_wind["gust"]; // 6.83

        int list_12_visibility = list_12["visibility"]; // 10000
        int list_12_pop = list_12["pop"]; // 0

        const char* list_12_sys_pod = list_12["sys"]["pod"]; // "n"

        const char* list_12_dt_txt = list_12["dt_txt"]; // "2024-08-12 21:00:00"

        JsonObject list_13 = list[13];
        long list_13_dt = list_13["dt"]; // 1723507200

        JsonObject list_13_main = list_13["main"];
        float list_13_main_temp = list_13_main["temp"]; // 22.28
        float list_13_main_feels_like = list_13_main["feels_like"]; // 22.34
        float list_13_main_temp_min = list_13_main["temp_min"]; // 22.28
        float list_13_main_temp_max = list_13_main["temp_max"]; // 22.28
        int list_13_main_pressure = list_13_main["pressure"]; // 1010
        int list_13_main_sea_level = list_13_main["sea_level"]; // 1010
        int list_13_main_grnd_level = list_13_main["grnd_level"]; // 997
        int list_13_main_humidity = list_13_main["humidity"]; // 68
        int list_13_main_temp_kf = list_13_main["temp_kf"]; // 0

        JsonObject list_13_weather_0 = list_13["weather"][0];
        int list_13_weather_0_id = list_13_weather_0["id"]; // 500
        const char* list_13_weather_0_main = list_13_weather_0["main"]; // "Rain"
        const char* list_13_weather_0_description = list_13_weather_0["description"]; // "légère pluie"
        const char* list_13_weather_0_icon = list_13_weather_0["icon"]; // "10n"

        int list_13_clouds_all = list_13["clouds"]["all"]; // 7

        JsonObject list_13_wind = list_13["wind"];
        float list_13_wind_speed = list_13_wind["speed"]; // 3.29
        int list_13_wind_deg = list_13_wind["deg"]; // 331
        float list_13_wind_gust = list_13_wind["gust"]; // 5.93

        int list_13_visibility = list_13["visibility"]; // 10000
        float list_13_pop = list_13["pop"]; // 0.35

        float list_13_rain_3h = list_13["rain"]["3h"]; // 0.36

        const char* list_13_sys_pod = list_13["sys"]["pod"]; // "n"

        const char* list_13_dt_txt = list_13["dt_txt"]; // "2024-08-13 00:00:00"

        JsonObject list_14 = list[14];
        long list_14_dt = list_14["dt"]; // 1723518000

        JsonObject list_14_main = list_14["main"];
        float list_14_main_temp = list_14_main["temp"]; // 20.91
        float list_14_main_feels_like = list_14_main["feels_like"]; // 20.99
        float list_14_main_temp_min = list_14_main["temp_min"]; // 20.91
        float list_14_main_temp_max = list_14_main["temp_max"]; // 20.91
        int list_14_main_pressure = list_14_main["pressure"]; // 1010
        int list_14_main_sea_level = list_14_main["sea_level"]; // 1010
        int list_14_main_grnd_level = list_14_main["grnd_level"]; // 997
        int list_14_main_humidity = list_14_main["humidity"]; // 74
        int list_14_main_temp_kf = list_14_main["temp_kf"]; // 0

        JsonObject list_14_weather_0 = list_14["weather"][0];
        int list_14_weather_0_id = list_14_weather_0["id"]; // 500
        const char* list_14_weather_0_main = list_14_weather_0["main"]; // "Rain"
        const char* list_14_weather_0_description = list_14_weather_0["description"]; // "légère pluie"
        const char* list_14_weather_0_icon = list_14_weather_0["icon"]; // "10n"

        int list_14_clouds_all = list_14["clouds"]["all"]; // 15

        JsonObject list_14_wind = list_14["wind"];
        float list_14_wind_speed = list_14_wind["speed"]; // 2.12
        int list_14_wind_deg = list_14_wind["deg"]; // 308
        float list_14_wind_gust = list_14_wind["gust"]; // 3.76

        int list_14_visibility = list_14["visibility"]; // 10000
        float list_14_pop = list_14["pop"]; // 0.91

        float list_14_rain_3h = list_14["rain"]["3h"]; // 0.92

        const char* list_14_sys_pod = list_14["sys"]["pod"]; // "n"

        const char* list_14_dt_txt = list_14["dt_txt"]; // "2024-08-13 03:00:00"

        JsonObject list_15 = list[15];
        long list_15_dt = list_15["dt"]; // 1723528800

        JsonObject list_15_main = list_15["main"];
        float list_15_main_temp = list_15_main["temp"]; // 18.93
        float list_15_main_feels_like = list_15_main["feels_like"]; // 19.07
        float list_15_main_temp_min = list_15_main["temp_min"]; // 18.93
        float list_15_main_temp_max = list_15_main["temp_max"]; // 18.93
        int list_15_main_pressure = list_15_main["pressure"]; // 1011
        int list_15_main_sea_level = list_15_main["sea_level"]; // 1011
        int list_15_main_grnd_level = list_15_main["grnd_level"]; // 998
        int list_15_main_humidity = list_15_main["humidity"]; // 84
        int list_15_main_temp_kf = list_15_main["temp_kf"]; // 0

        JsonObject list_15_weather_0 = list_15["weather"][0];
        int list_15_weather_0_id = list_15_weather_0["id"]; // 501
        const char* list_15_weather_0_main = list_15_weather_0["main"]; // "Rain"
        const char* list_15_weather_0_description = list_15_weather_0["description"]; // "pluie modérée"
        const char* list_15_weather_0_icon = list_15_weather_0["icon"]; // "10d"

        int list_15_clouds_all = list_15["clouds"]["all"]; // 43

        JsonObject list_15_wind = list_15["wind"];
        float list_15_wind_speed = list_15_wind["speed"]; // 2.88
        int list_15_wind_deg = list_15_wind["deg"]; // 319
        float list_15_wind_gust = list_15_wind["gust"]; // 4.76

        int list_15_visibility = list_15["visibility"]; // 10000
        int list_15_pop = list_15["pop"]; // 1

        float list_15_rain_3h = list_15["rain"]["3h"]; // 3.06

        const char* list_15_sys_pod = list_15["sys"]["pod"]; // "d"

        const char* list_15_dt_txt = list_15["dt_txt"]; // "2024-08-13 06:00:00"

        JsonObject list_16 = list[16];
        long list_16_dt = list_16["dt"]; // 1723539600

        JsonObject list_16_main = list_16["main"];
        float list_16_main_temp = list_16_main["temp"]; // 22.71
        float list_16_main_feels_like = list_16_main["feels_like"]; // 22.66
        float list_16_main_temp_min = list_16_main["temp_min"]; // 22.71
        float list_16_main_temp_max = list_16_main["temp_max"]; // 22.71
        int list_16_main_pressure = list_16_main["pressure"]; // 1011
        int list_16_main_sea_level = list_16_main["sea_level"]; // 1011
        int list_16_main_grnd_level = list_16_main["grnd_level"]; // 998
        int list_16_main_humidity = list_16_main["humidity"]; // 62
        int list_16_main_temp_kf = list_16_main["temp_kf"]; // 0

        JsonObject list_16_weather_0 = list_16["weather"][0];
        int list_16_weather_0_id = list_16_weather_0["id"]; // 500
        const char* list_16_weather_0_main = list_16_weather_0["main"]; // "Rain"
        const char* list_16_weather_0_description = list_16_weather_0["description"]; // "légère pluie"
        const char* list_16_weather_0_icon = list_16_weather_0["icon"]; // "10d"

        int list_16_clouds_all = list_16["clouds"]["all"]; // 90

        JsonObject list_16_wind = list_16["wind"];
        float list_16_wind_speed = list_16_wind["speed"]; // 2.38
        int list_16_wind_deg = list_16_wind["deg"]; // 288
        float list_16_wind_gust = list_16_wind["gust"]; // 2.78

        int list_16_visibility = list_16["visibility"]; // 10000
        float list_16_pop = list_16["pop"]; // 0.36

        float list_16_rain_3h = list_16["rain"]["3h"]; // 0.27

        const char* list_16_sys_pod = list_16["sys"]["pod"]; // "d"

        const char* list_16_dt_txt = list_16["dt_txt"]; // "2024-08-13 09:00:00"

        JsonObject list_17 = list[17];
        long list_17_dt = list_17["dt"]; // 1723550400

        JsonObject list_17_main = list_17["main"];
        float list_17_main_temp = list_17_main["temp"]; // 23.35
        float list_17_main_feels_like = list_17_main["feels_like"]; // 23.36
        float list_17_main_temp_min = list_17_main["temp_min"]; // 23.35
        float list_17_main_temp_max = list_17_main["temp_max"]; // 23.35
        int list_17_main_pressure = list_17_main["pressure"]; // 1011
        int list_17_main_sea_level = list_17_main["sea_level"]; // 1011
        int list_17_main_grnd_level = list_17_main["grnd_level"]; // 998
        int list_17_main_humidity = list_17_main["humidity"]; // 62
        int list_17_main_temp_kf = list_17_main["temp_kf"]; // 0

        JsonObject list_17_weather_0 = list_17["weather"][0];
        int list_17_weather_0_id = list_17_weather_0["id"]; // 500
        const char* list_17_weather_0_main = list_17_weather_0["main"]; // "Rain"
        const char* list_17_weather_0_description = list_17_weather_0["description"]; // "légère pluie"
        const char* list_17_weather_0_icon = list_17_weather_0["icon"]; // "10d"

        int list_17_clouds_all = list_17["clouds"]["all"]; // 95

        JsonObject list_17_wind = list_17["wind"];
        float list_17_wind_speed = list_17_wind["speed"]; // 3.29
        int list_17_wind_deg = list_17_wind["deg"]; // 281
        float list_17_wind_gust = list_17_wind["gust"]; // 4.1

        int list_17_visibility = list_17["visibility"]; // 10000
        int list_17_pop = list_17["pop"]; // 1

        float list_17_rain_3h = list_17["rain"]["3h"]; // 1.23

        const char* list_17_sys_pod = list_17["sys"]["pod"]; // "d"

        const char* list_17_dt_txt = list_17["dt_txt"]; // "2024-08-13 12:00:00"


        JsonObject city = doc["city"];
        long city_id = city["id"]; // 2969679
        const char* city_name = city["name"]; // "Versailles"
        lv_label_set_text(ui_comp_get_child(ui_city_gruop_1, UI_COMP_TITLEGROUP_TITLE), city_name);


        float city_coord_lat = city["coord"]["lat"]; // 48.8035
        float city_coord_lon = city["coord"]["lon"]; // 2.1267

        const char* city_country = city["country"]; // "FR"
        long city_population = city["population"]; // 85416
        int city_timezone = city["timezone"]; // 7200
        long city_sunrise = city["sunrise"]; // 1723351151
        long city_sunset = city["sunset"]; // 1723403656
    }
  }
  https1.end();
  client1->stop();
  return requeteOK;
}

