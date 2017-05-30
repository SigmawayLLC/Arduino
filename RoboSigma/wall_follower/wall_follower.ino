/*
  wall_follower
  WallFollwer code for Robo-Sigma Workshop
  
  created 1 Feb 2017
  by Mohit Sharma
*/

//include Motor Shield Library
#include <AFMotor.h>

//Connect Left Motor on M1 and Right Motor on M2
AF_DCMotor mL(1);
AF_DCMotor mR(2);

#define sR A0

void setup(){
  mL.setSpeed(255); //set speed of Left Motor
  mL.run(RELEASE);  //stop motor initially
  mR.setSpeed(255); //set speed of Right Motor  
  mR.run(RELEASE);  //stop motor initially

  pinMode(sR,INPUT);
}

void loop(){
  int sense_right=digitalRead(sR);
  if(sense_right==0){
    mL.run(RELEASE);
    mR.run(FORWARD);
  }
  else{
    mR.run(RELEASE);
    mL.run(FORWARD);
  }
}
