#include <Servo.h>

  Servo myservo;  // rightshoulder
  Servo myservo2; //leftshoulder
Servo myservo3; //rightelbow
Servo myservo4; //leftelbow
Servo myservo5; //eyebrow
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int i=0;
void setup() {
  
}

void loop() {
  myservo5.attach(47);
  for(pos=45;pos<=50; pos+=1){
    myservo5.write(pos);
    delay(5);
  }
  myservo5.detach();
 myservo.attach(8);
 myservo2.attach(11);
  for (pos = 160; pos >= 50; pos -= 1) { // goes from 0 degrees to 180 degrees
    myservo2.write(180-pos);
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(20);                       // waits 15ms for the servo to reach the position
  }
  for(pos=50; pos<=110; pos+=1){
    myservo.write(pos);
    myservo2.write(180-pos);
    delay(20);
  }
  for (pos = 110; pos >= 50; pos -= 1) { // goes from 0 degrees to 180 degrees
    myservo2.write(180-pos);
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(20);                       // waits 15ms for the servo to reach the position
  }
  for(pos=50; pos<=140; pos+=1){
    myservo.write(pos);
    myservo2.write(180-pos);
    delay(20);
  }
  for (pos = 140; pos >= 50; pos -= 1) { // goes from 0 degrees to 180 degrees
    myservo2.write(180-pos);
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(20);                       // waits 15ms for the servo to reach the position
  }
  for(pos=80; pos<=160; pos+=1){
    myservo.write(pos);
    myservo2.write(180-pos);
    delay(20);
  }
  for (pos = 160; pos >= 30; pos -= 1) { // goes from 0 degrees to 180 degrees
    myservo2.write(180-pos);
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(20);                       // waits 15ms for the servo to reach the position
  }
  myservo.detach();
  myservo2.detach();
  myservo5.attach(47);
  for(pos=50;pos>=0; pos-=1){
    myservo5.write(pos);
    delay(5);
  }

  exit(0);

}