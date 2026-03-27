#ifndef PAST_EARTHQUAKES_H
#define PAST_EARTHQUAKES_H

#include <bits/stdc++.h>
#include "past_earthquake_record.h"
#include "past_earthquake_exceptions.h"
using namespace std;

class PastEarthquakes {
private:
    vector<PastEarthquakeRecord> records;
    string filename;

    void loadFromFile();
    void displayAllRecords() const;
    void displayCountries() const;
    void searchByCountry() const;
    vector<string> getUniqueCountries() const;
    void showStrongestEarthquake() const;
    void saveSampleDataIfFileMissing();

    template <typename T>
    T getValidatedInput(T min, T max) const {
        T value;
        cin >> value;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw InvalidInputException("Invalid input type. Please enter a valid number.");
        }

        if (value < min || value > max) {
            throw InvalidInputException("Input out of allowed range.");
        }

        return value;
    }

public:
    PastEarthquakes();
    void run();
};

#endif