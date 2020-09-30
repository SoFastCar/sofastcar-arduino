#include<SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3);

int LightPin = 13;
int speakerpin = 12;

void setup() {
  // Bluetooth
  Serial.begin(9600);
  BTSerial.begin(9600);
  // LED
  pinMode(LightPin, OUTPUT);
}

void loop() {
  if(BTSerial.available()){
    char bt;
    bt = BTSerial.read();
    switch (bt) {
      case 1:
        Serial.println(bt);
        digitalWrite(LightPin, HIGH);
        break;  
      case 2:
        Serial.println(bt);
        digitalWrite(LightPin, LOW);
        break;
      case 3:
        Serial.println(bt);
         tone(speakerpin, 500, 1000);
        break;
      default:
        break;
    }
  }
}
