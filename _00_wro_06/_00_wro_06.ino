#include <Servo.h>
#define ARM_INIT 1700
#define GRIPPER_INIT 1500
Servo gripper;
Servo arm;
Servo camera;
/////
int gripper_cur = GRIPPER_INIT , arm_cur = ARM_INIT;            //Current values of Servos in micro-seconds
int arm_last = ARM_INIT;          //Initial values of servos in micro-seconds
int gripper_last = GRIPPER_INIT;
int GRIPPER_DLY = 1200;
int ARM_DLY = 2500;
#define fused_motion_debug false
////
int camera_pin = 48;
int grip_pin = 40;
int arm_pin = 42;
#include<Wire.h>
#define adr 0x29//0x28 or 0x29//bno
#define adr_encoder_0 8//primary//forward and backward
#define adr_encoder_1 0x0A//sideways
#define adr_encoder_2 9//not working
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
////////////
////
////
////////////
int compare_1[8];
int compare_2[8];
int compare_3[8];
//
int line1[8];
int line2[8];
int line3[8];
//
int line_data1[8];
int line_data2[8];
int line_data3[8];
//
int dline_data_1[8];
int dline_data_2[8];
int dline_data_3[8];
////////////
int dline1 = 0;
int dline2 = 0;
int dline3 = 0;
///////////////////
////////mux/////////
int s0 = 47;
int s1 = 49;
int s2 = 51;
int s3 = 53;
int en_m = 45;
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
double kp = 16.5;
double ki = 1.01;
double kd = 100.0;
double pid = 0.0;
bool flag_pid=true;
/////////////////////////
/////////////////////////
double lpf_output = 0.0;
double alpha = 0.02;
double desired_value = 0.0;
double prev_output = 0.0;
//////////
int highspeed = 50;
int lowspeed = 50;
////////////////////////
////////////////////////
int i, j;
char ch = '\0';
int sqc = 1;
int sqc_pin = 18;
/////i2c data from pi////
//int pi_data=0;
///////////
///////////
byte encode[6];
volatile int encoder_0 = 0;
///////////
///////////
bool flag_reset = true;
bool L_bool = true;
//////////
//////////
///////L298N
int pwm_l = 2;
int a_l = 36;
int b_l = 38;
///////////
///////////
