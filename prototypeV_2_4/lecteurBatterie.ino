void lecteurBaterrie(){

    valBat = analogRead(bat);
    valBat= (valBat*3.3/1024)*2;
    valBat = 66.66*valBat-180; //On met sur la valeur de la batterie en % -> 0% = 2.7V / 100% = 4.2V

    //int32_t valBat2 = valBat;
    //Serial.println(valBat2);
}
