void fetchData() {
  if (Serial.available()) {
    char ch = Serial.read();
    while (!Serial.available());
    int val = Serial.read();
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
    }
    Serial.print("Power :: ");
    Serial.print(test);
    Serial.print("\tKp :: ");
    Serial.print(kp);
    Serial.print("\tKi :: ");
    Serial.print(ki);
    Serial.print("\tKd :: ");
    Serial.print(kd);
  }
}
