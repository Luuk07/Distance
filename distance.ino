/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://docs.arduino.cc/hardware/

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/Blink/
*/
#include <LiquidCrystal.h>
// the setup function runs once when you press reset or power the board
LiquidCrystal lcd(2,3,4,5,6,7);
const int trigPin = 9;
const int echoPin = 8;

long duration;
int distance;


void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  
  
  lcd.begin(16,2);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  duration = pulseIn(echoPin, HIGH);
}
  


// the loop function runs over and over again forever
void loop() {
  lcd.setCursor(2,0);


  digitalWrite(trigPin, LOW);
  
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(2);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 /2;
  lcd.print("Distance:");

  lcd.println(distance);

 

  
  if(distance < 5)
  {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else 
  {
    digitalWrite(LED_BUILTIN, LOW);
  }





}