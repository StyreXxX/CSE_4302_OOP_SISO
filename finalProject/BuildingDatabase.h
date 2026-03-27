#ifndef BUILDINGDATABASE_H
#define BUILDINGDATABASE_H

#include "Building.h"

class BuildingDatabase {
private:
    vector<Building> buildings;

public:
    void loadData(const string& filename);
    void showAll() const;
    void showByCountry(const string& country) const;
    Building* findById(int id);
    vector<Building*> getByCountry(const string& country);
};

#endif