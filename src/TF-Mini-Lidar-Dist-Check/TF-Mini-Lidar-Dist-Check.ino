/** TF-Mini Testprogramm , reads the distance and sends the value to the console
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
  
  Serial.print("Distance is ");
  Serial.print(distInMM);
  Serial.println( "mm");
  
  delay (100);
}
