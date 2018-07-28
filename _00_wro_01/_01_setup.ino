void setup() {
  Serial.begin(9600);
  Wire.begin(5);
  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent);
  //
  declaration();
  //
  global_initial();
  //
  bno_initialize();
  analog_pins();
}

