void bno() {
  Wire.beginTransmission(adr);
  Wire.write(0x1A);
  Wire.endTransmission();
  Wire.requestFrom(adr, 2);
  lsb_yaw = Wire.read();
  msb_yaw = Wire.read();
  yaw = (((((int)msb_yaw) << 8) | lsb_yaw));
  yaw /= 16;
  yaw = yaw - yaw_offset;
  if (yaw < 0)
    yaw = yaw + 360;
  if (yaw > 180 && yaw < 360) {
    yaw = map(yaw, 180, 360, -180, 0);
  }
  //        Serial.print("yaw=");
  //        Serial.println(yaw);
}
///////
///////
//////
//////
void pid_yaw() {
  bno();
  error = yaw;
  P = error * kp;
  I = (I + (error / (double)time)) * ki;
  D = (error - (prev_error / (double)time)) * kd;
  pid = P + I + D;
  m[0].pwm = m[0].pwm + int(pid);
  m[2].pwm = m[2].pwm - int(pid);
  //////
  m[0].pwm = constrain(m[0].pwm, 0, desired_value);
  m[2].pwm = constrain(m[2].pwm, 2, desired_value);
}
//////
//////
void encoder_data() {
  Wire.requestFrom(adr_encoder_0, 2);
  encode[0] = Wire.read();
  encode[1] = Wire.read();
  encoder_0 = encode[0];
  encoder_0 = (encoder_0 << 8) | encode[1];
  //  Serial.println(encoder_0);
}
//////
//////
void reset_encoder() {
  Wire.beginTransmission(adr_encoder_0);
  Wire.write('r');
  Wire.endTransmission();
  //
  Wire.beginTransmission(adr_encoder_1);
  Wire.write('r');
  Wire.endTransmission();
}
/////
/////
void lpf(double d_value) {
  /////low pass
  desired_value = d_value;
  lpf_output = alpha * desired_value + (1 - alpha) * prev_output;
  prev_output = lpf_output;
  m[0].pwm = int(lpf_output);
  m[2].pwm = int(lpf_output);
}
/////
/////////////////////
/////////////
//////////////////////
void reset_feedback() {
  if (flag_reset == true) {
    reset_encoder();
    dline1 = 0;
    dline2 = 0;
    dline3 = 0;
    prev_output = 0.0;
    error = 0;
    prev_error = 0;
    m[0].pwm = 0;
    m[2].pwm = 0;
    flag_reset = false;
    L_bool = true;
  }
}
///////////////////////////
///////////////////////////
void l298n() {
  if (L_bool == true) {
    L_bool = false;
    digitalWrite(a_l, HIGH);
    digitalWrite(b_l, LOW);
    analogWrite(pwm_l, 150);
    delay(900);
    digitalWrite(a_l, LOW);
    digitalWrite(b_l, HIGH);
    analogWrite(pwm_l, 150);
    delay(900);
    digitalWrite(a_l, LOW);
    digitalWrite(b_l, LOW);
    analogWrite(pwm_l, 0);
    delay(900);
  }
}
