

#include <RCSwitch.h>
#include <EEPROM.h>

#define EEPROM_SIZE 12

RCSwitch mySwitch = RCSwitch();

const   int onBtn = 13;
const   int offBtn = 14;

const  int relayPin = 4;


long unsigned int on = 1000;
long unsigned int off = 2000;
int stage = 0;
bool relay = 0;

unsigned int timeToReset =  3000;
unsigned long int resetTime = 0;


void setup() {

  pinMode(onBtn , INPUT_PULLUP);
  pinMode(offBtn , INPUT_PULLUP);
  pinMode(relayPin , OUTPUT);

  Serial.begin(115200);
     Serial.println("\n\nstarting pin mode");
  mySwitch.enableReceive(5);

    EEPROM.begin(EEPROM_SIZE);

     EEPROM.get(0, on);
     EEPROM.get(4, off);
       EEPROM.end();

     Serial.println("starting...");
     Serial.println("off code: " + off);
      Serial.println("on code: " + on);


}

void loop() {


  if (mySwitch.available()) {
    
    Serial.println("Received Something" );
    Serial.println( mySwitch.getReceivedValue());
 /*   Serial.print( mySwitch.getReceivedValue() );
    Serial.print(" / ");
    Serial.print( mySwitch.getReceivedBitlength() );
    Serial.print("bit ");
    Serial.print("Protocol: ");
    Serial.println( mySwitch.getReceivedProtocol() );*/





    if(  !digitalRead(onBtn)  ){

      on = mySwitch.getReceivedValue();

    EEPROM.begin(EEPROM_SIZE);
    EEPROM.put(0, on);
    EEPROM.end();
    Serial.print("Saved the ON button with a new value: ");
    Serial.println(on);

       


    }else if(  !digitalRead(offBtn)  ){

      off = mySwitch.getReceivedValue();

    EEPROM.begin(EEPROM_SIZE);
    EEPROM.put(4, off);
     EEPROM.end();


    Serial.print("Saved the OFF button with a new value: ");
    Serial.println(off);


    } else if( stage == 0 ){

      if(mySwitch.getReceivedValue() == on ){
        stage = 1;
        resetTime = millis() + timeToReset ;
        Serial.println("stage 1");
      }
      
    } else if( stage == 1 ){

      if(mySwitch.getReceivedValue() == off ){
        stage = 2;
        resetTime = millis() + timeToReset ;
        Serial.println("stage 2");

      }
      
    }else if( stage == 2 ){ 

      if(mySwitch.getReceivedValue() == on ){
        stage = 3;
        resetTime =0 ;
        Serial.println("stage 3");

      }
      
    }




    


    

    mySwitch.resetAvailable();
  }









  if( stage == 3 ){

        stage = 0;
        resetTime =0;
        relay ? relay = 0 : relay = 1 ;

        digitalWrite(relayPin , relay);
        Serial.println("back to stage 0 after toggling");

      
    } 

  if(resetTime != 0 && millis() > resetTime   ){
              stage = 0;
        resetTime =0;
        Serial.println("back to stag 0 after time waited for next signal ended");
    }









}
