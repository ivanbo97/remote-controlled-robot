#include "robot_config.h"

void calibrateMpu()
{
    byte status = 1;
    unsigned long startTime = millis();
    unsigned long currentTime;
    do  {
		currentTime = millis();
		status=mpu.begin();
		if(status == 0){
			mpu.calcOffsets();
			return;
		}
		
    } while (currentTime - startTime < TIME_FOR_MPU_CALIBRATION);
    
    mpuFlag = false;
	
}

void configureMotorPWM()
{
    ledcSetup(motorChannel, freq, resolution);
    ledcAttachPin(motorPin, motorChannel);
    ledcSetup(motorChannel2, freq, resolution);
    ledcAttachPin(motorPin2, motorChannel2);
    ledcSetup(motorChannel3, freq, resolution);
    ledcAttachPin(motorPin3, motorChannel3);
    ledcSetup(motorChannel4, freq, resolution);
    ledcAttachPin(motorPin4, motorChannel4);
}

void stopMotors()
{
  ledcWrite(motorChannel,255);
  ledcWrite(motorChannel2,255);
  ledcWrite(motorChannel3,255);
  ledcWrite(motorChannel4,255);
}