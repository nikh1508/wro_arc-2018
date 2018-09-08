void loop() {
  /////
  if (test == true) {
    lpf(60);//input_speed for low pass filter
    ch = 'f';
    move(ch);
  }
  if (test == false) {
    ch = 's';
    move(ch);
    prev_output = 0.0;
    m[0].pwm = 0;
    m[2].pwm = 0;
  }
  pid_yaw(360.0);
}
