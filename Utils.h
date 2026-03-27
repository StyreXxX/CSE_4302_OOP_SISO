#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <cmath>
#include <string>
#include <thread>
#include <chrono>
#include <iomanip>
#include <vector>
#include <functional>
#include <algorithm>
#include <sstream>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Color {
public:
    static void set(int code) { }
    static void reset() { }
    static void clear() { system("cls"); }
    
    static void printHeader(const std::string& text) {
        std::cout << "\n========================================\n";
        std::cout << "  " << text << "\n";
        std::cout << "========================================\n";
    }
    
    static void printSuccess(const std::string& text) { std::cout << "[OK] " << text << "\n"; }
    static void printError(const std::string& text) { std::cout << "[ERROR] " << text << "\n"; }
    static void printWarning(const std::string& text) { std::cout << "[WARN] " << text << "\n"; }
    static void printInfo(const std::string& text) { std::cout << "[INFO] " << text << "\n"; }
    static void printAlert(const std::string& text) { std::cout << "[ALERT] " << text << "\n"; }
    
    static void printProgress(int percent, int width = 40) {
        int filled = percent * width / 100;
        std::cout << "[";
        for(int i = 0; i < width; i++) std::cout << (i < filled ? "=" : " ");
        std::cout << "] " << percent << "%";
    }
};

class DistanceCalc {
public:
    static double haversine(double lat1, double lon1, double lat2, double lon2) {
        const double R = 6371.0;
        double dLat = (lat2 - lat1) * M_PI / 180.0;
        double dLon = (lon2 - lon1) * M_PI / 180.0;
        double a = sin(dLat/2) * sin(dLat/2) + cos(lat1 * M_PI/180.0) * cos(lat2 * M_PI/180.0) * sin(dLon/2) * sin(dLon/2);
        return R * 2 * atan2(sqrt(a), sqrt(1-a));
    }
};

#endif