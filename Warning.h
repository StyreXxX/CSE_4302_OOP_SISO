#ifndef WARNING_H
#define WARNING_H

#include "Utils.h"
#include "Cities.h"
#include "Earthquakes.h"

class Dashboard {
    std::vector<City*> cities;
    
public:
    void addCity(City* c) { cities.push_back(c); }
    
    void showMain() {
        Color::clear();
        std::cout << "========================================\n";
        std::cout << "    BANGLADESH EARTHQUAKE EARLY WARNING SYSTEM\n";
        std::cout << "========================================\n";
        
        Color::printSuccess("System: ONLINE");
        std::cout << "\nMONITORED CITIES (" << cities.size() << "):\n";
        for(auto c : cities) c->display();
        
        std::cout << "\nCOMMANDS:\n";
        std::cout << "  [S] Simulate Earthquake   [D] City Status\n";
        std::cout << "  [I] Infrastructure Status [Q] Quit\n";
    }
    
    void showWarning(const Earthquake* eq, double eta) {
        Color::clear();
        std::cout << "========================================\n";
        std::cout << "         EARTHQUAKE WARNING\n";
        std::cout << "========================================\n";
        
        Color::printAlert("MAGNITUDE: " + std::to_string(eq->getMagnitude()));
        Color::printAlert("EPICENTER: " + eq->getLocation());
        Color::printAlert("S-WAVE ETA: " + std::to_string((int)eta) + " seconds");
    }
    
    void showCountdown(int seconds, const std::string& city) {
        if(seconds > 0) {
            std::cout << "\r[COUNTDOWN] " << city << ": " << seconds << "s remaining   ";
            std::cout.flush();
        } else {
            Color::printAlert(city + " - EARTHQUAKE IMPACT!");
        }
    }
    
    void showInfrastructureShutdown() {
        std::cout << "\n";
        Color::printHeader("INFRASTRUCTURE SHUTDOWN");
        std::vector<std::string> systems = {"DPDC Power Grid", "DESCO Network", "Titas Gas", "MRT Lines", "Metro Rail"};
        for(auto& s : systems) { 
            Color::printWarning("SHUTTING: " + s); 
            Sleep(200); // REPLACED STD::THREAD
        }
    }
    
    void showCityStatus() {
        Color::clear();
        Color::printHeader("CITY STATUS");
        for(auto c : cities) {
            std::cout << "\n[City] " << c->getName() << " (" << c->getDistrict() << ")\n";
            c->sendAlert();
        }
        std::cout << "\nPress Enter...";
        std::cin.ignore();
        std::cin.get();
    }
};

#endif