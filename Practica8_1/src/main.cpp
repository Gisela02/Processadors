#include <Arduino.h>

char valor;
char valor2;

void setup() {

  Serial.begin(115200);
  Serial2.begin(115200);
  
}

void loop() {

  if(Serial.available()){
    valor = Serial.read();
    Serial.println("Primer valor");
    Serial2.write(valor);

    delay(2);

    if(Serial2.available()){
      Serial.println("Segundo valor");
      valor2 = Serial2.read();
      Serial.write(valor2);
    }
  }
}