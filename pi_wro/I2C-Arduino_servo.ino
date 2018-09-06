#include<Wire.h>
#include <Servo.h>
#define SLAVE_ADDR 0x07

Servo myservo; 

void setup() {
  Wire.begin(SLAVE_ADDR);
  Serial.begin(9600);
  Serial.println("Started...");
  Wire.onRequest(sendData);
  Wire.onReceive(recvData);
  myservo.attach(44, 750, 2250);  // attaches the servo on pin 9 to the servo object
  myservo.write(0);
}

int bytesToReceive = 1, recvingByte = 0;
byte data[10];
long num = 0;
void loop() {

  
}

void sendData() {
  Wire.write("1");
}

void recvData() {
  while(Wire.available()){
  data[recvingByte++] = Wire.read();
  }
  if (recvingByte >= bytesToReceive) {
    recvingByte = num = 0;
    num = num << 8 | data[0];
    Serial.print("Num : ");
    Serial.println(num);
    myservo.write(num);
  }
}
