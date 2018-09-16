double rotationSpeed, initialSpeed;
bool timeOut = false;
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

void rotateTo(double angle, int dir, int ROT_SPEED = 130) {
  timeOut = false;
  reset_encoder();
  initialSpeed = rotationSpeed = ROT_SPEED;
  angle = abs1(angle);
  bno();
  double initialDiff = abs1(diff(angle, yaw));
  double divisor =  initialDiff / 90.0;
  double currentDiff = initialDiff;
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
  long long last_time = millis();
  encoder_data0();
  encoder_data1();
  int lastEncCtr0 = encoder_0, lastEncCtr1 = encoder_1;
  while (currentDiff > 1.0 && !timeOut) {
    //    Serial.println(yaw);
    bno();
    currentDiff = abs1(diff(angle, yaw));
    if (currentDiff < (initialDiff / 2.0) && millis() - last_time > 100) {
      last_time = millis();
      encoder_data0();
      encoder_data1();
      if (lastEncCtr0 == encoder_0 && lastEncCtr1 == encoder_1) {
        Serial.println("Rotation Timeout");
        timeOut = true;
      }
      lastEncCtr0 = encoder_0;
      lastEncCtr1 = encoder_1;
    }
    analogWrite(m[0].pwm_pin, rotationSpeed);
    analogWrite(m[1].pwm_pin, rotationSpeed);
    analogWrite(m[2].pwm_pin, rotationSpeed);
    rotationSpeed = sin( (abs1(diff(angle, yaw)) / divisor) / 180.0 * 3.14) * initialSpeed;
    //    delay(2);
  }
  stop();
  ch = 's';
  //  rotate_desired = angle;
  bno();
  //  Serial.println("Current YAW::"+String(yaw));
}
