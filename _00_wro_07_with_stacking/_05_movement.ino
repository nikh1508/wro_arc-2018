void move(int n, int data, int d_angle) {
  if (n > 0) { //forward
    digitalWrite(m[0].a, HIGH);
    digitalWrite(m[0].b, LOW);
    //1///
    digitalWrite(m[1].a, HIGH);
    digitalWrite(m[1].b, HIGH);
    //2
    digitalWrite(m[2].a, HIGH);
    digitalWrite(m[2].b, LOW);
    //
    m[0].pwm = m[2].pwm = speed[fast];
    analogWrite(m[0].pwm_pin, m[0].pwm);
    analogWrite(m[1].pwm_pin, 0);
    analogWrite(m[2].pwm_pin, m[0].pwm);
    //
    myPID.SetTunings(kp[fast], ki[fast], kd[fast]);
    while (ch != 's') {
      pid_yaw(d_angle);
      encoder_data0();
      if (encoder_0 >= data  && pid_set_value == true) {
        m[0].pwm = m[2].pwm = speed[slow];
        analogWrite(m[0].pwm_pin, m[0].pwm);
        analogWrite(m[2].pwm_pin, m[0].pwm);
        Serial.println("here");
        myPID.SetTunings(kp[slow], ki[slow], kd[slow]);
        pid_set_value = false;
      }
      if (encoder_0 >= data ) {
        line_stop();
      }
    }
  }
  ////
  if (n < 0) { //backward
    digitalWrite(m[0].a, LOW);
    digitalWrite(m[0].b, HIGH);
    //1
    digitalWrite(m[1].a, HIGH);
    digitalWrite(m[1].b, HIGH);
    //2
    digitalWrite(m[2].a, LOW);
    digitalWrite(m[2].b, HIGH);
    //
    m[0].pwm = m[2].pwm = speed[fast];
    analogWrite(m[0].pwm_pin, m[0].pwm);
    analogWrite(m[1].pwm_pin, 0);
    analogWrite(m[2].pwm_pin, m[0].pwm);
    //
    myPID.SetTunings(kp[fast], ki[fast], kd[fast]);
    while (ch != 's') {
      pid_yaw(d_angle);
      encoder_data0();
      encoder_0 = encoder_0 * (-1);
      if (encoder_0 >= data && pid_set_value == true) {
        m[0].pwm = m[2].pwm = speed[slow];
        analogWrite(m[0].pwm_pin, m[0].pwm);
        analogWrite(m[2].pwm_pin, m[0].pwm);
        myPID.SetTunings(kp[slow], ki[slow], kd[slow]);
        pid_set_value = false;
      }
      if (encoder_0 >= data) {
        line_stop();
      }
    }
  }
}
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
void move_encoder_only(int n, int data, int d_angle) {
  reset_feedback();
  encoder_data0();
  int last_encoder_count = encoder_0;
  ch = '\0';
  if (n == 1) { //forward
    Serial.println("Going Forward " + String(data) + " counts.");
    digitalWrite(m[0].a, HIGH);
    digitalWrite(m[0].b, LOW);
    //1///
    digitalWrite(m[1].a, HIGH);
    digitalWrite(m[1].b, HIGH);
    //2
    digitalWrite(m[2].a, HIGH);
    digitalWrite(m[2].b, LOW);
    //
    analogWrite(m[1].pwm_pin, 0);
    //
    m[0].pwm = m[2].pwm = speed[slow];
    analogWrite(m[0].pwm_pin, m[0].pwm);
    analogWrite(m[2].pwm_pin, m[0].pwm);
    myPID.SetTunings(kp[slow], ki[slow], kd[slow]);
    while (ch != 's') {
      false_pid(d_angle, 1);
      encoder_data0();
      //      Serial.println(encoder_0);
      if (abs(encoder_0 - last_encoder_count) >= data) {
        Serial.println("ENC0 :: " + String(encoder_0));
        stop();
        ch = 's';
      }
    }
  }
  ////
  else { //backward
    Serial.println("Going Backward " + String(data) + " counts.");
    digitalWrite(m[0].a, LOW);
    digitalWrite(m[0].b, HIGH);
    //1
    digitalWrite(m[1].a, HIGH);
    digitalWrite(m[1].b, HIGH);
    //2
    digitalWrite(m[2].a, LOW);
    digitalWrite(m[2].b, HIGH);
    //
    analogWrite(m[1].pwm_pin, 0);
    //
    m[0].pwm = m[2].pwm = speed[slow];
    analogWrite(m[0].pwm_pin, m[0].pwm);
    analogWrite(m[2].pwm_pin, m[0].pwm);
    myPID.SetTunings(kp[slow], ki[slow], kd[slow]);
    while (ch != 's') {
      false_pid(d_angle, 0);
      encoder_data0();
      false_pid(d_angle, 0);
      encoder_data0();
      if (encoder_0 == -1) continue;
      if (abs(encoder_0 - last_encoder_count) >= data) {
        Serial.println("ENC0 :: " + String(encoder_0));
        stop();
        ch = 's';
      }
    }
  }
}
///////////////////////////
int encoder0_offset = 0;
///////////////////////////
void sideways(int dir, int data, double angle) {
  reset_feedback();
  encoder_data0();
  encoder_data1();
  int last_encoder_count0 = encoder_0;
  int last_encoder_count1 = encoder_1;
  ch = '\0';
  if (dir == 1) {//right
    Serial.println("Going Right " + String(data) + " counts.");
    right_value();
  }
  else {  //left
    Serial.println("Going Left " + String(data) + " counts.");
    left_value();
  }
  while (ch != 's') {
    pid_sideways(angle, dir);
    encoder_data1();
    //    Serial.println(encoder_1);
    if (abs(encoder_1 - last_encoder_count1) >= data) {
      Serial.println("ENC1 :: " + String(encoder_1));
      encoder_data0();
      Serial.println("**ENC0 :: " + String(encoder_0));
      encoder0_offset += encoder_0 - last_encoder_count0;
      stop();
      ch = 's';
    }
  }
}
/////////////////////////////////////
/////////////////////////////////////
void stop() {
  //0
  digitalWrite(m[0].a, HIGH);
  digitalWrite(m[0].b, HIGH);
  //1
  digitalWrite(m[1].a, HIGH);
  digitalWrite(m[1].b, HIGH);
  //2
  digitalWrite(m[2].a, HIGH);
  digitalWrite(m[2].b, HIGH);
  //
  analogWrite(m[0].pwm_pin, 0);
  analogWrite(m[1].pwm_pin, 0);
  analogWrite(m[2].pwm_pin, 0);
}
void left_value() {
  digitalWrite(m[0].a, HIGH);
  digitalWrite(m[0].b, LOW);
  digitalWrite(m[1].a, LOW);
  digitalWrite(m[1].b, HIGH);
  digitalWrite(m[2].a, LOW);
  digitalWrite(m[2].b, HIGH);
  analogWrite(m[0].pwm_pin, 38);
  analogWrite(m[1].pwm_pin, 50);
  analogWrite(m[2].pwm_pin, 38);
}
//
void right_value() {
  digitalWrite(m[0].a, LOW);
  digitalWrite(m[0].b, HIGH);
  digitalWrite(m[1].a, HIGH);
  digitalWrite(m[1].b, LOW);
  digitalWrite(m[2].a, HIGH);
  digitalWrite(m[2].b, LOW);
  analogWrite(m[0].pwm_pin, 38);
  analogWrite(m[1].pwm_pin, 50);
  analogWrite(m[2].pwm_pin, 38);
}
//////////////////////////////
//////////////////////////////
void clamp(int data, int d_angle) {
  reset_gripper();
  digitalWrite(m[0].a, HIGH);
  digitalWrite(m[0].b, LOW);
  //1///
  digitalWrite(m[1].a, HIGH);
  digitalWrite(m[1].b, HIGH);
  //2
  digitalWrite(m[2].a, HIGH);
  digitalWrite(m[2].b, LOW);
  //
  m[0].pwm = m[2].pwm = speed[fast];
  analogWrite(m[0].pwm_pin, m[0].pwm);
  analogWrite(m[1].pwm_pin, 0);
  analogWrite(m[2].pwm_pin, m[0].pwm);
  //
  myPID.SetTunings(kp[fast], ki[fast], kd[fast]);

  while (ch != 's') {
    encoder_data0();
    pid_yaw(d_angle);
    if (encoder_0 > data && pid_set_value == true) {
      m[0].pwm = m[2].pwm = speed[slow];
      analogWrite(m[0].pwm_pin, m[0].pwm);
      analogWrite(m[2].pwm_pin, m[0].pwm);
      myPID.SetTunings(kp[slow], ki[slow], kd[slow]);
      pid_set_value = false;
      digitalWrite(a_l, HIGH);
      digitalWrite(b_l, LOW);
      analogWrite(pwm_l, 150);
    }
    if (encoder_0 > data + 1600) {
      //      pid_yaw(d_angle);
      digitalWrite(a_l, LOW);
      digitalWrite(b_l, HIGH);
      analogWrite(pwm_l, 210);
      stop();
      fuse(1350, 2090, 600);
      fuse(1100, 2080, 300);
      digitalWrite(a_l, LOW);
      digitalWrite(b_l, LOW);
      analogWrite(pwm_l, 0);
      ch = 's';
      gripper_call();
    }
  }
}
