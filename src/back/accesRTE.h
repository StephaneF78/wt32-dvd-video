// Début des constantes pour récupération des données RTE
#define identificationRTE   "ZmIxYWMyMmUtYTAwNi00N2E5LThhYjAtYWNjMTMzNzZmMDNjOjExYzcwZGViLTNmMDctNGE5My1hNjA3LWNmZTcxMTc1MTBhMQ=="  // ID Client et ID Secret en base 64

// *****************************************
// *****************************************
const char * idRTE = "Basic " identificationRTE; // le compilateur se charge de concaténer "Basic " + ID Client et ID Secret en base 64
// le certificat racine (format PEM) de https://digital.iservices.rte-france.com
const char* root_ca = \
                      "-----BEGIN CERTIFICATE-----\n" \
                      "MIIDXzCCAkegAwIBAgILBAAAAAABIVhTCKIwDQYJKoZIhvcNAQELBQAwTDEgMB4G\n" \
                      "A1UECxMXR2xvYmFsU2lnbiBSb290IENBIC0gUjMxEzARBgNVBAoTCkdsb2JhbFNp\n" \
                      "Z24xEzARBgNVBAMTCkdsb2JhbFNpZ24wHhcNMDkwMzE4MTAwMDAwWhcNMjkwMzE4\n" \
                      "MTAwMDAwWjBMMSAwHgYDVQQLExdHbG9iYWxTaWduIFJvb3QgQ0EgLSBSMzETMBEG\n" \
                      "A1UEChMKR2xvYmFsU2lnbjETMBEGA1UEAxMKR2xvYmFsU2lnbjCCASIwDQYJKoZI\n" \
                      "hvcNAQEBBQADggEPADCCAQoCggEBAMwldpB5BngiFvXAg7aEyiie/QV2EcWtiHL8\n" \
                      "RgJDx7KKnQRfJMsuS+FggkbhUqsMgUdwbN1k0ev1LKMPgj0MK66X17YUhhB5uzsT\n" \
                      "gHeMCOFJ0mpiLx9e+pZo34knlTifBtc+ycsmWQ1z3rDI6SYOgxXG71uL0gRgykmm\n" \
                      "KPZpO/bLyCiR5Z2KYVc3rHQU3HTgOu5yLy6c+9C7v/U9AOEGM+iCK65TpjoWc4zd\n" \
                      "QQ4gOsC0p6Hpsk+QLjJg6VfLuQSSaGjlOCZgdbKfd/+RFO+uIEn8rUAVSNECMWEZ\n" \
                      "XriX7613t2Saer9fwRPvm2L7DWzgVGkWqQPabumDk3F2xmmFghcCAwEAAaNCMEAw\n" \
                      "DgYDVR0PAQH/BAQDAgEGMA8GA1UdEwEB/wQFMAMBAf8wHQYDVR0OBBYEFI/wS3+o\n" \
                      "LkUkrk1Q+mOai97i3Ru8MA0GCSqGSIb3DQEBCwUAA4IBAQBLQNvAUKr+yAzv95ZU\n" \
                      "RUm7lgAJQayzE4aGKAczymvmdLm6AC2upArT9fHxD4q/c2dKg8dEe3jgr25sbwMp\n" \
                      "jjM5RcOO5LlXbKr8EpbsU8Yt5CRsuZRj+9xTaGdWPoO4zzUhw8lo/s7awlOqzJCK\n" \
                      "6fBdRoyV3XpYKBovHd7NADdBj+1EbddTKJd+82cEHhXXipa0095MJ6RMG3NzdvQX\n" \
                      "mcIfeg7jLQitChws/zyrVQ4PkX4268NXSb7hLi18YIvDQVETI53O9zJrlAGomecs\n" \
                      "Mx86OyXShkDOOyyGeMlhLxS67ttVb9+E7gUJTb0o2HLO02JQZR7rkpeDMdmztcpH\n" \
                      "WD9f\n" \
                      "-----END CERTIFICATE-----\n";

const char* oauthURI =          "https://digital.iservices.rte-france.com/token/oauth/";
const char*  temposURI =         "https://digital.iservices.rte-france.com/open_api/tempo_like_supply_contract/v1/tempo_like_calendars";
const char*  temposSandboxURI =  "https://digital.iservices.rte-france.com/open_api/tempo_like_supply_contract/v1/sandbox/tempo_like_calendars";
//String headerBasePath =    "/open_api/tempo_like_supply_contract/v1/tempo_like_calendars";
const char*  headerHost =        "digital.iservices.rte-france.com";

