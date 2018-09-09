void gripper_call() {
  ch = 's';
  move(ch);
  delay(100);
  fuse(1300, 2120, 600);
  fuse(1100, 2110, 300);
  fuse(1200, 1760, 600); //non-blue
  fuse(800, 1500, 700);
  fuse(1700, 1100, 700);
  fuse(1700, 1500, 500);
}
/////////////////////////////////////////
/////////////////////////////////////////
void reset_gripper() {
  //long start = millis();
  arm_cur = ARM_INIT;
  gripper_cur = GRIPPER_INIT;
  fuse(ARM_INIT, GRIPPER_INIT, 500);
}
/////////////////////
/////////////////////
void fuse(int arm, int gripper, int time) {
  //  Serial.println(gripper);
  //  Serial.println(time);
  float gripper_diff = abs(gripper_last - gripper);
  float arm_diff = abs(arm_last - arm);
  float arm_new = arm_last, gripper_new = gripper_last;
  long last = micros();
  if (max(gripper_diff, arm_diff) == gripper_diff) {
    long time_inc = (long(time) * 1000) / gripper_diff;
    float inc = arm_diff / gripper_diff;
    if ((arm - arm_last) < 0)
      inc *= -1.0;
    while (gripper_last != gripper) {
      (gripper > gripper_last) ? gripper_last++ : gripper_last--;
      arm_new += inc;
      arm_last = arm_new;
      while ((micros() - last) < time_inc);
      last = micros();
      ::arm.writeMicroseconds(constrain(arm_last, 750, 2250));
      ::gripper.writeMicroseconds(constrain(gripper_last, 750, 2250));
      if (fused_motion_debug)
        Serial.println("ARM :: " + String(arm_last) + "\t GRIPPER :: " + String(gripper_last));
    }
  }
  else {
    long time_inc = (long(time) * 1000) / arm_diff;
    float inc = gripper_diff / arm_diff;
    if ((gripper - gripper_last) < 0)
      inc *= -1.0;
    while (arm_last != arm) {
      (arm > arm_last) ? arm_last++ : arm_last--;
      gripper_new += inc;
      gripper_last = gripper_new;
      while ((micros() - last) < time_inc);
      last = micros();
      ::arm.writeMicroseconds(constrain(arm_last, 750, 2250));
      ::gripper.writeMicroseconds(constrain(gripper_last, 750, 2250));
      if (fused_motion_debug)
        Serial.println("ARM :: " + String(arm_last) + "\t GRIPPER :: " + String(gripper_last));
    }
  }
  gripper_cur = gripper_last;
  arm_cur = arm_last;
}
/////////////////////////////////////////
/////////////////////////////////////////

/////////////////////////////////////////
/////////////////////////////////////////
void servo_camera() {
  int state_sqc_pin;
  state_sqc_pin = digitalRead(sqc_pin);
  if (state_sqc_pin == 1 && sqc == 101)
    camera.writeMicroseconds(900);
  //
  if (state_sqc_pin == 1 && sqc == 102)
    camera.writeMicroseconds(1150);
  //
  if (state_sqc_pin == 1 && sqc == 103)
    camera.writeMicroseconds(1000);
  //
  if (state_sqc_pin == 1 && sqc == 104)
    camera.writeMicroseconds(1080);
  //
  if (state_sqc_pin == 1 && sqc == 105)
    camera.writeMicroseconds(1000);
  //
  if (state_sqc_pin == 1 && sqc == 106)
    camera.writeMicroseconds(980);
}
