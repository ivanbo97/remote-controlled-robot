#pragma once
#include "CharacteristicTelecommandCallback.h"

void Characteristic_Telecom_Callback::onWrite(BLECharacteristic* pCharacteristic_Telecommand)
{
    std::string receivedCommand = pCharacteristic_Telecommand->getValue();
    std::vector<std::string> recievedStrings = splitToStrings(receivedCommand, ',');
    extractAndConvertStr(recievedStrings);
    retrieveNewCoordinates(currentLocation);
    if (currentLocation[0] != INVALID_GPS_DATA) {
        double azimuth = courseTo(
            currentLocation[0],
            currentLocation[1],
            receivedLat,
            receivedLon);

        rotateBeforeMovement(azimuth);

        double moveDistance = distanceBetween(
            currentLocation[0],
            currentLocation[1],
            receivedLat,
            receivedLon);
		startMoving(*speedLevel);
		
		while(moveDistance>3.0){
			retrieveNewCoordinates(currentLocation);
			if (currentLocation[0] == INVALID_GPS_DATA) {
				stopMotors();
				pCharacteristic_Status->setValue("Failed to reach-!GPS!!!");
				pCharacteristic_Status->notify();
				return;
			}
			moveDistance = distanceBetween(
				currentLocation[0],
				currentLocation[1],
				receivedLat,
				receivedLon);
			delay(500);
		}
		stopMotors();
        pCharacteristic_Status->setValue("Target reached!!!");
        pCharacteristic_Status->notify();
    }
    else {
        pCharacteristic_Status->setValue("No GPS Fix found!!!");
        pCharacteristic_Status->notify();
    }
}