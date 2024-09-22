void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
int i = 0;
char someChar[32] = {0};
// when characters arrive over the serial port...
if(Serial.available()) {
 do{
 someChar[i++] = Serial.read();
 delay(3);
 }while (Serial.available() > 0);
 Serial.print("lu ");
 Serial.println(someChar);
}
}
