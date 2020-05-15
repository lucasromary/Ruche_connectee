void lectureCapteursIR(){
  
  capteurValue1 = digitalRead(capteur1);
  capteurValue2 = digitalRead(capteur2); 
  capteurValue3 = digitalRead(capteur3);
  capteurValue4 = digitalRead(capteur4); 
  capteurValue5 = digitalRead(capteur5);
  capteurValue6 = digitalRead(capteur6); 
  capteurValue7 = digitalRead(capteur7);
  capteurValue8 = digitalRead(capteur8); 
  capteurValue9 = digitalRead(capteur9);
  capteurValue10 = digitalRead(capteur10); 
  capteurValue11 = digitalRead(capteur11);
  capteurValue12 = digitalRead(capteur12); 
  capteurValue13 = digitalRead(capteur13);
  capteurValue14 = digitalRead(capteur14); 
  capteurValue15 = digitalRead(capteur15);
//Serial.println(capteurValue1);

 /////////////////  CAPTEUR 1 ////////////////////////
if (capteurValue1 == HIGH && lastState1_1 == LOW) {
    temporaireHIGH_1 = time;
  }
  
    //if(capteurValue == LOW && interval > 100 && interval <= 600){
    if(capteurValue1 == LOW && lastState1_1 == HIGH){
      temporaireLOW_1 = time;
    }
    interval_1 = temporaireLOW_1-temporaireHIGH_1;
    //Serial.println(interval);
    
    if(interval_1 > borne_inf && interval_1 < borne_sup){
      compteur = compteur +1;
      Serial.println(compteur);
      temporaireHIGH_1 = 0;
      temporaireLOW_1 = 0;
    }

 /////////////////  CAPTEUR 2 ////////////////////////
if (capteurValue2 == HIGH && lastState1_2 == LOW) {
    temporaireHIGH_2 = time;
  }
  
    //if(capteurValue == LOW && interval > 100 && interval <= 600){
    if(capteurValue2 == LOW && lastState1_2 == HIGH){
      temporaireLOW_2 = time;
    }
    interval_2 = temporaireLOW_2-temporaireHIGH_2;
    //Serial.println(interval);
    
    if(interval_2 > borne_inf && interval_2 < borne_sup){
      compteur = compteur +1;
      Serial.println(compteur);
      temporaireHIGH_2 = 0;
      temporaireLOW_2 = 0;
    }

     /////////////////  CAPTEUR 3 ////////////////////////
if (capteurValue3 == HIGH && lastState1_3 == LOW) {
    temporaireHIGH_3 = time;
  }
  
    //if(capteurValue == LOW && interval > 100 && interval <= 600){
    if(capteurValue3 == LOW && lastState1_3 == HIGH){
      temporaireLOW_3 = time;
    }
    interval_3 = temporaireLOW_3-temporaireHIGH_3;
    //Serial.println(interval);
    
    if(interval_3 > borne_inf && interval_3 < borne_sup){
      compteur = compteur +1;
      Serial.println(compteur);
      temporaireHIGH_3 = 0;
      temporaireLOW_3 = 0;
    }

     /////////////////  CAPTEUR 4 ////////////////////////
if (capteurValue4 == HIGH && lastState1_4== LOW) {
    temporaireHIGH_4 = time;
  }
  
    //if(capteurValue == LOW && interval > 100 && interval <= 600){
    if(capteurValue4 == LOW && lastState1_4 == HIGH){
      temporaireLOW_4 = time;
    }
    interval_4 = temporaireLOW_4-temporaireHIGH_4;
    //Serial.println(interval);
    
    if(interval_4 > borne_inf && interval_4 < borne_sup){
      compteur = compteur +1;
      Serial.println(compteur);
      temporaireHIGH_4 = 0;
      temporaireLOW_4 = 0;
    }

     /////////////////  CAPTEUR 5 ////////////////////////
if (capteurValue5 == HIGH && lastState1_5== LOW) {
    temporaireHIGH_5 = time;
  }
  
    //if(capteurValue == LOW && interval > 100 && interval <= 600){
    if(capteurValue5 == LOW && lastState1_5 == HIGH){
      temporaireLOW_5 = time;
    }
    interval_5 = temporaireLOW_5-temporaireHIGH_5;
    //Serial.println(interval);
    
    if(interval_5 > borne_inf && interval_5 < borne_sup){
      compteur = compteur +1;
      Serial.println(compteur);
      temporaireHIGH_5 = 0;
      temporaireLOW_5 = 0;
    }
    

     /////////////////  CAPTEUR 6 ////////////////////////
if (capteurValue6 == HIGH && lastState1_6== LOW) {
    temporaireHIGH_6 = time;
  }
  
    //if(capteurValue == LOW && interval > 100 && interval <= 600){
    if(capteurValue6 == LOW && lastState1_6 == HIGH){
      temporaireLOW_6 = time;
    }
    interval_6 = temporaireLOW_6-temporaireHIGH_6;
    //Serial.println(interval);
    
    if(interval_6 > borne_inf && interval_6 < borne_sup){
      compteur = compteur +1;
      Serial.println(compteur);
      temporaireHIGH_6 = 0;
      temporaireLOW_6 = 0;
    }
    

     /////////////////  CAPTEUR 7 ////////////////////////
if (capteurValue7 == HIGH && lastState1_7== LOW) {
    temporaireHIGH_7 = time;
  }
  
    //if(capteurValue == LOW && interval > 100 && interval <= 600){
    if(capteurValue7== LOW && lastState1_7 == HIGH){
      temporaireLOW_7 = time;
    }
    interval_7 = temporaireLOW_7-temporaireHIGH_7;
    //Serial.println(interval);
    
    if(interval_7 > borne_inf && interval_7 < borne_sup){
      compteur = compteur +1;
      Serial.println(compteur);
      temporaireHIGH_7 = 0;
      temporaireLOW_7 = 0;
    }
    

     /////////////////  CAPTEUR 8 ////////////////////////
if (capteurValue8 == HIGH && lastState1_8== LOW) {
    temporaireHIGH_8 = time;
  }
  
    //if(capteurValue == LOW && interval > 100 && interval <= 600){
    if(capteurValue8 == LOW && lastState1_8 == HIGH){
      temporaireLOW_8 = time;
    }
    interval_8 = temporaireLOW_8-temporaireHIGH_8;
    //Serial.println(interval);
    
    if(interval_8 > borne_inf && interval_8 < borne_sup){
      compteur = compteur +1;
      Serial.println(compteur);
      temporaireHIGH_8 = 0;
      temporaireLOW_8 = 0;
    }

    
     /////////////////  CAPTEUR 9 ////////////////////////
if (capteurValue9 == HIGH && lastState1_9== LOW) {
    temporaireHIGH_9 = time;
  }
  
    //if(capteurValue == LOW && interval > 100 && interval <= 600){
    if(capteurValue9 == LOW && lastState1_9 == HIGH){
      temporaireLOW_9 = time;
    }
    interval_9 = temporaireLOW_9-temporaireHIGH_9;
    //Serial.println(interval);
    
    if(interval_9 > borne_inf && interval_9 < borne_sup){
      compteur = compteur +1;
      Serial.println(compteur);
      temporaireHIGH_9 = 0;
      temporaireLOW_9 = 0;
    }
    
     /////////////////  CAPTEUR 10 ////////////////////////
if (capteurValue10 == HIGH && lastState1_10 == LOW) {
    temporaireHIGH_10 = time;
  }
  
    //if(capteurValue == LOW && interval > 100 && interval <= 600){
    if(capteurValue10 == LOW && lastState1_10 == HIGH){
      temporaireLOW_10 = time;
    }
    interval_10 = temporaireLOW_10-temporaireHIGH_10;
    //Serial.println(interval);
    
    if(interval_10 > borne_inf && interval_10 < borne_sup){
      compteur = compteur +1;
      Serial.println(compteur);
      temporaireHIGH_10 = 0;
      temporaireLOW_10 = 0;
    }

         /////////////////  CAPTEUR 11 ////////////////////////
if (capteurValue11 == HIGH && lastState1_11 == LOW) {
    temporaireHIGH_11 = time;
  }
  
    //if(capteurValue == LOW && interval > 100 && interval <= 600){
    if(capteurValue11 == LOW && lastState1_11 == HIGH){
      temporaireLOW_11 = time;
    }
    interval_11 = temporaireLOW_11-temporaireHIGH_11;
    //Serial.println(interval);
    
    if(interval_11 > borne_inf && interval_11 < borne_sup){
      compteur = compteur +1;
      Serial.println(compteur);
      temporaireHIGH_11 = 0;
      temporaireLOW_11 = 0;
    }

     /////////////////  CAPTEUR 12 ////////////////////////
if (capteurValue12 == HIGH && lastState1_12 == LOW) {
    temporaireHIGH_12 = time;
  }
  
    //if(capteurValue == LOW && interval > 100 && interval <= 600){
    if(capteurValue12 == LOW && lastState1_12 == HIGH){
      temporaireLOW_12 = time;
    }
    interval_12 = temporaireLOW_12-temporaireHIGH_12;
    //Serial.println(interval);
    
    if(interval_12 > borne_inf && interval_12 < borne_sup){
      compteur = compteur +1;
      Serial.println(compteur);
      temporaireHIGH_12 = 0;
      temporaireLOW_12 = 0;
    }
         /////////////////  CAPTEUR 13 ////////////////////////
if (capteurValue13 == HIGH && lastState1_13 == LOW) {
    temporaireHIGH_13 = time;
  }
  
    //if(capteurValue == LOW && interval > 100 && interval <= 600){
    if(capteurValue13 == LOW && lastState1_13 == HIGH){
      temporaireLOW_13 = time;
    }
    interval_13 = temporaireLOW_13-temporaireHIGH_13;
    //Serial.println(interval);
    
    if(interval_13 > borne_inf && interval_13 < borne_sup){
      compteur = compteur +1;
      Serial.println(compteur);
      temporaireHIGH_13 = 0;
      temporaireLOW_13 = 0;
    }
         /////////////////  CAPTEUR 14 ////////////////////////
if (capteurValue14 == HIGH && lastState1_14 == LOW) {
    temporaireHIGH_14 = time;
  }
  
    //if(capteurValue == LOW && interval > 100 && interval <= 600){
    if(capteurValue14 == LOW && lastState1_14 == HIGH){
      temporaireLOW_14 = time;
    }
    interval_14 = temporaireLOW_14-temporaireHIGH_14;
    //Serial.println(interval);
    
    if(interval_14 > borne_inf && interval_14 < borne_sup){
      compteur = compteur +1;
      Serial.println(compteur);
      temporaireHIGH_14 = 0;
      temporaireLOW_14 = 0;
    }

         /////////////////  CAPTEUR 15 ////////////////////////
if (capteurValue15 == HIGH && lastState1_15 == LOW) {
    temporaireHIGH_15 = time;
  }
  
    //if(capteurValue == LOW && interval > 100 && interval <= 600){
    if(capteurValue15 == LOW && lastState1_15== HIGH){
      temporaireLOW_15= time;
    }
    interval_15 = temporaireLOW_15-temporaireHIGH_15;
    //Serial.println(interval);
    
    if(interval_15 > borne_inf && interval_15 < borne_sup){
      compteur = compteur +1;
      Serial.println(compteur);
      temporaireHIGH_15 = 0;
      temporaireLOW_15 = 0;
    }

    
lastState1_1 = capteurValue1;
lastState1_2 = capteurValue2;
lastState1_3 = capteurValue3;
lastState1_4 = capteurValue4;
lastState1_5 = capteurValue5;
lastState1_6 = capteurValue6;
lastState1_7 = capteurValue7;
lastState1_8 = capteurValue8;
lastState1_9 = capteurValue9;
lastState1_10 = capteurValue10;
lastState1_11 = capteurValue11;
lastState1_12 = capteurValue12;
lastState1_13 = capteurValue13;
lastState1_14 = capteurValue14;
lastState1_15 = capteurValue15;

  
}
