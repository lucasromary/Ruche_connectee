void lectureBME280(){
   capteurBME280.settings.commInterface = I2C_MODE; 
  capteurBME280.settings.I2CAddress = 0x77;
  capteurBME280.settings.runMode = 3; 
  capteurBME280.settings.tStandby = 0;
  capteurBME280.settings.filter = 0;
  capteurBME280.settings.tempOverSample = 5 ;
  capteurBME280.settings.pressOverSample = 5;
  capteurBME280.settings.humidOverSample = 5;
  delay(10);  // attente de la mise en route du capteur. 2 ms minimum
  // chargement de la configuration du capteur
  capteurBME280.begin();
  temp = capteurBME280.readTempC();
  humi = capteurBME280.readFloatHumidity();

 }
