void input_line() {
  for (i = 0; i < 6; i++) {
    line_data1[i] = analogRead(line1[i]);
  }
  ////////////////
  for (i = 0; i < 6; i++) {
    line_data1[i] >= compare_1[i] ? dline_data_1[i] = 1 : dline_data_1[i] = 0;
  }
}
///////////
void line_stop() {
  input_line();
  for (i = 0; i < 6; i++) {
    dline1 += dline_data_1[i];
  }
  if (dline1 == 6) {
    stop();
    ch = 's';
    //    Serial.println("line stop");
  }
  else
    dline1 = 0;
}
/////////////////
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
  line_data2[2] = analogRead(A9);/////---------->>>>form this point
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
    Serial.println(line_data2[i]);
  }
}
///////////////////
///////////////////
void line_stop_prependicular() {
  input_line_prependicular();
  for (i = 0; i < 8; i++) {
    dline2 += dline_data_2[i];
  }
  if (dline2 >= 5) {
    stop();
    ch = 's';
    Serial.println(dline2);
  }
  else
    dline2 = 0;
}
