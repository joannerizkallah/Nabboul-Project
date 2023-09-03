#include <Servo.h>
int LED = 53 ; // LED
int digitalPin = 7; // Hall magnetic sensor input 1 (high) or 0 (low)
int analogPin = A0; // analog Pin also available, but not necessary
int digitalInputValue ; // digital readings
int analogInputValue; // analog readings
Servo rightshoulder;
Servo rightelbow;
Servo rightwrist;
Servo leftshoulder;
void setup ()
{
  pinMode (LED, OUTPUT); 
  pinMode (digitalPin, INPUT); 
  pinMode(analogPin, INPUT); //not necessary, but it is interesting to see the analog values
  Serial.begin(9600);
}
void loop ()
{
  detectCard();
}

void detectCard() {
    
  digitalInputValue = digitalRead(digitalPin) ; 
  if (digitalInputValue == HIGH) // When magnet is present, digitalInputValue gets 1 (HIGH) and turns LED on
  {

    digitalWrite (LED, LOW);
    
  }
  else
  {
    
    digitalWrite (LED, HIGH);
  }
  
  //Here you can see the analog values of the sensor
  analogInputValue = analogRead(analogPin);
  Serial.println(analogInputValue); // print analog value
  if(analogInputValue < 100) {
    Serial.println("This is your card");
  }
  delay(100);
    
}
}