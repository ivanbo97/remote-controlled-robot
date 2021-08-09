#ifndef BLE_CUSTOM_CONFIG_H
#define BLE_CUSTOM_CONFIG_H

#define SERVICE_UUID        "00001050-a5d4-11eb-bcbc-0242ac130002"
#define CHARACTERISTIC_TELECOMMAND_UUID "00001051-a5d4-11eb-bcbc-0242ac130002"
#define CHARACTERISTIC_TELEMETRY_LAT_UUID "00001052-a5d4-11eb-bcbc-0242ac130002"
#define CHARACTERISTIC_TELEMETRY_LON_UUID "00001053-a5d4-11eb-bcbc-0242ac130002"
#define CHARACTERISTIC_CALIBRATION_UUID "00001054-a5d4-11eb-bcbc-0242ac130002"
#define CHARACTERISTIC_STATUS_UUID "00001055-a5d4-11eb-bcbc-0242ac130002"
#define STATIC_PIN 123456

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <ServerCallback.h>
#include <CharacteristicCalibrationCallback.h>
#include <CharacteristicTelecommandCallback.h>

extern bool deviceConnected;
extern BLEServer* pServer;
extern BLEService* pService;
extern BLECharacteristic* pCharacteristic_Telecommand;
extern BLECharacteristic* pCharacteristic_Telem_Lat;
extern BLECharacteristic* pCharacteristic_Telem_Lon;
extern BLECharacteristic* pCharacteristic_Calibration;
extern BLECharacteristic* pCharacteristic_Status;
extern BLEAdvertising* pAdvertising;

void configureBluetooth();

#endif