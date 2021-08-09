#pragma once
#include <BLECharacteristic.h>
#include <telecommand_parser.h>
#include <robot_movement.h>
#include <gps_reader.h>
#include <gps_data_calcs.h>
#include <Arduino.h>
#include <robot_config.h>

extern BLECharacteristic* pCharacteristic_Telecommand;
extern double currentLocation[2];
extern const char *speedLevel;
extern BLECharacteristic* pCharacteristic_Status;
class Characteristic_Telecom_Callback : public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic* pCharacteristic_Telecommand);
};