/*
  blink
  LED Blink code for Robo-Sigma Workshop
  
  created 1 Feb 2017
  by Mohit Sharma
*/


void setup(){
  pinMode(13,OUTPUT);
}

void loop(){
  digitalWrite(13,HIGH);
  delay(500);
  digitalWrite(13,LOW);
  delay(500);
}
