bool detached = false;
void gripper_call() {
  //  stop();
  //  ch = 's';
  fuse(1300, 2100, 600);
  fuse(1100, 2090, 300);
  fuse(1155, 1780, 800); //non-blue
  fuse(775, 1500, 700);
  fuse(1700, 1100, 700);
  fuse(1700, 1500, 500);
}
/////////////////////////////////////////

void changeAngle() {
  static long arm_last_us = micros();
  static long gripper_last_us = micros();

  if (gripper_cur != gripper_last)
    if ((micros() - gripper_last_us) > GRIPPER_DLY) {
      gripper_last_us = micros();
      (gripper_cur > gripper_last) ? gripper_last++ : gripper_last--;
      gripper.writeMicroseconds(constrain(gripper_last, 750, 2250));
    }
  if (arm_cur != arm_last)
    if ((micros() - arm_last_us) > ARM_DLY) {
      arm_last_us = micros();
      (arm_cur > arm_last) ? arm_last++ : arm_last--;
      arm.writeMicroseconds(constrain(arm_last, 750, 2250));
    }
}

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
  //  Serial.println(time);
  if (detached) {
    detached = false;
    ::gripper.attach(grip_pin, 750, 2250);
    ::arm.attach(arm_pin, 750, 2250);
    reset_gripper();
  }
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
  if (state_sqc_pin == 1 && index == 101)
    camera.writeMicroseconds(900);
  //
  if (state_sqc_pin == 1 && index == 102)
    camera.writeMicroseconds(1150);
  //
  if (state_sqc_pin == 1 && index == 103)
    camera.writeMicroseconds(1000);
  //
  if (state_sqc_pin == 1 && index == 104)
    camera.writeMicroseconds(1080);
  //
  if (state_sqc_pin == 1 && index == 105)
    camera.writeMicroseconds(1000);
  //
  if (state_sqc_pin == 1 && index == 106)
    camera.writeMicroseconds(980);
}

void retract() {
  fuse(2250, 750, 800);
  detached = true;
  arm.detach();
  gripper.detach();
}
