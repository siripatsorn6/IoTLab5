#include "Arduino.h"
#include <PCF8574.h>
#include <Wire.h>
int right = LOW, left = LOW, i = 0;
PCF8574 expander(0x20);
void setup(){
  expander.begin();
  for(int i=0;i<4;i++)
    expander.pinMode(i, OUTPUT);
  for(int i=4;i<6;i++)
    expander.pinMode(i, INPUT);
}
void loop(){
if(expander.digitalRead(4) == HIGH){
  left = HIGH;
  right = LOW;
}else if(expander.digitalRead(5) == HIGH){
  right = HIGH;
  left = LOW;
}
if(left == HIGH){
  i--;
  expander.digitalWrite(i, HIGH);
  delay(200);
  expander.digitalWrite(i, LOW);
  if(i<0) i=4;
}else if(right == HIGH){
    i++;
    expander.digitalWrite(i, HIGH);
    delay(200);
    expander.digitalWrite(i, LOW);
    if(i>2) i=-1;
  }
}
