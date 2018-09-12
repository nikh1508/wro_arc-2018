bool test;
void fetchData() {
  if (Serial1.available()) {
    char ch = Serial1.read();
    while (!Serial1.available());
    int val = Serial1.read();
    switch (ch) {
      case 'o':
        test = val;
        break;
      case 'p':
        kp = (double)val / 4.0;
        break;
      case 'i':
        ki = (double)val / 4.0;
        break;
      case 'd':
        kd = (double)val / 4.0;
        break;
      default:
        while (Serial1.available())
          char bin = Serial1.read();
    }
    Serial.print("Power :: ");
    Serial.print(test);
    Serial.print("\tKp :: ");
    Serial.print(kp);
    Serial.print("\tKi :: ");
    Serial.print(ki);
    Serial.print("\tKd :: ");
    Serial.println(kd);
    myPID.SetTunings(kp, ki, kd);
  }
}
