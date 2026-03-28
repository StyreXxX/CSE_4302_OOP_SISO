#include <iostream>
#include "earthquakes_today.h"
#include "past_earthquakes.h"
#include "EarthquakePrediction.h"
#include "BuildingMapping.h"

using namespace std;

int main() {
    while (true) {
        cout << "\n======================================\n";
        cout << "   GLOBAL EARTHQUAKE MONITORING API   \n";
        cout << "======================================\n";
        cout << "1. Earthquakes Today\n";
        cout << "2. Past Earthquakes\n";
        cout << "3. Earthquake Prediction\n";
        cout << "4. Building Mapping\n";
        cout << "5. Exit System\n";
        cout << "Select a module: ";

        int choice;
        cin >> choice;

        if (cin.fail()) { 
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number.\n";
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
            cout << "Shutting down system. Stay safe!\n";
            break;
        } else {
            cout << "Invalid choice. Please select between 1 and 5.\n";
        }
    }

    return 0;
}