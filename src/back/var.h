// Variables globales
// ******************** Affichage de l'heure ******************************
// Source : https://randomnerdtutorials.com/esp32-date-time-ntp-client-server-arduino/
// constantes pour ntp
const char *ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 0;
const int   daylightOffset_sec = 3600;
char heureNTP[50]; // Stocke la dernière heure NTP formattée
uint32_t RTEtimerCurrent=0; // Pour inclure un évènement dans la boucle timer 
uint32_t RTEtimerPrevious=0;
uint32_t mototimerCurrent=0; // Pour inclure un évènement dans la boucle timer 
uint32_t mototimerPrevious=0;
char heureCourante[20]; // Dernière heure obtenue formattée
static int32_t day, month, year; // la date du jour en int32

WiFiClientSecure *client = new WiFiClientSecure;
HTTPClient https;

// Report RTE
#define GREY    0x8410
//#define BLACK   0xffff
const uint16_t screenColor = 0xffff;
int brightness = 55; // Luminosité rétroéclairage par défaut

static constexpr uint64_t oneday = 86400000;  // 1 jour = 1000ms x 60sec x 60min x 24h = 86400000
static uint64_t count = rand() % oneday;      // Heure actuelle (compteur de millisecondes)
