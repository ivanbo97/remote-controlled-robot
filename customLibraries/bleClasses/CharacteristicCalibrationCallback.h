#pragma once
#include <BLECharacteristic.h>
#include <gps_data_calcs.h>
#include <robot_movement.h>
#include <gps_reader.h>

extern double currentLocation[2];
extern BLECharacteristic* pCharacteristic_Telem_Lon;
extern BLECharacteristic* pCharacteristic_Telem_Lat;
extern BLECharacteristic* pCharacteristic_Status;
extern double offsetGyro;
extern bool mpuFlag;
class Characteristic_Calibration_Callback : public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic* pCharacteristic_Calibration);  
};
//Dummy fix for BLE library bug
class Characteristic_Calibration_Callback_Dummy : public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic* pCharacteristic_Calibration);  
}; 