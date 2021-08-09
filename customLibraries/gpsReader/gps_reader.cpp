#include "gps_reader.h"

void retrieveNewCoordinates(double* coordinates){
	
	TinyGPSPlus gpsObject;
	unsigned long startTime = millis();
    unsigned long currentTime;

    do {
        while (Serial.available() > 0) {
            gpsObject.encode(Serial.read());
            if (gpsObject.location.isUpdated()) {
                coordinates[0] = gpsObject.location.lat();
				coordinates[1] = gpsObject.location.lng();
				return;
            }
        }
        currentTime = millis();
    } while (currentTime - startTime < TIME_FOR_GPS_FIX);

    coordinates[0] = INVALID_GPS_DATA;
	coordinates[1] = INVALID_GPS_DATA;
}