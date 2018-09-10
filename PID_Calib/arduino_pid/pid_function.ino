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
///////////////////////////////////////
void pid_yaw(double angle) {
  cur = millis();
  if (cur == 0 || prev == 0) {
    prev = cur;
    return;
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
  I = I + (error - prev_error);
  I = ki * I;
  D = ((error - prev_error) / time) * kd;
  pid = P + I + D;
  if (ch == 'f')
    m[0].pwm = m[0].pwm + int(pid);
  if (ch == 'b')
    m[0].pwm = m[0].pwm - int(pid);
  m[0].pwm = constrain(m[0].pwm, 0, 255);
  prev_error = error;//pid
  prev = cur;//dt
  Serial.println(m[0].pwm);
}
/////////////////////////////////////////
////////////
void lpf(double d_value) {
  /////low pass
  desired_value = d_value;
  lpf_output = alpha * desired_value + (1 - alpha) * prev_output;
  prev_output = lpf_output;
  m[0].pwm = int(lpf_output);
  m[2].pwm = int(lpf_output);
}
