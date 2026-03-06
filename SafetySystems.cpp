#include "SafetySystems.h"
#include <iostream>
#include <iomanip>
#include <cstdlib> // for rand()

// --- 1. Alarm System Logic ---
void AlarmSystem::processEarthquake(const EarthquakeRecord& quake) {
    EmergencyLevel level = quake.getSeverity();
    
    std::cout << "[" << moduleName << "] Analyzing sensor data from " << quake.place << "...\n";
    
    if (level == EmergencyLevel::CRITICAL || level == EmergencyLevel::HIGH) {
        std::cout << "   >>> CRITICAL ALERT: SIRENS ACTIVATED! Magnitude " << quake.mag << " detected!\n";
        std::cout << "   >>> SMS broadcast sent to all residents within 500km.\n";
    } else if (level == EmergencyLevel::MODERATE) {
        std::cout << "   >>> WARNING: Yellow alert. Local authorities notified.\n";
    } else {
        std::cout << "   >>> INFO: Minor tremor logged. No alarm necessary.\n";
    }
    std::cout << "-----------------------------------------------------\n";
}

// --- 2. Rescue Operation Logic ---
void RescueOperation::processEarthquake(const EarthquakeRecord& quake) {
    if (quake.mag >= 6.0) {
        std::cout << "[" << moduleName << "] Mobilizing units for " << quake.place << ".\n";
        deployDrones(quake.place);
        if (quake.mag >= 7.0) {
            deployHeavyMachinery(quake.place);
        }
    }
}

void RescueOperation::deployDrones(const std::string& location) {
    std::cout << "   -> Thermal Imaging Drones deployed to scan for survivors in " << location << ".\n";
}

void RescueOperation::deployHeavyMachinery(const std::string& location) {
    std::cout << "   -> Heavy Lift Helicopters dispatched with excavators to " << location << ".\n";
}

// --- 3. Regional Safety Mapping Logic ---
void RegionalSafetyMap::processEarthquake(const EarthquakeRecord& quake) {
    if (quake.mag < 5.0) return; // Ignore small quakes for building checks

    std::cout << "[" << moduleName << "] Scanning infrastructure database near " << quake.latitude << ", " << quake.longitude << "...\n";
    
    // Simulate checking 3 random buildings in the area
    for(int i = 1; i <= 3; i++) {
        // Random check simulation
        bool safe = checkBuildingStability(10 * i, quake.mag); 
        std::cout << "   -> Building Sector " << char('A' + i) << ": " 
                  << (safe ? "STRUCTURALLY SOUND" : "CRITICAL FAILURE DETECTED") << "\n";
    }
}

bool RegionalSafetyMap::checkBuildingStability(double distanceKm, double magnitude) {
    // Simple logic: Closer + Higher Mag = More likely to fail
    double riskFactor = (magnitude * 10) - distanceKm;
    // If risk factor > 50, building fails. 
    return riskFactor < 50.0; 
}

// --- 4. Community Safety Logic ---
void CommunitySafety::processEarthquake(const EarthquakeRecord& quake) {
    if (quake.mag >= 5.5) {
        std::cout << "[" << moduleName << "] Opening public reporting channel for " << quake.place << ".\n";
        // Simulating a report coming in
        reportMissingPerson("John Doe", quake.place);
        reportMissingPerson("Jane Smith", quake.place);
    }
}

void CommunitySafety::reportMissingPerson(const std::string& name, const std::string& location) {
    std::cout << "   -> REPORT RECEIVED: Person '" << name << "' reported missing in " << location << ".\n";
    missingPersons.push_back(name);
}