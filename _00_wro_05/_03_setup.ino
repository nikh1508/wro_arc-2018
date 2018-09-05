void setup() {
  Serial.begin(9600);
  Wire.begin(adr_mega);
  assign_pins();
  line_compare();
  declaration();
  bno_initialize();
}
