#ifndef EARTHQUAKE_DATA_H
#define EARTHQUAKE_DATA_H

#include <string>
#include <vector>

struct EarthquakeRecord {
    std::string time;       // ISO timestamp
    double latitude;        // Epicenter latitude
    double longitude;       // Epicenter longitude
    double depth_km;        // Depth in km
    double magnitude;       // Magnitude
    std::string locationName; // Human-readable location
};

// Sample dataset for Bangladesh + nearby regions
const std::vector<EarthquakeRecord> earthquakeDataset = {
    {"2026-03-07T10:00:00", 26.85, 88.62, 10.0, 6.2, "Sikkim, India"},
    {"2026-03-07T10:15:00", 27.70, 85.32, 12.0, 6.5, "Kathmandu, Nepal"},
    {"2026-03-07T10:30:00", 23.81, 90.41, 8.0, 5.8, "Dhaka, Bangladesh"},
    {"2026-03-07T10:45:00", 22.35, 91.78, 9.0, 5.5, "Chittagong, Bangladesh"},
    {"2026-03-07T11:00:00", 24.89, 91.87, 11.0, 6.0, "Sylhet, Bangladesh"},
    {"2026-03-07T11:15:00", 23.50, 89.18, 7.0, 5.2, "Rajshahi, Bangladesh"},
    {"2026-03-07T11:30:00", 22.84, 89.54, 10.0, 5.7, "Khulna, Bangladesh"},
    {"2026-03-07T11:45:00", 24.03, 90.20, 12.0, 6.1, "Mymensingh, Bangladesh"},
    {"2026-03-07T12:00:00", 22.45, 91.75, 9.5, 5.6, "Cox's Bazar, Bangladesh"},
    {"2026-03-07T12:15:00", 25.78, 88.90, 8.0, 5.9, "Dinajpur, Bangladesh"}
};

#endif