// ****************************** Fin des constantes pour RTE TEMPO ********************************
// ***************************************** TEMPO RTE *
// Source : https://forum.arduino.cc/t/api-rte-ecowatt/1017281
/* Exemple de retour prélevé dans JEEDOM
  [2023-02-26 08:11:43]DEBUG : {"tempo_like_calendars":{
  "start_date":"2022-09-01T00:00:00+02:00",
  "end_date":"2023-02-28T00:00:00+01:00",
  "values":[
  {"start_date":"2023-02-27T00:00:00+01:00","end_date":"2023-02-28T00:00:00+01:00","value":"WHITE","updated_date":"2023-02-26T10:20:00+01:00"}, attention attend +02 à partir de fin mars
  {"start_date":"2023-02-26T00:00:00+01:00","end_date":"2023-02-27T00:00:00+01:00","value":"BLUE","updated_date":"2023-02-25T10:20:00+01:00"},
  {"start_date":"2023-02-25T00:00:00+01:00","end_date":"2023-02-26T00:00:00+01:00","value":"BLUE","updated_date":"2023-02-24T10:20:00+01:00"},
*/

// Décodage des erreurs
// obtention d'une transcription des codes d'erreurs spécifique à l'API RTE ou message général
String errorDescription(int code, HTTPClient& https) {
  switch (code) {
    case 401: return "l'authentification a échouée";
    case 403: return "l’appelant n’est pas habilité à appeler la ressource";
    case 413: return "La taille de la réponse de la requête dépasse 7Mo";
    case 414: return "L’URI transmise par l’appelant dépasse 2048 caractères";
    case 429: return "Le nombre d’appel maximum dans un certain laps de temps est dépassé";
    case 509: return "L‘ensemble des requêtes des clients atteint la limite maximale";
    default: break;
  }
  return https.errorToString(code);
}


// Affichage des pastilles
void pastille(String couleurJour, String couleurDemain){ //BLUE, WHITE, RED
 
  // Pastille de gauche charger les paramètres sur les deux objets 'changement d'image)
  // Par défaut les pastilles seront rouges
  lv_imgbtn_set_src(ui_BPTempo1, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_bptemporouge50_png, NULL);
  lv_imgbtn_set_src(ui_BPTempo2, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_bptemporouge50_png, NULL);

  if (couleurJour.compareTo("BLUE")==0)  {
    //lcd.fillCircle(x, y, r, BLUE);
    lv_imgbtn_set_src(ui_BPTempo1, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_bptempobleu_50_png, NULL);

    }  //else {gfx->fillCircle(x, y, r, GREEN);}
  if (couleurJour.compareTo("WHITE")==0) {
    //lcd.fillCircle(x, y, r, WHITE);
    lv_imgbtn_set_src(ui_BPTempo1, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_bptempoblanc_50_png, NULL);

    }  //else {gfx->fillCircle(x, y, r, GREEN);}
  if (couleurJour.compareTo("RED")==0)   {
    //lcd.fillCircle(x, y, r, RED);
    lv_imgbtn_set_src(ui_BPTempo1, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_bptemporouge50_png, NULL);
    }    //else {gfx->fillCircle(x, y, r, GREEN);}
  // Pastille de droite
  if (couleurDemain.compareTo("BLUE")==0) {
    //lcd.fillCircle(x+e, y, r, BLUE);
    lv_imgbtn_set_src(ui_BPTempo2, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_bptempobleu_50_png, NULL);

    }   //else {gfx->fillCircle(x, y, r, GREEN);}
  if (couleurDemain.compareTo("WHITE")==0) {
    // lcd.fillCircle(x+e, y, r, WHITE);
    lv_imgbtn_set_src(ui_BPTempo2, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_bptempoblanc_50_png, NULL);

    } //else {gfx->fillCircle(x, y, r, GREEN);}
  if (couleurDemain.compareTo("RED")==0)  {
    // lcd.fillCircle(x+e, y, r, RED);
    lv_imgbtn_set_src(ui_BPTempo2, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_bptemporouge50_png, NULL);
    }    // else {gfx->fillCircle(x, y, r, GREEN);}
}


