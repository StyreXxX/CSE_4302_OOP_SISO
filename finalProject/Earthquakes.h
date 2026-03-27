#ifndef EARTHQUAKES_H
#define EARTHQUAKES_H

#include "Utils.h"
#include <string>

class Earthquake {
protected:
    std::string id;
    double lat, lon, depth, magnitude;
    std::string location;
    
public:
    Earthquake(std::string id, double lat, double lon, double depth, double mag, std::string loc)
        : id(id), lat(lat), lon(lon), depth(depth), magnitude(mag), location(loc) {}
    
    virtual ~Earthquake() {}
    
    std::string getId() const { return id; }
    double getLat() const { return lat; }
    double getLon() const { return lon; }
    double getMagnitude() const { return magnitude; }
    std::string getLocation() const { return location; }
    
    virtual double getPWaveTime(double distance) const = 0;
    virtual double getSWaveTime(double distance) const = 0;
    virtual std::string getSeverity() const = 0;
    
    virtual void display() const {
        std::cout << std::left << std::setw(25) << location
                  << " | Mag: " << magnitude << " | Depth: " << depth << "km\n";
    }
};

class RealEarthquake : public Earthquake {
public:
    RealEarthquake(std::string id, double lat, double lon, double depth, double mag, std::string loc)
        : Earthquake(id, lat, lon, depth, mag, loc) {}
    
    double getPWaveTime(double distance) const override { return distance / 6.0; }
    double getSWaveTime(double distance) const override { return distance / 3.5; }
    
    std::string getSeverity() const override {
        if(magnitude >= 7.0) return "CATASTROPHIC";
        if(magnitude >= 6.0) return "SEVERE";
        if(magnitude >= 5.0) return "STRONG";
        if(magnitude >= 4.0) return "MODERATE";
        return "LIGHT";
    }
    
    void display() const override {
        std::cout << "[REAL] ";
        Earthquake::display();
    }
};

class SimEarthquake : public Earthquake {
public:
    SimEarthquake(std::string id, double lat, double lon, double depth, double mag, std::string loc)
        : Earthquake(id, lat, lon, depth, mag, loc) {}
    
    double getPWaveTime(double distance) const override { return distance / 5.8; }
    double getSWaveTime(double distance) const override { return distance / 3.3; }
    
    std::string getSeverity() const override {
        if(magnitude >= 7.5) return "SIM_CATASTROPHIC";
        if(magnitude >= 6.5) return "SIM_SEVERE";
        if(magnitude >= 5.5) return "SIM_STRONG";
        return "SIM_MODERATE";
    }
    
    void display() const override {
        std::cout << "[SIM]  ";
        Earthquake::display();
    }
};

#endif