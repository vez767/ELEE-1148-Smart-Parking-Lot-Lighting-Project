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

int distance_filter(){
  distance = (duration*.0343)/2;
  delay(50);
  int total_distance = 0;

  for(int i = 0; i < 3; i++){
    total_distance += distance;
  }
  int avg_dis = total_distance/3;
  return avg_dis;
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

  int avg_distance = distance_filter();

  Serial.print("Distance: ");
  Serial.println(avg_distance);

  int avg_ldrValue = digital_filter();

  Serial.print("LDR Value: ");
  Serial.println(avg_ldrValue);
  Serial.println(" ");

  delay(1000);
  analogWrite(LEDPIN, 255);   
 
}