#include "DHT.h"
#define DHTPIN 4     // what pin we're connected to

#define DHTTYPE DHT22   // DHT 22  (AM2302)
#include <SigFox.h>

DHT dht(DHTPIN, DHTTYPE);
float SensorTemperature = 0;
int SensorHumidity = 0;

typedef struct __attribute__ ((packed)) sigfox_message { // see http://www.catb.org/esr/structure-packing/#_structure_alignment_and_padding
  int8_t moduleTemperature;
  int8_t moduleHumidity;
} SigfoxMessage;

// stub for message which will be sent
SigfoxMessage msg;

// =================== UTILITIES ===================
void reboot() {
  NVIC_SystemReset();
  while (1);
}
// =================================================


void setup() {
  Serial.begin(115200);
  while (!Serial);


  if (!SigFox.begin()) {
    Serial.println("SigFox error, rebooting");
    reboot();
  }

  delay(100); // Wait at least 30ms after first configuration

  // Enable debug prints and LED indication
  SigFox.debug();
  int humidity = dht.readHumidity();
  float Temperature = dht.readTemperature();
  // Read and convert the module temperature
  msg.moduleTemperature = (int32_t) (Temperature * 1.0);
  msg.moduleHumidity = humidity;
  Serial.print("DHT temp: ");
  Serial.print(msg.moduleTemperature, HEX); // display what we will send in Hexadecimal
  Serial.print(" (");
  Serial.print(msg.moduleTemperature); // display what we will send in Decimal
  Serial.println(" deg C)");

  Serial.print("DHT hum: ");
  Serial.print(msg.moduleHumidity, HEX); // display what we will send in Hexadecimal
  Serial.print(" (");
  Serial.print(msg.moduleHumidity); // display what we will send in Decimal
  Serial.println(" %)");
  
  // Clears all pending interrupts
  SigFox.status();
  delay(1);

  // Send the data
  SigFox.beginPacket();
  SigFox.write((uint8_t*)&msg, sizeof(SigfoxMessage));

  Serial.print("Status: ");
  Serial.println(SigFox.endPacket());

  SigFox.end();
}

void loop() {}
