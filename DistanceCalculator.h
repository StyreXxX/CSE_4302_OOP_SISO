#ifndef DISTANCE_CALCULATOR_H
#define DISTANCE_CALCULATOR_H

class DistanceCalculator {
public:
    // Haversine formula: distance in km between two lat/lon points
    static double calculate(double lat1, double lon1, double lat2, double lon2);
};

#endif