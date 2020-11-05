/*
   Demo de la création d'une classe en C++
   TODO: créer la classe Tempo
   voir les fichiers a venir *.ino, *.cpp, *.h
*/

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  acquisitionADC(A0);
  delay(10);        // delay in between two acquire
}

void acquisitionADC(int analog_pin) {
  // read the input on analog pin 0:
  int sensorValue = analogRead(analog_pin);
  // print out the value you read:
  Serial.println(sensorValue);
}
