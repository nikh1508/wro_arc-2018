byte lsb_yaw, msb_yaw;
double yaw_offset;
void bno_initialize() {
  Wire.beginTransmission(0x29);
  Wire.write(0x3D);
  Wire.write(0x0C);
  Wire.endTransmission();
  delay(1);
  ////////////////
  for (int i = 0; i < 50; i++) {
    Wire.beginTransmission(0x29);
    Wire.write(0x1A);
    Wire.endTransmission();
    Wire.requestFrom(0x29, 2);
    lsb_yaw = Wire.read();
    msb_yaw = Wire.read();
    yaw_offset = yaw_offset + (((((int)msb_yaw) << 8) | lsb_yaw));
  }
  yaw_offset /= 800.0;
  //
  Serial.println(yaw_offset);
}

double get_yaw() {
  double yaw;
  Wire.beginTransmission(0x29);
  Wire.write(0x1A);
  Wire.endTransmission();
  Wire.requestFrom(0x29, 2);
  lsb_yaw = Wire.read();
  msb_yaw = Wire.read();
  yaw = (((((int)msb_yaw) << 8) | lsb_yaw));
  yaw /= 16.0;
  yaw = yaw - yaw_offset;
  if (yaw < 0.0)
    yaw += 360.0;
  if (yaw > 180)                  //to get negative angles in CCW direction
    yaw -= 360;
  return yaw;
  //  Serial.println(yaw);
}
