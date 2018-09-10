void bno() {
  Wire.beginTransmission(adr);
  Wire.write(0x1A);
  Wire.endTransmission();
  Wire.requestFrom(adr, 2);
  lsb_yaw = Wire.read();
//  delay(5);
  msb_yaw = Wire.read();
//  delay(5);
  yaw = (((((int)msb_yaw) << 8) | lsb_yaw));
  yaw /= 16.0;
  yaw = yaw - yaw_offset;
  if (yaw < 0.0)
    yaw += 360.0;
    Serial.println(yaw);
}
///////////////////////////////////////
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
  // Serial.print(error);Serial.print(" ");Serial.print(P);Serial.print(" ");Serial.print(" ");Serial.print(I);Serial.print(" ");Serial.print(D);
  if (ch == 'f')
    m[0].pwm = m[0].pwm + int(pid);
  if (ch == 'b')
    m[0].pwm = m[0].pwm - int(pid);
  m[0].pwm = constrain(m[0].pwm, 0, 255);
  //Serial.print(" ");Serial.println(m[0].pwm);
  prev_error = error;//pid
  prev = cur;//dt
}
/////////////////////////////////////////
byte rpm_data[2];
int rpm = 0, rpm1 = 0;
void encoder_data() {
  Wire.beginTransmission(adr_encoder_0);
  Wire.write('e');
  Wire.endTransmission();
  delay(1);
  Wire.requestFrom(adr_encoder_0, 2);
  encode[0] = Wire.read();
  encode[1] = Wire.read();
  encoder_0 = encode[0];
  encoder_0 = (encoder_0 << 8) | encode[1];
  delay(5);
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
/////////////////////////////////////
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
  delay(5);
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
/////
void reset_encoder() {
  Wire.beginTransmission(adr_encoder_0);
  Wire.write('r');
  Wire.endTransmission();
  delay(10);
  encoder_0 = 0;
  //
  //  Wire.beginTransmission(adr_encoder_1);
  //  Wire.write('r');
  //  Wire.endTransmission();
  //  delay(10);
}

void reset_encoder1() {
  Wire.beginTransmission(adr_encoder_1);
  Wire.write('r');
  Wire.endTransmission();
  delay(10);
  encoder_1 = 0;
  //
  //  Wire.beginTransmission(adr_encoder_1);
  //  Wire.write('r');
  //  Wire.endTransmission();
  //  delay(10);
}
////////////
void lpf(double d_value) {
  /////low pass
  //  desired_value = d_value;
  //  lpf_output = alpha * desired_value + (1 - alpha) * prev_output;
  //  prev_output = lpf_output;
  m[0].pwm = int(d_value);
  m[2].pwm = int(d_value);
}
//////////////
void reset_feedback() {
  if (flag_reset == true) {
    flag_pid = true;
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
/////////////////
void l298n() {
  if (L_bool == true) {
    L_bool = false;
    digitalWrite(a_l, HIGH);
    digitalWrite(b_l, LOW);
    analogWrite(pwm_l, 150);
    for (i = 0; i < 1000; i++) {
      if (rotate_desired < 0)
        rotate_desired = rotate_desired * (-1.0);
      pid_yaw(rotate_desired);
//      Serial.print(" ");
    }
    digitalWrite(a_l, LOW);
    digitalWrite(b_l, HIGH);
    analogWrite(pwm_l, 150);
    for (i = 0; i < 1000; i++) {
      pid_yaw(rotate_desired);
//      Serial.print(" ");
    }
    digitalWrite(a_l, LOW);
    digitalWrite(b_l, LOW);
    analogWrite(pwm_l, 0);
  }
}
//////////////////
void i2c_recieve(int howMany) {
  int pi_data = 0;
  pi_data = Wire.read();
  if (digitalRead(sqc_pin) == HIGH)
    sqc = pi_data;
  //  Serial.println(pi_data);
}
/////////////////
