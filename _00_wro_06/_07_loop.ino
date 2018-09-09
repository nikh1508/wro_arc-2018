void loop() {
  //  sequence();
  //  servo_camera();
  //  rotate_desired = 90;
  //  ch='r';
  //  move(ch);
  //  while(1);
  ch = 'r';
  while (ch != 's') {
    right();
    encoder_data1();
    Serial.println(encoder_1);
  }
while(1);
}
//LEFT
//digitalWrite(m[0].a, HIGH);
//digitalWrite(m[0].b, LOW);
//digitalWrite(m[1].a, LOW);
//digitalWrite(m[1].b, HIGH);
//digitalWrite(m[2].a, LOW);
//digitalWrite(m[2].b, HIGH);
//  analogWrite(m[0].pwm_pin, 38);
//  analogWrite(m[1].pwm_pin, 50);
//  analogWrite(m[2].pwm_pin, 38);

//RIGHT
//digitalWrite(m[0].a, LOW);
//digitalWrite(m[0].b, HIGH);
//digitalWrite(m[1].a, HIGH);
//digitalWrite(m[1].b, LOW);
//digitalWrite(m[2].a, HIGH);
//digitalWrite(m[2].b, LOW);
//analogWrite(m[0].pwm_pin, 39);
//analogWrite(m[1].pwm_pin, 51);
//analogWrite(m[2].pwm_pin, 38);
