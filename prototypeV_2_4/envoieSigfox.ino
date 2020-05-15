void envoieSigfox(){

    // On construit le message
    msg.moduleTemperature = temp;
    msg.moduleHumidity = humi;
    msg.moduleCompteur = compteur;
    msg.levelBatterie = valBat;
    msg.poids = masse;

    // Print pour debug
    Serial.println("les 5 variables : (levelBatterie, compteur, température, humidité et masse)");
    
    Serial.println(valBat);
    Serial.println(compteur);
    Serial.println(temp);
    Serial.println(humi);
    Serial.println(masse);  

    // envoie du message
    SigFox.begin();
    //SigFox.debug();
    delay(100);
    // clears pending interrupts
    SigFox.status();
    delay(1);

    // On envoie le packet
    SigFox.beginPacket();
    SigFox.write((uint8_t*)&msg, sizeof(SigfoxMessage));

    // On regarde si Sigfox nous a répondu
    int ret = SigFox.endPacket(true);  // attendre la reponse de SigFox
    if (ret > 0)
    {
       Serial.println("No transmission");
    } 
    else
    {
       Serial.println("Transmission ok");
    }
    
    Serial.print("status SIG: ");
    Serial.println(SigFox.status(SIGFOX));
    Serial.print("status ATMEL: ");
    Serial.println(SigFox.status(ATMEL));

// Si SigFox n'a pas recu les données on laisse le compteur avec sa valeur, sinon on le reinitialise à 0.
    if (SigFox.parsePacket()) {
      Serial.println("Response from server:");


        if (SigFox.available()) 
        {
           Serial.print("Mise a 0 du compteur : ");
           compteur = 0;
           Serial.println(compteur);

           Serial.print("0x");
           Serial.print("status sigfoxRead: ");
           Serial.println(SigFox.read(), HEX);
        }
    }
    // On met etaint le module Sigfox
    SigFox.end();
    const byte AlarmHours = rtc.getHours();
    if(AlarmHours >= 22){
      nuit = 1;
    }
}
