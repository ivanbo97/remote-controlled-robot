#ifndef ROBOT_CONFIG_H
#define ROBOT_CONFIG_H
#define TIME_FOR_MPU_CALIBRATION 5000
#include "Arduino.h"

#include "Wire.h"

#include <MPU6050_light.h>

extern bool mpuFlag;
extern MPU6050 mpu;
extern const int motorPin;
extern const int motorPin2;
extern const int motorPin3;
extern const int motorPin4;

extern const int freq;
extern const int motorChannel;
extern const int motorChannel2;
extern const int motorChannel3;
extern const int motorChannel4;
extern const int resolution;

void calibrateMpu();
void configureMotorPWM();
void stopMotors();
#endif