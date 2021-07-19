/**
 * Test program for lidar 
 * Puts 1:1 the input from the lidar sensor to the serial console
 * If the lines are stating with 59 the connection should be ok.
 * 
 * Created by Stefan Fambach under GPL3
 * Visit www.fambach.net if you want.
 * 
 */
#include <SoftwareSerial.h>

// wo ist der Lidar angeschlossen 
#define TX A1 // am Sendeleitung am analogen Port 1
#define RX A0 // am Empfangsleitung am analogen Port 2

// Objekt für SW Serial erstellen
SoftwareSerial mySerial(TX, RX);

// initialise alles
void initDist() {
  
}


void setup(){

  // Serielle Schnittstelle für ein paar Ausgaben 
  Serial.begin(115200); // Bitte auch Konsole auf gleich boudrate einstellen
  
  // software serielle schnittstelle konfigurieren
  mySerial.begin(115200); //Wenn nur Müll auf der Ausgabe erscheint dann mal die Boud rate ändern
 
}

void loop(){

  // lese vom sensor und schreibe es auf die Konsole
  // wenn etwas mit 59 am Anfang steht sieht das schon mal ganz gut aus ;)
  int i = 0;
  while(mySerial.available()){
    if(i%9 == 0){
      Serial.println();
    }
    Serial.print(mySerial.read(),HEX);
    i++;
  }
  delay (100);
}
