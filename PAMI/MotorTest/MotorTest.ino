// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

AF_DCMotor moteur1(1);
AF_DCMotor moteur2(2);
void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");

  // turn on motor
  moteur1.setSpeed(200);
                                                   
  moteur1.run(RELEASE);
    // turn on motor
  moteur2.setSpeed(200);
                                                   
  moteur2.run(RELEASE);
}

void loop() {

  
  moteur1.run(FORWARD);

  moteur1.setSpeed(255);  
    
   
  moteur2.run(FORWARD);

  moteur2.setSpeed(255);  
    delay(1000);

    moteur2.run(RELEASE);
    moteur1.run(RELEASE);


   moteur1.run(BACKWARD);

  moteur1.setSpeed(255);  
    
   
  moteur2.run(BACKWARD);

  moteur2.setSpeed(255);  


  delay(1000); 
    moteur2.run(RELEASE);
    moteur1.run(RELEASE);
  
}
