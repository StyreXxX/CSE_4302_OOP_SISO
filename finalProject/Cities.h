#ifndef CITIES_H
#define CITIES_H

#include "Utils.h"
#include <vector>

class Infrastructure {
protected:
    std::string name;
    bool active;
public:
    Infrastructure(std::string n) : name(n), active(true) {}
    virtual ~Infrastructure() {}
    virtual void shutdown() = 0;
    virtual void restart() = 0;
    std::string getName() const { return name; }
    bool isActive() const { return active; }
};

class PowerGrid : public Infrastructure {
    std::string company;
public:
    PowerGrid(std::string n, std::string comp) : Infrastructure(n), company(comp) {}
    void shutdown() override { active = false; Color::printWarning("[POWER] " + company + " - " + name + " SHUTDOWN"); }
    void restart() override { active = true; }
};

class GasSystem : public Infrastructure {
    std::string op;
public:
    GasSystem(std::string n, std::string o) : Infrastructure(n), op(o) {}
    void shutdown() override { active = false; Color::printWarning("[GAS] " + op + " - " + name + " VALVES CLOSED"); }
    void restart() override { active = true; }
};

class Transport : public Infrastructure {
    std::string type;
public:
    Transport(std::string n, std::string t) : Infrastructure(n), type(t) {}
    void shutdown() override { active = false; Color::printWarning("[TRAIN] " + type + " - " + name + " EMERGENCY STOP"); }
    void restart() override { active = true; }
};

class City {
private:
    std::string name, district;
    double lat, lon;
    int population;
    std::vector<Infrastructure*> infra;
    std::vector<std::string> contacts;
    
public:
    City(std::string n, double lt, double ln, int pop, std::string dist)
        : name(n), lat(lt), lon(ln), population(pop), district(dist) {}
    
    ~City() { for(auto i : infra) delete i; }
    
    void addInfrastructure(Infrastructure* i) { infra.push_back(i); }
    void addContact(std::string c) { contacts.push_back(c); }
    
    void shutdownAll() {
        Color::printHeader("SHUTDOWN: " + name);
        for(auto i : infra) i->shutdown();
        sendAlert();
    }
    
    void sendAlert() {
        Color::printAlert("EMERGENCY: " + name + " - TAKE COVER!");
        for(auto c : contacts) std::cout << "  [ALERT] " << c << "\n";
    }
    
    double calculateRisk(double magnitude, double distance) const {
        double risk = (magnitude / 7.0) * (100.0 / (distance + 10)) * (population / 1000000.0);
        if(risk > 100) risk = 100;
        return risk;
    }
    
    void display() const {
        std::cout << "  [CITY] " << std::left << std::setw(15) << name 
                  << " | " << std::setw(12) << district 
                  << " | Pop: " << population/1000000 << "M\n";
    }
    
    std::string getName() const { return name; }
    double getLat() const { return lat; }
    double getLon() const { return lon; }
    std::string getDistrict() const { return district; }
};

#endif