void loop() {
  sequnece();
  servo_camera();
  if (Serial1.available()) {
    int x = Serial1.read();
    Serial.println(x);
    if (digitalRead(sqc_pin) == HIGH) {
      motion = 0;
      index = x;
    }
    x = 0;
  } 
}
