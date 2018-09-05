void forward(int a, int b) {
  //0
  digitalWrite(m[0].a, HIGH);
  digitalWrite(m[0].b, LOW);
  //1
  digitalWrite(m[1].a, HIGH);
  digitalWrite(m[1].b, HIGH);
  //2
  digitalWrite(m[2].a, HIGH);
  digitalWrite(m[2].b, LOW);
  //
  analogWrite(m[0].pwm_pin, a);
  analogWrite(m[1].pwm_pin, 0);
  analogWrite(m[2].pwm_pin, b);
}
//
void backward(int a, int b) {
  //0
  digitalWrite(m[0].a, LOW);
  digitalWrite(m[0].b, HIGH);
  //1
  digitalWrite(m[1].a, HIGH);
  digitalWrite(m[1].b, HIGH);
  //2
  digitalWrite(m[2].a, LOW);
  digitalWrite(m[2].b, HIGH);
  //
  analogWrite(m[0].pwm_pin, a);
  analogWrite(m[1].pwm_pin, 0);
  analogWrite(m[2].pwm_pin, b);
}
//
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
//
void ccw_90() {
  bno();
  if (yaw > (-90.0)) {
    //0
    digitalWrite(m[0].a, HIGH);
    digitalWrite(m[0].b, LOW);
    //1
    digitalWrite(m[1].a, HIGH);
    digitalWrite(m[1].b, LOW);
    //2
    digitalWrite(m[2].a, LOW);
    digitalWrite(m[2].b, HIGH);
    //
    analogWrite(m[0].pwm_pin, 30);
    analogWrite(m[1].pwm_pin, 30);
    analogWrite(m[2].pwm_pin, 30);
  }
  if (yaw <= -90.0) {
    ch = 's';
    yaw_offset += yaw;
    yaw = 0;
    move(ch);
  }
}
////////
void ccw_45() {
  bno();
  if (yaw > (-45.0)) {
    //0
    digitalWrite(m[0].a, HIGH);
    digitalWrite(m[0].b, LOW);
    //1
    digitalWrite(m[1].a, HIGH);
    digitalWrite(m[1].b, LOW);
    //2
    digitalWrite(m[2].a, LOW);
    digitalWrite(m[2].b, HIGH);
    //
    analogWrite(m[0].pwm_pin, 30);
    analogWrite(m[1].pwm_pin, 30);
    analogWrite(m[2].pwm_pin, 30);
  }
  if (yaw <= -45.0) {
    ch = 's';
    yaw_offset += yaw;
    yaw = 0;
    move(ch);
  }
}
////////
void cw_90() {
  bno();
  if (yaw < 90.0) {
    //0
    digitalWrite(m[0].a, LOW);
    digitalWrite(m[0].b, HIGH);
    //1
    digitalWrite(m[1].a, LOW);
    digitalWrite(m[1].b, HIGH);
    //2
    digitalWrite(m[2].a, HIGH);
    digitalWrite(m[2].b, LOW);
    //
    analogWrite(m[0].pwm_pin, 30);
    analogWrite(m[1].pwm_pin, 30);
    analogWrite(m[2].pwm_pin, 30);
  }
  if (yaw >= 90.0) {
    ch = 's';
    yaw_offset += yaw;
    yaw = 0;
    move(ch);
  }
}
///////
void cw_45() {
  bno();
  if (yaw < 45.0) {
    //0
    digitalWrite(m[0].a, LOW);
    digitalWrite(m[0].b, HIGH);
    //1
    digitalWrite(m[1].a, LOW);
    digitalWrite(m[1].b, HIGH);
    //2
    digitalWrite(m[2].a, HIGH);
    digitalWrite(m[2].b, LOW);
    //
    analogWrite(m[0].pwm_pin, 30);
    analogWrite(m[1].pwm_pin, 30);
    analogWrite(m[2].pwm_pin, 30);
  }
  if (yaw >= 45.0) {
    ch = 's';
    yaw_offset += yaw;
    yaw = 0;
    move(ch);
  }
}
///////
void move(char c) {
  switch (c) {
    case ('f'): {
        forward(m[0].pwm, m[2].pwm);
        break;
      }
    case ('b'): {
        backward(m[0].pwm, m[2].pwm);
        break;
      }
    case ('s'): {
        stop();
        break;
      }
    case ('q'): {
        while (ch != 's')
          ccw_90();
        break;
      }
    case ('e'): {
        while (ch != 's')
          cw_90();
        break;
      }
    case ('k'): {
        while (ch != 's')
          ccw_45();
        break;
      }
    case ('l'): {
        while (ch != 's')
          cw_45();
        break;
      }
      ////
    default: {
        Serial.println("Default Hit LOCO");
        break;
      }
  }
}
