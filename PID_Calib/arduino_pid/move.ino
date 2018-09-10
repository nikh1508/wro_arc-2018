void forward(int a, int b) {
  //  motor_pin_reset();
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
  //  motor_pin_reset();
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
void rotate(double d_angle) {
  bno();
  if (d_angle < 0) {
    d_angle = d_angle * (-1.0);
    int lower_v, upper_v;
    lower_v = d_angle - 0.5;
    upper_v = d_angle + 0.5;
    if (yaw >= lower_v && yaw <= upper_v && d_angle != 360.0) {
      ch = 's';
      move(ch);
    }
    if (d_angle == 360 && yaw >= 359.0) {
      ch = 's';
      move(ch);
    }
  }
  if (d_angle > 0) {
    int lower_v, upper_v;
    lower_v = d_angle - 0.5;
    upper_v = d_angle + 0.5;
    if (yaw >= lower_v && yaw <= upper_v && d_angle != 360) {
      ch = 's';
      move(ch);
    }
    if (d_angle == 360 && yaw >= 358.5) {
      ch = 's';
      move(ch);
    }
  }
}
void move(char c) {
  switch (c) {
    case ('f'): {
        forward(m[0].pwm, m[2].pwm);
        Serial.println("MOVE::" + String(m[0].pwm));
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
    case ('r'): {
        if (rotate_desired < 0) {
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
          analogWrite(m[0].pwm_pin, 50);//
          analogWrite(m[1].pwm_pin, 50);//
          analogWrite(m[2].pwm_pin, 65);//
          //
        }
        //
        if (rotate_desired > 0) {
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
          analogWrite(m[0].pwm_pin, 50);//
          analogWrite(m[1].pwm_pin, 50);//
          analogWrite(m[2].pwm_pin, 65);//
        }
        while (ch != 's')
          rotate(rotate_desired);
        break;
      }
    default: {
        //        Serial.println("Default Hit LOCO");
        break;
      }
  }

}
