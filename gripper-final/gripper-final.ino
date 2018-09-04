#define ARM_INIT 1700
#define GRIPPER_INIT 1500

#include <Servo.h>

Servo gripper;
Servo arm;

int gripper_cur = GRIPPER_INIT , arm_cur = ARM_INIT;            //Current values of Servos in micro-seconds

int arm_last = ARM_INIT;          //Initial values of servos in micro-seconds
int gripper_last = GRIPPER_INIT;
int GRIPPER_DLY = 1200;
int ARM_DLY = 2500;

void setup() {
  gripper.attach(40, 750, 2250);
  arm.attach(42, 750, 2250);
  gripper.writeMicroseconds(GRIPPER_INIT);
  arm.writeMicroseconds(ARM_INIT);
  Serial.println("Started Servo Test.");
}

void loop() {
  if (Serial.available()) {
    char ch = Serial.read();
    if (ch == 's')
      startSequence();
    else
      reset();
  }
}
