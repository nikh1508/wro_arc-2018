#include<Wire.h>
#define adr 0x29//0x28 or 0x29//bno
#define adr_encoder_0 8//primary//forward and backward
#define adr_encoder_1 0x0A//sideways
#define adr_encoder_2 9//not working
#define adr_mega 7
//////
byte lsb_yaw;
byte msb_yaw;
double yaw_offset = 0;
double yaw = 0;
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
unsigned long cur = 0;
unsigned long prev = 0;
unsigned long time = 0;
/////////////////////////
/////////////////////////
double P = 0.0;
double I = 0.0;
double D = 0.0;
double error = 0.0;
double prev_error = 0.0;
double kp = 3.0;
double ki = 0.0;
double kd = 3.0;
double pid = 0.0;
/////////////////////////
/////////////////////////
double lpf_output = 0.0;
double alpha = 0.02;
double desired_value = 0.0;
double prev_output = 0.0;
//////////
int highspeed = 60;
int lowspeed = 20;
////////////////////////
////////////////////////
int i, j;
char ch = '\0';
int sqc = 1;
int sqc_pin = 18;
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
