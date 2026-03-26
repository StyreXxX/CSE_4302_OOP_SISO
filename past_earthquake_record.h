#ifndef PAST_EARTHQUAKE_RECORD_H
#define PAST_EARTHQUAKE_RECORD_H

#include <bits/stdc++.h>
using namespace std;

class PastEarthquakeRecord {
private:
    string date;
    string country;
    string location;
    double magnitude;
    double depth;
    double latitude;
    double longitude;

public:
    PastEarthquakeRecord();
    PastEarthquakeRecord(string date, string country, string location, double magnitude, double depth, double latitude, double longitude);

    string getDate() const;
    string getCountry() const;
    string getLocation() const;
    double getMagnitude() const;
    double getDepth() const;
    double getLatitude() const;
    double getLongitude() const;

    bool operator>(const PastEarthquakeRecord& other) const;
    bool operator<(const PastEarthquakeRecord& other) const;
    bool operator==(const PastEarthquakeRecord& other) const;

    friend ostream& operator<<(ostream& out, const PastEarthquakeRecord& record);

    static PastEarthquakeRecord fromString(const string& line);
};

#endif