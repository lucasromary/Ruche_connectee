#include <SigFox.h>
#include "HX711.h"
#include <DS3231M.h>
#include <ArduinoLowPower.h>
#include <RTCZero.h>
#include "SparkFunBME280.h"
#include "Wire.h" // Pour travail en I2C

// CLOCK 
RTCZero rtc;
const byte seconds = 0;
const byte minutes = 05;
const byte hours = 12;

const byte day = 15;
const byte month = 05;
const byte year = 2020;

// variable de décision
int8_t nuit = 0;  
//nuit = 0 => dispositif en fonctionnement
//nuit = 1 => dispositif en veille pendant la nuit
//nuit = autre => dispositif en veille si la batterie devient trop faible
 
// Capteurs masse
const int LOADCELL_DOUT_PIN = A2;
const int LOADCELL_SCK_PIN = A3;
HX711 scale;
int calibration_factor = 2250;
//1810
//const int tare = 6;

// Capteur BME280
BME280 capteurBME280;


// Initialisation Sigfox
// On crée la structure du message a envoyer (Attention on doit rester dans les 12octets !)
//
typedef struct __attribute__ ((packed)) sigfox_message { // see http://www.catb.org/esr/structure-packing/#_structure_alignment_and_padding
  int16_t moduleCompteur;        // 2 Octets
  int8_t moduleTemperature;      // 1 Octet
  int8_t moduleHumidity;         // 1 Octet
  int32_t levelBatterie;         // 4 Octets
  float poids;                   // 4 Octets
  
} SigfoxMessage;
  SigfoxMessage msg;

void  reboot() {
 NVIC_SystemReset();
  while (1);
}

// Déclaration capteurs IR

const int capteur1 = A0;     
const int capteur2 = A0;     
const int capteur3 = A4;     
const int capteur4 = A5;
const int capteur5 = A6;     
const int capteur6 = 0;
const int capteur7 = 1;     
const int capteur8 = 2;
const int capteur9 = 3;     
const int capteur10 = 4;
const int capteur11 = 5;     
const int capteur12 = 7;
const int capteur13 = 8;     
const int capteur14 = 9;
const int capteur15 = 10;     
 
int8_t temp;
uint32_t press;
float   alti;
int8_t  humi;

float masse;
 
int capteurValue1 = 0;
int capteurValue2 = 0;
int capteurValue3 = 0;
int capteurValue4 = 0;
int capteurValue5 = 0;
int capteurValue6 = 0;
int capteurValue7 = 0;
int capteurValue8 = 0;
int capteurValue9 = 0;
int capteurValue10 = 0;
int capteurValue11 = 0;
int capteurValue12 = 0;
int capteurValue13 = 0;
int capteurValue14 = 0;
int capteurValue15 = 0;

int lastState1_1 = LOW;
int lastState1_2 = LOW;
int lastState1_3 = LOW;
int lastState1_4 = LOW;
int lastState1_5 = LOW;
int lastState1_6 = LOW;
int lastState1_7 = LOW;
int lastState1_8 = LOW;
int lastState1_9 = LOW;
int lastState1_10 = LOW;
int lastState1_11 = LOW;
int lastState1_12 = LOW;
int lastState1_13 = LOW;
int lastState1_14 = LOW;
int lastState1_15 = LOW;

unsigned long interval_1 = 0;
unsigned long interval_2 = 0;
unsigned long interval_3 = 0;
unsigned long interval_4 = 0;
unsigned long interval_5 = 0;
unsigned long interval_6 = 0;
unsigned long interval_7 = 0;
unsigned long interval_8 = 0;
unsigned long interval_9 = 0;
unsigned long interval_10 = 0;
unsigned long interval_11 = 0;
unsigned long interval_12 = 0;
unsigned long interval_13 = 0;
unsigned long interval_14 = 0;
unsigned long interval_15 = 0;

unsigned long temporaireHIGH_1= 0;
unsigned long temporaireHIGH_2= 0;
unsigned long temporaireHIGH_3= 0;
unsigned long temporaireHIGH_4= 0;
unsigned long temporaireHIGH_5= 0;
unsigned long temporaireHIGH_6= 0;
unsigned long temporaireHIGH_7= 0;
unsigned long temporaireHIGH_8= 0;
unsigned long temporaireHIGH_9= 0;
unsigned long temporaireHIGH_10= 0;
unsigned long temporaireHIGH_11= 0;
unsigned long temporaireHIGH_12= 0;
unsigned long temporaireHIGH_13= 0;
unsigned long temporaireHIGH_14= 0;
unsigned long temporaireHIGH_15= 0;

unsigned long temporaireLOW_1 = 0;
unsigned long temporaireLOW_2 = 0;
unsigned long temporaireLOW_3 = 0;
unsigned long temporaireLOW_4 = 0;
unsigned long temporaireLOW_5 = 0;
unsigned long temporaireLOW_6 = 0;
unsigned long temporaireLOW_7 = 0;
unsigned long temporaireLOW_8 = 0;
unsigned long temporaireLOW_9 = 0;
unsigned long temporaireLOW_10 = 0;
unsigned long temporaireLOW_11 = 0;
unsigned long temporaireLOW_12 = 0;
unsigned long temporaireLOW_13 = 0;
unsigned long temporaireLOW_14 = 0;
unsigned long temporaireLOW_15 = 0;

