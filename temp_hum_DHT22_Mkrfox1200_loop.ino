#include "DHT.h"
#define DHTPIN 4     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE);

#include <SigFox.h>

#define SleepTime 1 * 60 * 1000  // set delay 1 minute (1 min x 60 seconds x 1000 milliseconds)

 
typedef struct __attribute__ ((packed)) sigfox_message { // see http://www.catb.org/esr/structure-packing/#_structure_alignment_and_padding
  int8_t moduleTemperature;
  int8_t moduleHumidity;
} SigfoxMessage;

// stub message sent
  SigfoxMessage msg;

//=================== utilities ===================
  void  reboot() {
 NVIC_SystemReset();
  while (1);
}
// =================================================


void setup() {

  Serial.begin(115200);

  if (!SigFox.begin()) {
    Serial.println("sigfox error, rebooting");
    reboot();
}

  delay(100); // wait @ least 30ms after first configuration

  SigFox.end();
  

} 
void loop() {
  int humidity = dht.readHumidity();
  float Temperature = dht.readTemperature();
  
  msg.moduleTemperature = (int32_t) (Temperature * 1.0);
  msg.moduleHumidity = humidity;
  
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

  //sleep 15 minutes
  delay(SleepTime);
   }  
