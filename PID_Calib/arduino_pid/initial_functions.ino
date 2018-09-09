void assign_pins() {
  //
  m[0].a = m0_a;
  m[0].b = m0_b;
  m[0].pwm_pin = m0_pwm;
  //
  m[1].a = m1_a;
  m[1].b = m1_b;
  m[1].pwm_pin = m1_pwm;
  //
  m[2].a = m2_a;
  m[2].b = m2_b;
  m[2].pwm_pin = m2_pwm;
}
//
//
//
void declaration() {
  //MD1
  pinMode(m[0].a, OUTPUT);
  pinMode(m[0].b, OUTPUT);
  pinMode(m[0].pwm_pin, OUTPUT);
  pinMode(m[1].a, OUTPUT);
  pinMode(m[1].b, OUTPUT);
  pinMode(m[1].pwm_pin, OUTPUT);
  //MD2
  pinMode(m[2].a, OUTPUT);
  pinMode(m[2].b, OUTPUT);
  pinMode(m[2].pwm_pin, OUTPUT);
  pinMode(47, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  //
  //////////pi to mega select pin
  pinMode(sqc_pin, OUTPUT);
  digitalWrite(sqc_pin, LOW);

}
////
////
void bno_initialize() {
  Wire.beginTransmission(adr);
  Wire.write(0x3D);
  Wire.write(0x0C);
  Wire.endTransmission();
  delay(1);
  ////////////////
  for (int i = 0; i < 50; i++) {
    Wire.beginTransmission(adr);
    Wire.write(0x1A);
    Wire.endTransmission();
    Wire.requestFrom(adr, 2);
    lsb_yaw = Wire.read();
    msb_yaw = Wire.read();
    yaw_offset = yaw_offset + (((((int)msb_yaw) << 8) | lsb_yaw));
  }
  yaw_offset /= 800.0;
  //
  Serial.println(yaw_offset);
}
