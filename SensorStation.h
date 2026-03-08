#ifndef SENSORSTATION_H
#define SENSORSTATION_H

#include <string>
using namespace std;

struct SensorStation {
    string name;
    double latitude;
    double longitude;
    int countdown;  // seconds until S-wave hits
};

#endif