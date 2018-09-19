void dblue_orange() { //D_BLUE-SEQ - ORANGE
  fuse(1700, 1100, 600);
  delay(100);
  dump_error(600, 600, 270);
  delay(100);
  move_encoder_only(1, FWD_CONST, 270);
  delay(100);
  dump_error(400, 400, 270, 1);
  delay(100);
  sideways(0, 400, 270);
  delay(100);
  fuse(1700, 1640, 800);
  delay(100);
  int x = 1250;
  int arm_change = x - arm_cur;
  fuse(x, 0.26 * float(arm_change) + gripper_cur, ((abs(arm_change)) / 100) * 250);
  move_encoder_only(1, 200, 270);
  delay(100);
  move_encoder_only(0, 50, 270);
  delay(100);
  sideways(0, 200, 270);
  delay(100);
  move_encoder_only(1, 200, 270);
  delay(100);
  gripper.detach();
  detached = true;
  delay(100);
  move_encoder_only(0, 2500, 270);
}
/////////////////////////////////
void orange_dblue() { //orange seq---dblue
  fuse(1700, 1100, 600);
  delay(100);
  dump_error(600, 600, 270);
  delay(100);
  move_encoder_only(1, FWD_CONST, 270);
  delay(100);
  dump_error(400, 400, 270, 1);
  delay(100);
  sideways(1, 750, 270);
  delay(100);
  fuse(1700, 1640, 800);
  delay(100);
  move_encoder_only(1, 200, 270);
  delay(100);
  sideways(1, 600, 270);
  delay(100);
  int x = 1250;
  int arm_change = x - arm_cur;
  //      int temp = (0.26 * float(arm_change));
  //      temp += + gripper_cur;
  fuse(x, 0.26 * float(arm_change) + gripper_cur, ((abs(arm_change)) / 100) * 250);
  delay(100);
  move_encoder_only(1, 200, 270);
  delay(100);
  sideways(1, 100, 270);
  delay(100);
  gripper.detach();
  detached = true;
  delay(100);
  move_encoder_only(0, 2500, 270);
}
///////////////////////////////////////
void red__orange_dblue() { //ORANGE-SEQ -- RED //D_BLUE-SEQ -- RED
  fuse(1700, 1100, 600);
  delay(100);
  dump_error(600, 600, 270);
  delay(100);
  move_encoder_only(1, FWD_CONST, 270);
  delay(100);
  dump_error(400, 400, 270, 1);
  delay(100);
  sideways(1, 350, 270);
  delay(100);
  fuse(1700, 1640, 800);
  delay(100);
  move_encoder_only(1, 200, 270);
  delay(100);
  sideways(0, 200, 270);
  delay(100);
  //      move_encoder_only(1, 200, 0);
  //      delay(100);
  int x = 1250;
  int arm_change = x - arm_cur;
  //      int temp = (0.26 * float(arm_change));
  //      temp += + gripper_cur;
  fuse(x, 0.26 * float(arm_change) + gripper_cur, ((abs(arm_change)) / 100) * 250);
  delay(100);
  move_encoder_only(1, 30, 270);
  delay(100);
  sideways(0, 70, 270);
  delay(100);
  gripper.detach();
  detached = true;
  delay(100);
  move_encoder_only(1, 100, 270);
  delay(100);
  sideways(0, 80, 270);
  delay(100);
  move_encoder_only(0, 2500, 270);
}
//////////////////////////////////////////
void green__orange_dblue() {
  fuse(1700, 1100, 600);
  delay(100);
  dump_error(600, 600, 270);
  delay(100);
  move_encoder_only(1, FWD_CONST, 270);
  delay(100);
  dump_error(400, 400, 270, 1);
  delay(100);
  sideways(1, 500, 270);
  delay(100);
  move_encoder_only(0, 50, 270);
  delay(100);
  fuse(1700, 1500, 800);
  delay(100);
  move_encoder_only(1, 250, 270);
  delay(100);
  fuse(1700, 1640, 800);
  delay(100);
  sideways(1, 180, 270);
  delay(100);
  int x = 1250;
  int arm_change = x - arm_cur;
  //      int temp = (0.26 * float(arm_change));
  //      temp += + gripper_cur;
  fuse(x, 0.26 * float(arm_change) + gripper_cur, ((abs(arm_change)) / 100) * 250);
  delay(100);
  move_encoder_only(1, 100, 270);
  delay(50);
  sideways(1, 50, 270);
  delay(100);
  gripper.detach();
  detached = true;
  delay(100);
  move_encoder_only(0, 2500, 270);
}
/////////////////////////////
void second_red___orange_dblue() {//ORANGE-SEQ -- 2ND_RED_LEFT
  fuse(1900, 1100, 600);
  delay(100);
  dump_error(600, 600, 270);
  delay(100);
  move_encoder_only(1, FWD_CONST, 270);
  delay(100);
  dump_error(400, 400, 270, 1);
  delay(100);
  fuse(1900, 1500, 800);
  delay(100);
  move_encoder_only(1, 300, 270);
  delay(100);
  sideways(0, 100, 270);
  delay(100);
  gripper.detach();
  detached = true;
  delay(100);
  sideways(0, 100, 270);
  delay(100);
  move_encoder_only(1, 250, 270);
  delay(100);;
  sideways(0, 70, 270);
  delay(100);
  move_encoder_only(1, 100, 270);
  move_encoder_only(0, 2500, 270);
}
///////////////////////////////////
void second_green__orange_dblue() {
  fuse(1900, 1100, 600);
  delay(100);
  dump_error(600, 600, 270);
  delay(100);
  move_encoder_only(1, FWD_CONST, 270);
  delay(100);
  dump_error(400, 400, 270, 1);
  delay(100);
  sideways(1, 750, 270);
  delay(100);
  //      move_encoder_only(0, 50, 0);
  //      delay(100);
  fuse(1900, 1500, 800);
  delay(100);
  move_encoder_only(1, 300, 270);
  delay(100);
  sideways(1, 250, 270);
  delay(100);
  gripper.detach();
  detached = true;
  delay(100);
  move_encoder_only(1, 200, 270);
  delay(100);
  sideways(1, 100, 270);
  delay(100);
  move_encoder_only(1, 30, 270);
  delay(100);
  move_encoder_only(0, 2500, 270);
}
////////////////////////////////////////////////////
////////////////////////////////////////////////////
void orange_blue() { ////BLUE-SEQ -- ORANGE
  dump_error(400, 400, 270);
  delay(100);
  fuse(1700, 1100, 600);
  move_encoder_only(1, FWD_CONST, 270);
  delay(100);
  fuse(1700, 1640, 800);
  delay(100);
  move_encoder_only(1, 370, 270);
  delay(100);
  int x = 1250;
  int arm_change = x - arm_cur;
  //      int temp = (0.26 * float(arm_change));
  //      temp += + gripper_cur;
  fuse(x, 0.26 * float(arm_change) + gripper_cur, ((abs(arm_change)) / 100) * 250);
  delay(100);
  sideways(0, 250, 270);
  delay(100);
  move_encoder_only(1, 30, 270);
  delay(100);
  gripper.detach();
  detached = true;
  move_encoder_only(0, 3000, 270);
}
///////////////////////////////////////////////////
void red_blue() { //BLUE-SEQ -- RED
  fuse(1700, 1100, 600);
  delay(100);
  dump_error(400, 400, 270);
  delay(100);
  move_encoder_only(1, FWD_CONST, 270);
  delay(100);
  dump_error(400, 400, 270, 1);
  delay(100);
  sideways(1, 450, 270);
  delay(100);
  fuse(1700, 1640, 800);
  delay(100);
  move_encoder_only(1, 370, 270);
  delay(100);
  int x = 1250;
  int arm_change = x - arm_cur;
  //      int temp = (0.26 * float(arm_change));
  //      temp += + gripper_cur;
  fuse(x, 0.26 * float(arm_change) + gripper_cur, ((abs(arm_change)) / 100) * 250);
  delay(100);
  sideways(0, 150, 270);
  delay(100);
  gripper.detach();
  detached = true;
  delay(100);
  move_encoder_only(1, 30, 270);
  delay(50);
  move_encoder_only(0, 3000, 270);
}
//////////////////////////////////////
void dblue_blue() { //BLUE-SEQ -- D-Blue
  fuse(1700, 1100, 600);
  delay(100);
  dump_error(400, 400, 270);
  delay(100);
  move_encoder_only(1, FWD_CONST, 270);
  delay(100);
  dump_error(400, 400, 270, 1);
  delay(100);
  sideways(1, 750, 270);
  delay(100);
  fuse(1700, 1500, 800);
  delay(100);
  move_encoder_only(1, 370, 270);
  delay(100);
  sideways(1, 360, 270);
  delay(100);
  fuse(1700, 1640, 800);
  delay(100);
  int x = 1250;
  int arm_change = x - arm_cur;
  //      int temp = (0.26 * float(arm_change));
  //      temp += + gripper_cur;
  fuse(x, 0.26 * float(arm_change) + gripper_cur, ((abs(arm_change)) / 100) * 250);
  delay(100);
  gripper.detach();
  detached = true;
  delay(100);
  move_encoder_only(1, 200, 270);
  delay(50);
  move_encoder_only(0, 3000, 270);
}
/////////////////////////////
