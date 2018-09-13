void bno() {
  Wire.beginTransmission(adr);
  Wire.write(0x1A);
  Wire.endTransmission();
  Wire.requestFrom(adr, 2);
  lsb_yaw = Wire.read();
  msb_yaw = Wire.read();
  yaw = (((((int)msb_yaw) << 8) | lsb_yaw));
  yaw /= 16.0;
  yaw = yaw - yaw_offset;
  if (yaw < 0.0)
    yaw += 360.0;
  //  Serial.println(yaw);
}
////////////////////
void pid_yaw(double angle) {
  bno();
  input = diff(yaw, angle);
  //  Serial.println(input);
  myPID.Compute();
  if (direction[index][motion] == 1)
    m[2].pwm = constrain(m[0].pwm + output, 0, 255);
  else
    m[2].pwm = constrain(m[0].pwm - output, 0, 255);
  analogWrite(m[2].pwm_pin, m[2].pwm);
  //  Serial.print("SET:" + String(setpoint));
  //  Serial.print("\tINP:" + String(input));
  //  Serial.print("\tOUT:" + String(output));
  //  Serial.print("\tLFT:" + String(m[2].pwm));
  //  Serial.print("\tRT:" + String(m[0].pwm));
  //  Serial.print("\tYAW:" + String(yaw));
}
//////////////
void pid_sideways(double angle) {
  bno();
  //
  input_sideways = diff(yaw, angle);
  my_sideways.Compute();
  m[1].pwm = constrain(50 - output_sideways, 0, 255);
  analogWrite(m[1].pwm_pin, m[1].pwm);
}
///////////
byte rpm_data[2];
int rpm = 0, rpm1 = 0;
void encoder_data0() {
  Wire.beginTransmission(adr_encoder_0);
  Wire.write('e');
  Wire.endTransmission();
  Wire.requestFrom(adr_encoder_0, 2);
  encode[0] = Wire.read();
  encode[1] = Wire.read();
  encoder_0 = encode[0];
  encoder_0 = (encoder_0 << 8) | encode[1];
  Wire.beginTransmission(adr_encoder_0);
  Wire.write('p');
  Wire.endTransmission();
  Wire.requestFrom(adr_encoder_0, 2);
  rpm_data[0] = Wire.read();
  rpm_data[1] = Wire.read();
  rpm = rpm_data[0];
  rpm = (rpm << 8) | rpm_data[1];
  //  Serial.print(" "); Serial.print(encoder_0); Serial.print(" ");
}
//////////////////
void encoder_data1() {
  Wire.beginTransmission(adr_encoder_1);
  Wire.write('e');
  Wire.endTransmission();
  Wire.requestFrom(adr_encoder_1, 2);
  encode[0] = Wire.read();
  encode[1] = Wire.read();
  encoder_1 = encode[0];
  encoder_1 = (encoder_1 << 8) | encode[1];
  Wire.beginTransmission(adr_encoder_1);
  Wire.write('p');
  Wire.endTransmission();
  Wire.requestFrom(adr_encoder_1, 2);
  rpm_data[0] = Wire.read();
  rpm_data[1] = Wire.read();
  rpm1 = rpm_data[0];
  rpm1 = (rpm1 << 8) | rpm_data[1];
}
///////////////
void reset_encoder() {
  Wire.beginTransmission(adr_encoder_0);
  Wire.write('r');
  Wire.endTransmission();
  encoder_0 = 0;
  //
  Wire.beginTransmission(adr_encoder_1);
  Wire.write('r');
  Wire.endTransmission();
  encoder_1 = 0;
}
///////////////////////////
void reset_feedback() {
  pid_set_value = true;
  reset_encoder();
  dline1 = 0;
  dline2 = 0;
  ch = '\0';
}
//////////////////////////
void i2c_recieve(int howMany) {
  int pi_data = 0;
  pi_data = Wire.read();
  if (digitalRead(sqc_pin) == HIGH) {
    motion = 0;
    index = pi_data;
  }
  //  Serial.println(pi_data);
}
