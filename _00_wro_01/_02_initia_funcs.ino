///////motor///////////
void global_initial() {
  /////motor0/////
  motor[0].forw = 51;
  motor[0].bacw = 49;
  motor[0].pw = 2;
  /////motor1/////
  motor[1].forw = 24;
  motor[1].bacw = 22;
  motor[1].pw = 3;
  /////motor2/////
  motor[2].forw = 41;
  motor[2].bacw = 47;
  motor[2].pw = 4;
}
//////////////
void bno_initialize() {
  Wire.beginTransmission(adr);
  Wire.write(0x3D);
  Wire.write(0x0C);
  Wire.endTransmission();
  delay(1);
  ////////////////
  for (i = 0; i < 50; i++) {
    Wire.beginTransmission(adr);
    Wire.write(0x1A);
    Wire.endTransmission();
    Wire.requestFrom(adr, 2);
    lsb_yaw = Wire.read();
    msb_yaw = Wire.read();
    yaw_offset = yaw_offset + (((((int)msb_yaw) << 8) | lsb_yaw));
  }
  yaw_offset /= 800;
  Serial.println(yaw_offset);
}
/////////////////////
void analog_pins() {
  line[0] = A0;
  line[1] = A1;
  line[2] = A2;
  line[3] = A3;
  line[4] = A4;
  line[5] = A5;
  line[6] = A6;
  line[7] = A7;
  line[8] = A8;
  line[9] = A9;
  line[10] = A10;
  line[11] = A11;
  line[12] = A12;
  line[13] = A13;
  line[14] = A14;
  line[15] = A15;
}
void declaration() {
  //MD1
  pinMode(51, OUTPUT); //7//m1
  pinMode(49, OUTPUT); //8//m1
  pinMode(24, OUTPUT); //4//m2
  pinMode(22, OUTPUT); //9//m2
  pinMode(2, OUTPUT); //5//pwm1
  pinMode(3, OUTPUT); //6//pwm2
  //MD2
  pinMode(43, OUTPUT); //7//m1
  pinMode(45, OUTPUT); //8//m1
  pinMode(41, OUTPUT); //4//m2
  pinMode(47, OUTPUT); //9//m2
  pinMode(5, OUTPUT); //5//pwm1
  pinMode(4, OUTPUT); //6//pwm2
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
  pinMode(A15, INPUT);
}
