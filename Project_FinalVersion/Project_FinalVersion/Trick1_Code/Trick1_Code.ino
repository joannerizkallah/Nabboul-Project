#include <Servo.h>

Servo myservo;  // create servo object to control a servo //right elbow
Servo myservo2; //right shoulder
Servo myservo3; // left shoulder
Servo myservo4; // left elbow
Servo myservo5; //playingcard
Servo myservo6; //right wrist
Servo myservo7;

// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  //myservo.attach(9);  // attaches the servo on pin 9 to the servo object

}

void loop() {
  myservo.attach(9);
  for (pos = 40; pos <=50; pos += 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  myservo.detach();
  myservo4.attach(13);
  for (pos = 40; pos <=30; pos += 1) { // goes from 180 degrees to 0 degrees
    myservo4.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  myservo4.detach();
  myservo6.attach(10);
  for(pos=175; pos<=180;pos+=1){
    myservo6.write(pos);
    delay(15);
  }
  myservo6.detach();
  myservo7.attach(47);
  for(pos = 45; pos <= 50; pos +=1) {
    myservo7.write(pos);
    delay(15);
  }
  myservo7.detach();
  myservo2.attach(8);
  for (pos = 30; pos <= 160; pos+= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  // for(pos=180; pos>=110;pos-=1){
  //   myservo2.write(pos);
  //   delay(15);
  // }
  myservo2.detach();
  myservo6.attach(10);
  for(pos=180; pos>=90;pos-=1){
    myservo6.write(pos);
    delay(15);
  }
  myservo6.detach();
  myservo.attach(9);
  for(int i=0;i<2;i++){
    for(pos=90; pos>=0;pos-=1){
    myservo.write(pos);
    delay(7);
  }
  for(pos=0; pos<=90;pos+=1){
    myservo.write(pos);
    delay(7);
  }
  }
  myservo.detach();
  delay(500);
  myservo3.attach(11);
  for (pos = 20; pos <= 140; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo3.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
  for (pos = 140; pos >= 80; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo3.write(pos);              // tell servo to go to position in variable 'pos'
    delay(7);                       // waits 15ms for the servo to reach the position
  }
  myservo3.detach();
  myservo4.attach(13);
  for (pos = 100; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo4.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  myservo4.detach();
  delay(2000);
  myservo5.attach(6);
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo5.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
  myservo5.detach();
  myservo4.attach(13);
  for (pos = 90; pos <=100; pos += 1) { // goes from 180 degrees to 0 degrees
    myservo4.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  myservo4.detach();
  myservo7.attach(47);

  for(pos = 50; pos >= 0; pos -=1) {
    myservo7.write(pos);
    delay(15);
  }
  myservo7.detach();

  myservo4.attach(13);
  for (pos = 100; pos >=0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo4.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  exit(0);
}