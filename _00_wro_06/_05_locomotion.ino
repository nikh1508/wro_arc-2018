void forward(int a, int b) {
  //  motor_pin_reset();
  //0
  digitalWrite(m[0].a, HIGH);
  digitalWrite(m[0].b, LOW);
  //1///
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

void left() {
  digitalWrite(m[0].a, HIGH);
  digitalWrite(m[0].b, LOW);
  digitalWrite(m[1].a, LOW);
  digitalWrite(m[1].b, HIGH);
  digitalWrite(m[2].a, LOW);
  digitalWrite(m[2].b, HIGH);
  analogWrite(m[0].pwm_pin, 38);
  analogWrite(m[1].pwm_pin, 50);
  analogWrite(m[2].pwm_pin, 38);
  line_stop_prependicular();
}

void right() {
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
int rot_0 = 100, rot_2 = 100;
double rot_1 = 100;
double rot_Kp = 0.0010;
int var, var1;
void calcPWMforRotation() {
  encoder_data();
  encoder_data1();
  rot_1 += (rot_Kp * double(rpm - rpm1));
  //  Serial.print(rpm);
  //  Serial.print("\t");
  //  Serial.println(rpm1);
}

void rotate(double d_angle) {
  bno();
  //  Serial.println(yaw);
  if (d_angle < 0) {
    d_angle = d_angle * (-1.0);
    double lower_v, upper_v;
    lower_v = d_angle - 1.0;
    upper_v = d_angle + 1.0;
    if (yaw >= lower_v && yaw <= upper_v && d_angle != 360.0) {
      ch = 's';
      move(ch);
    }
    if (d_angle == 360 && yaw >= 359.0) {
      ch = 's';
      move(ch);
    }
  }
  else  {
    double lower_v, upper_v;
    lower_v = d_angle - 1.0;
    upper_v = d_angle + 1.0;
    while (!(yaw >= lower_v && yaw <= upper_v && d_angle != 360)) {
      bno();
      calcPWMforRotation();
      analogWrite(m[1].pwm_pin, constrain((int)rot_1, 0, 255));
      Serial.println(yaw);
    }
    ch = 's';
    move(ch);
  }
  if (d_angle == 360 && yaw >= 359.0) {
    ch = 's';
    move(ch);
  }
}


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
          analogWrite(m[0].pwm_pin, rot_0);//
          analogWrite(m[1].pwm_pin, rot_1);//
          analogWrite(m[2].pwm_pin, rot_2);//
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
          analogWrite(m[0].pwm_pin, rot_0);//
          analogWrite(m[1].pwm_pin, rot_1);//
          analogWrite(m[2].pwm_pin, rot_2);//
        }
        while (ch != 's') {
          rotate(rotate_desired);
          calcPWMforRotation();
          analogWrite(m[1].pwm_pin, constrain((int)rot_1, 0, 255));//
          //          Serial.println(constrain((int)rot_1, 0, 255));
        }
        break;
      }
    default: {
        //        Serial.println("Default Hit LOCO");
        break;
      }
  }

}
