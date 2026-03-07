#include "Wave.h"
#include "DistanceCalculator.h"
#include <cmath>

std::map<std::string, double> Wave::calculateArrivalTimes(
    double eqLat,
    double eqLon,
    const std::vector<SensorStation>& stations
) const {
    std::map<std::string, double> arrivals;

    for (const auto& s : stations) {
        double distance = DistanceCalculator::calculate(eqLat, eqLon, s.latitude, s.longitude);
        arrivals[s.name] = distance / speed_km_per_s; // Time in seconds
    }

    return arrivals;
}