
// benötigt folgende Bibliothek https://github.com/opensensinglab/tfmini 
// Bei Verwendung des TF-Mini Plus muss der fix eingespielt werden: https://github.com/opensensinglab/tfmini/issues/9
// hier ist der fix schon aktiv und die sourcen liegen bei.
#include "TFMini.h" 
#include <SoftwareSerial.h>

// wo ist der Lidar angeschlossen 
#define TX A1 // am Sendeleitung am analogen Port 1
#define RX A0 // am Empfangsleitung am analogen Port 2

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
  //if (tfmini.available()) {
    return tfmini.getDistance()*10;
  //}
  //return NO_READ;
}


void setup(){

  // Serielle Schnittstelle für ein paar Ausgaben 
  Serial.begin(115200);
  
  // tf mini initialisieren 
  initDist();
 
}

void loop(){

  long distInMM = getDistMM();
  if(distInMM != NO_READ ){
    Serial.print("Distance is ");
    Serial.print(distInMM);
    Serial.println( "mm");
  }
  delay (100);
}
