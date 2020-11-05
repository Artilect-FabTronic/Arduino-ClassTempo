/*
   Demo de la création d'une classe en C++
   TODO: créer la classe Tempo
   voir les fichiers a venir *.ino, *.cpp, *.h
*/

/*****************************************************************************/
// Import des fonctions externes au fichier principal
#include "tempo.h"

/*****************************************************************************/
// Definition of hardware I/O (GPIO) / Définition des E/S matérielles
// constants won't change. Used here to set a pin number:
const int ledStatusPin =  LED_BUILTIN;// the number of the LED pin

/*****************************************************************************/
// Création de l'objet "temporisationLedStatus" depuis la classe Tempo
Tempo temporisationLedStatus;  // tempo pour le clignotement de la LED status
Tempo periodeEchantillonnage;  // tempo entre deux valeurs analogiques

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  // set the digital pin as output:
  pinMode(ledStatusPin, OUTPUT);

  temporisationLedStatus.begin(500);  // start tempo for 500 ms
  periodeEchantillonnage.begin(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (temporisationLedStatus.isTimeEnding()) {
    toggle(ledStatusPin);
  }

  if (periodeEchantillonnage.isTimeEnding()) {
    acquisitionADC(A0);
  }
}

void toggle(int led_pin) {
  digitalWrite(led_pin, !digitalRead(led_pin));   // change the LED state (HIGH is the voltage level)
}

void acquisitionADC(int analog_pin) {
  // read the input on analog pin 0:
  int sensorValue = analogRead(analog_pin);
  // print out the value you read:
  Serial.println(sensorValue);
}
