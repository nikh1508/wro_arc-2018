void blue_orange() {
  dump_error(400, 400, 270.0);//
  delay(100);
  fuse(1700, 1100, 600);
  move_encoder_only(1, 2400, 270.0);//
  delay(100);
  fuse(1700, 1640, 800);
  delay(100);
  move_encoder_only(1, 370, 270.0);
  delay(100);
  int x = 1265;
  int arm_change = x - arm_cur;
  //      int temp = (0.26 * float(arm_change));
  //      temp += + gripper_cur;
  fuse(x, 0.26 * float(arm_change) + gripper_cur, ((abs(arm_change)) / 100) * 250);
  delay(100);
  sideways(0, 250, 270.0);
  delay(100);
  move_encoder_only(1, 30, 270.0);
  delay(100);
  gripper.detach();
  detached = true;
  move_encoder_only(0, 3000, 270.0);
}
////////////////////////////////////
void blue_red() {
  fuse(1700, 1100, 600);
  delay(100);
  dump_error(400, 400, 270.0);
  delay(100);
  move_encoder_only(1, 2400, 270.0);
  delay(100);
  dump_error(400, 400, 270.0, 1);
  delay(100);
  sideways(1, 450, 270.0);
  delay(100);
  fuse(1700, 1640, 800);
  delay(100);
  move_encoder_only(1, 370, 270.0);
  delay(100);
  int x = 1265;
  int arm_change = x - arm_cur;
  //      int temp = (0.26 * float(arm_change));
  //      temp += + gripper_cur;
  fuse(x, 0.26 * float(arm_change) + gripper_cur, ((abs(arm_change)) / 100) * 250);
  delay(100);
  sideways(0, 150, 270.0);
  delay(100);
  gripper.detach();
  detached = true;
  delay(100);
  move_encoder_only(1, 30, 270.0);
  delay(50);
  move_encoder_only(0, 3000, 270.0);
}
////////////////////////////
void blue_dblue____yellow_dblue() {
  fuse(1700, 1100, 600);
  delay(100);
  dump_error(400, 400, 270.0);
  delay(100);
  move_encoder_only(1, 2400, 270.0);
  delay(100);
  dump_error(400, 400, 270.0, 1);
  delay(100);
  sideways(1, 750, 270.0);
  delay(100);
  fuse(1700, 1500, 800);
  delay(100);
  move_encoder_only(1, 370, 270.0);
  delay(100);
  sideways(1, 360, 270.0);
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
  move_encoder_only(1, 200, 270.0);
  delay(50);
  move_encoder_only(0, 3000, 270.0);
}
////////////////////////////////////////////
void yellow_orange() {
  fuse(1700, 1100, 600);
  delay(100);
  dump_error(400, 400, 270.0);
  delay(100);
  move_encoder_only(1, 2400, 270.0);
  delay(100);
  dump_error(400, 400, 270.0, 1);
  delay(100);
  sideways(1, 50, 270.0);
  delay(100);
  fuse(1700, 1640, 800);
  delay(100);
  move_encoder_only(1, 370, 270.0);
  delay(100);
  int x = 1265;
  int arm_change = x - arm_cur;
  //      int temp = (0.26 * float(arm_change));
  //      temp += + gripper_cur;
  fuse(x, 0.26 * float(arm_change) + gripper_cur, ((abs(arm_change)) / 100) * 250);
  delay(100);
  sideways(0, 100, 270.0);
  delay(100);
  move_encoder_only(1, 70, 270.0);
  delay(50);
  gripper.detach();
  detached = true;
  delay(100);
  move_encoder_only(0, 3000, 270.0);
}
///////////////////////////////////
void green_red____orange_dblue() {
  fuse(1700, 1100, 600);
  delay(100);
  dump_error(400, 400, 270.0);
  delay(100);
  move_encoder_only(1, 2400, 270.0);
  delay(100);
  dump_error(400, 400, 270.0, 1);
  delay(100);
  sideways(1, 750, 270.0);
  delay(100);
  fuse(1700, 1500, 800);
  delay(100);
  move_encoder_only(1, 370, 270.0);
  delay(100);
  sideways(1, 600, 270.0);
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
  move_encoder_only(1, 200, 270.0);
  delay(100);
  sideways(1, 100, 270.0);
  delay(100);
  move_encoder_only(0, 3000, 270.0);
}
/////////////////////////////////////
void green_blue_left() {
  fuse(1900, 1100, 600);
  delay(100);
  dump_error(400, 400, 270.0);
  delay(100);
  move_encoder_only(1, 2400, 270.0);
  delay(100);
  dump_error(400, 400, 270.0, 1);
  delay(100);
  fuse(1900, 1500, 800);
  delay(100);
  move_encoder_only(1, 370, 270.0);
  delay(100);
  fuse(1700, 1640, 800);
  delay(100);
  sideways(0, 465, 270.0);
  delay(100);
  move_encoder_only(1, 30, 270.0);
  delay(100);
  sideways(0, 100, 270.0);
  delay(100);
  gripper.detach();
  detached = true;
  delay(100);
  move_encoder_only(0, 3000, 270.0);
}
//////////////
void green_blue_right() {
  fuse(1900, 1100, 600);
  delay(100);
  dump_error(400, 400, 270.0);
  delay(100);
  move_encoder_only(1, 2400, 270.0);
  delay(100);
  dump_error(400, 400, 270.0, 1);
  delay(100);
  fuse(1900, 1400, 800);
  delay(100);
  move_encoder_only(1, 340, 270.0);
  delay(100);
  sideways(1, 750, 270.0);
  delay(100);
  fuse(1700, 1640, 800);
  delay(100);
  move_encoder_only(1, 150, 270.0);
  delay(100);
  gripper.detach();
  detached = true;
  delay(100);
  move_encoder_only(0, 3000, 270.0);
}
//////////////////////
void red_green____dblue_orange() {
  fuse(1700, 1100, 600);
  delay(100);
  dump_error(400, 400, 270.0);
  delay(100);
  move_encoder_only(1, 2400, 270.0);
  delay(100);
  dump_error(400, 400, 270.0, 1);
  delay(100);
  sideways(0, 150, 270.0);
  delay(100);
  fuse(1700, 1640, 800);
  delay(100);
  move_encoder_only(1, 370, 270.0);
  delay(100);
  int x = 1265;
  int arm_change = x - arm_cur;
  //      int temp = (0.26 * float(arm_change));
  //      temp += + gripper_cur;
  fuse(x, 0.26 * float(arm_change) + gripper_cur, ((abs(arm_change)) / 100) * 250);
  delay(100);
  sideways(0, 350, 270.0);
  delay(100);
  move_encoder_only(1, 30, 270.0);
  delay(100);
  gripper.detach();
  detached = true;
  delay(100);
  move_encoder_only(0, 3000, 270.0);
}
/////////////////////////////
void orange_red____dblue_red() {
  fuse(1700, 1100, 600);
  delay(100);
  dump_error(400, 400, 270.0);
  delay(100);
  move_encoder_only(1, 2400, 270.0);
  delay(100);
  dump_error(400, 400, 270.0, 1);
  delay(100);
  sideways(1, 150, 270.0);
  delay(100);
  fuse(1700, 1640, 800);
  delay(100);
  move_encoder_only(1, 370, 270.0);
  delay(100);
  int x = 1265;
  int arm_change = x - arm_cur;
  //      int temp = (0.26 * float(arm_change));
  //      temp += + gripper_cur;
  fuse(x, 0.26 * float(arm_change) + gripper_cur, ((abs(arm_change)) / 100) * 250);
  delay(100);
  sideways(0, 150, 270.0);
  delay(100);
  gripper.detach();
  detached = true;
  delay(100);
  move_encoder_only(1, 30, 270.0);
  delay(100);
  sideways(0, 80, 270.0);
  delay(100);
  move_encoder_only(0, 3000, 270.0);
}
///////////////////////////////////
void orange_green____dblue_green() {
  fuse(1700, 1100, 600);
  delay(100);
  dump_error(400, 400, 270.0);
  delay(100);
  move_encoder_only(1, 2400, 270.0);
  delay(100);
  dump_error(400, 400, 270.0, 1);
  delay(100);
  sideways(1, 750, 270.0);
  delay(100);
  fuse(1700, 1500, 800);
  delay(100);
  move_encoder_only(1, 370, 270.0);
  delay(100);
  //      sideways(1, 360, 0);
  //      delay(100);
  fuse(1700, 1640, 800);
  delay(100);
  int x = 1265;
  int arm_change = x - arm_cur;
  //      int temp = (0.26 * float(arm_change));
  //      temp += + gripper_cur;
  fuse(x, 0.26 * float(arm_change) + gripper_cur, ((abs(arm_change)) / 100) * 250);
  delay(100);
  sideways(1, 50, 270.0);
  delay(100);
  gripper.detach();
  detached = true;
  delay(100);
  move_encoder_only(1, 100, 270.0);
  delay(50);
  sideways(1, 30, 270.0);
  delay(100);
  move_encoder_only(0, 3000, 270.0);
}
