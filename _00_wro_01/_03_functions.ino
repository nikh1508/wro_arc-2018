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
  //  Serial.print("yaw=");
  //  Serial.println(yaw);
}
////////
void lpf_sec() {
  /////low pass
  lpf_output_sec = alpha_sec * desired_value_sec + (1 - alpha_sec) * prev_output_sec;
  prev_output_sec = lpf_output_sec;
}
///////
void lpf_main() {
  /////low pass
  lpf_output_main = alpha_main * desired_value_main + (1 - alpha_main) * prev_output_main;
  prev_output_main = lpf_output_main;
}
////
void low_pass() {
  if (ch == 'f' || ch == 'b') {
    desired_value_main = 255.0;
    lpf_main();
  }
  else if (ch == 'l' || ch == 'r') {
    desired_value_main = 128.0;
    lpf_sec();
    lpf_main();
  }
}
///////////////
/////////////
void pid_main() {
  error = yaw;
  P = error * kp;
  I = (I + (error / time)) * ki;
  D = (error - (prev_error / time)) * kd;
  pid = P + I + D;
}
/////////////////////////
/////////////////////////
void calculate() {
  pwm0 = lpf_output_main;
  pwm2 = lpf_output_main;
  pwm1 = lpf_output_sec;
  if (ch == 'f') {
    pwm0 += pid;
    pwm2 -= pid;
    pwm1 = 0;
  }
  if (ch == 'b') {
    pwm0 -= pid;
    pwm2 += pid;
    pwm1 = 0;
  }
  if (ch == 'l') {
    pwm0 -= pid;
    pwm2 += pid;
    pwm1 -= pid;
  }
  if (ch == 'r') {
    pwm0 -= pid;
    pwm2 += pid;
    pwm1 += pid;
  }
  if (ch == 's') {
    pwm0 = 0;
    pwm2 = 0;
    pwm1 = 0;
  }
}
/////////////////////////////////////
////////////////////////////////////
///////////////////////////////////
void line_sensor() {
  for (i = 0; i < 8; i++) {
    line_data_1[i] = analogRead(line[i]);
  }
  for (i = 8; i < 16; i++) {
    line_data_2[i] = analogRead(line[i]);
  }
}
///////////////////////////////////
///////////////////////////////////
///////////////////////////////////
void encoder_data() {
  Wire.requestFrom(8, 2);
  encode[0] = Wire.read();
  encode[1] = Wire.read();
  //
  Wire.requestFrom(9, 2);
  encode[2] = Wire.read();
  encode[3] = Wire.read();
  //
  Wire.requestFrom(10, 2);
  encode[4] = Wire.read();
  encode[5] = Wire.read();
  ////
  ////
  encoder_0 = encode[0];
  encoder_0 = (encoder_0 << 8) | encode[1];
  //
  encoder_1 = encode[2];
  encoder_1 = (encoder_1 << 8) | encode[3];
  //
  encoder_2 = encode[4];
  encoder_2 = (encoder_2 << 8) | encode[5];
}
////////////////////
void reset_encoder() {
  Wire.beginTransmission(8);
  Wire.write('r');
  Wire.endTransmission();
  //
  Wire.beginTransmission(9);
  Wire.write('r');
  Wire.endTransmission();
  //
  Wire.beginTransmission(10);
  Wire.write('r');
  Wire.endTransmission();
}
////////////////////////
////////////////////////
void receiveEvent(int howMany) {
  ch = Wire.read();
}
////////////////////////
void requestEvent() {
  Wire.write('a');
}
