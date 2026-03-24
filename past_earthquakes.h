#ifndef PAST_EARTHQUAKES_H
#define PAST_EARTHQUAKES_H

#include <iostream>
#include <vector>
#include <string>
#include "past_earthquake_record.h"
#include "past_earthquake_exceptions.h"

class PastEarthquakes {
private:
    std::vector<PastEarthquakeRecord> records;
    std::string filename;

    void loadFromFile();
    void displayAllRecords() const;
    void searchByLocation() const;
    void showStrongestEarthquake() const;
    void saveSampleDataIfFileMissing();

    template <typename T>
    T getValidatedInput(T min, T max) const {
        T value;
        std::cin >> value;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            // ================= EXCEPTION =================
            throw InvalidInputException("Invalid input type. Please enter a valid number.");
        }

        if (value < min || value > max) {
            // ================= EXCEPTION =================
            throw InvalidInputException("Input out of allowed range.");
        }

        return value;
    }

public:
    PastEarthquakes();
    void run();
};

#endif