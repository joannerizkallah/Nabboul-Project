#include <Servo.h>
#include <millisDelay.h>
int LED = 53 ; // LED
int digitalPin = 7; // Hall magnetic sensor input 1 (high) or 0 (low)
int analogPin = A0; // analog Pin also available, but not necessary
int digitalInputValue ; // digital readings
int analogInputValue; // analog readings
int red;
int green;
int blue;
Servo myservo;  // create servo object to control a servo
Servo myservo2;
Servo myservo3; 
Servo eyebrows;
// twelve servo objects can be created on most boards
#define S0 46 //PWM
#define S1 2  //PWM
#define S2 4 //PWM
#define S3 5 //PWM
#define sensorOut 3 //PWM 
millisDelay d;
int frequency = 0;

int pos = 0;    // variable to store the servo position

void setup() {
  pinMode (LED, OUTPUT); 
  pinMode (digitalPin, INPUT); 
  pinMode(analogPin, INPUT); //not necessary, but it is interesting to see the analog values
  Serial.begin(9600);
  //myservo.attach(10);  //Wrist
  //myservo3.attach(9); //Right elbow
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
  d.start(30000);
}

void loop() {
  eyebrows.attach(47);
  for(pos = 40; pos <= 50; pos +=1) {
    eyebrows.write(pos);
    delay(15);
  }
  eyebrows.detach();
  while(!(red > 200 && green > 200 && blue <50)) {
    detectColor();
    
  }

  eyebrows.attach(47);
  for(pos = 50; pos >=0; pos -=1) {
    eyebrows.write(pos);
    delay(15);
  }
  eyebrows.detach();
  delay(40000);
  myservo2.attach(8); //right shoulder 
  for (pos = 140; pos >= 86; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(20);                       // waits 15ms for the servo to reach the position
  }
  myservo.attach(10);
  for (pos = 180; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(20);                       // waits 15ms for the servo to reach the position
  }
  myservo.detach();
  myservo3.attach(9); //Right elbow
    for (pos = 100; pos >=0; pos -= 1) { // goes from 180 degrees to 0 degrees
    detectCard();
    myservo3.write(pos);              // tell servo to go to position in variable 'pos'
    delay(100);                       // waits 15ms for the servo to reach the position
  }
  exit(0);

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
void detectColor(){
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  red = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  red = map(red, 25,72,255,0);
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(red);//printing RED color frequency
  Serial.print("  ");
  delay(100);

  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  green = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  green = map(green, 30,90,255,0);
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(green);//printing RED color frequency
  Serial.print("  ");
  delay(100);

  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  blue = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  blue = map(blue, 25,70,255,0);
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(blue);//printing RED color frequency
  Serial.println("  ");
  delay(100);
  if(red > 200 && green <0 && blue<20) {
    Serial.println("I see is red");
    digitalWrite(LED,LOW);
  }

  else if(red < -300 && green < -250 && blue < -250) {
    Serial.println("Your card is black");
    digitalWrite (LED, HIGH);
  }
   else {
     digitalWrite (LED, LOW);
   }
}
