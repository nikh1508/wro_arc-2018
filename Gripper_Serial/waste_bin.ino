///SECOND TEST
//void startSequence() {
//  long start_time = millis();
//  ///STEP-1
//  arm_cur = 1935;
//  gripper_cur = 1920;
//  while (millis() - start_time < steps[0]) {
//    changeAngle();
//  }
//  ///STEP-2
//  gripper_cur = 1000;
//  start_time = millis();
//  while (millis() - start_time < steps[1]) {
//    changeAngle();
//  }
//  ///STEP-3
//  arm_cur = 1800;
//  start_time = millis();
//  while (millis() - start_time < steps[2]) {
//    changeAngle();
//  }
//}
/*
  ///FIRST TEST
  void startSequence() {
  long start_time = millis();
  ///STEP-1
  arm_cur = 1650;
  gripper_cur = 1990;
  while (millis() - start_time < steps[0]) {
    changeAngle();
  }
  ///STEP-2
  gripper_cur = 1900;
  start_time = millis();
  while (millis() - start_time < steps[1]) {
    changeAngle();
  }
  ///STEP-3
  arm_cur = 1700;
  start_time = millis();
  while (millis() - start_time < steps[2]) {
    changeAngle();
  }
  ///STEP-4
  gripper_cur = 1700;
  start_time = millis();
  while (millis() - start_time < steps[3]) {
    changeAngle();
  }
  ///STEP-5
  gripper_cur = 750;
  start_time = millis();
  while (millis() - start_time < steps[4]) {
    changeAngle();
  }
  ///STEP-6
  gripper_cur = 1100;
  start_time = millis();
  while (millis() - start_time < steps[5]) {
    changeAngle();
  }
  }
*/
//THIRD TEST
//void startSequence() {
//  startStep(1920, 1935, 0);
//  startStep(1750, -1, 0);
//  startStep(-1, 2010, 0);
//  startStep(1200, -1, 0);
//  startStep(-1, 1800, 0);
//  startStep(1000, -1, 0);
//}

//FOURTH TEST
//void startSequence(bool blue = false) {
//  fuse(1350, 1979, 700);
//  startStep(1290, 1500, -1, -1);
//  if (blue)
//    fuse(1270, 1600, 600);//blue
//  else
//    fuse(1310, 1600, 700);
//  while (!Serial.available()); char ch = Serial.read();
//  //delay(1200);
//  startStep(1000, 1200, 1300, 1000 );
//  startStep(900, 1500, 1200, 1500 );
//}

//FIFTH TEST
void startSequence() {
  fuse(1450, 2210, 400);
  startStep(1300, 2220, -1, -1);
  fuse(1370, 1900, 600);
  startStep(900, 1500, 1200, 1500 );
  fuse(1600, 1100, 700);
  fuse(1600, 1600, 500);
}
