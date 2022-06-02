#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

File myFile;

void setup(){

  Serial.begin(9600);
  Serial.print("Iniciando SD ...");
  SPI.begin(18, 19, 23, 5); //Iniciamos el Bus SPI
  if (!SD.begin(5)) {
    Serial.println("No se pudo inicializar");
    return;
  }
  Serial.println("inicializacion exitosa");
  myFile = SD.open("/archivo.txt");//abrimos el archivo
  if (myFile) {
    Serial.println("archivo.txt");
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    myFile.close(); //cerramos el archivo
  } 
  else {
  Serial.println("Error al abrir el archivo");
  }
}
void loop(){}