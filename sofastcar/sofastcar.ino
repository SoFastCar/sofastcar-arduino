#include<SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial BTSerial(2, 3);
Servo servo;

int LightPin = 13;
int SpeakerPin = 12;
int ServoPin = 11;
int Stop = 90;
int Open = 180;
int Close = 0;

void setup() {
  // Bluetooth
  Serial.begin(9600);
  BTSerial.begin(9600);
  // LED
  pinMode(LightPin, OUTPUT);
  // Servo
  servo.attach(ServoPin);
  servo.write(Stop);
  servo.write(Open);
  delay(500);
  servo.write(Close);
  delay(500);
  servo.write(Stop);
}

void loop() {
  if(BTSerial.available()){
    char bt;
    bt = BTSerial.read();
    switch (bt) {
      case 1:
        Serial.println(bt);
        for (int i = 0; i < 5; i++) {
          digitalWrite(LED_BUILTIN, HIGH);
          delay(1000);                       
          digitalWrite(LED_BUILTIN, LOW);    
          delay(1000);
        }
        break;  
      case 2:
        Serial.println(bt);
        digitalWrite(LightPin, LOW);
        break;
      case 3:
        Serial.println(bt);
         tone(SpeakerPin, 500, 1000);
        break;
      default:
        break;
    }
  }
}
