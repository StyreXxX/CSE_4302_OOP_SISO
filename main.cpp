#include <iostream>
#include "earthquakes_today.h"
#include "past_earthquakes.h"
#include "earthquake_prediction.h"
#include "building_mapping.h"

int main() {
    while (true) {
        std::cout << "\n======================================\n";
        std::cout << "   GLOBAL EARTHQUAKE MONITORING API   \n";
        std::cout << "======================================\n";
        std::cout << "1. Earthquakes Today\n";
        std::cout << "2. Past Earthquakes\n";
        std::cout << "3. Earthquake Prediction\n";
        std::cout << "4. Building Mapping\n";
        std::cout << "5. Exit System\n";
        std::cout << "Select a module: ";

        int choice;
        std::cin >> choice;

        if (std::cin.fail()) { //Error Handling
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 1) { //Rayhan
            EarthquakesToday todayModule;
            todayModule.run(); 
        } else if (choice == 2) { //Hishu
            PastEarthquakes pastModule;
            pastModule.run();  
        } else if (choice == 3) { //Niloy
            EarthquakePrediction predModule;
            predModule.run();  
        } else if (choice == 4) { //Rayed
            BuildingMapping mapModule;
            mapModule.run();  
        } else if (choice == 5) {
            std::cout << "Shutting down system. Stay safe!\n";
            break;
        } else {
            std::cout << "Invalid choice. Please select between 1 and 5.\n";
        }
    }

    return 0;
}