#include "EarthquakePrediction.h"
#include <iostream>
#include <cctype>
#include <windows.h> 

EarthquakePrediction::EarthquakePrediction() : simulator(&dashboard) {
    initializeSystem();
}

EarthquakePrediction::~EarthquakePrediction() {
    cleanup();
}

void EarthquakePrediction::initializeSystem() {
    Color::clear();
    Color::printHeader("INITIALIZING BEEWS");

    for (int p = 25; p <= 100; p += 25) {
        Color::printProgress(p);
        std::cout << "\n";
        Sleep(500); 
    }

    loadCities();
    loadEarthquakes();

    Color::printSuccess("20 Cities Loaded");
    Color::printSuccess("20 Earthquakes Ready");
    Sleep(2000); 
}

void EarthquakePrediction::loadCities() {
    cities = {
        new City("Dhaka", 23.8103, 90.4125, 21000000, "Dhaka"),
        new City("Chittagong", 22.3569, 91.7832, 8500000, "Chittagong"),
        new City("Sylhet", 24.8949, 91.8687, 5000000, "Sylhet"),
        new City("Khulna", 22.8456, 89.5403, 2800000, "Khulna"),
        new City("Rajshahi", 24.3636, 88.6241, 1800000, "Rajshahi"),
        new City("Barisal", 22.7010, 90.3535, 1200000, "Barisal"),
        new City("Comilla", 23.4603, 91.1803, 1700000, "Comilla"),
        new City("Rangpur", 25.7439, 89.2752, 1000000, "Rangpur"),
        new City("Mymensingh", 24.7471, 90.4203, 1400000, "Mymensingh"),
        new City("Narayanganj", 23.6333, 90.5000, 1500000, "Narayanganj"),
        new City("Gazipur", 23.9900, 90.4200, 1800000, "Gazipur"),
        new City("Jessore", 23.1667, 89.2167, 800000, "Jessore"),
        new City("Bogra", 24.8500, 89.3667, 700000, "Bogra"),
        new City("Pabna", 24.0000, 89.2500, 600000, "Pabna"),
        new City("Cox's Bazar", 21.4272, 91.9732, 500000, "Cox's Bazar"),
        new City("Tangail", 24.2500, 89.9167, 550000, "Tangail"),
        new City("Faridpur", 23.6000, 89.8333, 450000, "Faridpur"),
        new City("Noakhali", 22.8333, 91.1000, 500000, "Noakhali"),
        new City("Brahmanbaria", 23.9667, 91.1167, 400000, "Brahmanbaria"),
        new City("Kushtia", 23.9000, 89.1333, 450000, "Kushtia")
    };

    for (auto city : cities) {
        city->addInfrastructure(
            new PowerGrid(city->getName() + " Grid",
            city->getDistrict() == "Dhaka" ? "DPDC" : "DESCO")
        );

        city->addInfrastructure(new GasSystem(city->getName() + " Gas", "Titas"));

        if (city->getDistrict() == "Dhaka") {
            city->addInfrastructure(new Transport(city->getName() + " MRT", "Metro Rail"));
        } else {
            city->addInfrastructure(new Transport(city->getName() + " Railway", "Railway"));
        }

        city->addContact("Fire: 16163");
        city->addContact("Police: 999");
        city->addContact("Ambulance: 123");

        dashboard.addCity(city);
        simulator.addCity(city);
    }
}

void EarthquakePrediction::loadEarthquakes() {
    simulator.addEarthquake(new RealEarthquake("EQ01", 23.8103, 90.4125, 15, 7.5, "Dhaka Region"));
    simulator.addEarthquake(new RealEarthquake("EQ02", 24.8949, 91.8687, 12, 7.2, "Sylhet Region"));
    simulator.addEarthquake(new RealEarthquake("EQ03", 22.3569, 91.7832, 10, 7.8, "Chittagong Region"));
    simulator.addEarthquake(new RealEarthquake("EQ04", 26.4525, 87.2718, 20, 6.8, "Nepal Border"));
    simulator.addEarthquake(new RealEarthquake("EQ05", 25.5000, 89.0000, 18, 6.5, "Rangpur Region"));
    simulator.addEarthquake(new SimEarthquake("SIM01", 23.7000, 90.3500, 12, 6.0, "Central Bangladesh"));
    simulator.addEarthquake(new SimEarthquake("SIM02", 24.5000, 89.8000, 10, 5.8, "Northern Region"));
    simulator.addEarthquake(new SimEarthquake("SIM03", 22.8000, 90.2000, 8, 5.5, "Southern Delta"));
    simulator.addEarthquake(new RealEarthquake("EQ06", 24.3636, 88.6241, 14, 6.2, "Rajshahi Region"));
    simulator.addEarthquake(new SimEarthquake("SIM04", 23.4603, 91.1803, 9, 4.8, "Comilla Region"));
    simulator.addEarthquake(new SimEarthquake("SIM05", 22.7010, 90.3535, 7, 4.5, "Barisal Region"));
    simulator.addEarthquake(new RealEarthquake("EQ07", 22.5726, 88.3639, 25, 5.3, "Kolkata Border"));
    simulator.addEarthquake(new RealEarthquake("EQ08", 21.4272, 91.9732, 8, 6.3, "Cox's Bazar"));
    simulator.addEarthquake(new SimEarthquake("SIM06", 24.7471, 90.4203, 10, 5.2, "Mymensingh"));
    simulator.addEarthquake(new RealEarthquake("EQ09", 23.9900, 90.4200, 16, 5.7, "Gazipur"));
    simulator.addEarthquake(new SimEarthquake("SIM07", 23.6333, 90.5000, 12, 5.4, "Narayanganj"));
    simulator.addEarthquake(new RealEarthquake("EQ10", 25.7439, 89.2752, 11, 5.1, "Rangpur"));
    simulator.addEarthquake(new SimEarthquake("SIM08", 23.1667, 89.2167, 9, 4.6, "Jessore"));
    simulator.addEarthquake(new RealEarthquake("EQ11", 24.8500, 89.3667, 13, 5.0, "Bogra"));
    simulator.addEarthquake(new SimEarthquake("SIM09", 24.0000, 89.2500, 8, 4.4, "Pabna"));
}

void EarthquakePrediction::run() {
    bool running = true;
    char choice;

    while (running) {
        dashboard.showMain();
        std::cout << "\n\nEnter command: ";
        std::cin >> choice;

        switch (std::toupper(choice)) {
            case 'S':
                if (!simulator.isSimulating()) {
                    simulator.showEarthquakes();
                    std::cout << "\nSelect earthquake (1-20): ";

                    int sel;
                    std::cin >> sel;

                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        Color::printError("Invalid input");
                        Sleep(1000); // 1 second pause
                        break;
                    }

                    if (sel >= 1 && sel <= 20) {
                        simulator.simulate(sel - 1);
                    } else {
                        Color::printError("Invalid selection");
                        Sleep(1000); // 1 second pause
                    }
                }
                break;

            case 'D':
                dashboard.showCityStatus();
                break;

            case 'I':
                dashboard.showInfrastructureShutdown();
                std::cout << "\nPress Enter...";
                std::cin.ignore();
                std::cin.get();
                break;

            case 'Q':
                running = false;
                Color::printSuccess("Returning to Main Menu...");
                break;

            default:
                Color::printWarning("Use S, D, I, or Q");
                Sleep(1000); // 1 second pause
        }
    }
}

void EarthquakePrediction::cleanup() {
    for (auto c : cities) {
        delete c;
    }
    cities.clear();
}