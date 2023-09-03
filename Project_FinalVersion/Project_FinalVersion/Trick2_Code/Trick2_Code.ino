#include <Servo.h>
const int IN1 = 33;
const int IN2 = 35;
const int ENA = 13;
int pos;
Servo eyebrows;

void setup() {

  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (ENA, OUTPUT);
}

void loop() {
//control speed 
  analogWrite(ENA, 255);
//control direction 
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(10000);
  frown();
  
  exit(0);
}

void frown() {
  eyebrows.attach(47);
  for(pos = 20; pos <= 90; pos+=1) {
    eyebrows.write(pos);
    delay(15);
  }
}