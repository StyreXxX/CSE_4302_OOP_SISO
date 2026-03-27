#include "Building.h"

Building::Building() {
    id = 0;
    name = "";
    country = "";
    city = "";
    floors = 0;
    material = "";
    yearBuilt = 0;
    retrofitted = false;
    soilType = "";
    latitude = 0.0;
    longitude = 0.0;
}

Building::Building(int id, string name, string country, string city, int floors,
                   string material, int yearBuilt, bool retrofitted,
                   string soilType, double latitude, double longitude) {
    this->id = id;
    this->name = name;
    this->country = country;
    this->city = city;
    this->floors = floors;
    this->material = material;
    this->yearBuilt = yearBuilt;
    this->retrofitted = retrofitted;
    this->soilType = soilType;
    this->latitude = latitude;
    this->longitude = longitude;
}

void Building::display() const {
    cout << left
         << setw(5)  << id
         << setw(22) << name
         << setw(15) << country
         << setw(15) << city
         << setw(8)  << floors
         << setw(12) << material
         << setw(10) << yearBuilt
         << setw(13) << (retrofitted ? "Yes" : "No")
         << setw(10) << soilType
         << endl;
}

int Building::getId() const { return id; }
string Building::getName() const { return name; }
string Building::getCountry() const { return country; }
string Building::getCity() const { return city; }
int Building::getFloors() const { return floors; }
string Building::getMaterial() const { return material; }
int Building::getYearBuilt() const { return yearBuilt; }
bool Building::isRetrofitted() const { return retrofitted; }
string Building::getSoilType() const { return soilType; }
double Building::getLatitude() const { return latitude; }
double Building::getLongitude() const { return longitude; }