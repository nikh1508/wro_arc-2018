void loop() {
  //  sequence();
  //  servo_camera();
  //  rotate_desired = 90;
  //  ch='r';
  //  move(ch);
  //  while(1);
//  ch = 'r';
//  while (ch != 's') {
//    right();
//    encoder_data1();
//    Serial.println(encoder_1);
//  }
//while(1);

rotateTo(270, CCW, 90);
delay(300);
rotateTo(180, CCW, 90);
delay(300);
rotateTo(90, CCW, 90);
delay(300);
rotateTo(0, CCW, 90);
while(1);
}

