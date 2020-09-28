#include<SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3);

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);

}

void loop() {
  if(BTSerial.available()){
    char bt;
    bt = BTSerial.read();
    switch (bt) {
      case 'a':
        Serial.write(bt);
        break;  
      case 'b':
        Serial.write(bt);
        break;
      default:
        break;
    }
  }
}
