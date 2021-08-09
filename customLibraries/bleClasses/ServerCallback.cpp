#include "ServerCallback.h"


void ServerCallback::onConnect(BLEServer* pServer) {
  pAdvertising->stop();  
}

void ServerCallback::onDisconnect(BLEServer* pServer) {
  BLEDevice::startAdvertising();
}
