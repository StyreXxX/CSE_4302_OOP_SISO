#ifndef EARTHQUAKE_PREDICTOR_H
#define EARTHQUAKE_PREDICTOR_H

#include "PWave.h"
#include "SWave.h"
#include "SensorStation.h"
#include "earthquake_data.h"
#include <vector>
#include <map>
#include <mutex>

class EarthquakePredictor {
private:
    std::vector<SensorStation> stations;
    PWave pWave;
    SWave sWave;
    std::mutex coutMutex; // Prevent overlapping terminal output

public:
    EarthquakePredictor(const std::vector<SensorStation>& sts) : stations(sts) {}

    // Process a single earthquake (professional terminal simulation)
    void processEarthquake(const EarthquakeRecord& eq);

    // Process multiple earthquakes sequentially
    void processAll(const std::vector<EarthquakeRecord>& dataset);
};

#endif