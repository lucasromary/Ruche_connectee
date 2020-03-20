/*
  Input Pull-up Serial

  This example demonstrates the use of pinMode(INPUT_PULLUP). It reads a digital
  input on pin 2 and prints the results to the Serial Monitor.

  The circuit:
  - momentary switch attached from pin 2 to ground
  - built-in LED on pin 13

  Unlike pinMode(INPUT), there is no pull-down resistor necessary. An internal
  20K-ohm resistor is pulled to 5V. This configuration causes the input to read
  HIGH when the switch is open, and LOW when it is closed.

  created 14 Mar 2012
  by Scott Fitzgerald

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/InputPullupSerial
*/
int sensorPin = A0;
int sensorValue = 0;
int lastValue = 0;
int compteur = 0;

int p1 = 0;
int p2 = 0;
int p3 = 0;
int p4 = 0;
int p5 = 0;
int p6 = 0;
int p7 = 0;
int p8 = 0;
int p9 = 0;
int p10 = 0;

double moyenne = 0;
void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(5, INPUT);
  pinMode(4, OUTPUT);

}

void loop() {

  p1 = analogRead(sensorPin);
  moyenne = (p1+p2+p3+p4+p5+p6+p7+p8+p9+p10)/10;
  p10 = p9;
  p9 = p8;
  p8 = p7;
  p7 = p6;
  p6 = p5;
  p5 = p4;
  p4 = p3;
  p3 = p2;
  p2 = p1;
  //read the pushbutton value into a variable
  sensorValue = analogRead(sensorPin);
  sensorValue = moyenne;
  //print out the value of the pushbutton
  Serial.println(sensorValue);
  //delay(10);
  //Serial.println(moyenne);
  // Keep in mind the pull-up means the pushbutton's logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed. Turn on pin 13 when the
  // button's pressed, and off when it's not:
  if (sensorValue >= 600 && lastValue <= 600) {
    digitalWrite(4, HIGH);
    compteur = compteur +1;

  //Serial.println(compteur);
  } else {
    digitalWrite(4, LOW);
  }
  lastValue = sensorValue;
}
