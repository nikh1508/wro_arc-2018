void loop() {
//  reset_gripper();
//  while(!Serial.available());
//  char ch = Serial.read();
//  green__orange_dblue();
//  while(1);
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
