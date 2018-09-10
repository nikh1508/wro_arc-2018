bool flag_speed = true;
void loop() {
  /////
  //  pid_yaw(360.0);
  if (test == true) {
    if (flag_speed == true) {
      flag_speed = false;
      m[0].pwm = 45;
      m[2].pwm = 45;
    }
    pid_yaw(360.0);
    ch = 'f';
    move(ch);
  }
  if (test == false) {
    ch = 's';
    move(ch);
    flag_speed = true;
  }
  fetchData();
}
