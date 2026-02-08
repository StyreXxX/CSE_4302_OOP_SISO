#ifndef EARTHQUAKE_DATA_H
#define EARTHQUAKE_DATA_H

#include <string>
#include <vector>

// Enum to categorize severity easily
enum class EmergencyLevel { LOW, MODERATE, HIGH, CRITICAL };

struct EarthquakeRecord {
    std::string time;
    double latitude;
    double longitude;
    double depth;
    double mag;
    std::string magType;
    int nst;
    int gap;
    double dmin;
    double rms;
    std::string net;
    std::string id;
    std::string updated;
    std::string place;
    std::string type;
    double horizontalError;
    double depthError;
    double magError;
    int magNst;
    std::string status;
    std::string locationSource;
    std::string magSource;

    // Helper to get severity based on magnitude
    EmergencyLevel getSeverity() const {
        if (mag < 4.0) return EmergencyLevel::LOW;
        if (mag < 6.0) return EmergencyLevel::MODERATE;
        if (mag < 7.0) return EmergencyLevel::HIGH;
        return EmergencyLevel::CRITICAL;
    }
};

extern const std::vector<EarthquakeRecord> earthquakeDataset;

#endif