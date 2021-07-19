/** TF-Mini Testprogramm , checks if the distance is lower than an reference value.
* Needs the followint libs https://github.com/opensensinglab/tfmini 
* in case of any trouble modify the lib with: https://github.com/opensensinglab/tfmini/issues/9
* In the source in this directory the fix is already applied.
* Created by Stefan Fambach under GPL v3
* Visit www.fambach.net if you want.
 */

#include "TFMini.h" 
#include <SoftwareSerial.h>

// wo ist der Lidar angeschlossen 
#define TX A1 // am Sendeleitung am analogen Port 1
#define RX A0 // am Empfangsleitung am analogen Port 2


#define ALARM_DIST 1000 // mm - wenn die distanz in mm kleiner dem Wert ist gib alarm
#define ALARM_PIN A5   // welcher pin soll auf High gesetzt werden wenn ein alarm ausgelöst wurde
#define ALRAM_ON HIGH     // definiere ob der ausgang an oder aus bei alarm sein soll 
#define ALARM_OFF LOW   // definiere ob der ausgang an oder aus bei kein alarm sein soll 

// Objekt für SW Serial erstellen
SoftwareSerial mySerial(TX, RX);

// TF mini objekt erstellen.
TFMini tfmini;


// initialise alles
void initDist() {
  // init the sensor
  mySerial.begin(TFMINI_BAUDRATE); // evtl habt ihr eine andere boud rate hiermit mal spielen sollte es nicht klappen
  tfmini.begin(&mySerial); // verheiraten der der Schnittstelle und des TF mini
}

long getDistMM() {
     return tfmini.getDistance()*10;
  
}


void setup(){

  // Serielle Schnittstelle für ein paar Ausgaben 
  Serial.begin(115200);
  
  // tf mini initialisieren 
  initDist();

  // init alarm pin
  pinMode(ALARM_PIN, OUTPUT);
 
}

void loop(){

  long distInMM = getDistMM();

  {
    Serial.print("Distance is ");
    Serial.print(distInMM);
    Serial.print( "mm");
    if(distInMM < ALARM_DIST) {
      Serial.print( " [ALARM ON]");
      digitalWrite(ALARM_PIN, ALRAM_ON);
    }else {
      Serial.print( " [ALARM OFF]");
      digitalWrite(ALARM_PIN, ALARM_OFF);
    }

    Serial.println();
    
  }
  delay (100);
}