// un passage d'abeille est compris entre [borne_inf;borne_sup]; en ms
int borne_inf = 150;
int borne_sup = 600;

// Gestion de la batterie
const int bat = A1;
float valBat = 0;

// Gestion du compteur
int compteurOneDay = 0;
int compteur = 0;
int capteurON = 6;

//int compteurLED = 6;

// déclaration variable de temps
unsigned long time;
unsigned long previous_millis = 0;
unsigned long interval = 0;

void alarmMatch()
{
  Serial.println("Alarm Match!");
  nuit = 1;
  //LowPower.sleep(1 * 60 * 1000);
}

void setup() {
   pinMode(capteurON, OUTPUT);
   digitalWrite(capteurON, HIGH);
   
Serial.begin(115200);

// CLOCK  

  rtc.begin(); // initialize RTC 24H format

  rtc.setTime(hours, minutes, seconds);
  rtc.setDate(day, month, year);

  //Setup de l'alarme de la nuit ! 
  rtc.setAlarmTime(22, 01, 01);
  rtc.enableAlarm(rtc.MATCH_HHMMSS);
  
  rtc.attachInterrupt(alarmMatch);


// poids

scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
scale.set_scale(calibration_factor);
scale.tare();

//BME280
  capteurBME280.settings.commInterface = I2C_MODE; 
  capteurBME280.settings.I2CAddress = 0x77;
  capteurBME280.settings.runMode = 3; 
  capteurBME280.settings.tStandby = 0;
  capteurBME280.settings.filter = 0;
  capteurBME280.settings.tempOverSample = 5 ;
  capteurBME280.settings.pressOverSample = 5;
  capteurBME280.settings.humidOverSample = 5;
 
  Serial.println("Starting BME280... ");
  delay(10);  // attente de la mise en route du capteur. 2 ms minimum
  // chargement de la configuration du capteur
  capteurBME280.begin();

//SigFox
   if (!SigFox.begin()) {
    Serial.println("sigfox error, rebooting");
    reboot();
   }
  delay(100); // wait @ least 30ms after first configuration

  SigFox.end();

// capteurs IR
     
  pinMode(capteur1, INPUT);
  //pinMode(capteur2, INPUT);
  pinMode(capteur3, INPUT);
  pinMode(capteur4, INPUT);
  pinMode(capteur5, INPUT);
  pinMode(capteur6, INPUT);
  pinMode(capteur7, INPUT);
  pinMode(capteur8, INPUT);
  pinMode(capteur9, INPUT);
  pinMode(capteur10, INPUT);
  pinMode(capteur11, INPUT);
  pinMode(capteur12, INPUT);
  pinMode(capteur13, INPUT);
  pinMode(capteur14, INPUT);
  pinMode(capteur15, INPUT);
  pinMode(capteurON, OUTPUT);
  //pinMode(compteurLED, OUTPUT);
  pinMode(bat, INPUT);
}

void loop() {

// La journée on lit met en marche le compteur d'abeilles
if (nuit == 0)
{
    pinMode(capteurON, OUTPUT);
    digitalWrite(capteurON, HIGH);
/*  if(compteur%2 == 0){
  digitalWrite(compteurLED, HIGH);
  
 }
 else{
  digitalWrite(compteurLED, LOW);
 }
 */ 

    lectureCapteursPoids();
    // On met en fonctionnement les capteurs et les timers

    time = millis();
    interval = time-previous_millis;
    //lectureBME280();
    //Serial.println(temp);
    //Serial.println(humi);
    lectureCapteursIR();
 
    // Toute les 10minutes relevé capteurs + envoie
    if(interval > 600000)
    {
      
       previous_millis = time;
       lectureCapteursPoids();
       delay(1000);
       lectureBME280();
       delay(1000);
       lecteurBaterrie();

       //Si la valeur de la batterie est inférieur à 15% -> on met le dispositif en veille le temps que le panneau solaire recharge la batterie.
       if(valBat < 15){
          nuit = 2;
       }
       else{
          envoieSigfox();
       }
   } 
}

else if(nuit == 1)
{
   pinMode(capteurON, OUTPUT);
   digitalWrite(capteurON, LOW);
   //pinMode(capteurON, INPUT);
   
   LowPower.deepSleep(8*60*60*1000); // 8heures de repos
   //LowPower.deepSleep(1800000);
   nuit = 0; //Dès que la nuit est terminé on retourne au travail ! 
}
else
{
  pinMode(capteurON, OUTPUT);
  digitalWrite(capteurON, LOW);
  LowPower.deepSleep(1*60*60*1000); // 1 heure de repos
  nuit = 0;
}

}
