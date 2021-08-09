#ifndef GPS_DATA_CALCS
#define GPS_DATA_CALCS
#include "Arduino.h"

double distanceBetween(double lat1, double long1, double lat2, double long2);
double courseTo(double lat1, double long1, double lat2, double long2);
#endif