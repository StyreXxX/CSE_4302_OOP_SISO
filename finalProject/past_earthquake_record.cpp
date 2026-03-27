#include "past_earthquake_record.h"
#include "past_earthquake_exceptions.h"
using namespace std;

PastEarthquakeRecord::PastEarthquakeRecord() {
    date = "";
    country = "";
    location = "";
    magnitude = 0.0;
    depth = 0.0;
    latitude = 0.0;
    longitude = 0.0;
}

PastEarthquakeRecord::PastEarthquakeRecord(string date, string country, string location, double magnitude, double depth, double latitude, double longitude) {
    this->date = date;
    this->country = country;
    this->location = location;
    this->magnitude = magnitude;
    this->depth = depth;
    this->latitude = latitude;
    this->longitude = longitude;
}

string PastEarthquakeRecord::getDate() const {
    return date;
}

string PastEarthquakeRecord::getCountry() const {
    return country;
}

string PastEarthquakeRecord::getLocation() const {
    return location;
}

double PastEarthquakeRecord::getMagnitude() const {
    return magnitude;
}

double PastEarthquakeRecord::getDepth() const {
    return depth;
}

double PastEarthquakeRecord::getLatitude() const {
    return latitude;
}

double PastEarthquakeRecord::getLongitude() const {
    return longitude;
}

bool PastEarthquakeRecord::operator>(const PastEarthquakeRecord& other) const {
    return magnitude > other.magnitude;
}

bool PastEarthquakeRecord::operator<(const PastEarthquakeRecord& other) const {
    return magnitude < other.magnitude;
}

bool PastEarthquakeRecord::operator==(const PastEarthquakeRecord& other) const {
    return date == other.date && country == other.country && location == other.location;
}

ostream& operator<<(ostream& out, const PastEarthquakeRecord& record) {
    out << "Date      : " << record.date << "\n";
    out << "Country   : " << record.country << "\n";
    out << "Location  : " << record.location << "\n";
    out << "Magnitude : " << record.magnitude << "\n";
    out << "Depth     : " << record.depth << " km\n";
    out << "Latitude  : " << record.latitude << "\n";
    out << "Longitude : " << record.longitude << "\n";
    return out;
}

PastEarthquakeRecord PastEarthquakeRecord::fromString(const string& line) {
    stringstream ss(line);
    string token;
    vector<string> parts;

    while (getline(ss, token, '|')) {
        parts.push_back(token);
    }

    if (parts.size() != 7) {
        throw InvalidRecordFormatException(line);
    }

    try {
        string date = parts[0];
        string country = parts[1];
        string location = parts[2];
        double magnitude = stod(parts[3]);
        double depth = stod(parts[4]);
        double latitude = stod(parts[5]);
        double longitude = stod(parts[6]);

        return PastEarthquakeRecord(date, country, location, magnitude, depth, latitude, longitude);
    }
    catch (...) {
        throw InvalidRecordFormatException(line);
    }
}