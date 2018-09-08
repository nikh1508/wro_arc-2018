void loop() {
  cur = millis();
  cur - prev == 0 ? time = 1 : time = cur - prev;
  /////
  sequence();
  servo_camera();
  prev_error = error;//pid
  prev = cur;//dt
}
