/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
*/
#include <SigFox.h>
typedef struct __attribute__ ((packed)) sigfox_message { // see http://www.catb.org/esr/structure-packing/#_structure_alignment_and_padding
  int8_t moduleTemperature;
  int8_t moduleHumidity;
} SigfoxMessage;
  SigfoxMessage msg;

void  reboot() {
 NVIC_SystemReset();
  while (1);
}

unsigned long time;
unsigned long last_time;
unsigned long previous_millis = 0;
unsigned long interval = 0;
int LED = 6;

// Déclaration capteurs
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


int lastState1 = LOW;
int lastState2 = LOW;
int lastState3 = LOW;
int lastState4 = LOW;
int lastState5 = LOW;
int lastState6 = LOW;
int lastState7 = LOW;
int lastState8 = LOW;
int lastState9 = LOW;
int lastState10 = LOW;
int lastState11 = LOW;
int lastState12 = LOW;
int lastState13 = LOW;
int lastState14 = LOW;
int lastState15 = LOW;


int compteur = 0;


int sensorPin = A2;
double sensorValue = 0;
// variables will change:

void setup() {
  // initialize the LED pin as an output:
  Serial.begin(115200);
   if (!SigFox.begin()) {
    Serial.println("sigfox error, rebooting");
    reboot();
}
 delay(100); // wait @ least 30ms after first configuration

  SigFox.end();
  // initialize the pushbutton pin as an input:
  pinMode(LED,OUTPUT);
     
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
  
  pinMode(sensorPin, INPUT);
}

void loop() {
 digitalWrite(LED,LOW);
 time = millis();
 interval = time-previous_millis;
 if(interval >= 59995 && interval <=60005){
    Serial.println(time); 
    previous_millis = time;
    msg.moduleTemperature = compteur;
    msg.moduleHumidity = compteur+1;
  
    SigFox.begin();
    delay(100);
    // clears pending interrupts
    SigFox.status();
    delay(1);

    // send data
    SigFox.beginPacket();
    SigFox.write((uint8_t*)&msg, sizeof(SigfoxMessage));

    // serial.print("status: ");
    Serial.println(SigFox.endPacket());//011217
    // delay(10000);
    SigFox.end();
    delay(500);
 }
 last_time = time;
  // read the state of the pushbutton value:
  sensorValue = analogRead(sensorPin);

  capteurValue1 = digitalRead(capteur1);
  capteurValue2 = digitalRead(capteur2); 
  capteurValue3 = digitalRead(capteur3);
  capteurValue4 = digitalRead(capteur4); 
  capteurValue5 = digitalRead(capteur5);
  capteurValue6 = digitalRead(capteur6); 
  capteurValue7 = digitalRead(capteur7);
  capteurValue8 = digitalRead(capteur8); 
  capteurValue9 = digitalRead(capteur9);
  capteurValue10 = digitalRead(capteur10); 
  capteurValue11 = digitalRead(capteur11);
  capteurValue12 = digitalRead(capteur12); 
  capteurValue13 = digitalRead(capteur13);
  capteurValue14 = digitalRead(capteur14); 
  capteurValue15 = digitalRead(capteur15);
  
 //Serial.print("A1 = ");
 //Serial.println(sensorValue);
delay(10);

   if (capteurValue1 == LOW && lastState1 == HIGH) {
    // turn LED on:
    compteur = compteur + 1;
      Serial.println(compteur);
  } 
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (capteurValue2 == LOW && lastState2 == HIGH) {
    // turn LED on:
    compteur = compteur + 1;
      Serial.println(compteur);

  } 

   if (capteurValue3 == LOW && lastState3 == HIGH) {
    // turn LED on:
    compteur = compteur + 1;
      Serial.println(compteur);
  } 
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (capteurValue4 == LOW && lastState4 == HIGH) {
    // turn LED on:
    compteur = compteur + 1;
      Serial.println(compteur);

  } 
     if (capteurValue5 == LOW && lastState5 == HIGH) {
    // turn LED on:
    compteur = compteur + 1;
      Serial.println(compteur);
  } 
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (capteurValue6 == LOW && lastState6 == HIGH) {
    // turn LED on:
    compteur = compteur + 1;
      Serial.println(compteur);

  } 
     if (capteurValue7 == LOW && lastState7 == HIGH) {
    // turn LED on:
    compteur = compteur + 1;
      Serial.println(compteur);
  } 
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (capteurValue8 == LOW && lastState8 == HIGH) {
    // turn LED on:
    compteur = compteur + 1;
      Serial.println(compteur);

  } 
     if (capteurValue9 == LOW && lastState9 == HIGH) {
    // turn LED on:
    compteur = compteur + 1;
      Serial.println(compteur);
  } 
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (capteurValue10 == LOW && lastState10 == HIGH) {
    // turn LED on:
    compteur = compteur + 1;
      Serial.println(compteur);

  } 
     if (capteurValue11 == LOW && lastState11 == HIGH) {
    // turn LED on:
    compteur = compteur + 1;
      Serial.println(compteur);
  } 
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (capteurValue12 == LOW && lastState12 == HIGH) {
    // turn LED on:
    compteur = compteur + 1;
      Serial.println(compteur);

  } 
     if (capteurValue13 == LOW && lastState13 == HIGH) {
    // turn LED on:
    compteur = compteur + 1;
      Serial.println(compteur);
  } 
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (capteurValue14 == LOW && lastState14 == HIGH) {
    // turn LED on:
    compteur = compteur + 1;
      Serial.println(compteur);

  } 
     if (capteurValue15 == LOW && lastState15 == HIGH) {
    // turn LED on:
    compteur = compteur + 1;
      Serial.println(compteur);
  } 



  lastState1 = capteurValue1;
  lastState2 = capteurValue2;
  lastState3 = capteurValue3;
  lastState4 = capteurValue4;
  lastState5 = capteurValue5;
  lastState6 = capteurValue6;
  lastState7 = capteurValue7;
  lastState8 = capteurValue8;
  lastState9 = capteurValue9;
  lastState10 = capteurValue10;
  lastState11 = capteurValue11;
  lastState12 = capteurValue12;
  lastState13 = capteurValue13;
  lastState14 = capteurValue14;
  lastState15 = capteurValue15;


}
