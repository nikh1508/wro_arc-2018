void loop() {
  cur = millis();
  time = cur - prev; //////start
  //  for reseting bno-->
  //  yaw_offset=yaw;
  bno();
  //////////////////
  pid_main();
  /////////////////////
  /////////////////////
  //code
  low_pass();
  //////////////
  if(ch=='f'||ch=='b'||ch=='l'||ch=='r')
  calculate();
  //////////
  ////////////
  line_sensor();
  //
  encoder_data();
  //
  move(ch);
  //
  if (ch != ch_mask) {//directional change
    prev_output_main = 0;
    lpf_output_main = 0;
    prev_output_sec = 0;
    lpf_output_sec = 0;
    ch_mask = ch;
  }




  prev_error = error;
  prev = cur; ////////end
}

