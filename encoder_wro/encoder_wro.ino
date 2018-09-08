#include <Wire.h>
#define adr 8
int encoderPin1 = 2;
int encoderPin2 = 3;
byte arr[2];
char chh = '\0';
volatile int lastEncoded = 0;
volatile int encoderValue = 0;

long lastencoderValue = 0;

int lastMSB = 0;
int lastLSB = 0;

void setup() {
  Serial.begin (9600);
  Wire.begin(adr);
  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent);
  pinMode(encoderPin1, INPUT);
  pinMode(encoderPin2, INPUT);

  digitalWrite(encoderPin1, HIGH); //turn pullup resistor on
  digitalWrite(encoderPin2, HIGH); //turn pullup resistor on

  //call updateEncoder() when any high/low changed seen
  //on interrupt 0 (pin 2), or interrupt 1 (pin 3)
  attachInterrupt(0, updateEncoder, CHANGE);
  attachInterrupt(1, updateEncoder, CHANGE);

}

void loop() {
//  Serial.println(encoderValue);
  if (chh == 'r') {
    encoderValue = 0;
    chh = '\0';
  }
}
//
void requestEvent() {
  arr[0] = (encoderValue >> 8) & 0xFF;
  arr[1] = encoderValue & 0xFF;
  Wire.write(arr, 2);
}
//
void receiveEvent(int howMany) {
  chh = Wire.read();
}
void updateEncoder() {
  int MSB = digitalRead(encoderPin1); //MSB = most significant bit
  int LSB = digitalRead(encoderPin2); //LSB = least significant bit

  int encoded = (MSB << 1) | LSB; //converting the 2 pin value to single number
  int sum  = (lastEncoded << 2) | encoded; //adding it to the previous encoded value

  if (sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) encoderValue ++;
  if (sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) encoderValue --;

  lastEncoded = encoded; //store this value for next time
}
