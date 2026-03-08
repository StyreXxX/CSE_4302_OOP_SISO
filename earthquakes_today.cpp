#include "earthquakes_today.h"

EarthquakesToday::EarthquakesToday() {
    loadDummyData();
}

void EarthquakesToday::loadDummyData() {
    dataset = {
        // --- JAPAN ---
        {"Japan", "2026-03-11T02:15:00", 6.8, 30.0, "Offshore Miyagi", 1500000, 4, {"tsunami_risk", "infrastructure_down"}},
        {"Japan", "2026-03-11T05:40:22", 4.2, 15.5, "10km E of Tokyo", 5000, 0, {"minor_tremor"}},
        {"Japan", "2026-03-11T11:05:10", 7.4, 25.0, "Hokkaido Region", 8500000, 22, {"buildings_damaged", "power_outage", "tsunami_risk"}},
        {"Japan", "2026-03-11T16:30:05", 3.1, 10.0, "Kyoto", 0, 0, {"minor_tremor"}},
        {"Japan", "2026-03-11T21:45:50", 5.5, 40.2, "Fukushima Coast", 45000, 0, {"infrastructure_down", "power_outage"}},

        // --- USA ---
        {"USA", "2026-03-11T01:10:15", 3.5, 8.0, "San Francisco, CA", 2000, 0, {"minor_tremor"}},
        {"USA", "2026-03-11T06:22:40", 6.1, 12.5, "Los Angeles, CA", 2000000, 3, {"buildings_damaged", "power_outage"}},
        {"USA", "2026-03-11T09:45:00", 4.8, 20.0, "Anchorage, AK", 15000, 0, {"infrastructure_down"}},
        {"USA", "2026-03-11T14:15:30", 2.2, 5.0, "Yellowstone, WY", 0, 0, {"minor_tremor"}},
        {"USA", "2026-03-11T19:50:55", 7.0, 25.4, "Seattle, WA", 5500000, 12, {"buildings_damaged", "infrastructure_down", "tsunami_risk"}},

        // --- CHILE ---
        {"Chile", "2026-03-11T03:05:12", 8.1, 35.0, "Offshore Valparaiso", 12000000, 45, {"tsunami_risk", "buildings_damaged", "infrastructure_down"}},
        {"Chile", "2026-03-11T07:30:45", 5.2, 20.0, "Santiago", 50000, 0, {"power_outage"}},
        {"Chile", "2026-03-11T12:15:20", 4.5, 18.5, "Antofagasta", 10000, 0, {"minor_tremor"}},
        {"Chile", "2026-03-11T17:40:10", 6.7, 40.0, "Concepcion", 800000, 5, {"buildings_damaged", "power_outage"}},
        {"Chile", "2026-03-11T22:55:05", 3.8, 15.0, "Iquique", 1000, 0, {"minor_tremor"}},

        // --- INDONESIA ---
        {"Indonesia", "2026-03-11T00:45:30", 7.5, 20.0, "Offshore Sumatra", 9000000, 50, {"tsunami_risk", "buildings_damaged"}},
        {"Indonesia", "2026-03-11T04:20:15", 5.8, 15.0, "Jakarta", 400000, 2, {"infrastructure_down", "power_outage"}},
        {"Indonesia", "2026-03-11T08:10:50", 4.1, 10.0, "Bali", 5000, 0, {"minor_tremor"}},
        {"Indonesia", "2026-03-11T13:35:40", 6.4, 25.5, "Sulawesi", 1200000, 8, {"buildings_damaged", "tsunami_risk"}},
        {"Indonesia", "2026-03-11T18:50:25", 3.3, 12.0, "Lombok", 0, 0, {"minor_tremor"}},

        // --- MEXICO ---
        {"Mexico", "2026-03-11T02:30:10", 7.1, 50.0, "Mexico City", 15000000, 80, {"buildings_damaged", "infrastructure_down", "power_outage"}},
        {"Mexico", "2026-03-11T06:15:45", 4.6, 20.0, "Oaxaca", 25000, 0, {"power_outage"}},
        {"Mexico", "2026-03-11T10:40:20", 3.9, 15.0, "Acapulco", 2000, 0, {"minor_tremor"}},
        {"Mexico", "2026-03-11T15:05:55", 6.2, 35.5, "Chiapas", 600000, 4, {"buildings_damaged", "tsunami_risk"}},
        {"Mexico", "2026-03-11T20:20:30", 2.8, 10.0, "Monterrey", 0, 0, {"minor_tremor"}},

        // --- ITALY ---
        {"Italy", "2026-03-11T01:50:40", 6.0, 10.0, "Amatrice", 3000000, 15, {"buildings_damaged", "infrastructure_down"}},
        {"Italy", "2026-03-11T05:35:15", 3.4, 8.0, "Rome", 5000, 0, {"minor_tremor"}},
        {"Italy", "2026-03-11T11:20:50", 4.9, 15.0, "Milan", 80000, 0, {"power_outage"}},
        {"Italy", "2026-03-11T16:45:25", 5.5, 12.5, "Naples", 450000, 2, {"buildings_damaged", "power_outage"}},
        {"Italy", "2026-03-11T21:10:00", 2.5, 5.0, "Florence", 0, 0, {"minor_tremor"}},

        // --- NEW ZEALAND ---
        {"New Zealand", "2026-03-11T03:25:10", 7.2, 22.0, "Wellington", 4000000, 10, {"buildings_damaged", "infrastructure_down"}},
        {"New Zealand", "2026-03-11T08:50:45", 4.3, 15.0, "Christchurch", 15000, 0, {"minor_tremor"}},
        {"New Zealand", "2026-03-11T13:15:20", 6.5, 30.0, "Offshore Auckland", 800000, 1, {"tsunami_risk", "power_outage"}},
        {"New Zealand", "2026-03-11T18:40:55", 3.7, 12.0, "Queenstown", 5000, 0, {"minor_tremor"}},
        {"New Zealand", "2026-03-11T23:05:30", 5.8, 18.5, "Napier", 250000, 0, {"infrastructure_down"}},

        // --- TURKEY ---
        {"Turkey", "2026-03-11T00:15:20", 7.6, 15.0, "Gaziantep", 20000000, 150, {"buildings_damaged", "infrastructure_down", "power_outage"}},
        {"Turkey", "2026-03-11T04:40:55", 5.1, 10.0, "Istanbul", 150000, 1, {"power_outage"}},
        {"Turkey", "2026-03-11T09:05:30", 3.6, 8.0, "Izmir", 8000, 0, {"minor_tremor"}},
        {"Turkey", "2026-03-11T14:30:05", 6.3, 20.0, "Antalya", 900000, 5, {"buildings_damaged", "tsunami_risk"}},
        {"Turkey", "2026-03-11T19:55:40", 2.9, 5.0, "Ankara", 0, 0, {"minor_tremor"}},

        // --- PHILIPPINES ---
        {"Philippines", "2026-03-11T02:05:50", 7.3, 25.0, "Mindanao", 5000000, 30, {"buildings_damaged", "tsunami_risk"}},
        {"Philippines", "2026-03-11T06:30:25", 4.7, 15.0, "Manila", 40000, 0, {"power_outage"}},
        {"Philippines", "2026-03-11T11:55:00", 3.8, 12.0, "Cebu", 5000, 0, {"minor_tremor"}},
        {"Philippines", "2026-03-11T17:20:35", 6.6, 30.5, "Luzon", 1500000, 12, {"infrastructure_down", "power_outage"}},
        {"Philippines", "2026-03-11T22:45:10", 2.4, 8.0, "Davao", 0, 0, {"minor_tremor"}},

        // --- PERU ---
        {"Peru", "2026-03-11T01:35:05", 7.0, 40.0, "Lima", 6000000, 25, {"buildings_damaged", "power_outage"}},
        {"Peru", "2026-03-11T06:00:40", 4.4, 20.0, "Cusco", 12000, 0, {"minor_tremor"}},
        {"Peru", "2026-03-11T10:25:15", 5.9, 35.0, "Arequipa", 300000, 2, {"infrastructure_down"}},
        {"Peru", "2026-03-11T15:50:50", 3.2, 15.0, "Trujillo", 1000, 0, {"minor_tremor"}},
        {"Peru", "2026-03-11T21:15:25", 6.8, 28.5, "Offshore Callao", 2000000, 8, {"tsunami_risk", "buildings_damaged"}}
    };

    // Dynamically extract unique countries so the menu populates automatically
    for (const auto& eq : dataset) {
        bool exists = false;
        for (const auto& c : availableCountries) {
            if (c == eq.country) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            availableCountries.push_back(eq.country);
        }
    }
}

