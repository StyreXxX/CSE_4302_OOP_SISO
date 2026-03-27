#include "BuildingDatabase.h"
#include <fstream>
#include <sstream>

void BuildingDatabase::loadData(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error: could not open file: " << filename << endl;
        return;
    }

    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string token;

        int id, floors, yearBuilt;
        string name, country, city, material, soilType;
        bool retrofitted;
        double latitude, longitude;

        getline(ss, token, ','); id = stoi(token);
        getline(ss, name, ',');
        getline(ss, country, ',');
        getline(ss, city, ',');
        getline(ss, token, ','); floors = stoi(token);
        getline(ss, material, ',');
        getline(ss, token, ','); yearBuilt = stoi(token);
        getline(ss, token, ','); retrofitted = stoi(token);
        getline(ss, soilType, ',');
        getline(ss, token, ','); latitude = stod(token);
        getline(ss, token, ','); longitude = stod(token);

        buildings.push_back(Building(
            id, name, country, city, floors, material,
            yearBuilt, retrofitted, soilType, latitude, longitude
        ));
    }
}

void BuildingDatabase::showAll() const {
    if (buildings.empty()) {
        cout << "No buildings loaded.\n";
        return;
    }

    cout << left
         << setw(5)  << "ID"
         << setw(22) << "Name"
         << setw(15) << "Country"
         << setw(15) << "City"
         << setw(8)  << "Floors"
         << setw(12) << "Material"
         << setw(10) << "Year"
         << setw(13) << "Retrofitted"
         << setw(10) << "Soil"
         << endl;

    cout << string(110, '-') << endl;

    for (const auto& b : buildings) {
        b.display();
    }
}

void BuildingDatabase::showByCountry(const string& country) const {
    bool found = false;

    cout << left
         << setw(5)  << "ID"
         << setw(22) << "Name"
         << setw(15) << "Country"
         << setw(15) << "City"
         << setw(8)  << "Floors"
         << setw(12) << "Material"
         << setw(10) << "Year"
         << setw(13) << "Retrofitted"
         << setw(10) << "Soil"
         << endl;

    cout << string(110, '-') << endl;

    for (const auto& b : buildings) {
        if (b.getCountry() == country) {
            b.display();
            found = true;
        }
    }

    if (!found) {
        cout << "No buildings found for this country.\n";
    }
}

Building* BuildingDatabase::findById(int id) {
    for (auto& b : buildings) {
        if (b.getId() == id) return &b;
    }
    return nullptr;
}

vector<Building*> BuildingDatabase::getByCountry(const string& country) {
    vector<Building*> result;
    for (auto& b : buildings) {
        if (b.getCountry() == country) {
            result.push_back(&b);
        }
    }
    return result;
}