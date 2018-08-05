#define BLYNK_PRINT Serial
#define serial_debug true
#define ARM_DLY 5000                  //delay in micro-seconds
#define GRIPPER_DLY 3000
#define ARM_INIT 900
#define GRIPPER_INIT 1500

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

char auth[] = "ce94b01dfe7d4b6bac4b666c0a7fc61d";

char ssid[] = "Robocon";
char pass[] = "paisapaisa";

int gripper_cur = GRIPPER_INIT , arm_cur = ARM_INIT;            //Current values of Servos in micro-seconds

Servo gripper;
Servo arm;

void changeAngle() {
  static int arm_last = ARM_INIT;          //Initial values of servos in micro-seconds
  static int gripper_last = GRIPPER_INIT;
  static int arm_last_us = micros();
  static int gripper_last_us = micros();

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
      arm.writeMicroseconds(constrain(arm_last, 900, 2100));
    }
}

void setup() {
  if (serial_debug)
    Serial.begin(115200);
  Blynk.begin(auth, ssid, pass, IPAddress(192, 168, 43, 73), 8080);
  gripper.attach(D3, 750, 2250);
  arm.attach(D4, 900, 2100);
  gripper.writeMicroseconds(1500);
  arm.writeMicroseconds(900);
  Serial.println("Started Servo Test.");
}

void loop() {
  Blynk.run();
  changeAngle();
}