void miseAJourPastille(String date0, String couleur0, String date1, String couleur1){
  // Donne aux pastille leur couleur tempo
  // comparer now() et la date recue pour affecter la bonne couleur date à formater en texte 2023-03-03
  // Comment alimenter une structure tm avec un string cf https://koor.fr/C/ctime/mktime.wp
  int MAX_SIZE = 80;
  time_t timestamp = time( NULL );
  char dateNow[MAX_SIZE];
  struct tm *pTime = localtime(&timestamp );
  strftime(dateNow, MAX_SIZE, "%Y-%m-%d", pTime); // mettre au format 2023-03-05
  String sDateNow = dateNow;
  String date0Trunc = date0.substring(0,10);
  String date1Trunc = date1.substring(0,10);
  int result0 =  sDateNow.compareTo(date0); // Renvoie -1 si date 0 est le lendemain
  int result1 =  sDateNow.compareTo(date1);
  // apparement résultat -1 si identique bizarre
  if (result0 == -1) {pastille( "", couleur0);} // couleurJour, couleurDemain
  if (result0 == 0) {pastille( couleur0, "");} // couleurJour, couleurDemain
  if (result1 <= -2) {pastille( couleur1, couleur0);} // couleurJour, couleurDemain
}



bool getRTEData() {
  String oauthPayload;
  String temposPayload;
  int codeReponseHTTP;
  const char* access_token;
  bool requeteOK = true;
  // La log RTE en petit
// lcd.setTextColor(WHITE, screenColor);
// lcd.setCursor(10, 90);
//lcd.setTextSize(1);

  if (WiFi.status() != WL_CONNECTED) {
    Serial.print("*** RTE *** WiFI non disponible. Requête impossible");
    delay(1000);
    // ESP.restart(); // si le WIFI est indispo on reboot pour réétablir la connexion
    return false;
  }
  // SBI WiFiClientSecure client; // ouvre un client sécurisé
  // HTTPClient http;
  client->setCACert(root_ca);    // positionne le certificat racine
  https.begin(*client, oauthURI); // prépare l'appel à l'url de prod

  // Specify content-type header
  https.addHeader("Content-Type", "application/x-www-form-urlencoded");
  https.addHeader("Authorization", idRTE);

  // Send HTTP POST request
  codeReponseHTTP = https.POST(nullptr, 0);

  if (codeReponseHTTP == HTTP_CODE_OK) {
    oauthPayload = https.getString();
    StaticJsonDocument<1024> doc; // SBI 1024 à la place de 192
    DeserializationError error = deserializeJson(doc, oauthPayload);
    if (error) {
//      Serial.printf("deserializeJson() oauthPayload failed: ");
//      Serial.printf("%s",error.c_str());
        // SBI à traduire dans un champ texte LVGL lcd.print("Erreur deseri");
        delay(3000);
        // ESP.restart(); // si erreur on reboot
        access_token = "";
        requeteOK = false;
    } else { // parsing effectué
      access_token = doc["access_token"];
    }
  } else {
//    Serial.print("Authentification RTE : erreur HTTP POST: ");
    // SBI 30/06/2024 à mapper LVGL lcd.printf("erreur authent RTE, le system va rebooter : %s",errorDescription(codeReponseHTTP, http));
      Serial.printf("*** RTE *** %s",errorDescription(codeReponseHTTP, https));
      delay(12000);
      // ESP.restart(); // si erreur on reboot
      requeteOK = false;
    }

  // on libère les resources
  https.end();
  if (!requeteOK) return false;

  // on a récupéré l'access_token, on peut l'utiliser pour faire notre requête GET sur l'API
  // String signalsAutorization = "Bearer ";
  // signalsAutorization += String(access_token);
  String temposAutorization = "Bearer ";
  temposAutorization += String(access_token);


  // ********************************************** Calcule les deux dates à envoyer à l'API 
  // Source : https://openclassrooms.com/forum/sujet/ajouter-des-jours-a-une-date-43394
  int NbJoursMoins = 0; // le jour -1 pour la première date 
  int NbJoursPlus = +2; // +2 jours pour la date de fin
  time_t DateJour;        // Pour stocker la date du jour
  struct tm Date;         // Structure pour recevoir la date et faire des op
  // unsigned long epochTime = timeClient.getEpochTime();   
  
  getLocalTime(&Date);//Get a time structure of type tm, calculated from epoch time Normalement tient compte du décalage horaire
  // Date = gmtime ((time_t *)&epochTime); //https://www.cplusplus.com/reference/ctime/gmtime/ recup date du jour
  // time(&DateJour);       // on recup la date du jour
  /* copie */
  //Date = *localtime (&DateJour);        // Copie la date du jour dans la struct TM
  Date.tm_mday += NbJoursMoins;         // On ajoute le nb de jours dans la structure
  DateJour = mktime (&Date);            // On recalcule la structure après ajout de jours

  // Nov 2023
  //Conditionne l'url au timezone
  strftime (MinuteTimezone, sizeof MinuteTimezone, "%z", &Date); // Récup Timezone +0100 en heure hiver et +0200 en eure d'été
  snprintf(MinuteTimezoneH, 4, "%s", MinuteTimezone);       // résultat +01 Convertir la chaine +0100 en +01:00 pour concaténation
  sprintf(MinuteTimezoneM, "%s%s", MinuteTimezoneH, ":00"); // résultat +01:00 Convertir la chaine +0100 en +01:00 pour concaténation de l'appel RTE

  strftime(DateDebRTE, sizeof DateDebRTE, "%Y-%m-%dT00:00:00", &Date); // transforme en string formattée  cette date 2023-03-03T00:00:00%2B02:00 ou deb 2023-03-05T00:00:00+01:00
  sprintf(DateDebRTE, "%s%s", DateDebRTE, MinuteTimezoneM); // Concaténation du décalage de temps timezone à la fin de la chaine +01:00
  // lcd.setTextColor(WHITE, screenColor);
  // lcd.setCursor(90, 250);
  // lcd.setTextSize(1);
  // Calcule la date de fin
  //Date = *localtime (&DateJour);       // Copie la date du jour dans la struct TM
  // Date = gmtime ((time_t *)&epochTime); //https://www.cplusplus.com/reference/ctime/gmtime/ recup date du jour
  getLocalTime(&Date);
  Date.tm_mday += NbJoursPlus;         // On ajoute le nb de jours dans la structure
  DateJour = mktime (&Date);           // On recalcule la structure après ajout de jours
   
  strftime (DateFinRTE, sizeof DateFinRTE, "%Y-%m-%dT00:00:00", &Date); // transforme en string formattée  cette date
  sprintf(DateFinRTE, "%s%s", DateFinRTE, MinuteTimezoneM); // Concaténation du décalage de temps timezone à la fin de la chaine

  Serial.printf("MinuteTimezoneH="); Serial.printf("%s\n", MinuteTimezoneH);
  Serial.printf("MinuteTimezoneM="); Serial.printf("%s\n", MinuteTimezoneM);
  Serial.printf("MinuteTimezone="); Serial.printf("%s\n", MinuteTimezone);
  Serial.printf("DateDebRTE="); Serial.printf("%s\n", DateDebRTE);
  Serial.printf("DateFinRTE="); Serial.printf("%s\n", DateFinRTE);

  //*********************************************** Fin de calcule les deux dates à envoyer à l'API ********************************************



  // Documentation pour JSON : cf https://arduinojson.org/v6/how-to/use-arduinojson-with-httpclient/#how-to-parse-a-json-document-from-an-http-response
  
  String tempoURIPlusParam ="";
  tempoURIPlusParam += String(temposURI); 
  tempoURIPlusParam += String("?start_date="); 
  tempoURIPlusParam += String(DateDebRTE); // On complète l'URL avec  "?start_date=2023-03-05T00:00:00+01:00&end_date=2023-03-07T00:00:00+01:00"
  tempoURIPlusParam += String("&end_date=");
  tempoURIPlusParam += String(DateFinRTE);
  // Nov2023
  // lcd.setTextSize(1);
  // lcd.setCursor(4,230);
  // lcd.print(tempoURIPlusParam);
  Serial.println("*** RTE *** tempoURIPlusParam= ");
  Serial.println(tempoURIPlusParam);
  //Nov2023

  https.begin(*client, tempoURIPlusParam); // si on veut tester le code sans être gêné par la limite d'un appel toutes les 15 minutes, on utilise la sandbox

  https.addHeader("Authorization", temposAutorization.c_str()); // On remplit le header iso postman autorization dans le header
  https.addHeader("host", headerHost);

  codeReponseHTTP = https.GET();// On envoie la requête HTTP GET
  if (codeReponseHTTP == HTTP_CODE_OK) {
    // version qui imprime tout le JSON
    temposPayload = https.getString();
    //gfx->print("Apres recup http temposPayload=");
    Serial.print("*** RTE *** temposPayload=");
    Serial.println(temposPayload);
    StaticJsonDocument<1024> doc;
    DeserializationError error = deserializeJson(doc, temposPayload); // On désérialise sans filtre
    Serial.print("*** RTE *** Après désérialisation temposPayload=");
    Serial.println(temposPayload);
    //lcd.setTextSize(1);
    //lcd.setCursor(20, 20);
    //lcd.print(temposPayload);
    if (error) {
        Serial.print("*** RTE *** deserializeJson() failed temposPayload= : ");
        Serial.println(error.c_str());
        lv_textarea_set_text(ui_Log, "*** MOTO *** Erreur de désérialisation");     //lv_textarea_set_text(ui_Log, error.c_str());
        return false;
      }

    else {
        JsonObject tempo_like_calendars = doc["tempo_like_calendars"]; // Niveau 1 :On prend le premier niveau du json (il y a deux dates fournies en entrée)
        const char* start_date = tempo_like_calendars["start_date"]; // gfx->println("start_date = "); gfx->print(start_date);   // Niveau 1 / Date
        
        // On prend le tableau des "values" sous calendars
        JsonObject values_pos0 = tempo_like_calendars["values"][0];
        String start_date_pos0 = values_pos0["start_date"];
        //const char* end_date_pos0     = values_pos0["end_date"];
        String couleur_pos0 = values_pos0["value"]; // "BLUE", "WHITE", "RED"
        Serial.print("*** RTE *** value_pos0=");
        Serial.println(couleur_pos0);
  
        //const char* updated_date_pos0 = values_pos0["updated_date"];
        // On prends les deuxièmes valeurs en pos 1
        JsonObject values_pos1 = tempo_like_calendars["values"][1]; // On prend le tableau de "values" dans calendars
        String start_date_pos1 = values_pos1["start_date"];
        //const char* end_date_pos1     = values_pos1["end_date"];
        String couleur_pos1 = values_pos1["value"]; // "BLUE", "WHITE", "RED"
        Serial.print("*** RTE *** value_pos1=");
        Serial.println(couleur_pos1);

        // On envoie sur le screen
        Serial.print("*** RTE ***  Avant miseAjourPastille");        
        miseAJourPastille(start_date_pos0, couleur_pos0, start_date_pos1, couleur_pos1);     
        Serial.print("*** RTE *** Avant JsonObject tempo_like_calendar");        

        for (JsonObject tempofor : doc["tempo_like_calendars"]["values"].as<JsonArray>()) { // On met ds le for les values (là il ne rentre pas !)
          //gfx->println("Dans le for json");
          const char* dateupdate = tempofor["updated_date"];
          const char* couleur = tempofor["value"]; 
          //gfx->print(" ds for date="); gfx->print(dateupdate);
          //gfx->println(" ds for couleur="); gfx->print(couleur);
        }
        Serial.println(" *** RTE ***Après JsonObject tempo_like_calendar");        

    }
  } else {
      Serial.println(" *** RTE *** erreur HTTP GET: ");
      Serial.printf(" => %s", codeReponseHTTP);
      Serial.printf("%s", https.errorToString(codeReponseHTTP));
      Serial.printf("Erreur appel RTE (ligne321)=%s", https.errorToString(codeReponseHTTP));
      delay(1200);
      // ESP.restart(); // si erreur on reboot
      requeteOK = false;
  }

  https.end();
  client->stop();
  // SBI 30/06/2024 à mapper lvgl lcd.printf("MAJ RTE :%s", heureCourante);
  return requeteOK;
}

