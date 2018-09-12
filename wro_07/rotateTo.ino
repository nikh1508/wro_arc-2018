double rotationSpeed, initialSpeed;
double diff(float x, float y) {
  double tmp = abs(x - y);
  double diff = min(tmp, abs(360 - tmp));
  if ((y + diff) != x && (y - diff) != x) {
    if ((x + diff) >= 360)
      return -diff;
    else return diff;
  }
  else return (x - y);
}


double abs1(double x) {
  if (x < 0) return (x * -1.0);
  else return x;
}

void rotateTo(double angle, int dir, int ROT_SPEED=95) {
  initialSpeed = rotationSpeed = ROT_SPEED;
  angle = abs1(angle);
  switch (dir) {
    case CW:
      digitalWrite(m[0].a, LOW);
      digitalWrite(m[0].b, HIGH);
      digitalWrite(m[1].a, LOW);
      digitalWrite(m[1].b, HIGH);
      digitalWrite(m[2].a, HIGH);
      digitalWrite(m[2].b, LOW);
      break;
    case CCW:
      digitalWrite(m[0].a, HIGH);
      digitalWrite(m[0].b, LOW);
      digitalWrite(m[1].a, HIGH);
      digitalWrite(m[1].b, LOW);
      digitalWrite(m[2].a, LOW);
      digitalWrite(m[2].b, HIGH);
      break;
  }
  delay(50);
  encoder_data0();
  encoder_data1();
  bno();
//  Serial.println("here");
  long long last_time = millis();
  while (abs1(diff(angle, yaw)) > 1.0) {
    Serial.println(yaw);
    bno();
    encoder_data0();
    encoder_data1();
    analogWrite(m[0].pwm_pin, rotationSpeed);
    analogWrite(m[1].pwm_pin, rotationSpeed);
    analogWrite(m[2].pwm_pin, rotationSpeed);
    rotationSpeed = sin( abs1(diff(angle, yaw)) / 180.0 * 3.14) * initialSpeed;
//    delay(2);
  }

  stop();
//  rotate_desired = angle;
  bno();
//  Serial.println("Current YAW::"+String(yaw));
}
