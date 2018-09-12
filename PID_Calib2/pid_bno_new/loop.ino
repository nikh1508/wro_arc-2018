bool state = false, prev_off = true;
int dir_ctr = 0, mul = 1;
double yaw_data;
double nwSetpoint;
void loop() {
  if (Serial.available()) {
    char bin = Serial.read();
    state = !state;
  }

  fetchData();
  if (state) {
    if (prev_off) {
      dir_ctr++;
      (dir_ctr % 2 == 0) ? mul = -1 : mul = 1;
      prev_off = false;
      nwSetpoint = get_yaw();
    }
    yaw_data = get_yaw();
    input = diff(yaw_data, nwSetpoint);
    myPID.Compute();
    pwm_r = setValue * mul;
    pwm_l = constrain((setValue * mul) + output, -255, 255);
    write_motor(pwm_l, pwm_r);
    Serial.print("SET:" + String(setpoint));
    Serial.print("\tINP:" + String(input));
    Serial.print("\tOUT:" + String(output));
    Serial.print("\tLFT:" + String(pwm_l));
    Serial.print("\tRT:" + String(pwm_r));
    Serial.print("\tYAW:" + String(yaw_data));
    Serial.print(myPID.GetKp());
    Serial.print("\t");
    Serial.print(myPID.GetKi());
    Serial.print("\t");
    Serial.println(myPID.GetKd());
  }
  else {
    write_motor(0, 0);
    prev_off = true;
  }
}
