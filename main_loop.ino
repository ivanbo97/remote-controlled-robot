#include <robot_config.h>

#include <ble_custom_config.h>

#include <robot_movement.h>

#include <esp_task_wdt.h>

#define WDT_TIMEOUT_SEC 600
double currentLocation[2];
double offsetGyro;
double receivedLat;
double receivedLon;
const char * speedLevel;
bool mpuFlag = true;

bool deviceConnected = false;
BLEServer * pServer = NULL;
BLEService * pService = NULL;
BLECharacteristic * pCharacteristic_Telecommand = NULL;
BLECharacteristic * pCharacteristic_Telem_Lat = NULL;
BLECharacteristic * pCharacteristic_Telem_Lon = NULL;
BLECharacteristic * pCharacteristic_Calibration = NULL;
BLECharacteristic * pCharacteristic_Status = NULL;
BLEAdvertising * pAdvertising = NULL;

MPU6050 mpu(Wire);

const int motorPin = 18;
const int motorPin2 = 19;
const int motorPin3 = 5;
const int motorPin4 = 23;

const int freq = 5000;
const int motorChannel = 0;
const int motorChannel2 = 1;
const int motorChannel3 = 2;
const int motorChannel4 = 3;
const int resolution = 8;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  esp_task_wdt_init(WDT_TIMEOUT_SEC, true);
  configureBluetooth();
  calibrateMpu();
  configureMotorPWM();
  stopMotors();
}