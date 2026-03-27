#include <bits/stdc++.h>
#include "BuildingDatabase.h"
#include "CountryRisks.h"

using namespace std;

void clearScreen() {
    system("cls");
}

void pauseScreen() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void printLine(int n = 55) {
    cout << string(n, '=') << "\n";
}

void printTitle(const string& title) {
    printLine();
    cout << title << "\n";
    printLine();
}

string getRiskLevel(double score) {
    if (score <= 2.5) return "Very Safe";
    if (score <= 4.5) return "Low Risk";
    if (score <= 6.5) return "Moderate Risk";
    if (score <= 8.0) return "High Risk";
    return "Very Dangerous";
}

string getRecommendation(double score) {
    if (score <= 2.5) return "Building appears structurally safer under current factors.";
    if (score <= 4.5) return "Regular inspection and minor strengthening are recommended.";
    if (score <= 6.5) return "Detailed engineering assessment and selective retrofitting advised.";
    if (score <= 8.0) return "High priority retrofitting is recommended.";
    return "Immediate structural review and urgent retrofitting required.";
}

void showCountryMenu() {
    printTitle("SELECT COUNTRY MODEL");
    cout << "1. Bangladesh\n";
    cout << "2. Japan\n";
    cout << "3. USA\n";
    cout << "4. Turkey\n";
    cout << "5. Nepal\n";
    cout << "6. India\n";
    cout << "7. Indonesia\n";
    cout << "8. Mexico\n";
    cout << "9. Chile\n";
    cout << "10. Italy\n";
    printLine();
}

void showRiskReport(Building* b, RiskModel* model, double score) {
    printTitle("BUILDING RISK REPORT");
    cout << "Building Name : " << b->getName() << "\n";
    cout << "Country       : " << b->getCountry() << "\n";
    cout << "City          : " << b->getCity() << "\n";
    cout << "Country Model : " << model->getCountryName() << "\n";
    cout << "Risk Score    : " << fixed << setprecision(2) << score << "/10\n";
    cout << "Risk Level    : " << getRiskLevel(score) << "\n";
    cout << "Recommendation: " << getRecommendation(score) << "\n";
    printLine();
}

void buildingModule(BuildingDatabase& db) {
    clearScreen();
    showCountryMenu();

    int countryChoice;
    cout << "Enter choice: ";
    cin >> countryChoice;

    RiskModel* model = createCountryModel(countryChoice);

    if (model == nullptr) {
        cout << "Invalid country choice.\n";
        pauseScreen();
        return;
    }

    int subChoice;
    while (true) {
        clearScreen();
        printTitle("BUILDING MAPPING & RISK ASSESSMENT");
        cout << "Current Country Model: " << model->getCountryName() << "\n";
        printLine();

        cout << "1. Show Building Code Rules\n";
        cout << "2. Show Buildings for This Country\n";
        cout << "3. Assess a Building by ID\n";
        cout << "4. Compare Two Buildings\n";
        cout << "5. Change Country Model\n";
        cout << "6. Back to Main Menu\n";
        printLine();

        cout << "Enter choice: ";
        cin >> subChoice;

        if (subChoice == 1) {
            clearScreen();
            printTitle("BUILDING CODE RULES");
            model->showRules();
            pauseScreen();
        }
        else if (subChoice == 2) {
            clearScreen();
            printTitle("BUILDINGS FOR SELECTED COUNTRY");
            cout << "Country Model: " << model->getCountryName() << "\n\n";
            db.showByCountry(model->getCountryName());
            pauseScreen();
        }
        else if (subChoice == 3) {
            clearScreen();
            printTitle("ASSESS BUILDING BY ID");

            int id;
            cout << "Enter building ID: ";
            cin >> id;

            Building* b = db.findById(id);

            if (b == nullptr) {
                cout << "\nBuilding not found.\n";
            }
            else {
                double score = model->calculateRisk(*b);
                cout << "\n";
                showRiskReport(b, model, score);
            }

            pauseScreen();
        }
        else if (subChoice == 4) {
            clearScreen();
            printTitle("COMPARE TWO BUILDINGS");

            int id1, id2;
            cout << "Enter first building ID: ";
            cin >> id1;
            cout << "Enter second building ID: ";
            cin >> id2;

            Building* b1 = db.findById(id1);
            Building* b2 = db.findById(id2);

            if (b1 == nullptr || b2 == nullptr) {
                cout << "\nOne or both building IDs are invalid.\n";
            }
            else {
                double s1 = model->calculateRisk(*b1);
                double s2 = model->calculateRisk(*b2);

                cout << "\n";
                showRiskReport(b1, model, s1);
                cout << "\n";
                showRiskReport(b2, model, s2);

                if (s1 > s2) {
                    cout << "More dangerous building: " << b1->getName() << "\n";
                }
                else if (s2 > s1) {
                    cout << "More dangerous building: " << b2->getName() << "\n";
                }
                else {
                    cout << "Both buildings have equal risk under this model.\n";
                }
            }

            pauseScreen();
        }
        else if (subChoice == 5) {
            delete model;
            clearScreen();
            showCountryMenu();
            cout << "Enter new choice: ";
            cin >> countryChoice;
            model = createCountryModel(countryChoice);

            if (model == nullptr) {
                cout << "Invalid country choice.\n";
                pauseScreen();
                return;
            }
        }
        else if (subChoice == 6) {
            delete model;
            return;
        }
        else {
            cout << "\nInvalid option.\n";
            pauseScreen();
        }
    }
}

int main() {
    BuildingDatabase db;
    db.loadData("buildings_dataset.txt");

    int choice;

    while (true) {
        clearScreen();
        printTitle("EARTHQUAKE MANAGEMENT SYSTEM");

        cout << "1. Past Earthquakes\n";
        cout << "2. Today's Earthquake\n";
        cout << "3. Earthquake Prediction (P-wave / S-wave)\n";
        cout << "4. Building Mapping & Risk Assessment\n";
        cout << "5. Exit\n";
        printLine();

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            clearScreen();
            printTitle("PAST EARTHQUAKES");
            cout << "This module will be handled by another teammate.\n";
            pauseScreen();
        }
        else if (choice == 2) {
            clearScreen();
            printTitle("TODAY'S EARTHQUAKES");
            cout << "This module will be handled by another teammate.\n";
            pauseScreen();
        }
        else if (choice == 3) {
            clearScreen();
            printTitle("EARTHQUAKE PREDICTION");
            cout << "This module will be handled by another teammate.\n";
            pauseScreen();
        }
        else if (choice == 4) {
            buildingModule(db);
        }
        else if (choice == 5) {
            clearScreen();
            printTitle("EXIT");
            cout << "Exiting program.\n";
            break;
        }
        else {
            cout << "\nInvalid choice.\n";
            pauseScreen();
        }
    }

    return 0;
}