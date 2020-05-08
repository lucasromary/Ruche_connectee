/**
 * Copyright (c) 2009 Andrew Rapp. All rights reserved.
 *
 * This file is part of XBee-Arduino.
 *
 * XBee-Arduino is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * XBee-Arduino is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with XBee-Arduino.  If not, see <http://www.gnu.org/licenses/>.
 */


////////////////////////////// Arduino olimexino //////////////////////////////
#include <XBee.h>
 #include <SoftwareSerial.h>
 SoftwareSerial portTwo(2, 3); // RX, TX
/*
This example is for Series 1 XBee (802.15.4)
Receives either a RX16 or RX64 packet and sets a PWM value based on packet data.
Error led is flashed if an unexpected packet is received
*/

XBee xbee = XBee();
XBeeResponse response = XBeeResponse();
// create reusable response objects for responses we expect to handle 
Rx16Response rx16 = Rx16Response();
Rx64Response rx64 = Rx64Response();

int statusLed = 11;
int errorLed = 12;
int dataLed = 10;

uint8_t option = 0;
uint8_t data = 0;
uint8_t data2 = 0;
uint8_t frame;

void flashLed(int pin, int times, int wait) {
    
    for (int i = 0; i < times; i++) {
      digitalWrite(pin, HIGH);
      delay(wait);
      digitalWrite(pin, LOW);
      
      if (i + 1 < times) {
        delay(wait);
      }
    }
}

void setup() {
  pinMode(statusLed, OUTPUT);
  pinMode(errorLed, OUTPUT);
  pinMode(dataLed,  OUTPUT);
  
  // start serial
  Serial.begin(9600);
  Serial.begin(9600);
  portTwo.begin(9600);
  xbee.setSerial(portTwo);
  
  flashLed(statusLed, 3, 50);
}

// continuously reads packets, looking for RX16 or RX64
void loop() {
    String sample;
    byte test = 0;
    byte test2 = 0;
    byte test3 = 0;
    byte myNumber;
    byte c[4];
    xbee.readPacket();
    //Serial.println("J'attend le packet");
    if (xbee.getResponse().isAvailable()) {
      // got something
      Serial.println("J'ai recu quelque chose !");
      if (xbee.getResponse().getApiId() == RX_16_RESPONSE || xbee.getResponse().getApiId() == RX_64_RESPONSE) {
        // got a rx packet
        
        if (xbee.getResponse().getApiId() == RX_16_RESPONSE) {
                xbee.getResponse().getRx16Response(rx16);
        	option = rx16.getOption();
        	data = rx16.getData(1);
        } 
        else {
        xbee.getResponse().getRx64Response(rx64);
        option = rx64.getOption();

        for (int i = 0; i < rx64.getDataLength(); i++) {
          sample += (char)rx64.getData(i);
          c[i] = rx64.getData(i);
        }
       int data = (c[0] << 8) | c[1];
       Serial.println(data);
        
        }
        
        // TODO check option, rssi bytes    
        flashLed(statusLed, 1, 10);
        
        // set dataLed PWM to value of the first byte in the data
        analogWrite(dataLed, data);

      } else {

      	// not something we were expecting
        flashLed(errorLed, 1, 25);    
      }
    } else if (xbee.getResponse().isError()) {
      //nss.print("Error reading packet.  Error code: ");  
      //nss.println(xbee.getResponse().getErrorCode());
      // or flash error led
    } 
}