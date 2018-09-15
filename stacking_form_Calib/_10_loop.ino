void loop() {
  if (Serial.available()) {
    char ch = Serial.read();

    if (ch == 's')
      gripper_call();

    if (ch == 'a') {
      while (!Serial.available());
      arm_cur = Serial.parseInt();
      Serial.print("Arm :: "); Serial.println(arm_cur);
    }
    else if (ch == 'g') {
      while (!Serial.available());
      gripper_cur = Serial.parseInt();
      Serial.print("Gripper :: "); Serial.println(gripper_cur);
    }
    else if (ch == 'r') {
      //      Serial.println("here");
      reset_gripper();
      Serial.println("reset");
    }
    else if (ch == 'q') {
      int x = Serial.parseInt();
      Serial.print("ARM :: ");
      Serial.println(x);
      int arm_change = x - arm_cur;
      int temp = (0.26 * float(arm_change));
      temp += + gripper_cur;
      //      Serial.println(arm_change);
      fuse(x, 0.26 * float(arm_change) + gripper_cur, ((abs(arm_change)) / 100) * 250);
      Serial.println("GRIPPER [Q-Mot]:: " + String(temp));
    }
    else if (ch == '1') {
      Serial.println("Step-1");
      //      startStep(-1, -1, 1979, 500 );
      fuse(1300, 2110, 600);
      fuse(1100, 2100, 300);
    }
    else if (ch == '2') {
      Serial.println("Step-2");
      fuse(1155, 1780, 800); //non-blue
    }
    else if (ch == '3') {
      Serial.println("Step-3");
      //startStep(1310, 1200, 1600, 300);
      //      fuse(1270, 1600, 600);//blue
      fuse(775, 1500, 700);
    }
    else if (ch == '4') {
      Serial.println("Step-4");
      fuse(1700, 1100, 700);
      fuse(1700, 1500, 500);
    }
    else if (ch == 'T') {
      resetDrive();
    }
    else if (ch == 'S') {
      dump_error(400, 400, 0);
    }
    else if (ch == 'D') {
      dump_error(400, 400, 0, 1);
    }
    else if (ch == 'F') {
      while (!Serial.available());
      int fwd = Serial.parseInt();
      Serial.print("FORWARD :: "); Serial.println(fwd);
      move_encoder_only(1, abs(fwd), 0);
    }
    else if (ch == 'B') {
      while (!Serial.available());
      int bkd = Serial.parseInt();
      Serial.print("BACKWRD :: "); Serial.println(bkd);
      move_encoder_only(0, abs(bkd), 0);
    }

    else if (ch == 'L') {
      while (!Serial.available());
      int lft = Serial.parseInt();
      Serial.print("LEFT :: "); Serial.println(lft);
      sideways(0, abs(lft), 0);
    }

    else if (ch == 'R') {
      while (!Serial.available());
      int rt = Serial.parseInt();
      Serial.print("RIGHT :: "); Serial.println(rt);
      sideways(1, abs(rt), 0);
    }
    else if (ch == 'C') {
      Serial.println("Gripper Detached");
      gripper.detach();
      detached = true;
    }
    else if (ch == 'A') {
      Serial.println("Gripper Attached");
      gripper.attach(grip_pin, 750, 2250);
      detached = false;
    }

    else if (ch == 'W') { //BLUE-SEQ -- ORANGE
      dump_error(400, 400, 0);
      delay(100);
      fuse(1700, 1100, 600);
      move_encoder_only(1, 2800, 0);
      delay(100);
      fuse(1700, 1640, 800);
      delay(100);
      move_encoder_only(1, 370, 0);
      delay(100);
      int x = 1265;
      int arm_change = x - arm_cur;
      //      int temp = (0.26 * float(arm_change));
      //      temp += + gripper_cur;
      fuse(x, 0.26 * float(arm_change) + gripper_cur, ((abs(arm_change)) / 100) * 250);
      delay(100);
      sideways(0, 250, 0);
      delay(100);
      move_encoder_only(1, 30, 0);
      delay(100);
      gripper.detach();
      detached = true;
      move_encoder_only(0, 3000, 0);
    }

    else if (ch == 'X') {//BLUE-SEQ -- RED
      fuse(1700, 1100, 600);
      delay(100);
      dump_error(400, 400, 0);
      delay(100);
      move_encoder_only(1, 2800, 0);
      delay(100);
      dump_error(400, 400, 0, 1);
      delay(100);
      sideways(1, 450, 0);
      delay(100);
      fuse(1700, 1640, 800);
      delay(100);
      move_encoder_only(1, 370, 0);
      delay(100);
      int x = 1265;
      int arm_change = x - arm_cur;
      //      int temp = (0.26 * float(arm_change));
      //      temp += + gripper_cur;
      fuse(x, 0.26 * float(arm_change) + gripper_cur, ((abs(arm_change)) / 100) * 250);
      delay(100);
      sideways(0, 150, 0);
      delay(100);
      gripper.detach();
      detached = true;
      delay(100);
      move_encoder_only(1, 30, 0);
      delay(50);
      move_encoder_only(0, 3000, 0);
    }
    else if (ch == 'Y') { //BLUE-SEQ -- D-Blue  //YELLOW-SEQ -- D-Blue
      fuse(1700, 1100, 600);
      delay(100);
      dump_error(400, 400, 0);
      delay(100);
      move_encoder_only(1, 2800, 0);
      delay(100);
      dump_error(400, 400, 0, 1);
      delay(100);
      sideways(1, 750, 0);
      delay(100);
      fuse(1700, 1500, 800);
      delay(100);
      move_encoder_only(1, 370, 0);
      delay(100);
      sideways(1, 360, 0);
      delay(100);
      fuse(1700, 1640, 800);
      delay(100);
      int x = 1265;
      int arm_change = x - arm_cur;
      //      int temp = (0.26 * float(arm_change));
      //      temp += + gripper_cur;
      fuse(x, 0.26 * float(arm_change) + gripper_cur, ((abs(arm_change)) / 100) * 250);
      delay(100);
      gripper.detach();
      detached = true;
      delay(100);
      move_encoder_only(1, 200, 0);
      delay(50);
      move_encoder_only(0, 3000, 0);
    }
    else if (ch == 'Z') { //YELLOW-SEQ -- Orange
      fuse(1700, 1100, 600);
      delay(100);
      dump_error(400, 400, 0);
      delay(100);
      move_encoder_only(1, 2800, 0);
      delay(100);
      dump_error(400, 400, 0, 1);
      delay(100);
      sideways(1, 50, 0);
      delay(100);
      fuse(1700, 1640, 800);
      delay(100);
      move_encoder_only(1, 370, 0);
      delay(100);
      int x = 1265;
      int arm_change = x - arm_cur;
      //      int temp = (0.26 * float(arm_change));
      //      temp += + gripper_cur;
      fuse(x, 0.26 * float(arm_change) + gripper_cur, ((abs(arm_change)) / 100) * 250);
      delay(100);
      sideways(0, 100, 0);
      delay(100);
      move_encoder_only(1, 70, 0);
      delay(50);
      gripper.detach();
      detached = true;
      delay(100);
      move_encoder_only(0, 3000, 0);
    }
    else if (ch == 'P') { //GREEN-SEQ -- RED
      fuse(1700, 1100, 600);
      delay(100);
      dump_error(400, 400, 0);
      delay(100);
      move_encoder_only(1, 2800, 0);
      delay(100);
      dump_error(400, 400, 0, 1);
      delay(100);
      sideways(1, 750, 0);
      delay(100);
      fuse(1700, 1500, 800);
      delay(100);
      move_encoder_only(1, 370, 0);
      delay(100);
      sideways(1, 600, 0);
      delay(100);
      fuse(1700, 1640, 800);
      delay(100);
      int x = 1265;
      int arm_change = x - arm_cur;
      //      int temp = (0.26 * float(arm_change));
      //      temp += + gripper_cur;
      fuse(x, 0.26 * float(arm_change) + gripper_cur, ((abs(arm_change)) / 100) * 250);
      delay(100);
      gripper.detach();
      detached = true;
      delay(100);
      move_encoder_only(1, 200, 0);
      delay(50);
      move_encoder_only(0, 3000, 0);
    }
    else if (ch == 'Q') { //GREEN-SEQ -- BLUE_LEFT
      fuse(1900, 1100, 600);
      delay(100);
      dump_error(400, 400, 0);
      delay(100);
      move_encoder_only(1, 2800, 0);
      delay(100);
      dump_error(400, 400, 0, 1);
      delay(100);
      fuse(1900, 1500, 800);
      delay(100);
      move_encoder_only(1, 370, 0);
      delay(100);
      fuse(1700, 1640, 800);
      delay(100);
      sideways(0, 465, 0);
      delay(100);
      move_encoder_only(1, 30, 0);
      delay(100);
      sideways(0, 100, 0);
      delay(100);
      gripper.detach();
      detached = true;
      delay(100);
      move_encoder_only(0, 3000, 0);
    }
    else if (ch == 'R') { //GREEN-SEQ -- BLUE_RIGHT
      fuse(1900, 1100, 600);
      delay(100);
      dump_error(400, 400, 0);
      delay(100);
      move_encoder_only(1, 2800, 0);
      delay(100);
      dump_error(400, 400, 0, 1);
      delay(100);
      fuse(1900, 1400, 800);
      delay(100);
      move_encoder_only(1, 340, 0);
      delay(100);
      sideways(1, 750, 0);
      delay(100);
      fuse(1700, 1640, 800);
      delay(100);
      move_encoder_only(1, 150, 0);
      delay(100);
      gripper.detach();
      detached = true;
      delay(100);
      move_encoder_only(0, 3000, 0);
    }
  }
  changeAngle();
}
