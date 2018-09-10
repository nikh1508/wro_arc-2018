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
  cur = millis();
  if (cur == 0 || prev == 0) {
    prev = cur;
    return;
  }
  if (flag_pid == true) {
    I = 0.0;
    prev = cur;
    flag_pid = false;
  }
  cur - prev == 0 ? time = 1 : time = cur - prev;
  bno();
  error = yaw - angle;
  if (angle == 360.0 && yaw > 0.0 && yaw < 90.0)
    error = yaw;
  if (error == -360.0)
    error = 0.0;
  //
  P = error * kp;
  if (error == 0.00)
  {
    I = 0.0;
  }
  if (I > 10.0 || I < -10.0)
  {
    I = I < 0 ? -10.0 : 10.0;
  }
  //  I = (I + (error * time)) * ki;//
  I = I + (error - prev_error);
  I = ki * I;
  D = ((error - prev_error) / time) * kd;
  pid = P + I + D;
  if (ch == 'f')
    m[0].pwm = m[0].pwm + int(pid);
  if (ch == 'b')
    m[0].pwm = m[0].pwm - int(pid);
  m[0].pwm = constrain(m[0].pwm, 0, 255);
  analogWrite(m[0].pwm_pin, m[0].pwm );/////////////////--------->>>>>>>>>>>>>>>>
  prev_error = error;//pid
  prev = cur;//dt
}
///////////
byte rpm_data[2];
int rpm = 0, rpm1 = 0;
void encoder_data0() {
  Wire.beginTransmission(adr_encoder_0);
  Wire.write('e');
  Wire.endTransmission();
  delay(1);
  Wire.requestFrom(adr_encoder_0, 2);
  encode[0] = Wire.read();
  encode[1] = Wire.read();
  encoder_0 = encode[0];
  encoder_0 = (encoder_0 << 8) | encode[1];
  delay(1);
  Wire.beginTransmission(adr_encoder_0);
  Wire.write('p');
  Wire.endTransmission();
  delay(1);
  Wire.requestFrom(adr_encoder_0, 2);
  rpm_data[0] = Wire.read();
  rpm_data[1] = Wire.read();
  rpm = rpm_data[0];
  rpm = (rpm << 8) | rpm_data[1];
}
//////////////////
void encoder_data1() {
  Wire.beginTransmission(adr_encoder_1);
  Wire.write('e');
  Wire.endTransmission();
  delay(1);
  Wire.requestFrom(adr_encoder_1, 2);
  encode[0] = Wire.read();
  encode[1] = Wire.read();
  encoder_1 = encode[0];
  encoder_1 = (encoder_1 << 8) | encode[1];
  delay(1);
  Wire.beginTransmission(adr_encoder_1);
  Wire.write('p');
  Wire.endTransmission();
  delay(1);
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
  delay(1);
  encoder_0 = 0;
  //
  Wire.beginTransmission(adr_encoder_1);
  Wire.write('r');
  Wire.endTransmission();
  delay(1);
  encoder_1 = 0;
}
///////////////////////////
void reset_feedback() {
  reset_encoder();
  flag_pid = true;
  dline1 = 0;
  dline2 = 0;
  error = 0;
  prev_error = 0;
  m[0].pwm = 0;
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
