#include <Wire.h>
#define encoder0PinA  2
#define encoder0PinB  3
volatile int encoder0Pos = 0;
byte arr[2];
char chh;
//
void setup() {
  Serial.begin(9600);
  Wire.begin(8);
  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent);
  ////
  pinMode(encoder0PinA, INPUT);
  pinMode(encoder0PinB, INPUT);
  attachInterrupt(digitalPinToInterrupt(encoder0PinA), doEncoderA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoder0PinB), doEncoderB, CHANGE);
}
void loop() {
  if (chh == 'r') {
    encoder0Pos = 0;
    chh = '\0';
  }
  //  Serial.println (encoder0Pos, DEC);
}
void requestEvent() {
  arr[0] = (encoder0Pos >> 8) & 0xFF;
  arr[1] = encoder0Pos & 0xFF;
  Wire.write(arr, 2);
}
////
void receiveEvent(int howMany) {
  chh = Wire.read();
}
///////////////////////////
void doEncoderA() {
  if (PIND & _BV(PD2)) {
    if (PIND & _BV(PD3)) {
      encoder0Pos += 1; // CW
    }
    else {
      encoder0Pos -= 1; // CCW
    }
  }

  else
  {
    if (PIND & _BV(PD3)) {
      encoder0Pos = encoder0Pos + 1;// CW
    }
    else {
      encoder0Pos = encoder0Pos - 1;// CCW
    }
  }
  //  Serial.println (encoder0Pos, DEC);---------------------------------------------<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
}
///////////////////////////
void doEncoderB() {
  if (PIND & _BV(PD3)) {
    if (PIND & _BV(PD2)) {
      encoder0Pos += 1;// CW
    }
    else {
      encoder0Pos -= 1;// CCW
    }
  }
  else {
    if (PIND & _BV(PD2)) {
      encoder0Pos += 1;// CW
    }
    else {
      encoder0Pos -= 1;// CCW
    }
  }
}
