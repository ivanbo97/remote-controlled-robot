#include "CharacteristicCalibrationCallback.h"

void Characteristic_Calibration_Callback_Dummy::onWrite(BLECharacteristic * pCharacteristic_Calibration) {
  //Dummy fix of BLE library bug
  return;
}

void Characteristic_Calibration_Callback::onWrite(BLECharacteristic * pCharacteristic_Calibration) {
  if (mpuFlag == false) {
    pCharacteristic_Status -> setValue("MPU Failure!");
    pCharacteristic_Status -> notify();
    return;
  }
  std::string receivedCommand = pCharacteristic_Calibration -> getValue();
  retrieveNewCoordinates(currentLocation);
  if (currentLocation[0] != INVALID_GPS_DATA) {
    char s[20];
    sprintf(s, "%.8f", currentLocation[0]);
    std::string coord_str;
    coord_str = s;

    pCharacteristic_Telem_Lat -> setValue(coord_str);
    pCharacteristic_Telem_Lat -> notify();

    sprintf(s, "%.8f\n", currentLocation[1]);
    coord_str = s;
    pCharacteristic_Telem_Lon -> setValue(coord_str);
    pCharacteristic_Telem_Lon -> notify();
  } else {
    pCharacteristic_Status -> setValue("No GPS Fix!");
    pCharacteristic_Status -> notify();
    return;
  }
  MoveForward(CONFIG_METERS);
  double newLocation[2];
  retrieveNewCoordinates(newLocation);

  if (newLocation[0] != INVALID_GPS_DATA) {

    offsetGyro = courseTo(
      currentLocation[0],
      currentLocation[1],
      newLocation[0],
      newLocation[1]);
    pCharacteristic_Status -> setValue("Robot Calibrated!");
    pCharacteristic_Status -> notify();
  } else {
    pCharacteristic_Status -> setValue("No GPS Fix!");
    pCharacteristic_Status -> notify();
  }
  MoveBackward(CONFIG_METERS);

  pCharacteristic_Calibration -> setCallbacks(new Characteristic_Calibration_Callback_Dummy());

}