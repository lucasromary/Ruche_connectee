void lectureBME280(){
 
    temp = bme.getTemperature();
    press = bme.getPressure();
    bme.calAltitude(SEA_LEVEL_PRESSURE, press);
    bme.getHumidity();

 }
