/*
   Demo de la création d'une classe "Tempo" en C++
   les différents formats des fichiers sont *.ino, *.cpp, *.h
*/

/*****************************************************************************/
// Import des fonctions externes au fichier principal
#include "tempo.h"

/*****************************************************************************/
// Definition of hardware I/O (GPIO) / Définition des E/S matérielles
// constants won't change. Used here to set a pin number:
const int ledStatusPin =  LED_BUILTIN;  // the number of the LED pin, for Arduino MKRZero LED_BUILTIN = pin 32

/*****************************************************************************/
// Création de l'objet "temporisationLedStatus" depuis la classe Tempo
Tempo temporisationLedStatus;  // tempo pour le clignotement de la LED status
Tempo periodeEchantillonnage;  // tempo entre deux valeurs analogiques

/*****************************************************************************/
// Fonction d'initialisation au démarrage du programme
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  // set the digital pin as output:
  pinMode(ledStatusPin, OUTPUT);

  // initialize and configure all timeout:
  temporisationLedStatus.begin(500);  // start tempo for 500 ms
  periodeEchantillonnage.begin(10);  // sampling ADC every 10 ms
}

/*****************************************************************************/
// Fonction principale, répété indéfiniment
void loop() {
  // Déclenchement de l'évènement pour le clignotement de la LED :
  if (temporisationLedStatus.isTimeEnding()) {
    toggle(ledStatusPin);
  }

  // Déclenchement de l'évènement pour l'acquisition de l'entrée analogique :
  if (periodeEchantillonnage.isTimeEnding()) {
    acquisitionADC(A0);
  }
}

/*****************************************************************************/
// Fonction permettant le changement d'état d'une sortie
void toggle(int led_pin) {
  digitalWrite(led_pin, !digitalRead(led_pin));   // change the LED state (HIGH is the voltage level)
}

/*****************************************************************************/
// Fonction d'acquisition et d'affichage d'uen entrée analogique
void acquisitionADC(int analog_pin) {
  // read the input on analog pin 0:
  int sensorValue = analogRead(analog_pin);
  // print out the value you read:
  Serial.println(sensorValue);
}
