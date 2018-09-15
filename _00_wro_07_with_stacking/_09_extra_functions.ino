void dump_error(int enc0 = 400, int enc1 = 400, double angle = 270.0, int area = 0) {
  reset_feedback();
  if (area == 0) {
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
      false_pid(angle, 0);
      encoder_data0();
      encoder_0 = abs(encoder_0);
      if (encoder_0 >= enc0) {
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
      false_pid(angle, 1);
      line_stop();
    }
    ch = '\0';
  }
  reset_feedback();
  /////////////////////////////////////////////////////
  left_value();
  while (ch != 's') {
    false_pid_sideways(angle, 0);
    encoder_data1();
    encoder_1 = abs(encoder_1);
    if (encoder_1 >= enc1) {
      stop();
      ch = 's';
    }
  }
  ch = '\0';
  right_value();
  while (ch != 's') {
    false_pid_sideways(angle, 1);
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
/////////////////////////////////////
void resetDrive() {
  encoder_data0();
  encoder_data1();
  sideways((encoder_1 < 0), abs(encoder_1), 0);
  delay(500);
  Serial.println("NOW0::" + String(encoder_0));
  Serial.println("OFFSET::" + String(encoder0_offset));
  int enc0 = encoder_0 + encoder0_offset;
  move_encoder_only((enc0 < 0), abs(enc0), 0);
}
