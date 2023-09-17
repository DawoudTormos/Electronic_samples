//Michael Klements
//The DIY Life
//27 October 2014

#define currentPin1  A4 
#define currentPin2  A3  
#define currentPin3  A2 
double kilos = 0;
int peakPower = 0;



void setup(){
  Serial.begin(9600);            //Start serial communication
  Serial.println("Running");
 /* pinMode(currentPin1, INPUT);
  pinMode(currentPin2, INPUT);
  pinMode(currentPin3, INPUT);*/
}



unsigned long int s;
void loop(){
 while (Serial.available() > 0){ 
    s = millis();
String str = Serial.readStringUntil('\n');
if (str == "x"){
  measureC();
}

/*unsigned long int e = millis();

Serial.println(e - s);*/

 }
  
}




void measureC(){
  
  int current = 0;
  int maxCurrent1 = 0;
  int maxCurrent2 = 0;
  int maxCurrent3 = 0;


  int current1 = 0 ;
  int current2 = 0 ;
  int current3 = 0 ;

  
 


  



  for (unsigned long endT = millis() + 40; millis() <= endT; ) //Monitors and logs the current input for 200 cycles to determine max and min current
  { 
    current1 = analogRead(currentPin1);//Reads current input and records maximum and minimum current
    current2 = analogRead(currentPin2);
    current3 = analogRead(currentPin3);
    if(current1 >= maxCurrent1){
      maxCurrent1 = current1;
      
      }

 


     if(current2 >= maxCurrent2){
      maxCurrent2 = current2;

  }


     if(current3 >= maxCurrent3){
      maxCurrent3 = current3;

  }

  
 }

 
  
 float RMSCurrent1 = ( abs(maxCurrent1 - 520) * 0.707) /18.15;
 float RMSCurrent2 = ( abs(maxCurrent2 - 520) * 0.707) /18.15;
 float RMSCurrent3 = ( abs(maxCurrent3 - 520) * 0.707) /18.15;
 
 

  
 /*  int RMSPower = 220 * RMSCurrent;  //Calculates RMS Power Assuming Voltage 220VAC, change to 110VAC accordingly
 if (RMSPower > peakPower)
  {
    peakPower = RMSPower;
  }
  kilos = kilos + (RMSPower * (2.05 / 60 / 60 / 1000)); //Calculate kilowatt hours used*/


    String myString = "";
    Serial.print(RMSCurrent1,6);
    Serial.print(",");
    Serial.print(RMSCurrent2,6);
    Serial.print(",");
    Serial.print(RMSCurrent3,6);
    Serial.println(",");

 

 /* Serial.println("\n\n\n");

  
  Serial.println(maxCurrent1);
  Serial.println(maxCurrent2);
  Serial.println(maxCurrent3);
  Serial.println("\n\n\n");*/
  
 /* Serial.println("A");
  Serial.print(RMSPower);
  Serial.println("W");
  Serial.print(kilos);
  Serial.println("kWh");
  Serial.print(peakPower);
  Serial.println("W");*/
}
