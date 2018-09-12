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
      if (encoder_0 > data)
      {
        m[0].pwm = m[2].pwm = speed[slow];
        myPID.SetTunings(kp[slow], ki[slow], kd[slow]);
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
    m[0].pwm = m[2].pwm = speed;
    analogWrite(m[0].pwm_pin, m[0].pwm);
    analogWrite(m[1].pwm_pin, 0);
    analogWrite(m[2].pwm_pin, m[0].pwm);
    //
    while (ch != 's') {
      pid_yaw(d_angle);
      encoder_data0();
      if (encoder_0 < data)
        line_stop();
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
    m[0].pwm = m[2].pwm = speed;
    analogWrite(m[0].pwm_pin, m[0].pwm);
    analogWrite(m[1].pwm_pin, 0);
    analogWrite(m[2].pwm_pin, m[0].pwm);
    //
    while (ch != 's') {
      pid_yaw(d_angle);
      encoder_data0();
      if (encoder_0 > data) {
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
    m[0].pwm = m[2].pwm = speed;
    analogWrite(m[0].pwm_pin, m[0].pwm);
    analogWrite(m[1].pwm_pin, 0);
    analogWrite(m[2].pwm_pin, m[0].pwm);
    //
    while (ch != 's') {
      pid_yaw(d_angle);
      encoder_data0();
      if (encoder_0 < data) {
        stop();
        ch = 's';
      }
    }
  }
}
///////////////////////////
///////////////////////////
void sideways(int data) {
  encoder_data0();
  if (encoder_0 >= data) {
    stop();
    ch = 's';
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
//////////////////////////////
//////////////////////////////
void clamp(int data, int d_angle) {
  while (ch != 's') {
    digitalWrite(m[0].a, HIGH);
    digitalWrite(m[0].b, LOW);
    //1///
    digitalWrite(m[1].a, HIGH);
    digitalWrite(m[1].b, HIGH);
    //2
    digitalWrite(m[2].a, HIGH);
    digitalWrite(m[2].b, LOW);
    //
    analogWrite(m[0].pwm_pin, speed);
    analogWrite(m[1].pwm_pin, 0);
    analogWrite(m[2].pwm_pin, speed);
    encoder_data0();
    if (encoder_0 > data) {
      pid_yaw(d_angle);
      digitalWrite(a_l, HIGH);
      digitalWrite(b_l, LOW);
      analogWrite(pwm_l, 150);
    }
    if (encoder_0 > data + 200) {
      pid_yaw(d_angle);
      digitalWrite(a_l, LOW);
      digitalWrite(b_l, HIGH);
      analogWrite(pwm_l, 150);
    }
    if (encoder_0 > data + 250) {
      pid_yaw(d_angle);
      digitalWrite(a_l, LOW);
      digitalWrite(b_l, LOW);
      analogWrite(pwm_l, 0);
      stop();
    }
  }
}
