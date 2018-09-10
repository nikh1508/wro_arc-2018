void setup() {
  Serial.begin(9600);
  Wire.begin(adr_mega);
  assign_pins();
  declaration();
  bno_initialize();
  m[0].pwm = 45;
  m[2].pwm = 45;
}
