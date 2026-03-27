#ifndef SIMULATION_H
#define SIMULATION_H

#include "Earthquakes.h"
#include "Cities.h"
#include "Warning.h"
#include <vector>

class EarthquakeSimulator {
    std::vector<Earthquake*> earthquakes;
    std::vector<City*> cities;
    Dashboard* dashboard;
    bool simulating;
    
public:
    EarthquakeSimulator(Dashboard* dash) : dashboard(dash), simulating(false) {}
    ~EarthquakeSimulator() { for(auto e : earthquakes) delete e; }
    
    void addEarthquake(Earthquake* e) { earthquakes.push_back(e); }
    void addCity(City* c) { cities.push_back(c); }
    
    void showEarthquakes() {
        Color::clear();
        Color::printHeader("EARTHQUAKE SCENARIOS");
        for(size_t i = 0; i < earthquakes.size(); i++) {
            std::cout << "[" << (i+1) << "] ";
            earthquakes[i]->display();
        }
    }
    
    void simulate(int index) {
        if(index < 0 || index >= (int)earthquakes.size()) return;
        
        Earthquake* eq = earthquakes[index];
        simulating = true;
        
        double maxTime = 0;
        for(auto city : cities) {
            double dist = DistanceCalc::haversine(eq->getLat(), eq->getLon(), city->getLat(), city->getLon());
            maxTime = std::max(maxTime, eq->getSWaveTime(dist));
        }
        
        dashboard->showWarning(eq, maxTime);
        
        // Store city impact data
        struct CityImpact {
            std::string name;
            double sTime;
            double risk;
        };
        std::vector<CityImpact> impacts;
        
        for(auto city : cities) {
            double dist = DistanceCalc::haversine(eq->getLat(), eq->getLon(), city->getLat(), city->getLon());
            double sTime = eq->getSWaveTime(dist);
            double risk = city->calculateRisk(eq->getMagnitude(), dist);
            impacts.push_back({city->getName(), sTime, risk});
            
            Color::printHeader(city->getName());
            std::cout << "  Distance: " << (int)dist << " km\n";
            std::cout << "  S-wave: " << (int)sTime << " seconds\n";
            std::cout << "  Risk: " << (int)risk << "% - ";
            if(risk > 70) Color::printError("EVACUATE");
            else if(risk > 40) Color::printWarning("SEEK COVER");
            else Color::printInfo("PREPARE");
        }
        
        // Sort by S-wave time (bubble sort - simple)
        for(size_t i = 0; i < impacts.size(); i++) {
            for(size_t j = i+1; j < impacts.size(); j++) {
                if(impacts[i].sTime > impacts[j].sTime) {
                    CityImpact temp = impacts[i];
                    impacts[i] = impacts[j];
                    impacts[j] = temp;
                }
            }
        }
        
        // Countdown for each city
        for(auto& imp : impacts) {
            Color::printAlert("COUNTDOWN FOR " + imp.name);
            for(int t = (int)imp.sTime; t >= 0; t--) {
                dashboard->showCountdown(t, imp.name);
                Sleep(1000); // REPLACED STD::THREAD
            }
        }
        
        // Shutdown all infrastructure
        for(auto city : cities) {
            city->shutdownAll();
        }
        
        dashboard->showInfrastructureShutdown();
        
        Color::printSuccess("SIMULATION COMPLETE");
        Sleep(3000); // REPLACED STD::THREAD
        simulating = false;
    }
    
    bool isSimulating() const { return simulating; }
};

#endif