void EarthquakesToday::displayCountries() const {
    std::cout << "\n--- Available Countries Today ---\n";
    for (size_t i = 0; i < availableCountries.size(); ++i) {
        std::cout << i + 1 << ". " << availableCountries[i] << "\n";
    }
}

std::vector<EarthquakeRecord> EarthquakesToday::getEarthquakesByCountry(const std::string& country) const {
    std::vector<EarthquakeRecord> filtered;
    for (const auto& eq : dataset) {
        if (eq.country == country) {
            filtered.push_back(eq);
        }
    }
    return filtered;
}

void EarthquakesToday::displayEarthquakeDetails(const EarthquakeRecord& eq) const {
    std::cout << "\n=== Earthquake Details ===\n";
    std::cout << "Location: " << eq.place << "\n";
    std::cout << "Time: " << eq.time << "\n";
    std::cout << "Magnitude: " << eq.magnitude << "\n";
    std::cout << "Depth: " << eq.depth << " km\n";
    std::cout << "Estimated Damages: $" << eq.damages << "\n";
    std::cout << "Missing Persons: " << eq.missingPersons << "\n";
}

void EarthquakesToday::displayDisasterManagement(const std::vector<std::string>& keywords) const {
    std::cout << "\n+++ Post-Disaster Management Advice +++\n";
    if (keywords.empty()) {
        std::cout << "No specific hazard warnings at this time. Stay alert.\n";
        return;
    }

    for (const auto& kw : keywords) {
        if (kw == "buildings_damaged") {
            std::cout << "- DO NOT re-enter damaged buildings. Aftershocks may cause collapse.\n";
        } else if (kw == "tsunami_risk") {
            std::cout << "- TSUNAMI WARNING: Move to higher ground immediately. Do not wait for official sirens.\n";
        } else if (kw == "power_outage") {
            std::cout << "- Power grids affected. Use flashlights, avoid candles to prevent gas fires.\n";
        } else if (kw == "infrastructure_down") {
            std::cout << "- Roads and bridges may be compromised. Avoid driving unless absolutely necessary.\n";
        } else if (kw == "minor_tremor") {
            std::cout << "- Minor tremor detected. Check for gas leaks and secure loose heavy furniture.\n";
        }
    }
    std::cout << "+++++++++++++++++++++++++++++++++++++++\n";
}