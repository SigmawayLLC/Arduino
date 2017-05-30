/*
  edge_avoider
  Edge Avoider code for Robo-Sigma Workshop
  
  created 1 Feb 2017
  by Mohit Sharma
*/

//include Motor Shield Library
#include <AFMotor.h>

//Connect Left Motor on M1 and Right Motor on M2
AF_DCMotor mL(1);
AF_DCMotor mR(2);

void setup(){
  Serial.begin(9600);
  mL.setSpeed(170); //set speed of Left Motor
  mL.run(RELEASE);  //stop motor initially
  mR.setSpeed(170); //set speed of Right Motor  
  mR.run(RELEASE);  //stop motor initially

  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
}

void loop(){
  int sense_right=digitalRead(A0);
  int sense_left=digitalRead(A1);
  if((sense_right==0)&&(sense_left==0)){
    Serial.println(sense_right);
    mL.run(FORWARD);
    mR.run(FORWARD);
    
  }
  else if((sense_right==1)&&(sense_left==1)){
    mR.run(RELEASE);
    mL.run(RELEASE);
    delay(1000);
    mR.run(BACKWARD);
    mL.run(BACKWARD);
    delay(1000);
    mR.run(BACKWARD);
    mL.run(FORWARD);
    delay(1000);
    mR.run(FORWARD);
    mL.run(FORWARD);
  }
  else if((sense_right==0)&&(sense_left==1)){
    mR.run(RELEASE);
    mL.run(RELEASE);
    delay(1000);
    mR.run(BACKWARD);
    mL.run(BACKWARD);
    delay(1000);
    mR.run(BACKWARD);
    mL.run(FORWARD);
    delay(1000);
    mR.run(FORWARD);
    mL.run(FORWARD);
  }
  else{
    mR.run(RELEASE);
    mL.run(RELEASE);
    delay(1000);
    mR.run(BACKWARD);
    mL.run(BACKWARD);
    delay(1000);
    mR.run(BACKWARD);
    mL.run(FORWARD);
    delay(1000);
    mR.run(FORWARD);
    mL.run(FORWARD);
  }
}
