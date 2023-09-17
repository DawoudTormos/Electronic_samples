




//////////////////////////

const int sensorPin_1 = A0;

const int ledPin_1 = 11;
int ledPinVal_1 = 0; 

//////////////////////////

const int sensorPin_2 = A1;

const int ledPin_2 = 9;
int ledPinVal_2 = 0;

//////////////////////////

const int sensorPin_3 = A2;

const int ledPin_3 = 6;
int ledPinVal_3 = 0;

//////////////////////////

const int sensorPin_4 = A3;

const int ledPin_4 = 3;
int ledPinVal_4 = 0;





const int sensorPin_5 = A5;

const int ledPin_5 = 5;
int ledPinVal_5 = 0;









int brightness = 0;   // Initialize the brightness level (0-255)

void setup() {
  pinMode(ledPin_1, OUTPUT); // Set the LED pin as an OUTPUT
  pinMode(sensorPin_1, INPUT);

  pinMode(ledPin_2, OUTPUT); // Set the LED pin as an OUTPUT
  pinMode(sensorPin_2, INPUT);

  pinMode(ledPin_3, OUTPUT); // Set the LED pin as an OUTPUT
  pinMode(sensorPin_3, INPUT);

  pinMode(ledPin_4, OUTPUT); // Set the LED pin as an OUTPUT
  pinMode(sensorPin_4, INPUT);


  
  pinMode(ledPin_5, OUTPUT); // Set the LED pin as an OUTPUT
  pinMode(sensorPin_5, INPUT);
}

void loop() {


    delay(2);  






if( digitalRead(sensorPin_1)){
  ledPinVal_1 = 255;


}else{
    if(ledPinVal_1 == 0){

    }else{
      ledPinVal_1 -= 1;
    }
    
}
  analogWrite(ledPin_1, ledPinVal_1);











if( digitalRead(sensorPin_2)){
  ledPinVal_2 = 255;


}else{
    if(ledPinVal_2 == 0){

    }else{
      ledPinVal_2 -= 1;
    }
    
}
  analogWrite(ledPin_2, ledPinVal_2);






if( digitalRead(sensorPin_3)){
  ledPinVal_3 = 255;


}else{
    if(ledPinVal_3 == 0){

    }else{
      ledPinVal_3 -= 1;
    }
    
}
  analogWrite(ledPin_3, ledPinVal_3);










  if( digitalRead(sensorPin_4)){
  ledPinVal_4 = 255;


}else{
    if(ledPinVal_4 == 0){

    }else{
      ledPinVal_4 -= 1;
    }
    
}
  analogWrite(ledPin_4, ledPinVal_4);






  if( digitalRead(sensorPin_5)){
  ledPinVal_5 = 255;


}else{
    if(ledPinVal_5 == 0){

    }else{
      ledPinVal_5 -= 1;
    }
    
}
  analogWrite(ledPin_5, ledPinVal_5);




  

/*
  // Fade the LED in
  for (int i = 0; i <= 255; ) {
    analogWrite(ledPin, i); // Set the LED brightness (0-255)
    delay(10);             // Adjust the delay for the desired fade rate
    i++;
  }



  // Fade the LED out
  for (int i = 255; i >= 0; i--) {
    analogWrite(ledPin, i); // Set the LED brightness (0-255)
    delay(10);             // Adjust the delay for the desired fade rate
  }
*/


}