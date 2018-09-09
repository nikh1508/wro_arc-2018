void input_line() {
  for (i = 0; i < 8; i++) {
    line_data1[i] = analogRead(line1[i]);
    //    Serial.print(line_data1[i]);Serial.print(" ");
  }
  //  Serial.print("\n");
  //
  for (i = 0; i < 8; i++) {
    line_data1[i] >= compare_1[i] ? dline_data_1[i] = 1 : dline_data_1[i] = 0;
  }
  ////
}
//////
void input_line_prependicular() {
  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  digitalWrite(s3, HIGH);
  line_data2[0] = analogRead(A9);
  //
  digitalWrite(s0, HIGH);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  digitalWrite(s3, HIGH);
  line_data2[1] = analogRead(A9);
  //
  digitalWrite(s0, LOW);
  digitalWrite(s1, HIGH);
  digitalWrite(s2, LOW);
  digitalWrite(s3, HIGH);
  line_data2[2] = analogRead(A9);
  //
  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);
  digitalWrite(s2, LOW);
  digitalWrite(s3, HIGH);
  line_data2[3] = analogRead(A9);
  //
  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, HIGH);
  digitalWrite(s3, HIGH);
  line_data2[4] = analogRead(A9);
  //
  digitalWrite(s0, HIGH);
  digitalWrite(s1, LOW);
  digitalWrite(s2, HIGH);
  digitalWrite(s3, HIGH);
  line_data2[5] = analogRead(A9);
  //
  digitalWrite(s0, LOW);
  digitalWrite(s1, HIGH);
  digitalWrite(s2, HIGH);
  digitalWrite(s3, HIGH);
  line_data2[6] = analogRead(A9);
  //
  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);
  digitalWrite(s2, HIGH);
  digitalWrite(s3, HIGH);
  line_data2[7] = analogRead(A9);
  ///////////////////
  ///////////////////
  for (i = 0; i < 8; i++) {
    line_data2[i] >= compare_2[i] ? dline_data_2[i] = 1 : dline_data_2[i] = 0;
  }
}
//////
///
void input_line_block() {
  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  line_data3[0] = analogRead(A9);
  //
  digitalWrite(s0, HIGH);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  line_data3[1] = analogRead(A9);
  //
  digitalWrite(s0, LOW);
  digitalWrite(s1, HIGH);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  line_data3[2] = analogRead(A9);
  //
  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  line_data3[3] = analogRead(A9);
  //
  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, HIGH);
  digitalWrite(s3, LOW);
  line_data3[4] = analogRead(A9);
  //
  digitalWrite(s0, HIGH);
  digitalWrite(s1, LOW);
  digitalWrite(s2, HIGH);
  digitalWrite(s3, LOW);
  line_data3[5] = analogRead(A9);
  //
  digitalWrite(s0, LOW);
  digitalWrite(s1, HIGH);
  digitalWrite(s2, HIGH);
  digitalWrite(s3, LOW);
  line_data3[6] = analogRead(A9);
  //
  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);
  digitalWrite(s2, HIGH);
  digitalWrite(s3, LOW);
  line_data3[7] = analogRead(A9);
  ///////////////////
  ///////////////////
  for (i = 0; i < 8; i++) {
    line_data3[i] >= compare_3[i] ? dline_data_3[i] = 1 : dline_data_3[i] = 0;
  }
}
void line_stop() {
  input_line();
  for (i = 0; i < 8; i++) {
    dline1 += dline_data_1[i];
  }
  if (dline1 == 8) {
    ch = 's';
    move(ch);
    flag_reset = true;
    sqc = 0;
  }
  else
    dline1 = 0;
}
////////////
void line_stop_block() {
  input_line_block();
  for (i = 0; i < 8; i++) {
    dline3 += dline_data_3[i];
  }
  if (dline3 == 8) {
    ch = 's';
    move(ch);
    flag_reset = true;
    sqc = 0;
  }
  else
    dline3 = 0;
}
////////////////////
int sideShift[] = {80, 0};
///////////////////
void line_stop_prependicular(int dir) {
  input_line_prependicular();
  for (i = 0; i < 8; i++) {
    dline2 += dline_data_2[i];
  }
  //  Serial.println(dline2);
  if (dline2 >= 7) {
    encoder_data1();
    int lastEncCounts = encoder_1;
    while (abs(lastEncCounts - encoder_1) < sideShift[dir]) {
      encoder_data1();
    }
    ch = 's';
    move(ch);
    flag_reset = true;
    sqc = 0;
  }
  else
    dline2 = 0;
}
