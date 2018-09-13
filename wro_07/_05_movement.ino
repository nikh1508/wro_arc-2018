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
      if (encoder_0 >= data && encoder_0 < data + 300 && pid_set_value == true) {
        m[0].pwm = m[2].pwm = speed[slow];
        myPID.SetTunings(kp[slow], ki[slow], kd[slow]);
        pid_set_value = false;
      }
      if (encoder_0 >= data + 300) {
        line_stop();
      }
    }
  }
}
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
void move_encoder_only(int n, int data, int d_angle) {
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
      if (encoder_0 >= data && encoder_0 < data + 300 && pid_set_value == true) {
        m[0].pwm = m[2].pwm = speed[slow];
        myPID.SetTunings(kp[slow], ki[slow], kd[slow]);
        pid_set_value = false;
      }
      if (encoder_0 >= data + 300) {
        stop();
        ch = 's';
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
      if (encoder_0 >= data && encoder_0 < data + 300 && pid_set_value == true) {
        m[0].pwm = m[2].pwm = speed[slow];
        myPID.SetTunings(kp[slow], ki[slow], kd[slow]);
        pid_set_value = false;
      }
      if (encoder_0 >= data + 300) {
        stop();
        ch = 's';
      }
    }
  }
}
///////////////////////////
///////////////////////////
void sideways(int data) {
  if (direction[index][motion] > 0) //right
    right_value();
  else //left
    left_value();
  while (ch != 's') {
    encoder_data0();
    if (encoder_0 >= data) {
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
  analogWrite(m[0].pwm_pin, 39);
  analogWrite(m[1].pwm_pin, 51);
  analogWrite(m[2].pwm_pin, 38);
}
//////////////////////////////
//////////////////////////////
void clamp(int data, int d_angle) {
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
      fuse(1300, 2120, 600);
      fuse(1100, 2110, 300);
      digitalWrite(a_l, LOW);
      digitalWrite(b_l, LOW);
      analogWrite(pwm_l, 0);
      ch = 's';
      gripper_call();
    }

  }
}
