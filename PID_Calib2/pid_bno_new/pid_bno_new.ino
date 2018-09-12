#define BNO055_SAMPLERATE_DELAY_MS (100)

#include<PID_v1.h>
#include<Wire.h>
//#include <Adafruit_Sensor.h>
//#include <Adafruit_BNO055.h>
//#include <utility/imumaths.h>

#define setValue 35

struct mtr {
  int left_1 = 30;
  int left_2 = 28;
  int left_pwm = 4;

  int right_1 = 32;
  int right_2 = 34;
  int right_pwm = 3;

} motor;

int pins[] = {30, 28, 4, 32, 34, 3, 24, 26, 5};

double setpoint, input, output, kp=13.0, ki=1.5, kd=6.75;

PID myPID(&input, &output, &setpoint, kp, ki, kd, DIRECT);
//Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x29);

//double get_yaw() {
//  sensors_event_t event;
//  bno.getEvent(&event);
//  double x = event.orientation.x; // taking X readings
//  double y = event.orientation.y;
//  double z = event.orientation.z;
//  if (x > 180)                  //to get negative angles in CCW direction
//    x = (360 - x) * -1;
//  return x;
//}

int pwm_l = setValue, pwm_r = setValue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  Serial1.begin(115200);
  for (int pin : pins) {
    pinMode(pin, OUTPUT);
  }
  
//  if (!bno.begin())
//  {
//    Serial.print("BNO not detected. Check connections or I2C ADDR!(Run I2C Scanner in Debug Mode.)");
//    while (1);
//  }
  Serial.println("Started");
//  bno.setExtCrystalUse(true);
  setpoint = 0.0;
  myPID.SetOutputLimits(-255, 255);
  myPID.SetMode(AUTOMATIC);
  bno_initialize();
  digitalWrite(24, HIGH);
  digitalWrite(26, HIGH);
  digitalWrite(5, HIGH);
//  delay(2000);
}
