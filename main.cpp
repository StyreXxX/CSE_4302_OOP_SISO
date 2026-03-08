#include "earthquakes_today.h"

int main() {
    EarthquakesToday api;
    
    while (true) {
        std::cout << "\n=== EARTHQUAKE TRACKER ===\n";
        std::cout << "1. View Earthquakes Today\n";
        std::cout << "2. Exit\n";
        std::cout << "Select an option: ";

        try {
            int mainChoice = api.getValidInput<int>(1, 2);
            if (mainChoice == 2) {
                std::cout << "Stay safe! Exiting...\n";
                break;
            }

            // Show Countries
            api.displayCountries();
            std::cout << "Select a country by number: ";
            // Assuming we have 3 countries loaded in our dummy data for now
            int countryChoice = api.getValidInput<int>(1, 3); 
            
            // Re-fetch the country name based on choice (Hardcoded mapping for the example flow)
            std::vector<std::string> countries = {"Japan", "Chile", "USA"};
            std::string selectedCountry = countries[countryChoice - 1];

            // Show Earthquakes for that country
            std::vector<EarthquakeRecord> countryEQs = api.getEarthquakesByCountry(selectedCountry);
            
            if (countryEQs.empty()) {
                std::cout << "No earthquakes recorded for " << selectedCountry << " today.\n";
                continue;
            }

            std::cout << "\n--- Earthquakes in " << selectedCountry << " Today ---\n";
            for (size_t i = 0; i < countryEQs.size(); ++i) {
                std::cout << i + 1 << ". " << countryEQs[i].place 
                          << " (Mag: " << countryEQs[i].magnitude << ")\n";
            }

            std::cout << "Select an earthquake for details: ";
            int eqChoice = api.getValidInput<int>(1, countryEQs.size());
            EarthquakeRecord selectedEQ = countryEQs[eqChoice - 1];

            // Show Details
            api.displayEarthquakeDetails(selectedEQ);

            // Post-Disaster Management Option
            std::cout << "\n1. View Post-Disaster Management Plan\n";
            std::cout << "2. Return to Main Menu\n";
            std::cout << "Select an option: ";
            
            int actionChoice = api.getValidInput<int>(1, 2);
            if (actionChoice == 1) {
                api.displayDisasterManagement(selectedEQ.keywords);
            }

        } catch (const InvalidSelectionException& e) {
            std::cout << "\n[ERROR]: " << e.what() << " Let's try that again.\n";
        } catch (const std::exception& e) {
            std::cout << "\n[CRITICAL ERROR]: " << e.what() << "\n";
        }
    }

    return 0;
}