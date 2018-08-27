#define fused_motion_debug false

void fuse(int arm, int gripper, int time) {
  float gripper_diff = abs(gripper_last - gripper);
  float arm_diff = abs(arm_last - arm);
  float arm_new = arm_last, gripper_new = gripper_last;
  long last = micros();;
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
}
