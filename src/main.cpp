#include <Arduino.h>
const int trigPin = 9;
const int echoPin = 10;
const int LEDPIN = 6;
const int LDR_PIN = A0;

float duration, distance; 
unsigned long lastTriggerTime = 0;

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


void LED_state(int ambient_light, int proximity){
  int total_ambient_light = 0;

  for(int i = 0; i < 9; i++){
    total_ambient_light += ambient_light;
  }
  int avg_ambient_light = total_ambient_light/10;

  if(proximity < 16){
 lastTriggerTime = millis();
  }

  if(millis() - lastTriggerTime < 60000){
   if(avg_ambient_light >= 200){
     analogWrite(LEDPIN, 0); 
     Serial.println("LED 0");
   }
   else if(avg_ambient_light >= 150){
     analogWrite(LEDPIN, 63);
    Serial.println("LED 63");
   }
   else if(avg_ambient_light >= 100){
    analogWrite(LEDPIN, 127);
    Serial.println("LED 127");
   }
   else if(avg_ambient_light >= 50){
    analogWrite(LEDPIN, 191);
    Serial.println("LED 191");
   }
   else{
    analogWrite(LEDPIN, 255);
    Serial.println("LED 255");
   }
}
else  analogWrite(LEDPIN, 0); 
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
 

  LED_state(avg_ldrValue, avg_distance);
  Serial.println(" ");
  delay(1000);
}