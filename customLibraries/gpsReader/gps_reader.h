#ifndef GPS_READER_H
#define GPS_READER_H
#include <TinyGPS++.h>
#define TIME_FOR_GPS_FIX 20000
#define INVALID_GPS_DATA 200.0
void retrieveNewCoordinates(double *coordinates);
#endif