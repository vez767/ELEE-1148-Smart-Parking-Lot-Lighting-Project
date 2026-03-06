#include <Arduino.h>
const int trigPin = 9;
const int echoPin = 10;
const int LEDPIN = 6;

float duration, distance; 

void setup() {
Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);   
pinMode(LEDPIN, OUTPUT);
}

void loop() {

digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  delay(500);
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);

  analogWrite(LEDPIN, 255);   
 
}