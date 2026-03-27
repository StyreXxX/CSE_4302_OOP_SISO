#ifndef EARTHQUAKE_PREDICTION_H
#define EARTHQUAKE_PREDICTION_H

#include <vector>
#include "Earthquakes.h"
#include "Cities.h"
#include "Sensors.h"
#include "Warning.h"
#include "Simulation.h"

class EarthquakePrediction {
private:
    Dashboard dashboard;
    EarthquakeSimulator simulator;
    std::vector<City*> cities;

    void initializeSystem();
    void loadCities();
    void loadEarthquakes();
    void cleanup();

public:
    EarthquakePrediction();
    ~EarthquakePrediction();

    void run();
};

#endif