#ifndef BUILDING_MAPPING_H
#define BUILDING_MAPPING_H

#include <string>
#include "BuildingDatabase.h"
#include "CountryRisks.h"

class BuildingMapping {
private:
    BuildingDatabase db;

    // Helper functions
    void clearScreen();
    void pauseScreen();
    void printLine(int n = 55);
    void printTitle(const std::string& title);
    std::string getRiskLevel(double score);
    std::string getRecommendation(double score);
    void showCountryMenu();
    void showRiskReport(Building* b, RiskModel* model, double score);

public:
    BuildingMapping(); // Constructor
    void run();        // Main entry point for this module
};

#endif