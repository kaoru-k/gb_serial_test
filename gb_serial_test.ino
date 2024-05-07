#include <SoftwareSerial.h>

#define RX_PIN 10
#define TX_PIN 11

SoftwareSerial mySerial(RX_PIN, TX_PIN);

void setup()  {
  mySerial.begin(9600);

  Serial.begin(115200);
  Serial.println("Ready.");
}

void loop() {
  if (Serial.available()){
    int recv_data = int(Serial.read());
    if (recv_data != 10) {
      mySerial.write(recv_data);

      Serial.print("send: ");
      Serial.println(recv_data, HEX);
    }
  }

  while (mySerial.available()) {
    int recv_data = int(mySerial.read());
    if (recv_data != 0) {
      Serial.print("recv: ");
      Serial.println(recv_data, HEX);
    }
  }
}
