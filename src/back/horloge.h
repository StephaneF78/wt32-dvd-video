//ESP32Time rtc;
  // sbi ESP32Time rtc(3600);  // offset in seconds GMT+1
// ********************* Define NTP Client to get time ********************************************
// SBI   WiFiUDP ntpUDP;
  // sup time client : NTPClient timeClient(ntpUDP);
  // SBI 30/06/2024 char formattedDate[50];
  // SBI 30/06/2024 char date_ntp_init[50];
  struct tm timeinfo ; // 
// ********************* Fin Define NTP Client to get time ********************************************

// ************ Date de début et de fin pour appel RTE
char DateDebRTE[64];    // Pour stocker date deb requête RTE
char DateFinRTE[64];    // Pour stocker date fin requête RTE
char MinuteTimezone[64]; // décalage horaire en minutes
char MinuteTimezoneH[64]; // décalage horaire en minutes
char MinuteTimezoneM[64]; // décalage horaire en minutes

void initTimeNTP(){ https://forum.arduino.cc/t/conseil-sur-lutilisation-de-configtime/679950
  configTzTime("CET-1CEST-2,M3.5.0/02:00:00,M10.5.0/03:00:00", ntpServer); //lance le server NTP
}

// ******************** Affichage de l'heure ******************************
// Source : https://randomnerdtutorials.com/esp32-date-time-ntp-client-server-arduino/
void printLocalTime(){
/*  getLocalTime(&timeinfo);
  strftime(heureNTP, 50, "%H:%M:%S",&timeinfo);
  lcd.setTextSize(1);
  lcd.setCursor(20, 5);
  lcd.printf(heureNTP); // Affichage de la date  %A le jour, %B le mois, %d la date du jour, %Y l'année
*/

  //*********************************************** Debut de calcule les deux dates à envoyer à l'API
  int NbJoursMoins = 0; // le jour même pour la première date 
  int NbJoursPlus = +2; // +2 jours pour la date de fin
  time_t DateJour;        // Pour stocker la date du jour
  struct tm * pDate;         // Structure pour recevoir la date et faire des op
  char decalageH[10], decalageHFormat[10],tmp[10]=":00\0";

  getLocalTime(&timeinfo);
  strftime (decalageH, sizeof decalageH, "%z", &timeinfo); // ca donne le décalage sous cette forme +0200 à la place de +02:00
  strncpy(decalageHFormat, decalageH,3);
  strncat(decalageHFormat, tmp, 3); // là on dispose désormais de +02:00 dans decalageHFormat qu'il reste à concaténer à datedeb / fin pour interroger RTE
  
  //#define DEBUG
  #ifdef DEBUG  
  lcd.setTextSize(1);
  lcd.setCursor(20, 10);
  lcd.print("decalageHFormat="); lcd.println(decalageHFormat);
  #endif

  timeinfo.tm_mday += NbJoursMoins;         // On ajoute le nb de jours dans la structure
  DateJour = mktime (&timeinfo);            // On recalcule la structure après ajout de jours
  //strftime (DateDebRTE, sizeof DateDebRTE, "%Y-%m-%dT00:00:00+01:00", &timeinfo); // transforme en string formattée  cette date 2023-03-03T00:00:00%2B02:00 ou deb 2023-03-05T00:00:00+01:00
  strftime (DateDebRTE, sizeof DateDebRTE, "%Y-%m-%dT00:00:00", &timeinfo); // transforme en string formattée  cette date 2023-03-03T00:00:00%2B02:00 ou deb 2023-03-05T00:00:00 (sans +01:00)
  strncat(DateDebRTE, decalageHFormat, 6); // là on complète avec le décalage heure d'été/hivert +01:00 

  //#define DEBUG
  #ifdef DEBUG  
  lcd.setTextSize(1);
  lcd.setCursor(20, 10);
  lcd.print("DateDebRTE="); lcd.println(DateDebRTE);
  #endif

  // Calcule la date de fin
  // Sup Client getLocalTime(&Date);
  //getLocalTime(&timeinfo);
  timeinfo.tm_mday += NbJoursPlus;         // On ajoute le nb de jours dans la structure
  DateJour = mktime (&timeinfo);           // On recalcule la structure après ajout de jours
  strftime (DateFinRTE, sizeof DateFinRTE, "%Y-%m-%dT00:00:00", &timeinfo); // transforme en string formattée  cette date
  strncat(DateFinRTE, decalageHFormat, 6); // là on complète avec le décalage heure d'été/hiver +01:00 
  //#define DEBUG

  #ifdef DEBUG  
  lcd.setTextSize(1);
  lcd.setCursor(20, 10);
  lcd.print("DateDebRTE="); lcd.println(DateDebRTE);
  lcd.print("DateFinRTE="); lcd.println(DateFinRTE);
  //*********************************************** Fin de calcule les deux dates à envoyer à l'API
  #endif

  // Affichage des détails l'heure en petit
  //#define DEBUG
  #ifdef DEBUG  
    lcd.setCursor(1,190);
    lcd.setTextSize(1);
    lcd.println("NTP : ");
    lcd.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
    lcd.print("Day of week: ");
    lcd.println(&timeinfo, "%A");
    lcd.print("Month: ");
    lcd.println(&timeinfo, "%B");
    lcd.print("Day of Month: ");
    lcd.println(&timeinfo, "%d");
    lcd.print("Year: ");
    lcd.println(&timeinfo, "%Y");
    lcd.print("Hour: ");
    lcd.println(&timeinfo, "%H");
    lcd.print("Hour (12 hour format): ");
    lcd.println(&timeinfo, "%I");
    lcd.print("Minute: ");
    lcd.println(&timeinfo, "%M");
    lcd.print("Second: ");
    lcd.println(&timeinfo, "%S");
    lcd.println("Time variables");
    char timeHour[3];
    strftime(timeHour,3, "%H", &timeinfo);
    lcd.println(timeHour);
    char timeWeekDay[10];
    strftime(timeWeekDay,10, "%A", &timeinfo);
    lcd.println(timeWeekDay);
  #endif
}

