bool state = false, prev_off = true;

double nwSetpoint;
void loop() {
  if (Serial.available()) {
    char bin = Serial.read();
    state = !state;
  }

  fetchData();
  if (state) {
    if (prev_off) {
      prev_off = false;
      nwSetpoint = get_yaw();
    }
    input = diff(get_yaw(), nwSetpoint);
    myPID.Compute();
    pwm_l = constrain(setValue + output, 0, 255);
    write_motor(pwm_l, pwm_r);
    Serial.println("input" + String(input));
    Serial.print("L_PWM::"); Serial.print(pwm_l); Serial.print("\t");
    Serial.print("R_PWM::"); Serial.println(pwm_r);
    Serial.println(String("OUT::") + String(output));
    Serial.println("------------------------------------------------------");
  }
  else{
    write_motor(0, 0);
    prev_off = true;
    }
}
