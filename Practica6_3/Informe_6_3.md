# **INFORME PRÀCTICA 6_3** #
### **CODI** ###
```c++
        #include <Arduino.h>

        #include "pitches.h"
        #include "EasyBuzzer.h"
        #define BUZZZER_PIN  16 // ESP32 pin GIOP18 connected to piezo buzzer

        int melody[] = {
            NOTE_E5, NOTE_E5, NOTE_E5,
            NOTE_E5, NOTE_E5, NOTE_E5,
            NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
            NOTE_E5,
            NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
            NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
            NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
            NOTE_D5, NOTE_G5,
            NOTE_E5, NOTE_E5, NOTE_E5,
            NOTE_E5, NOTE_E5, NOTE_E5,
            NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
            NOTE_E5,
            NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
            NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
            NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
            NOTE_D5, NOTE_G5
        };

        int noteDurations[] = {
            8, 8, 4,
            8, 8, 4,
            8, 8, 8, 8,
            2,
            8, 8, 8, 8,
            8, 8, 8, 16, 16,
            8, 8, 8, 8,
            4, 4,
            8, 8, 4,
            8, 8, 4,
            8, 8, 8, 8,
            2,
            8, 8, 8, 8,
            8, 8, 8, 16, 16,
            8, 8, 8, 8,
            4, 4
        };

        void setup() {
            ledcSetup(0, 1E5, 12);
            ledcAttachPin(16,0);
            int size = sizeof(noteDurations) / sizeof(int);
            for (int thisNote = 0; thisNote < size ; thisNote++) {
                int noteDuration = 1000 / noteDurations[thisNote];
                ledcWriteTone(0, melody[thisNote]);
                delay(noteDuration);
                
                int pauseBetweenNotes = noteDuration * 1.30;
                delay(pauseBetweenNotes);
                
                ledcWriteTone(0,0);
            }
        }

        void loop() {
        }
```

## **FUNCIONAMENT** ###
Per aquesta part, hem d'incloure la llibreria pitches.h ja que en aquesta estan tots els valors de to de les notes típiques.  
A continuació, en el *int melody[]* definim totes les notes que volem que sonin en el buzzer i en el *int noteDurations[]* trobem, com bé indica el nom de la funció, la duració de cada nota.
Finalment, en el setup() cridem les funcions anteriors i afegim delays a les notes per tal de que no es col·lapsi i dongui temps a executar-se.  

## **VIDEO DE L'EXECUCIÓ** ##
[https://drive.google.com/file/d/1PQo-at_zF5othMcq0Blh2kY8oM-5wCgJ/view?usp=sharing](https://drive.google.com/file/d/1PQo-at_zF5othMcq0Blh2kY8oM-5wCgJ/view?usp=sharing)