#define serial_debug true
//#define ARM_DLY 2500//3000            //delay in micro-seconds
//#define GRIPPER_DLY 1200             //last -1200
#define ARM_INIT 1700
#define GRIPPER_INIT 1500

#include <Servo.h>

int gripper_cur = GRIPPER_INIT , arm_cur = ARM_INIT;            //Current values of Servos in micro-seconds

Servo gripper;
Servo arm;

int arm_last = ARM_INIT;          //Initial values of servos in micro-seconds
int gripper_last = GRIPPER_INIT;
int GRIPPER_DLY = 1200;
int ARM_DLY = 2500;

//void startSequence(bool blue = false);

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
  gripper.attach(40, 750, 2250);
  arm.attach(42, 750, 2250);
  gripper.writeMicroseconds(GRIPPER_INIT);
  arm.writeMicroseconds(ARM_INIT);
  Serial.println("Started Servo Test.");
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

    if (ch == 's')
      startSequence();

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
    else if (ch == 'q') {
      int x = Serial.parseInt();
      Serial.print("ARM :: ");
      Serial.println(x);
      int arm_change = x - arm_cur;
      //      Serial.println(arm_change);
      fuse(x, 0.26 * float(arm_change) + gripper_cur, ((abs(arm_change)) / 100) * 250);
    }
    else if (ch == '1') {
      Serial.println("Step-1");
      //      startStep(-1, -1, 1979, 500 );
      fuse(1300, 2110, 600);
      fuse(1100, 2100, 300);
    }
    else if (ch == '2') {
      Serial.println("Step-2");
      fuse(1155, 1780, 800); //non-blue
    }
    else if (ch == '3') {
      Serial.println("Step-3");
      //startStep(1310, 1200, 1600, 300);
      //      fuse(1270, 1600, 600);//blue
      fuse(775, 1500, 700);
    }
    else if (ch == '4') {
      Serial.println("Step-4");
      fuse(1700, 1100, 700);
      fuse(1700, 1500, 500);
    }
  }
  changeAngle();

  //-----------------------------------------------------------------------------------------------

  //  if (Serial.available()) {
  //    char ch = Serial.read();
  //    if (ch == 's')
  //      startSequence();
  //    else if (ch == 'b')
  //      startSequence();
  //    else
  //      reset();
  //  }

}
