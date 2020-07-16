#include <IRremote.h>

#include <ServoTimer1.h>

ServoTimer1 servo1;

int RECV_PIN = 11;  // connect IR receiver to pin 11
IRrecv irrecv(RECV_PIN);
decode_results results;




void setup()
{
 Serial.begin(9600);
 irrecv.enableIRIn(); // Start the receiver

pinMode(13, OUTPUT);  //LED on pin 13

servo1.attach(9);   // servo on pin 9
}

void loop() {
unsigned long codeValue;

/*
Phillips MAGNAVOX VALUES
CHANNEL UP = 32, 2080
CHANNEL DOWN = 33, 2081
VOL UP= 16, 2064
VOL DOWN= 17, 2065
1= 1, 2049
2= 2, 2050
3= 3, 2051
4= 4, 2052
5= 5, 2053
6= 6, 2054
7= 7, 2055
8= 8, 2056
9= 9, 2057
0= 0, 2048
POWER= 12, 2060
MENU= 59, 2107
STATUS= 15, 2063
*/
 
 if (irrecv.decode(&results) ) {
//     Serial.println (results.value, HEX) ;
 
 codeValue = results.value;
 Serial.println(codeValue);

 
 if (codeValue == 59 || codeValue == 2107){ // menu
 digitalWrite(13, HIGH);
 delay(100);
 digitalWrite(13, LOW);  
 }
 
   if (codeValue == 32 || codeValue == 2080){  // channel up
 servo1.write(175);
   }
 
  if (codeValue == 16 || codeValue == 2064){  // vol up
 servo1.write(90);
   }
   
    if (codeValue == 33 || codeValue == 2081){  // channel down
 servo1.write(5);
   }
 
   irrecv.resume(); // Receive the next value
 }




delay(10);
}
