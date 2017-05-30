// Click within the image and press
// the left and right mouse buttons to 
// change the value of the rectangle
 import processing.serial.*;
 Serial port;
 void setup(){
 println(Serial.list());

 // Open the port that the Arduino board is connected to (in this case #0)
 // Make sure to open the port at the same speed Arduino is using (9600bps)
 port = new Serial(this, Serial.list()[1], 9600);
 fill(0);
 }
  int click=0;
void draw() {
  rect(25, 25, 50, 50);
}

void mousePressed() {
  if ((mousePressed) && (mouseButton == LEFT) && (click==0)) {
    fill(255);
    click=1;
    port.write('H');
  }
  else if((mousePressed) && (mouseButton == LEFT) && (click==1)){
    fill(0);
    click=0;
    port.write('L');
  }
}