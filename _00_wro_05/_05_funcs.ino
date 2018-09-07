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
  if (yaw < 0.0)
    yaw = yaw + 360.0;
  if (yaw > 180.0 && yaw < 360.0)
    yaw = map(yaw, 180.0, 360.0, -180.0, 0.0);
  yaw = yaw + bno_off;
  //  Serial.print("yaw="); Serial.print(yaw); Serial.print("bno_off= "); Serial.println(bno_off);
}
void re_offset() {
  bno();
  if (last_rot == 'q')
    bno_off = yaw + 90.0;
  //
  if (last_rot == 'k')
    bno_off = yaw + 45.0;
  //
  if (last_rot == 'e')
    bno_off = yaw - 90.0;
  //
  if (last_rot == 'l')
    bno_off = yaw - 45.0;
  //
  if (last_rot != '\0') {
    for (int i = 0; i < 50; i++) {
      Wire.beginTransmission(adr);
      Wire.write(0x1A);
      Wire.endTransmission();
      Wire.requestFrom(adr, 2);
      lsb_yaw = Wire.read();
      msb_yaw = Wire.read();
      yaw_offset = yaw_offset + (((((int)msb_yaw) << 8) | lsb_yaw));
    }
    yaw_offset /= 800;
    yaw_offset -= 1;
  }
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
  if (ch == 'f') {
    m[0].pwm = m[0].pwm + int(pid);
    m[2].pwm = m[2].pwm - int(pid);
  }
  if (ch == 'b') {
    m[0].pwm = m[0].pwm - int(pid);
    m[2].pwm = m[2].pwm + int(pid);
  }
  //////
  m[0].pwm = constrain(m[0].pwm, 0, desired_value);
  m[2].pwm = constrain(m[2].pwm, 2, desired_value);
  //  pin_reversal();///////////////------------>>>>changefor reversal
}
//////
//////
void encoder_data() {
  Wire.requestFrom(adr_encoder_0, 2);
  encode[0] = Wire.read();
  encode[1] = Wire.read();
  encoder_0 = encode[0];
  encoder_0 = (encoder_0 << 8) | encode[1];
}
//////
//////
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
//        error = 0;
//        prev_error = 0;
    m[0].pwm = 0;
    m[2].pwm = 0;
    flag_reset = false;
    L_bool = true;
    flag_motor = true;
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
/////////////////////////
/////////////////////////
void i2c_recieve(int howMany) {
  int pi_data = 0;
  pi_data = Wire.read();
  if (digitalRead(sqc_pin) == HIGH)
    sqc = pi_data;
  delay(10);
  //  Serial.println(pi_data);
}
/////////////////////////////
/////////////////////////////
void pin_reversal() {
  if (m[0].pwm < 0) {
    if (ch == 'f') {
      status_m0a = 0;
      status_m0b = 1;
    }
    if (ch == 'b') {
      status_m0a = 1;
      status_m0b = 0;
    }
  }
  //
  if (m[0].pwm >= 0) {
    if (ch == 'f') {
      status_m0a = 1;
      status_m0b = 0;
    }
    if (ch == 'b') {
      status_m0a = 0;
      status_m0b = 1;
    }
  }
  //////////////////////////////////////
  if (m[2].pwm < 0) {
    if (ch == 'f') {
      status_m2a = 0;
      status_m2b = 1;
    }
    if (ch == 'b') {
      status_m2a = 1;
      status_m2b = 0;
    }
  }
  //
  if (m[2].pwm >= 0) {
    if (ch == 'f') {
      status_m2a = 1;
      status_m2b = 0;
    }
    if (ch == 'b') {
      status_m2a = 0;
      status_m2b = 1;
    }
  }
}
//////////////////////////////////
//////////////////////////////////
/*void motor_pin_reset() {
  if (flag_motor == true) {
    flag_motor = false;
    if (ch == 'f') {
      status_m0a = 1;
      status_m0b = 0;
      //
      status_m2a = 1;
      status_m2b = 0;
    }
    //
    if (ch == 'b') {
      status_m0a = 0;
      status_m0b = 1;
      //
      status_m2a = 0;
      status_m2b = 1;
    }
  }
  }*/
