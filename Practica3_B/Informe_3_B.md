# **INFORME PRÀCTICA 3_B** #
## **CODI** ##
```c++
        #include "BluetoothSerial.h"  
        #if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)  
        #error Bluetooth is not enabled! Please run `make menuconfig` to and enable it  
        #endif  
        BluetoothSerial SerialBT;  
        void setup() {
            Serial.begin(115200);  
            SerialBT.begin("Placa1");   
            Serial.println("The device started, now you can pair it with bluetooth!");  
        }  
        void loop() {
            if (Serial.available()) { 
                SerialBT.write(Serial.read());
            }  
            if (SerialBT.available()) {
                Serial.write(SerialBT.read());
            }
            delay(20);  
        }
```

## **FUNCIONAMENT** ##
Definim la llibreria BluetoothSerial.h i seguidament definim l'objecte SerialBT d'aquest tipus que ens permetrà establir la connexió amb el nostre mòbil mitjançant la app Serial Bluetooth Terminal.  
En el setup, definim el nostre dispositiu amb el nom Placa1 i fem que tregui pel monitordel Visual Studio que la placa està llesta per realitzar la connexió.  
Seguidament connectem el nostre mòbil a la placa i veiem que tot el que escrivim per aquest, apareixerà en les terminals.

### **VÍDEO DE L'EXECUCIÓ** ###
[https://drive.google.com/file/d/1XmW1ZFinlzO4PqcDksAm1nZPZx8hylLI/view?usp=sharing](https://drive.google.com/file/d/1XmW1ZFinlzO4PqcDksAm1nZPZx8hylLI/view?usp=sharing)
