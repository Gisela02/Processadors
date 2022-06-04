#include <Arduino.h>

#define LED 16
unsigned long myTime;
#define interruptPin 0
void serialPin();
void QuitarPin();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), serialPin, FALLING);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Serial.println(myTime); // prints time since program started
  myTime = millis();
  while(millis()<myTime+1000);
 // delay(1000);         
  digitalWrite(LED,HIGH);
  Serial.println("ON");
  myTime = millis();
  while(millis()<myTime+500);
  //delay(500);
  digitalWrite(LED,HIGH);
  Serial.println("OFF");
  digitalWrite(LED,LOW);
  myTime = millis();
  while(millis()<myTime+500);
  //delay(500);

}

void serialPin(){
  Serial.println("Pulsado");
}

void QuitarPin(){
detachInterrupt(interruptPin);
}