void write_motor(int x, int y) {
  digitalWrite(motor.left_1, 1);
  digitalWrite(motor.left_2, 0);
  digitalWrite(motor.right_1, 1);
  digitalWrite(motor.right_2, 0);
  analogWrite(motor.left_pwm, x);
  analogWrite(motor.right_pwm, y);
}

double diff(float x, float y) {
    double tmp = abs(x - y);
    double diff = min(tmp, abs(360 - tmp));
    if ((y + diff) != x && (y - diff) != x) {
        if ((x + diff) >= 360)
            return -diff;
        else return diff;
    }
    else return (x-y);
}
