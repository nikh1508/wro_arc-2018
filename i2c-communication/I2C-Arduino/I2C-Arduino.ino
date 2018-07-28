#include<Wire.h>
#define SLAVE_ADDR 0x07

void setup() {
  Wire.begin(SLAVE_ADDR);
  Serial.begin(115200);
  Serial.println("Started...");
  Wire.onRequest(sendData);
  Wire.onReceive(recvData);
}

int bytesToReceive = 3, recvingByte = 0;
byte data[10];
long num = 0;
void loop() {

  if (recvingByte >= bytesToReceive) {
    recvingByte = num = 0;
    Serial.println("Received all bytes:");
    for (int i = 0; i < bytesToReceive; i++) {
      Serial.print(int(data[i]));
      Serial.print("\t");
    }
    Serial.print("Char : ");
    Serial.print(char(data[1]));
    Serial.print("\t");
    for(int i = 2; i< bytesToReceive-1; i++)
      num = num << 8 | data[i];
    Serial.print("Num : ");
    Serial.println(num);
  }
}

void sendData() {
  Serial.println("I2C Data Requested.");
  Wire.write("test");
  Serial.println("Data Sent.");
}

void recvData() {
  Serial.println("Received a Byte.");
  data[recvingByte++] = Wire.read();
  if (recvingByte == 1){
    bytesToReceive = data[0];
    Serial.println("Recv :: " + String(bytesToReceive));
    }
}



