#include "HX711.h"
#include "DHT.h"
#define DHTPIN 4     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE);
float SensorTemperature = 0;
int SensorHumidity = 0;

const int LOADCELL_DOUT_PIN = A2;
const int LOADCELL_SCK_PIN = A3;
HX711 scale;

#include <SigFox.h>

#define SleepTime 1 * 10 * 1000  // set delay 1 minute (1 min x 60 seconds x 1000 milliseconds)

const int tare = 6;

 
typedef struct __attribute__ ((packed)) sigfox_message { // see http://www.catb.org/esr/structure-packing/#_structure_alignment_and_padding
  int8_t moduleTemperature;
  float poids;
} SigfoxMessage;

// stub message sent
  SigfoxMessage msg;

void  reboot() {
 NVIC_SystemReset();
  while (1);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  if (!SigFox.begin()) {
    Serial.println("sigfox error, rebooting");
    reboot();
}

  delay(100); // wait @ least 30ms after first configuration

  SigFox.end();

pinMode(tare,INPUT);
scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
scale.set_scale(2280.f);
scale.tare();
}

void loop() {
  // put your main code here, to run repeatedly:

float Temperature = dht.readTemperature();
  
msg.moduleTemperature = (int32_t) (Temperature * 1.0);
float masse = scale.get_units()*0.1;
msg.poids = 12.7;


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

  

delay(SleepTime);
}
