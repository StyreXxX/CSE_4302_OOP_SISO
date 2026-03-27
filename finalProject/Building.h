#ifndef BUILDING_H
#define BUILDING_H

#include <bits/stdc++.h>
using namespace std;

class Building {
private:
    int id;
    string name;
    string country;
    string city;
    int floors;
    string material;
    int yearBuilt;
    bool retrofitted;
    string soilType;
    double latitude;
    double longitude;

public:
    Building();
    Building(int id, string name, string country, string city, int floors,
             string material, int yearBuilt, bool retrofitted,
             string soilType, double latitude, double longitude);

    void display() const;

    int getId() const;
    string getName() const;
    string getCountry() const;
    string getCity() const;
    int getFloors() const;
    string getMaterial() const;
    int getYearBuilt() const;
    bool isRetrofitted() const;
    string getSoilType() const;
    double getLatitude() const;
    double getLongitude() const;
};

#endif