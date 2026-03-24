#include "past_earthquakes.h"
#include "past_earthquake_exceptions.h"
using namespace std;

PastEarthquakes::PastEarthquakes() : filename("past_earthquakes.txt") {}

void PastEarthquakes::saveSampleDataIfFileMissing() {
    ifstream fin(filename.c_str());
    if (fin.is_open()) {
        fin.close();
        return;
    }

    ofstream fout(filename.c_str());
    if (!fout.is_open()) {
        throw FileOpenException(filename);
    }

    fout << "2024-01-01|Dhaka, Bangladesh|5.6|12.5|23.8103|90.4125\n";
    fout << "2023-11-12|Chittagong, Bangladesh|6.1|18.0|22.3569|91.7832\n";
    fout << "2022-09-05|Sylhet, Bangladesh|5.8|10.2|24.8949|91.8687\n";
    fout << "2021-07-19|Kathmandu, Nepal|6.9|20.4|27.7172|85.3240\n";
    fout << "2020-03-14|Sikkim, India|5.4|14.8|27.5330|88.5122\n";
    fout << "2019-10-21|Cox's Bazar, Bangladesh|5.9|16.3|21.4272|92.0058\n";
    fout << "2018-05-08|Mymensingh, Bangladesh|4.9|8.5|24.7471|90.4203\n";
    fout << "2017-12-30|Rajshahi, Bangladesh|5.2|11.0|24.3745|88.6042\n";

    fout.close();
}

void PastEarthquakes::loadFromFile() {
    records.clear();

    ifstream fin(filename.c_str());
    if (!fin.is_open()) {
        throw FileOpenException(filename);
    }

    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        PastEarthquakeRecord record = PastEarthquakeRecord::fromString(line);
        records.push_back(record);
    }

    fin.close();

    if (records.empty()) {
        throw RecordNotFoundException("No past earthquake records found in file.");
    }
}

void PastEarthquakes::displayAllRecords() const {
    cout << "\n========== PAST EARTHQUAKE RECORDS ==========\n";
    for (size_t i = 0; i < records.size(); ++i) {
        cout << "\nRecord #" << i + 1 << "\n";
        cout << records[i];
        cout << "--------------------------------------------\n";
    }
}

void PastEarthquakes::searchByLocation() const {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string keyword;
    cout << "Enter location keyword: ";
    getline(cin, keyword);

    bool found = false;
    cout << "\n========= SEARCH RESULT =========\n";

    for (size_t i = 0; i < records.size(); ++i) {
        if (records[i].getLocation().find(keyword) != string::npos) {
            cout << "\nRecord #" << i + 1 << "\n";
            cout << records[i];
            cout << "---------------------------------\n";
            found = true;
        }
    }

    if (!found) {
        throw RecordNotFoundException("No earthquake found for location keyword: " + keyword);
    }
}

void PastEarthquakes::showStrongestEarthquake() const {
    if (records.empty()) {
        throw RecordNotFoundException("No records available to compare.");
    }

    PastEarthquakeRecord strongest = records[0];

    for (size_t i = 1; i < records.size(); ++i) {
        if (records[i] > strongest) {
            strongest = records[i];
        }
    }

    cout << "\n====== STRONGEST PAST EARTHQUAKE ======\n";
    cout << strongest;
    cout << "=======================================\n";
}

void PastEarthquakes::run() {
    while (true) {
        cout << "\n=====================================\n";
        cout << "       PAST EARTHQUAKES MODULE       \n";
        cout << "=====================================\n";
        cout << "1. Load Past Earthquake Records\n";
        cout << "2. Show All Past Earthquakes\n";
        cout << "3. Search Past Earthquake by Location\n";
        cout << "4. Show Strongest Earthquake\n";
        cout << "5. Return to Main Menu\n";
        cout << "Enter choice: ";

        try {
            int choice = getValidatedInput<int>(1, 5);

            if (choice == 1) {
                saveSampleDataIfFileMissing();
                loadFromFile();
                cout << "\nPast earthquake records loaded successfully from file.\n";
            }
            else if (choice == 2) {
                if (records.empty()) {
                    loadFromFile();
                }
                displayAllRecords();
            }
            else if (choice == 3) {
                if (records.empty()) {
                    loadFromFile();
                }
                searchByLocation();
            }
            else if (choice == 4) {
                if (records.empty()) {
                    loadFromFile();
                }
                showStrongestEarthquake();
            }
            else if (choice == 5) {
                cout << "Returning to main menu...\n";
                break;
            }
        }
        catch (const FileOpenException& e) {
            cout << "\n[FILE ERROR] " << e.what() << "\n";
        }
        catch (const InvalidRecordFormatException& e) {
            cout << "\n[FORMAT ERROR] " << e.what() << "\n";
        }
        catch (const InvalidInputException& e) {
            cout << "\n[INPUT ERROR] " << e.what() << "\n";
        }
        catch (const RecordNotFoundException& e) {
            cout << "\n[NOT FOUND] " << e.what() << "\n";
        }
        catch (const exception& e) {
            cout << "\n[GENERAL ERROR] " << e.what() << "\n";
        }
    }
}