int ParseDatePart(int partNumber, String pDate) // on passe les dates récup du json rte
{
	// Find the right part using space and colon as delimiters.  Return -1 if we run out of parts.
	int index = 0;
	while (partNumber)
	{
		if (pDate[index] == ':' || pDate[index] == ' ' || pDate[index] == '-') partNumber--;
		if (!pDate[++index]) return -1;
	}

	// If the part starts with a digit, read all of the digits.
	int result = 0;
	while (pDate[index] >= '0' && pDate[index] <= '9')
	{
		result = result * 10 + pDate[index++] - '0';
		if (pDate[index] < '0' || pDate[index] > '9') return result;
	}

	// Otherwise, read it as a month.
	switch (pDate[index++])
	{
	case 'J':
		if (pDate[index] == 'a') return 1;
		if (pDate[index++] && pDate[index] == 'n') return 6;
		return 7;
	case 'F':
		return 2;
	case 'M':
		if (pDate[index++] && pDate[index] == 'r') return 3;
		return 5;
	case 'A':
		if (pDate[index] == 'p') return 4;
		return 8;
	case 'S':
		return 9;
	case 'O':
		return 10;
	case 'N':
		return 11;
	case 'D':
		return 12;
	}

	// Return -1 if it didn't parse as either a number or a month.
	return -1;
}

