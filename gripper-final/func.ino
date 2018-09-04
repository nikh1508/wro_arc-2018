#define fused_motion_debug false

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

void startStep(int arm,  int nw_arm_dly, int gripper, int nw_gripper_dly) {
  //  long start_time = millis();
  if (arm != -1)
    arm_cur = arm;
  if (gripper != -1)
    gripper_cur = gripper;
  if (nw_gripper_dly != -1)
    GRIPPER_DLY = nw_gripper_dly;
  if (nw_arm_dly != -1)
    ARM_DLY = nw_arm_dly;
  while (gripper_cur != gripper_last || arm_cur != arm_last) {
    changeAngle();
  }

}

void reset() {
  //long start = millis();
  arm_cur = ARM_INIT;
  gripper_cur = GRIPPER_INIT;
  GRIPPER_DLY = 1200;
  ARM_DLY = 2500;
  while (gripper_cur != gripper_last || arm_cur != arm_last) {
    changeAngle();
  }
}

void startSequence() {
  fuse(1350, 2200, 400);
  startStep(1150, 2220, -1, -1);
  fuse(1220, 1900, 600);
  startStep(750, 1500, 1200, 1500 );
  fuse(1450, 1100, 700);
  fuse(1600, 1650, 500);
  Serial.println("waiting to exeute next step.");
  while(!Serial.available());
  char ch = Serial.read();
  arm_cur = 1350;
}

