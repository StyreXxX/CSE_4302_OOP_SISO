#ifndef EARTHQUAKES_TODAY_H
#define EARTHQUAKES_TODAY_H

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <map>

// Custom Exception for invalid user inputs
class InvalidSelectionException : public std::exception {
private:
    std::string message;
public:
    InvalidSelectionException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Simulated API Record
struct EarthquakeRecord {
    std::string country;
    std::string time;
    double magnitude;
    double depth;
    std::string place;
    int damages;          // Simulated API data
    int missingPersons;   // Simulated API data
    std::vector<std::string> keywords; // e.g., "tsunami_risk", "buildings_damaged"
};

class EarthquakesToday {
private:
    std::vector<EarthquakeRecord> dataset;
    std::vector<std::string> availableCountries;

    void loadDummyData(); // Simulates fetching the API

public:
    EarthquakesToday();

    void displayCountries() const;
    std::vector<EarthquakeRecord> getEarthquakesByCountry(const std::string& country) const;
    void displayEarthquakeDetails(const EarthquakeRecord& eq) const;
    void displayDisasterManagement(const std::vector<std::string>& keywords) const;

    // Template function to handle user input safely
    template <typename T>
    T getValidInput(T min, T max) const {
        T choice;
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            throw InvalidSelectionException("Invalid input type. Please enter a number.");
        }
        if (choice < min || choice > max) {
            throw InvalidSelectionException("Selection out of range.");
        }
        return choice;
    }
};

#endif