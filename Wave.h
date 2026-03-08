#ifndef WAVE_H
#define WAVE_H

#include "SensorStation.h"
#include <vector>
#include <map>

class Wave {
protected:
    double speed_km_per_s; // Wave speed in km/s

public:
    // Constructor with speed
    Wave(double speed) : speed_km_per_s(speed) {}

    // Calculate arrival times (in seconds) for all stations
    virtual std::map<std::string, double> calculateArrivalTimes(
        double eqLat, double eqLon,
        const std::vector<SensorStation>& stations
    ) const;
};

#endif