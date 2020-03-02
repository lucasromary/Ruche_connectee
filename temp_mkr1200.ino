
#include <SigFox.h>
typedef struct __attribute__ ((packed)) sigfox_message { // see http://www.catb.org/esr/structure-packing/#_structure_alignment_and_padding
  int16_t moduleTemperature;
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

  // Read and convert the module temperature
  msg.moduleTemperature = (int32_t) (SigFox.internalTemperature() * 100.0); // température 1/100th of degrees

  Serial.print("Internal temp: ");
  Serial.print(msg.moduleTemperature, HEX); // display what we will send in Hexadecimal
  Serial.print(" (");
  Serial.print(msg.moduleTemperature); // display what we will send in Decimal
  Serial.println(" x100 deg C)");

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
