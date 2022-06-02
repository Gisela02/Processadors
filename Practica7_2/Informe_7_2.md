# **INFORME PRÀCTICA 7_2** #
## **CODI** ##
```C++
#include <Arduino.h>

#include "WiFi.h"
#include "Audio.h"  
#include "SD.h"
#include "FS.h"

// Digital I/O used
#define SD_CS          5
#define SPI_MOSI      23
#define SPI_MISO      19
#define SPI_SCK       18
#define I2S_DOUT      25
#define I2S_BCLK      27
#define I2S_LRC       26

Audio audio;

String ssid = "Xiaomi_11_T_Pro";
String password = "f5cbd8a82232";

void setup() {
    pinMode(SD_CS, OUTPUT);      digitalWrite(SD_CS, HIGH);
    SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI);
    Serial.begin(115200);
    SD.begin(SD_CS);
    WiFi.disconnect();
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid.c_str(), password.c_str());
    while (WiFi.status() != WL_CONNECTED) delay(1500);
    audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
    audio.setVolume(21); // 0...21

   audio.connecttoFS(SD, "/superhyper.wav");
}

void loop()
{
    audio.loop();
}

// optional
void audio_info(const char *info){
    Serial.print("info        "); Serial.println(info);
}
void audio_id3data(const char *info){  //id3 metadata
    Serial.print("id3data     ");Serial.println(info);
}
void audio_eof_mp3(const char *info){  //end of file
    Serial.print("eof_mp3     ");Serial.println(info);
}
void audio_showstation(const char *info){
    Serial.print("station     ");Serial.println(info);
}
void audio_showstreamtitle(const char *info){
    Serial.print("streamtitle ");Serial.println(info);
}
void audio_bitrate(const char *info){
    Serial.print("bitrate     ");Serial.println(info);
}
void audio_commercial(const char *info){  //duration in sec
    Serial.print("commercial  ");Serial.println(info);
}
void audio_icyurl(const char *info){  //homepage
    Serial.print("icyurl      ");Serial.println(info);
}
void audio_lasthost(const char *info){  //stream URL played
    Serial.print("lasthost    ");Serial.println(info);
}
void audio_eof_speech(const char *info){
    Serial.print("eof_speech  ");Serial.println(info);
}
```

### **FUNCIONAMENT** ###
En aquesta part de la pràctica s'utilitzarà la comunicació SPI per importar un arxiu d'àudio amb format ".wav" emmagatzemat en una targeta SD. Per codificar les dades de l'àudio farem servir la placa MAX98357 amb protocol I2S, d'aquesta manera tenim tant comunicació SPI com I2S.

El còdi comença amb les definicions de les llibreries necessaries en aquest cas i, de 7 pins necessaris per realitzar les comunicacions SPI i I2S, a part d'un objecte de classe Àudio, on posteriorment s'explica per a què s'utiliza.

En el setup(), inicialitzem les linies de còdi necessaries per establir la comunicació SPI mitjançant el lector de targeta SD. Seguidament, s'inici el *Serial* i, desprès, utilitzem tes funcions definides a la classe Aidio que hem definit abans del setup(). La primera funció és *"audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT)"*, on s'especifiquen els pins de sortida del I2S, la segona és *"audio.setVolume(10)"*, que s'encarrega de delimitar el volum de l'àudio a l'hora de reproduir-lo. Per últim, la tercera funció és *"audio.connecttoFS(SD, "15163726_Hypnocurrency_(Original_Mix).wav")"*, que importa l'arxiu contingut a la targeta SD.

En el loop(), s'inicialitza el loop de l'objecte audio, que conté el arxiu de música que hem emmagatzemat a la SD. 

Finalment, tenim unes funcions que mostren la informació tècnica de l'arxiu .wav per la terminal.

## **VÍDEO DEL FUNCIONAMENT** ##
[https://drive.google.com/file/d/1YvFB61foYFR7mb0UM9SmmK2QemKPncMb/view?usp=sharing](https://drive.google.com/file/d/1YvFB61foYFR7mb0UM9SmmK2QemKPncMb/view?usp=sharing)