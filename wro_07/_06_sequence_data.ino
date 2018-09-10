void assign_sequence() {
  ///----->initial
  action[0][0] = 1;
  action[0][1] = 3;
  action[0][2] = 1;
  action[0][3] = 0;
  //
  direction[0][0] = 1;
  direction[0][2] = 1;
  //
  steps[0][0] = 1500;
  steps[0][2] = 8000;
  //
  angle[0][0] = 360.0;//////
  angle[0][1] = -270.0;
  angle[0][2] = 270.0;
  //
  //////////rotation via pi
  action[1][0] = 3;
  action[1][1] = 0;
  angle[1][0] = -180.0;
  //
  action[2][0] = 3;
  action[1][1] = 0;
  angle[2][0] = -135.0;
  //
  action[3][0] = 3;
  action[1][1] = 0;
  angle[3][0] = -45.0;
  //
  action[4][0] = 3;
  action[1][1] = 0;
  angle[4][0] = -360.0;
  //
  action[5][0] = 3;
  action[1][1] = 0;
  angle[5][0] = 90.0;
  //
  ///////////////////////////////////////------->short supply 1
  action[6][0] = 3;
  action[6][1] = 6;
  action[6][2] = 1;
  action[6][3] = 3;
  action[6][4] = 0;
  //
  angle[6][0] = 180.0;
  angle[6][1] = 180.0;
  angle[6][2] = 180.0;
  angle[6][3] = 270.0;
  //
  direction[6][2] = -1;
  //
  steps[6][1] = 1800;
  steps[6][2] = -1800;
  ///////////////------------>>>>>>>>>>>>>short supply 2
  action[7][0] = 1;
  action[7][1] = 3;
  action[7][2] = 6;
  action[7][3] = 1;
  action[7][4] = 3;
  action[7][5] = 1;
  action[7][6] = 0;
  //
  angle[7][0] = 90.0;
  angle[7][1] = 180.0;
  angle[7][2] = 180.0;
  angle[7][3] = 180.0;
  angle[7][4] = 270.0;
  angle[7][5] = 270.0;
  //
  direction[7][0] = 1;
  direction[7][3] = -1;
  direction[7][5] = 1;
  //
  steps[7][0] = 4000;
  steps[7][2] = 1800;
  steps[7][3] = -1800;
  steps[7][5] = 4000;
  //
  ////////////////////////////////---------------->>>>>>>>>>>>position 3
  action[8][0] = 5;
  action[8][1] = 6;
  action[8][2] = 1;
  action[8][3] = 4;
  action[8][4] = 3;
  action[8][5] = 0;
  //
  angle[8][1] = 90.0;
  angle[8][2] = 90.0;
  angle[8][4] = 270.0;
  //
  direction[8][0] = 0;//////----------------------->>>>>>>>>>>/////////confirm from nikhil
  direction[8][2] = -1;
  direction[8][3] = 1;//////----------------------->>>>>>>>>>>/////////confirm from nikhil
  //
  steps[8][0] = 2000;
  steps[8][1] = 1800;
  steps[8][2] = -1800;
  /////////////////////////
  ////////////////////////////////---------------->>>>>>>>>>>>position 4
  action[9][0] = 5;
  action[9][1] = 6;
  action[9][2] = 1;
  action[9][3] = 4;
  action[9][4] = 3;
  action[9][5] = 0;
  //
  angle[9][1] = 90.0;
  angle[9][2] = 90.0;
  angle[9][4] = 270.0;
  //
  direction[9][0] = 0;//////----------------------->>>>>>>>>>>/////////confirm from nikhil
  direction[9][2] = -1;
  direction[9][3] = 1;//////----------------------->>>>>>>>>>>/////////confirm from nikhil
  //
  steps[9][0] = 3000;
  steps[9][1] = 1800;
  steps[9][2] = -1800;
  /////////////////////////////
  ////////////////////////////////---------------->>>>>>>>>>>>position 5
  action[10][0] = 3;
  action[10][1] = 5;
  action[10][2] = 6;
  action[10][3] = 1;
  action[10][4] = 4;
  action[10][5] = 0;
  //
  angle[10][0] = 270.0;
  angle[10][2] = 270.0;
  angle[10][3] = 270.0;
  //
  direction[10][1] = 1;//////----------------------->>>>>>>>>>>/////////confirm from nikhil
  direction[10][3] = -1;
  direction[10][4] = 0;//////----------------------->>>>>>>>>>>/////////confirm from nikhil
  //
  steps[10][1] = 3000;
  steps[10][2] = 1800;
  steps[10][3] = -1800;
  /////////////////////////////////
  ////////////////////////////////---------------->>>>>>>>>>>>position 6---delivery chute
  action[11][0] = 3;
  action[11][1] = 6;
  action[11][2] = 1;
  action[11][3] = 3;
  //
  angle[11][0] = -360.0;
  angle[11][1] = 360.0;
  angle[11][2] = 360.0;
  angle[11][3] = -270.0;
  //
  direction[11][2] = -1;
  //
  steps[11][1] = 4000;
  steps[11][2] = -4000;
}
