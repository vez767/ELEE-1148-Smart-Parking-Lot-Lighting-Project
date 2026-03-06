#include <Arduino.h>
const int trigPin = 9;
const int echoPin = 10;
const int LEDPIN = 6;
const int LDR_PIN = A0;

float duration, distance; 

int digital_filter(){
  long total_ldrValue = 0;

  for(int i = 0; i < 15; i++){
    total_ldrValue += analogRead(LDR_PIN);
    delay(10);
  }
  int avg = total_ldrValue/15;
  return avg;
}


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
  int avg_ldrValue = digital_filter();
  Serial.print("LDR Value: ");
  Serial.println(avg_ldrValue);
  delay(1000);
  analogWrite(LEDPIN, 255);   
 
}