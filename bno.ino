////BNO/////
#define BNO055_ADDRESS          0x29
#define BNO055_ST_RESULT        0x36

byte lsb_yaw;
byte msb_yaw;
double yaw = 0;
double yaw_offset = 0;

void bnoSelftest(){
    SerialFlush();
    Wire.beginTransmission(BNO055_ADDRESS);       
    Wire.write(BNO055_ST_RESULT);	                
    Wire.endTransmission();
    Wire.requestFrom(BNO055_ADDRESS, (size_t) 1); 
    byte selftest = Wire.read();
    
    if(selftest & 0x01) {
      Serial.println("accelerometer passed selftest"); 
    } else {
      Serial.println("accelerometer failed selftest"); 
    }
    if(selftest & 0x02) {
      Serial.println("magnetometer passed selftest"); 
    } else {
      Serial.println("magnetometer failed selftest"); 
    }  
    if(selftest & 0x04) {
      Serial.println("gyroscope passed selftest"); 
    } else {
      Serial.println("gyroscope failed selftest"); 
    }      
    if(selftest & 0x08) {
      Serial.println("MCU passed selftest"); 
    } else {
      Serial.println("MCU failed selftest"); 
    }
    while(!Serial.available()){
      Serial.print("YAW : : ");
      Serial.println(getYaw());
    }
    SerialFlush();
}

bool bnoInitialize() {
  Wire.beginTransmission(BNO055_ADDRESS);
  byte error = Wire.endTransmission();
  if(error!=0)
    return false;
  Wire.beginTransmission(BNO055_ADDRESS);
  Wire.write(0x3D);
  Wire.write(0x0C);
  Wire.endTransmission();
  delay(10);

  for (int i = 0; i < 50; i++) {
    Wire.beginTransmission(BNO055_ADDRESS);
    Wire.write(0x1A);
    Wire.endTransmission();
    Wire.requestFrom(BNO055_ADDRESS, 2);
    lsb_yaw = Wire.read();
    msb_yaw = Wire.read();
    yaw_offset = yaw_offset + (((((int)msb_yaw) << 8) | lsb_yaw));
  }
  yaw_offset /= 800;
  Serial.println(yaw_offset);
  delay(50);
  return true;
}

double getYaw() {
  Wire.beginTransmission(BNO055_ADDRESS);
  Wire.write(0x1A);
  Wire.endTransmission();
  Wire.requestFrom(BNO055_ADDRESS, 2);
  lsb_yaw = Wire.read();
  msb_yaw = Wire.read();
  yaw = (((((int)msb_yaw) << 8) | lsb_yaw));
  yaw /= 16;
  yaw = yaw - yaw_offset;
  if (yaw < 0)
    yaw += 360;
  Serial.println(yaw);
  return yaw;
}