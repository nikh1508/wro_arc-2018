void loop(){
    writeMotor(back, 100);
    delay(2000);
    stopMotor(all);
    writeMotor(left, 100);
    delay(2000);
    stopMotor(all);
    writeMotor(right, 100);
    delay(2000);
    stopMotor(all);
    writeMotor(back, -100);
    delay(2000);
    stopMotor(all);
    writeMotor(left, -100);
    delay(2000);
    stopMotor(all);
    writeMotor(right, -100);
    delay(2000);
    stopMotor(all);
}