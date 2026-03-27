#ifndef SENSORS_H
#define SENSORS_H

#include "Utils.h"
#include "Earthquakes.h"

class Sensor {
protected:
    std::string id, location;
    double lat, lon;
public:
    Sensor(std::string id, std::string loc, double lt, double ln)
        : id(id), location(loc), lat(lt), lon(ln) {}
    virtual ~Sensor() {}
    virtual bool detect(const Earthquake* eq) = 0;
    double getLat() const { return lat; }
    double getLon() const { return lon; }
};

class PWaveSensor : public Sensor {
public:
    PWaveSensor(std::string id, std::string loc, double lt, double ln) : Sensor(id, loc, lt, ln) {}
    
    bool detect(const Earthquake* eq) override {
        double dist = DistanceCalc::haversine(lat, lon, eq->getLat(), eq->getLon());
        double time = eq->getPWaveTime(dist);
        return (time < 180 && eq->getMagnitude() > 3.0);
    }
};

class SWaveSensor : public Sensor {
public:
    SWaveSensor(std::string id, std::string loc, double lt, double ln) : Sensor(id, loc, lt, ln) {}
    
    bool detect(const Earthquake* eq) override {
        double dist = DistanceCalc::haversine(lat, lon, eq->getLat(), eq->getLon());
        double time = eq->getSWaveTime(dist);
        return (time < 300 && eq->getMagnitude() > 4.0);
    }
};

#endif