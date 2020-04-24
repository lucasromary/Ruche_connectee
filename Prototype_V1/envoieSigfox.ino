void envoieSigfox(){

    

    compteurOneDay = compteurOneDay + compteur;

    // Construction du message
    
    msg.moduleTemperature = temp;
    msg.moduleHumidity = humi;
    msg.moduleCompteur = compteur;
    msg.moduleCompteurOneDay = compteurOneDay;
    msg.poids = masse;

    // Print pour debug
    Serial.println("les 5 variables : (CompteurOneDay, compteur_interval, température, humidité et poids)");
    
    Serial.println(compteurOneDay);
    Serial.println(compteur);
    Serial.println(temp);
    Serial.println(humi);
     Serial.println(masse);  

    // envoie du message
    SigFox.begin();
    SigFox.debug();
    delay(100);
    // clears pending interrupts
    SigFox.status();
    delay(1);

    SigFox.beginPacket();
    SigFox.write((uint8_t*)&msg, sizeof(SigfoxMessage));

    int ret = SigFox.endPacket(true);  // attendre la reponse de SigFox
    if (ret > 0) {
      Serial.println("No transmission");
    } else {
    Serial.println("Transmission ok");
    }
    Serial.print("status SIG: ");
    Serial.println(SigFox.status(SIGFOX));
    Serial.print("status ATMEL: ");
    Serial.println(SigFox.status(ATMEL));

// Si SigFox n'a pas recu les données on laisse le compteur avec sa valeur, sinon on le reinitialise à 0.
    if (SigFox.parsePacket()) {
      Serial.println("Response from server:");


        if (SigFox.available()) {
        Serial.print("Mise a 0 du compteur : ");
        compteur = 0;
        Serial.println(compteur);

        Serial.print("0x");
        Serial.print("status sigfoxRead: ");
        Serial.println(SigFox.read(), HEX);
        }
    }
    else{
      compteurOneDay = compteurOneDay-compteur;
    }

    SigFox.end();

}
