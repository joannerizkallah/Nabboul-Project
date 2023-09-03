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
  myservo.attach(8);  // attaches the servo on pin 9 to the servo object
}

void loop() {

  for(int i = 0; i <=2; i +=1) {
 myservo.attach(8);
 myservo2.attach(11);
  for (pos = 160; pos >= 110; pos -= 1) { // goes from 0 degrees to 180 degrees
    myservo2.write(180-pos);
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(7);                       // waits 15ms for the servo to reach the position
  }
  myservo.detach();
  myservo2.detach();

  myservo3.attach(9);
  for(pos=90; pos>=0; pos-=1){
    myservo3.write(pos);
    
    delay(10);
  }
  myservo3.detach();

  myservo4.attach(13);
  for(pos=0;pos<=50;pos+=1){
    myservo4.write(pos);
    delay(10);
  }
  myservo3.detach();
  myservo4.detach();



  myservo3.attach(9);
  for(pos=0; pos<=50; pos+=1){
    myservo3.write(pos);
    
    delay(10);
  }
  myservo3.detach();
  myservo4.attach(13);
  for(pos=50;pos>=0;pos-=1){
    myservo4.write(pos);
    delay(5);
  }
  // myservo3.detach();
  myservo4.detach();
  }
    myservo5.attach(47);
  for(pos=50;pos<=80; pos+=1){
    myservo5.write(pos);
    delay(15);
  }
  myservo5.detach();
  myservo3.attach(9);
  for(pos=50; pos>=35; pos-=1){
    myservo3.write(pos);
    
    delay(10);
  }

  delay(5);
  myservo.attach(8);
  myservo2.attach(11);
  for(pos=110; pos<=160; pos+=1){
    myservo.write(pos);
    myservo2.write(180-pos);
    delay(15);
  }
  exit(0);

}