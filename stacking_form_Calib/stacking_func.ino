void resetDrive() {
  encoder_data0();
  encoder_data1();
  sideways((encoder_1 < 0), abs(encoder_1), 0);
  delay(500);
  Serial.println("NOW0::"+String(encoder_0));
  Serial.println("OFFSET::"+String(encoder0_offset));
  int enc0 = encoder_0 + encoder0_offset;  
  move_encoder_only((enc0 < 0), abs(enc0), 0);
}
