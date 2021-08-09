#include "robot_movement.h"

void MoveForward(double meters) {

  ledcWrite(motorChannel, 0);
  ledcWrite(motorChannel2, 0);
  delay(floor(2000 * meters));
  ledcWrite(motorChannel, 255);
  ledcWrite(motorChannel2, 255);

}

void MoveBackward(double meters) {

  ledcWrite(motorChannel3, 0);
  ledcWrite(motorChannel4, 0);
  delay(floor(2000 * meters));
  ledcWrite(motorChannel3, 255);
  ledcWrite(motorChannel4, 255);
}

float GetYaw() {
  float deg = 0;
  mpu.update();
  map(mpu.getAngleZ(), -180, 180, 0, 360);
  deg = mpu.getAngleZ();
  while (deg >= 360) {
    deg -= 360;
  }
  return deg;
}

void rotateBeforeMovement(double degrees) {

  double rot_z = degrees - offsetGyro;

  if (rot_z < 0)
    rot_z = 360 + rot_z;

  while ((GetYaw() < rot_z - 1) || (GetYaw() > rot_z + 1)) {
    ledcWrite(motorChannel, 130);
    delay(30);
    ledcWrite(motorChannel, 255);
  }

  return;
}

void startMoving(char speed) {

  switch (speed) {
  case 'L': {
    ledcWrite(motorChannel, 100);
    ledcWrite(motorChannel2, 100);
    break;
  }
  case 'M': {
    ledcWrite(motorChannel, 50);
    ledcWrite(motorChannel2, 50);
    break;
  }
  case 'H': {
    ledcWrite(motorChannel, 0);
    ledcWrite(motorChannel2, 0);
    break;
  }
  default:
    break;

  }
}