uint64_t setSynchroHour(){
// Assure la synchro de l'heure  
// Afffecter au conteur le nombre de millisecondes de l'heure actuelle
  #define ONE_MINUTE_MS (60 * 1000)
  #define ONE_HOUR_MS (60 * 60 * 1000)
  #define TWELVE_HOUR_MS (12 * 60 * 60 * 1000)

  char charYYYY[10];
  char charMON[10];
  char charDAY[15];
  char charHH[10];
  char charMM[10];
  char charSS[10];
  uint64_t heureMS;
  char heureCouranteMS[16];
  //setlocale(LC_ALL,"");
  setlocale(LC_ALL, "fr_FR.utf8 French");
  setlocale(LC_TIME, "fr_FR.utf8 French");
 // setlocale(LC_TIME, 'fr', 'fr_FR', 'fr_FR.ISO8859-1');
  
  getLocalTime(&timeinfo);
  strftime( charYYYY, sizeof charYYYY, "%Y", &timeinfo);
  strftime( charMON, sizeof charMON, "%B", &timeinfo);
  strftime( charDAY, sizeof charDAY, "%a %e", &timeinfo);
  strftime( charHH, sizeof charHH, "%H", &timeinfo);
  strftime( charMM, sizeof charMM, "%M", &timeinfo);
  strftime( charSS, sizeof charSS, "%S", &timeinfo);
  
  strftime( heureCourante, sizeof heureCourante, "%H:%M", &timeinfo);
  lv_label_set_text(ui_clock,heureCourante); // Pour tester l'alimentation de l'heure numérique
  
  int16_t angle = (atoi(charSS)) * 3600 / 60000;
  // lv_img_set_angle(ui_sec, angle); // positionne l'aiguille des secondes
  angle = ((atoi(charMM) * 3600)) / 60;
  lv_img_set_angle(ui_min, angle); // positionne l'aiguille minutes
  angle = (angle + ((atoi(charHH) * 3600))) / 12;
  lv_img_set_angle(ui_hour, angle);
  // Mise à jour de la date
  lv_label_set_text(ui_day2,charDAY);
  lv_label_set_text(ui_month2,charMON);
  lv_label_set_text(ui_year2,charYYYY);
  return(heureMS);
}

void setSynchroDate(void){
  // Découpe la date pour mise à jour de la date de la montre
  char charDD[10];
  char charMM[10];
  char charYY[10];
  getLocalTime(&timeinfo);
  strftime( charDD, sizeof charDD, "%d", &timeinfo);
  strftime( charMM, sizeof charMM, "%m", &timeinfo);
  strftime( charYY, sizeof charYY, "%Y", &timeinfo);
  day=atoi(charDD);
  month=atoi(charMM);
  year=atoi(charYY);
}