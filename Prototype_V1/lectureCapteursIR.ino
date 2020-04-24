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

  // On regarde 5 valeurs dans le temps pour chaque capteurs. Le but est de réduire la monté ducapteur en cas de perturbation ou d'erreur du capteur
   if (capteurValue1 == LOW && lastState1_1 == HIGH && lastState2_1 == HIGH && lastState3_1 == HIGH && lastState4_1 == HIGH && lastState5_1 == HIGH) {
    // turn LED on:
    compteur = compteur + 1;
      Serial.println(compteur);
  } 
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
   if (capteurValue2 == LOW && lastState1_2 == HIGH && lastState2_2 == HIGH && lastState3_2 == HIGH && lastState4_2 == HIGH && lastState5_2 == HIGH) {
    // turn LED on:
    compteur = compteur + 1;
      Serial.println(compteur);
  } 
   if (capteurValue3 == LOW && lastState1_3 == HIGH && lastState2_3== HIGH && lastState3_3 == HIGH && lastState4_3 == HIGH && lastState5_3 == HIGH) {
    // turn LED on:
    compteur = compteur + 1;
      Serial.println(compteur);
  } 
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
    if (capteurValue4 == LOW && lastState1_4 == HIGH && lastState2_4 == HIGH && lastState3_4 == HIGH && lastState4_4 == HIGH && lastState5_4 == HIGH) {
    // turn LED on:
    compteur = compteur + 1;
      Serial.println(compteur);
  } 
   if (capteurValue5 == LOW && lastState1_5 == HIGH && lastState2_5 == HIGH && lastState3_5 == HIGH && lastState4_5 == HIGH && lastState5_5 == HIGH) {
    // turn LED on:
    compteur = compteur + 1;
      Serial.println(compteur);
  } 
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
   if (capteurValue6 == LOW && lastState1_6 == HIGH && lastState2_6 == HIGH && lastState3_6 == HIGH && lastState4_6 == HIGH && lastState5_6 == HIGH) {
    // turn LED on:
    compteur = compteur + 1;
      Serial.println(compteur);
  } 
   if (capteurValue7 == LOW && lastState1_7 == HIGH && lastState2_7 == HIGH && lastState3_7 == HIGH && lastState4_7 == HIGH && lastState5_7 == HIGH) {
    // turn LED on:
    compteur = compteur + 1;
      Serial.println(compteur);
  } 
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
   if (capteurValue8 == LOW && lastState1_8 == HIGH && lastState2_8 == HIGH && lastState3_8 == HIGH && lastState4_8 == HIGH && lastState5_8 == HIGH) {
    // turn LED on:
    compteur = compteur + 1;
  } 
   if (capteurValue9 == LOW && lastState1_9 == HIGH && lastState2_9 == HIGH && lastState3_9 == HIGH && lastState4_9 == HIGH && lastState5_9 == HIGH) {
    // turn LED on:
    compteur = compteur + 1;
      Serial.println(compteur);
  } 
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
   if (capteurValue10 == LOW && lastState1_10 == HIGH && lastState2_10 == HIGH && lastState3_10 == HIGH && lastState4_10 == HIGH && lastState5_10 == HIGH) {
    // turn LED on:
    compteur = compteur + 1;
      Serial.println(compteur);

  } 
   if (capteurValue11 == LOW && lastState1_11 == HIGH && lastState2_11 == HIGH && lastState3_11 == HIGH && lastState4_11 == HIGH && lastState5_11 == HIGH) {
    // turn LED on:
    compteur = compteur + 1;
      Serial.println(compteur);
  } 
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
   if (capteurValue12 == LOW && lastState1_12 == HIGH && lastState2_12 == HIGH && lastState3_12 == HIGH && lastState4_12 == HIGH && lastState5_12 == HIGH) {
    // turn LED on:
    compteur = compteur + 1;
      Serial.println(compteur);
  } 
   if (capteurValue13 == LOW && lastState1_13 == HIGH && lastState2_13 == HIGH && lastState3_13 == HIGH && lastState4_13 == HIGH && lastState5_13 == HIGH) {
    // turn LED on:
    compteur = compteur + 1;
      Serial.println(compteur);
  } 
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
   if (capteurValue14 == LOW && lastState1_14 == HIGH && lastState2_14 == HIGH && lastState3_14 == HIGH && lastState4_14 == HIGH && lastState5_14 == HIGH) {
    // turn LED on:
    compteur = compteur + 1;
      Serial.println(compteur);

  } 
   if (capteurValue15 == LOW && lastState1_15 == HIGH && lastState2_15 == HIGH && lastState3_15 == HIGH && lastState4_15 == HIGH && lastState5_15 == HIGH) {
    // turn LED on:
    compteur = compteur + 1;
      Serial.println(compteur);
  } 


