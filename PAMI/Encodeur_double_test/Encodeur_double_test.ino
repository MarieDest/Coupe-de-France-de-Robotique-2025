/* Encoder Library - Basic Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.
 */

#include <Encoder.h>

// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder myEnc1(A0, A4);
 Encoder myEnc2(A2, A3);
//   avoid using pins with LEDs attached
int pin_bouton = 10;
int pin_tirette = 9;



void setup() {
  Serial.begin(9600);
 // Serial.println("Basic Encoder Test:");
 /*pinMode(pin_bouton,INPUT);
  pinMode(pin_tirette,INPUT);
Serial.print("état bouton = ");
bool val = digitalRead(pin_bouton);
Serial.println (val);
Serial.print("état tirette ");
bool val2 = digitalRead(pin_tirette);
Serial.println (val2);
*/
}

long oldPosition1  = -999;
 long oldPosition2  = -999;

void loop() {
 // delay(500);
  long newPosition1 = myEnc1.read();
  if (newPosition1 != oldPosition1) {
    oldPosition1 = newPosition1;
    Serial.println(newPosition1);
  } 
    long newPosition2 = myEnc2.read();
   if (newPosition2 != oldPosition2) {
     oldPosition2 = newPosition2;
     Serial.println(newPosition2);
   }



}



