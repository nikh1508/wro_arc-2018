#include<Wire.h>
//////////motors///////////
struct motors {
  int pw;
  int forw;
  int bacw;
} motor[3];
///////////
int pwm0;
int pwm1;
int pwm2;
///////////////////////////
#define adr 0x29//0x28 or 0x29
//
byte lsb_yaw;
byte msb_yaw;
double yaw_offset = 0;
double yaw = 0;
//////////////////////////
//start of dt
unsigned long cur;
unsigned long prev;
unsigned long time;
////////////////
////////////start of pid
double P = 0;
double I = 0;
double D = 0;
double error = 0;
double prev_error = 0;
double kp = 0.5;
double ki = 0.5;
double kd = 0.5;
double pid = 0;
//////////////////////////
////low pass filters
double lpf_output_sec;
double alpha_sec;
double desired_value_sec = 255.0;
double prev_output_sec;
///
double lpf_output_main;
double alpha_main;
double desired_value_main;
double prev_output_main;
/////////////////////////////////
////////////////////////////////
int line[16];
int line_data_1[8], line_data_2[8];
//////////////////encoder///////////////////
byte encode[6];
//
int encoder_0 = 0;
int encoder_1 = 0;
int encoder_2 = 0;
/////////////misc/////////////
int i, j;
char ch = '\0';
char ch_mask = '\0';

