#define serial_debug true
//#define ARM_DLY 2500//3000            //delay in micro-seconds
//#define GRIPPER_DLY 1200             //last -1200
#define ARM_INIT 1500
#define GRIPPER_INIT 1500

#include <Servo.h>

int gripper_cur = GRIPPER_INIT , arm_cur = ARM_INIT;            //Current values of Servos in micro-seconds

Servo gripper;
Servo arm;

int arm_last = ARM_INIT;          //Initial values of servos in micro-seconds
int gripper_last = GRIPPER_INIT;
int GRIPPER_DLY = 1200;
int ARM_DLY = 2500;

void changeAngle() {
  static long arm_last_us = micros();
  static long gripper_last_us = micros();

  if (gripper_cur != gripper_last)
    if ((micros() - gripper_last_us) > GRIPPER_DLY) {
      gripper_last_us = micros();
      (gripper_cur > gripper_last) ? gripper_last++ : gripper_last--;
      gripper.writeMicroseconds(constrain(gripper_last, 750, 2250));
    }
  if (arm_cur != arm_last)
    if ((micros() - arm_last_us) > ARM_DLY) {
      arm_last_us = micros();
      (arm_cur > arm_last) ? arm_last++ : arm_last--;
      arm.writeMicroseconds(constrain(arm_last, 750, 2250));
    }
}

void setup() {
  if (serial_debug)
    Serial.begin(115200);
  gripper.attach(7, 750, 2250);
  arm.attach(8, 750, 2250);
  gripper.writeMicroseconds(GRIPPER_INIT);
  arm.writeMicroseconds(ARM_INIT);
  Serial.println("Started Servo Test.");
  delay(1000);
  fuse(1500, 1979, 1000);
  delay(1000);
  fuse(2100, 1200, 3000);
  while(1);
}
//int steps[] = {4000, 800, 500, 800, 1500, 2000}; //FIRST
//int steps[] = {5500, 1000, 800};  //SECOND
int steps[] = {5500, 1000, 500, 1500};

void startStep(int arm,  int nw_arm_dly, int gripper, int nw_gripper_dly) {
  //  long start_time = millis();
  if (arm != -1)
    arm_cur = arm;
  if (gripper != -1)
    gripper_cur = gripper;
  if (nw_gripper_dly != -1)
    GRIPPER_DLY = nw_gripper_dly;
  if (nw_arm_dly != -1)
    ARM_DLY = nw_arm_dly;
  while (gripper_cur != gripper_last || arm_cur != arm_last) {
    changeAngle();
  }

}


void reset() {
  //long start = millis();
  arm_cur = ARM_INIT;
  gripper_cur = GRIPPER_INIT;
  GRIPPER_DLY = 1200;
  ARM_DLY = 2500;
  while (gripper_cur != gripper_last || arm_cur != arm_last) {
    changeAngle();
  }
}
void loop() {
  if (Serial.available()) {
    char ch = Serial.read();

    if (ch == 'a') {
      while (!Serial.available());
      arm_cur = Serial.parseInt();
      Serial.print("Arm :: "); Serial.println(arm_cur);
    }
    else if (ch == 'g') {
      while (!Serial.available());
      gripper_cur = Serial.parseInt();
      Serial.print("Gripper :: "); Serial.println(gripper_cur);
    }
    else if (ch == 'r') {
      //      Serial.println("here");
      reset();
      Serial.println("reset");
    }
    else if (ch == '1') {
      Serial.println("Step-1");
      startStep(-1, -1, 1979, 500 );
    }
    else if (ch == '2') {
      Serial.println("Step-2");
      startStep(1290, 1500, -1, -1 );
    }
    else if (ch == '3') {
      Serial.println("Step-3");
      startStep(1310, 1200, 1600, 300);
    }
    else if (ch == '4') {
      Serial.println("Step-4");
      startStep(1000, 1200, 1300, 1000 );
    }
    else if (ch == '5') {
      Serial.println("Step-5");
      startStep(900, -1, 1200, -1 );
    }
    else if (ch == '6') {
      Serial.println("Step-6");
      startStep(1600, 500, 1100, 300 );
    }

    //    else if (ch == 'd') {
    //      arm.detach();
    //      arm.write(90);
    //    }
    //    else if (ch == 'a') {
    //      arm.attach(33, 900, 2100);
    //    }
  }
  //    if (Serial.available()) {
  //      char ch = Serial.read();
  //      if (ch == 's')
  //        startSequence();
  //      else
  //        reset();
  //    }
  changeAngle();
}

