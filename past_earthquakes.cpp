#include "past_earthquakes.h"
#include "past_earthquake_exceptions.h"
using namespace std;

PastEarthquakes::PastEarthquakes() {
    filename = "past_earthquakes.txt";
}

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

    fout << "2024-01-11|Bangladesh|Dhaka|5.6|12.5|23.81|90.41\n";
    fout << "2023-11-22|Bangladesh|Chattogram|6.1|18.0|22.36|91.78\n";
    fout << "2022-09-05|Bangladesh|Sylhet|5.8|10.2|24.89|91.87\n";
    fout << "2021-07-30|Bangladesh|Rajshahi|5.2|11.4|24.37|88.60\n";
    fout << "2020-06-18|Bangladesh|Khulna|5.4|13.0|22.82|89.55\n";
    fout << "2024-02-09|Japan|Tokyo|6.7|32.0|35.68|139.69\n";
    fout << "2023-08-14|Japan|Osaka|5.9|24.2|34.69|135.50\n";
    fout << "2022-04-28|Japan|Kyoto|5.5|16.8|35.01|135.76\n";
    fout << "2021-03-16|Japan|Sendai|6.8|41.5|38.27|140.87\n";
    fout << "2020-12-05|Japan|Yokohama|5.7|21.0|35.44|139.64\n";
    fout << "2024-01-20|USA|NewYork|4.9|9.5|40.71|-74.00\n";
    fout << "2023-09-18|USA|LosAngeles|6.2|14.8|34.05|-118.24\n";
    fout << "2022-10-07|USA|Chicago|4.8|11.6|41.88|-87.63\n";
    fout << "2021-05-29|USA|SanFrancisco|6.5|17.4|37.77|-122.42\n";
    fout << "2020-08-12|USA|Seattle|5.3|13.7|47.61|-122.33\n";
    fout << "2024-03-03|Turkey|Istanbul|6.6|19.1|41.01|28.97\n";
    fout << "2023-02-26|Turkey|Ankara|5.4|12.3|39.93|32.85\n";
    fout << "2022-11-09|Turkey|Izmir|6.1|16.7|38.42|27.14\n";
    fout << "2021-06-17|Turkey|Bursa|5.2|10.5|40.19|29.06\n";
    fout << "2020-04-01|Turkey|Antalya|5.0|8.9|36.90|30.70\n";
    fout << "2024-02-17|Nepal|Kathmandu|6.4|18.6|27.71|85.32\n";
    fout << "2023-10-08|Nepal|Pokhara|5.5|11.2|28.21|83.99\n";
    fout << "2022-07-21|Nepal|Lalitpur|5.7|12.8|27.66|85.32\n";
    fout << "2021-03-11|Nepal|Bhaktapur|5.3|9.4|27.67|85.43\n";
    fout << "2020-01-15|Nepal|Biratnagar|5.1|10.1|26.45|87.27\n";
    fout << "2024-01-29|India|Mumbai|5.8|14.0|19.07|72.88\n";
    fout << "2023-06-25|India|Delhi|5.6|13.5|28.61|77.21\n";
    fout << "2022-09-14|India|Kolkata|5.9|17.1|22.57|88.36\n";
    fout << "2021-08-03|India|Chennai|5.4|12.2|13.08|80.27\n";
    fout << "2020-05-22|India|Guwahati|6.2|20.8|26.14|91.74\n";
    fout << "2024-02-06|Indonesia|Jakarta|6.3|21.4|-6.20|106.85\n";
    fout << "2023-09-09|Indonesia|Bandung|5.6|13.9|-6.91|107.61\n";
    fout << "2022-05-18|Indonesia|Surabaya|5.5|12.7|-7.26|112.75\n";
    fout << "2021-04-07|Indonesia|Yogyakarta|5.8|16.2|-7.80|110.37\n";
    fout << "2020-10-30|Indonesia|Medan|5.4|11.8|3.59|98.67\n";
    fout << "2024-03-12|Mexico|MexicoCity|6.9|25.0|19.43|-99.13\n";
    fout << "2023-07-02|Mexico|Monterrey|5.3|10.6|25.69|-100.32\n";
    fout << "2022-11-26|Mexico|Puebla|5.7|14.3|19.04|-98.21\n";
    fout << "2021-09-15|Mexico|Guadalajara|5.5|12.9|20.67|-103.35\n";
    fout << "2020-06-04|Mexico|Oaxaca|6.4|22.5|17.07|-96.72\n";
    fout << "2024-01-08|Chile|Santiago|6.6|19.3|-33.45|-70.66\n";
    fout << "2023-08-20|Chile|Valparaiso|6.1|18.1|-33.05|-71.62\n";
    fout << "2022-04-13|Chile|Concepcion|6.3|21.7|-36.83|-73.05\n";
    fout << "2021-10-24|Chile|LaSerena|5.6|13.8|-29.90|-71.25\n";
    fout << "2020-02-19|Chile|Valdivia|5.9|15.4|-39.81|-73.25\n";
    fout << "2024-02-25|Italy|Rome|5.4|11.1|41.90|12.50\n";
    fout << "2023-07-19|Italy|Milan|4.9|8.7|45.46|9.19\n";
    fout << "2022-03-06|Italy|Venice|4.7|7.9|45.44|12.33\n";
    fout << "2021-11-01|Italy|Naples|5.8|14.6|40.85|14.27\n";
    fout << "2020-09-27|Italy|Turin|4.8|9.2|45.07|7.69\n";

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

vector<string> PastEarthquakes::getUniqueCountries() const {
    set<string> st;
    for (int i = 0; i < records.size(); i++) {
        st.insert(records[i].getCountry());
    }

    vector<string> countries;
    for (auto country : st) {
        countries.push_back(country);
    }
    return countries;
}

void PastEarthquakes::displayCountries() const {
    vector<string> countries = getUniqueCountries();

    cout << "\n--- Available Countries in Past Records ---\n";
    for (int i = 0; i < countries.size(); i++) {
        cout << i + 1 << ". " << countries[i] << "\n";
    }
}

void PastEarthquakes::displayAllRecords() const {
    cout << "\n========== PAST EARTHQUAKE RECORDS ==========\n";
    for (int i = 0; i < records.size(); i++) {
        cout << "\nRecord #" << i + 1 << "\n";
        cout << records[i];
        cout << "--------------------------------------------\n";
    }
}

void PastEarthquakes::searchByCountry() const {
    vector<string> countries = getUniqueCountries();

    if (countries.empty()) {
        throw RecordNotFoundException("No countries found in records.");
    }

    displayCountries();
    cout << "Select a country by number: ";
    int choice = getValidatedInput<int>(1, countries.size());

    string selectedCountry = countries[choice - 1];
    bool found = false;

    cout << "\n========= EARTHQUAKES IN " << selectedCountry << " =========\n";

    for (int i = 0; i < records.size(); i++) {
        if (records[i].getCountry() == selectedCountry) {
            cout << "\nRecord #" << i + 1 << "\n";
            cout << records[i];
            cout << "---------------------------------\n";
            found = true;
        }
    }

    if (!found) {
        throw RecordNotFoundException("No earthquake found for country: " + selectedCountry);
    }
}

void PastEarthquakes::showStrongestEarthquake() const {
    if (records.empty()) {
        throw RecordNotFoundException("No records available to compare.");
    }

    PastEarthquakeRecord strongest = records[0];

    for (int i = 1; i < records.size(); i++) {
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
        cout << "3. View Countries and Select One\n";
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
                searchByCountry();
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