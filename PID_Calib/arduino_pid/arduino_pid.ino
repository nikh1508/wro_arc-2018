bool test=false;
#include<Wire.h>
#define adr 0x29//0x28 or 0x29//bno
#define adr_mega 7
//////
byte lsb_yaw = 0;
byte msb_yaw = 0;
double yaw_offset = 0.0;
double yaw = 0.0;
double rotate_desired = 0.0;
////////////
////////////
struct motors {
  int a;
  int b;
  int pwm_pin;
  int pwm;
} m[3];
//////////
/////////
////..................pins..............///
int m0_a = 32;
int m0_b = 34;
int m0_pwm = 3;
//
int m1_a = 24;
int m1_b = 26;
int m1_pwm = 5;
//
int m2_a = 30;
int m2_b = 28;
int m2_pwm = 4;

///////////////////////////
///////////////////////////
double prev = 0.0;
double cur = 0.0;
double time = 0.0;
/////////////////////////
/////////////////////////
double P = 0.0;
double I = 0.0;
double D = 0.0;
double error = 0.0;
double prev_error = 0.0;
double kp = 12.0;
double ki = 1.0;
double kd = 100.0;
double pid = 0.0;
/////////////////////////
/////////////////////////
double lpf_output = 0.0;
double alpha = 0.02;
double desired_value = 0.0;
double prev_output = 0.0;
//////////
int highspeed = 60;
int lowspeed = 30;
////////////////////////
////////////////////////
int i, j;
char ch = '\0';
int sqc = 1;
int sqc_pin = 18;
/////i2c data from pi////
//int pi_data=0;
///////////
