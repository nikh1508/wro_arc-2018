void assign_pins() {
  line1[0] = A3;
  line1[1] = A4;
  line1[2] = A5;
  line1[3] = A6;
  line1[4] = A7;
  line1[5] = A8;//////this point only
  line1[6] = A9;
  line1[7] = A8;
  //
  line2[0] = A8;
  line2[1] = A9;
  line2[2] = A10;
  line2[3] = A11;
  line2[4] = A12;
  line2[5] = A13;
  line2[6] = A14;
  //  line2[7] = A15;
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
////////////////////////////////////////
void line_compare() {
  compare_1[0] = 450;
  compare_1[1] = 450;
  compare_1[2] = 450;
  compare_1[3] = 450;
  compare_1[4] = 450;
  compare_1[5] = 450;
  compare_1[6] = 425;
  compare_1[7] = 425;
  //
  compare_2[0] = 500;
  compare_2[1] = 500;
  compare_2[2] = 500;
  compare_2[3] = 500;
  compare_2[4] = 500;
  compare_2[5] = 500;
  compare_2[6] = 500;
  compare_2[7] = 500;
}
////////////////////////////////////////
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
  //
  //////mux/////////
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(en_m, OUTPUT);
  digitalWrite(en_m, LOW);
  //
  //analogpins
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);
  pinMode(A7, INPUT);
  pinMode(A8, INPUT);
  pinMode(A9, INPUT);
  pinMode(A10, INPUT);
  pinMode(A11, INPUT);
  pinMode(A12, INPUT);
  pinMode(A13, INPUT);
  pinMode(A14, INPUT);
  //  pinMode(A15, INPUT);
}
//////
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
//////////////////////////
void base_start() {
  digitalWrite(m[0].a, HIGH);
  digitalWrite(m[0].b, LOW);
  //
  digitalWrite(m[1].a, LOW);
  digitalWrite(m[1].b, HIGH);
  //
  analogWrite(m[0].pwm_pin, 40);
  analogWrite(m[1].pwm_pin, 40);
  while (ch != 's') {
    encoder_data0();
    encoder_data1();
    encoder_0 = abs(encoder_0);
    encoder_1 = abs(encoder_1);
    if (encoder_0 >= 400 && encoder_1 >= 400) {
      stop();
      ch = 's';
    }
  }
}
