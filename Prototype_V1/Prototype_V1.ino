#include <SigFox.h>
#include "HX711.h"
#include "DFRobot_BME280.h"
#include "Wire.h"

// Capteurs Poids
const int LOADCELL_DOUT_PIN = A2;
const int LOADCELL_SCK_PIN = A3;
HX711 scale;
int calibration_factor = 2250;
//const int tare = 6;

// Capteur BME280
typedef DFRobot_BME280_IIC BME;    // ******** use abbreviations instead of full names ********
BME   bme(&Wire, 0x77);   // select TwoWire peripheral and set sensor address
#define SEA_LEVEL_PRESSURE    1015.0f


// Initialisation Sigfox
typedef struct __attribute__ ((packed)) sigfox_message { // see http://www.catb.org/esr/structure-packing/#_structure_alignment_and_padding
  int16_t moduleCompteur;
  int8_t moduleTemperature;
  int8_t moduleHumidity;
  int32_t moduleCompteurOneDay;
  float poids;
} SigfoxMessage;
  SigfoxMessage msg;

void  reboot() {
 NVIC_SystemReset();
  while (1);
}

// Déclaration capteurs IR

const int capteur1 = A0;     
const int capteur2 = A1;     
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
int8_t   humi;
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
int lastState2_1 = LOW;
int lastState3_1 = LOW;
int lastState4_1 = LOW;
int lastState5_1 = LOW;


int lastState1_2 = LOW;
int lastState2_2 = LOW;
int lastState3_2 = LOW;
int lastState4_2 = LOW;
int lastState5_2 = LOW;


int lastState1_3 = LOW;
int lastState2_3 = LOW;
int lastState3_3 = LOW;
int lastState4_3 = LOW;
int lastState5_3 = LOW;


int lastState1_4 = LOW;
int lastState2_4 = LOW;
int lastState3_4 = LOW;
int lastState4_4 = LOW;
int lastState5_4 = LOW;


int lastState1_5 = LOW;
int lastState2_5 = LOW;
int lastState3_5 = LOW;
int lastState4_5 = LOW;
int lastState5_5 = LOW;


int lastState1_6 = LOW;
int lastState2_6 = LOW;
int lastState3_6 = LOW;
int lastState4_6 = LOW;
int lastState5_6 = LOW;


int lastState1_7 = LOW;
int lastState2_7 = LOW;
int lastState3_7 = LOW;
int lastState4_7 = LOW;
int lastState5_7 = LOW;


int lastState1_8 = LOW;
int lastState2_8 = LOW;
int lastState3_8 = LOW;
int lastState4_8 = LOW;
int lastState5_8 = LOW;


int lastState1_9 = LOW;
int lastState2_9 = LOW;
int lastState3_9 = LOW;
int lastState4_9 = LOW;
int lastState5_9 = LOW;


int lastState1_10 = LOW;
int lastState2_10 = LOW;
int lastState3_10 = LOW;
int lastState4_10 = LOW;
int lastState5_10 = LOW;


int lastState1_11 = LOW;
int lastState2_11 = LOW;
int lastState3_11 = LOW;
int lastState4_11 = LOW;
int lastState5_11 = LOW;


int lastState1_12 = LOW;
int lastState2_12 = LOW;
int lastState3_12 = LOW;
int lastState4_12 = LOW;
int lastState5_12 = LOW;


int lastState1_13 = LOW;
int lastState2_13 = LOW;
int lastState3_13 = LOW;
int lastState4_13 = LOW;
int lastState5_13 = LOW;


int lastState1_14 = LOW;
int lastState2_14 = LOW;
int lastState3_14 = LOW;
int lastState4_14 = LOW;
int lastState5_14 = LOW;


int lastState1_15 = LOW;
int lastState2_15 = LOW;
int lastState3_15 = LOW;
int lastState4_15 = LOW;
int lastState5_15 = LOW;

int compteurOneDay = 0;
int compteur = 0;

// déclaration variable de temps

unsigned long time;
unsigned long previous_millis = 0;
unsigned long interval = 0;


void setup() {
 
Serial.begin(115200);

// poids
scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
scale.set_scale(calibration_factor);
scale.tare();

//BME280
  bme.reset();
  bme.begin();
  delay(100);

//SigFox
   if (!SigFox.begin()) {
    Serial.println("sigfox error, rebooting");
    reboot();
   }
  delay(100); // wait @ least 30ms after first configuration

  SigFox.end();

// capteurs IR
     
  pinMode(capteur1, INPUT);
  pinMode(capteur2, INPUT);
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
  
}

void loop() {
 time = millis();
 interval = time-previous_millis;
 
 lectureCapteursIR();
 
 // Toute les 10minutes relevé capteurs + envoie
 if(interval >= 599960 && interval <=600000){
    Serial.println(time); 
    previous_millis = time;
    lectureCapteursPoids();
    lectureBME280();
    envoieSigfox();
} 
   
// delaie a changer selon la sensibilité que l'on veut sur les capteurs. plus le delai est faible plus les compteurs d'abeilles sera sensible aux perturbations  
delay(40);



}
