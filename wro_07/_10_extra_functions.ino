void dump_error() {
  reset_feedback();
  /////---->backward till encoder
  digitalWrite(m[0].a, LOW);
  digitalWrite(m[0].b, HIGH);
  //1
  digitalWrite(m[1].a, HIGH);
  digitalWrite(m[1].b, HIGH);
  //2
  digitalWrite(m[2].a, LOW);
  digitalWrite(m[2].b, HIGH);
  /////
  /////
  m[0].pwm = m[2].pwm = speed[slow];
  analogWrite(m[0].pwm_pin, m[0].pwm);
  analogWrite(m[1].pwm_pin, 0);
  analogWrite(m[2].pwm_pin, m[0].pwm);
  //
  myPID.SetTunings(kp[slow], ki[slow], kd[slow]);
  /////
  while (ch != 's') {
    false_pid(270.0, 0);
    encoder_data0();
    encoder_0 = abs(encoder_0);
    if (encoder_0 >= 400) {
      stop();
      ch = 's';
    }
  }
  ch = '\0';
  /////////----->>>>forward
  digitalWrite(m[0].a, HIGH);
  digitalWrite(m[0].b, LOW);
  //1///
  digitalWrite(m[1].a, HIGH);
  digitalWrite(m[1].b, HIGH);
  //2
  digitalWrite(m[2].a, HIGH);
  digitalWrite(m[2].b, LOW);
  ////
  m[0].pwm = m[2].pwm = speed[slow];
  analogWrite(m[0].pwm_pin, m[0].pwm);
  analogWrite(m[1].pwm_pin, 0);
  analogWrite(m[2].pwm_pin, m[0].pwm);
  //
  myPID.SetTunings(kp[slow], ki[slow], kd[slow]);
  while (ch != 's') {
    false_pid(270.0, 1);
    line_stop();
  }
  ch = '\0';
  reset_feedback();
  /////////////////////////////////////////////////////
  left_value();
  while (ch != 's') {
    false_pid_sideways(270.0, 0);
    encoder_data1();
    encoder_1 = abs(encoder_1);
    if (encoder_1 >= 400) {
      stop();
      ch = 's';
    }
  }
  ch = '\0';
  right_value();
  while (ch != 's') {
    false_pid_sideways(270.0, 1);
    input_line_prependicular();
    for (i = 2; i < 8; i++) {
      dline2 += dline_data_2[i];
    }
    if (dline2 >= 5) {
      stop();
      ch = 's';
      Serial.println(dline2);
    }
    else
      dline2 = 0;
  }
}
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
void goto_stacking(int enc0, int enc1, int dir) {
  reset_feedback();
  ///////////----->>>forward
  digitalWrite(m[0].a, HIGH);
  digitalWrite(m[0].b, LOW);
  //1///
  digitalWrite(m[1].a, HIGH);
  digitalWrite(m[1].b, HIGH);
  //2
  digitalWrite(m[2].a, HIGH);
  digitalWrite(m[2].b, LOW);
  ////
  m[0].pwm = m[2].pwm = speed[slow];
  analogWrite(m[0].pwm_pin, m[0].pwm);
  analogWrite(m[1].pwm_pin, 0);
  analogWrite(m[2].pwm_pin, m[0].pwm);
  /////
  myPID.SetTunings(kp[slow], ki[slow], kd[slow]);
  while (ch != 's') {
    false_pid(270.0, 1);
    encoder_data0();
    encoder_0 = abs(encoder_0);
    if (encoder_0 >= enc0) {
      stop();
      ch = 's';
    }
  }
  reset_feedback();
  if (dir > 0)
    right_value();
  else
    left_value();
  /////////////////
  while (ch != 's') {
    false_pid_sideways(270.0, dir);
    encoder_data1();
    encoder_1 = abs(encoder_1);
    if (encoder_1 >= enc1) {
      stop();
      ch = 's';
    }
  }
}
