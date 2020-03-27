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

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 4;     // the number of the pushbutton pin
const int capteur = 5;     // the number of the pushbutton pin
int capteurValue = 0;
const int ledPin =  7;      // the number of the LED pin
int compteur = 0;
int sensorPin = A0;
double sensorValue = 0;
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int lastState = HIGH;
void setup() {
  // initialize the LED pin as an output:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
    pinMode(capteur, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
   sensorValue = analogRead(sensorPin);
  buttonState = digitalRead(buttonPin);
  capteurValue = digitalRead(capteur);
  //Serial.print("D5 = ");
  //Serial.println(capteurValue);
delay(10);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (capteurValue == LOW && lastState == HIGH) {
    // turn LED on:
    compteur = compteur + 1;
      Serial.println(compteur);
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
  lastState = capteurValue;

}
