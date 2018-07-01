#define ENC_FR 0x5 
#define ENC_LT 0x6
#define ENC_RT 0x7
#define motor_debug true

#include<Wire.h>


//Motor Pinouts :

//Front Wheel
constexpr int ft_d1 = 51;
constexpr int ft_d2 = 49;
constexpr int ft_pwm = 2;

//Left Wheel
constexpr int lt_d1 = 24;
constexpr int lt_d2 = 22;
constexpr int lt_pwm = 3;

//Right Wheel
constexpr int rt_d1 = 41;
constexpr int rt_d2 = 43;
constexpr int rt_pwm = 5;

//Clamping Rack & Pinion Motor
constexpr int rp_d1 = 39;
constexpr int rp_d2 = 45;
constexpr int rp_pwm = 4;

constexpr int pins[] = {51, 49, 2, 24, 22, 3, 41, 43, 5, 39, 45, 4};