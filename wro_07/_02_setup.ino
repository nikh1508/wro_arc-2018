void setup() {
  Serial.begin(9600);
  Wire.begin(adr_mega);
  Wire.onReceive(i2c_recieve);
  assign_pins();
  line_compare();
  declaration();
  assign_sequence();
  camera.attach(camera_pin, 750, 2250);
  camera.writeMicroseconds(900);
  gripper.attach(grip_pin, 750, 2250);
  arm.attach(arm_pin, 750, 2250);
  gripper.writeMicroseconds(GRIPPER_INIT);
  arm.writeMicroseconds(ARM_INIT);
  
  setpoint = 0.0;
  myPID.SetOutputLimits(-255, 255);
  myPID.SetMode(AUTOMATIC);
  bno_initialize();
  reset_feedback();
}
