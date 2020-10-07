#include<SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial BTSerial(2, 3);
Servo servo;

int RedPin = 6;
int GreenPin = 7;
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
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  digitalWrite(6, HIGH); 
  digitalWrite(7, HIGH); 
  // Servo
  servo.attach(ServoPin);
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
          digitalWrite(6, LOW);
          digitalWrite(7, LOW);
          delay(1000);                       
          digitalWrite(6, HIGH); 
          digitalWrite(7, HIGH); 
          delay(1000);
        }
        break;  
      case 2:
        Serial.println(bt);
        tone(SpeakerPin, 500, 1000);
        break;
      case 3:
        servo.write(Open);
        delay(250);
        servo.write(Stop);
        break;
      case 4:
        servo.write(Close);
        delay(250);
        servo.write(Stop);
        break;
      default:
        break;
    }
  }
}
