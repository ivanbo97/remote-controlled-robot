#ifndef ROBOT_MOVEMENT_H
#define ROBOT_MOVEMENT_H
#include "Arduino.h"

#include <MPU6050_light.h>
#define CONFIG_METERS 5


extern const int motorChannel;
extern const int motorChannel2;
extern const int motorChannel3;
extern const int motorChannel4;
extern double offsetGyro;
extern MPU6050 mpu;
float GetYaw();
void MoveForward(double meters);
void MoveBackward(double meters);
void startMoving(char speed);
void rotateBeforeMovement(double degrees);
#endif