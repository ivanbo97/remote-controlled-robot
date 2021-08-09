#pragma once
#include <BLEServer.h>
#include <BLEDevice.h>
extern bool deviceConnected;
extern BLEAdvertising *pAdvertising;	

class ServerCallback: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer);
    void onDisconnect(BLEServer* pServer);
};