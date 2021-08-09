#include "ble_custom_config.h"

void configureBluetooth()
{
    BLEDevice::init("RC_Robot_Persie");
    pServer = BLEDevice::createServer();
    pServer->setCallbacks(new ServerCallback());
    pService = pServer->createService(SERVICE_UUID);
    pCharacteristic_Telecommand = pService->createCharacteristic(
        CHARACTERISTIC_TELECOMMAND_UUID,
        BLECharacteristic::PROPERTY_WRITE);
    pCharacteristic_Telem_Lat = pService->createCharacteristic(
        CHARACTERISTIC_TELEMETRY_LAT_UUID,
        BLECharacteristic::PROPERTY_NOTIFY);
    pCharacteristic_Telem_Lon = pService->createCharacteristic(
        CHARACTERISTIC_TELEMETRY_LON_UUID,
        BLECharacteristic::PROPERTY_NOTIFY);
    pCharacteristic_Calibration = pService->createCharacteristic(
        CHARACTERISTIC_CALIBRATION_UUID,
        BLECharacteristic::PROPERTY_WRITE);
    pCharacteristic_Status = pService->createCharacteristic(
        CHARACTERISTIC_STATUS_UUID,
        BLECharacteristic::PROPERTY_NOTIFY);

    pCharacteristic_Telecommand->setCallbacks(new Characteristic_Telecom_Callback());
    pCharacteristic_Calibration->setCallbacks(new Characteristic_Calibration_Callback());

    pService->start();

    pAdvertising = BLEDevice::getAdvertising();
    pAdvertising->addServiceUUID(SERVICE_UUID);
    pAdvertising->setScanResponse(true);
    pAdvertising->setMinPreferred(0x06);  
    pAdvertising->setMaxPreferred(0x12);
    BLEDevice::startAdvertising();
    BLESecurity* pSecurity = new BLESecurity();
    pSecurity->setStaticPIN(STATIC_PIN);
}