lastState5_1 = lastState4_1;
lastState4_1 = lastState3_1;
lastState3_1 = lastState2_1;
lastState2_1 = lastState1_1;
lastState1_1 = capteurValue1;

lastState5_2 = lastState4_2;
lastState4_2 = lastState3_2;
lastState3_2 = lastState2_2;
lastState2_2 = lastState1_2;
lastState1_2 = capteurValue2;

lastState5_3 = lastState4_3;
lastState4_3 = lastState3_3;
lastState3_3 = lastState2_3;
lastState2_3 = lastState1_3;
lastState1_3 = capteurValue3;

lastState5_4 = lastState4_4;
lastState4_4 = lastState3_4;
lastState3_4 = lastState2_4;
lastState2_4 = lastState1_4;
lastState1_4 = capteurValue4;

lastState5_5 = lastState4_5;
lastState4_5 = lastState3_5;
lastState3_5 = lastState2_5;
lastState2_5 = lastState1_5;
lastState1_5 = capteurValue5;

lastState5_6 = lastState4_6;
lastState4_6 = lastState3_6;
lastState3_6 = lastState2_6;
lastState2_6 = lastState1_6;
lastState1_6 = capteurValue6;

lastState5_7 = lastState4_7;
lastState4_7 = lastState3_7;
lastState3_7 = lastState2_7;
lastState2_7 = lastState1_7;
lastState1_7 = capteurValue7;

lastState5_8 = lastState4_8;
lastState4_8 = lastState3_8;
lastState3_8 = lastState2_8;
lastState2_8 = lastState1_8;
lastState1_8 = capteurValue8;

lastState5_9 = lastState4_9;
lastState4_9 = lastState3_9;
lastState3_9 = lastState2_9;
lastState2_9 = lastState1_9;
lastState1_9 = capteurValue9;

lastState5_10 = lastState4_10;
lastState4_10 = lastState3_10;
lastState3_10 = lastState2_10;
lastState2_10 = lastState1_10;
lastState1_10 = capteurValue10;

lastState5_11 = lastState4_11;
lastState4_11 = lastState3_11;
lastState3_11 = lastState2_11;
lastState2_11 = lastState1_11;
lastState1_11 = capteurValue11;

lastState5_12 = lastState4_12;
lastState4_12 = lastState3_12;
lastState3_12 = lastState2_12;
lastState2_12 = lastState1_12;
lastState1_12 = capteurValue12;

lastState5_13 = lastState4_13;
lastState4_13 = lastState3_13;
lastState3_13 = lastState2_13;
lastState2_13 = lastState1_13;
lastState1_13 = capteurValue13;

lastState5_14 = lastState4_14;
lastState4_14 = lastState3_14;
lastState3_14 = lastState2_14;
lastState2_14 = lastState1_14;
lastState1_14 = capteurValue14;

lastState5_15 = lastState4_15;
lastState4_15 = lastState3_15;
lastState3_15 = lastState2_15;
lastState2_15 = lastState1_15;
lastState1_15 = capteurValue15;

  
}
