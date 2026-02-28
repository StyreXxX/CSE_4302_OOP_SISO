#include "earthquake_data.h"
#include <vector>

// 20 Randomized Earthquakes for OOP Project Testing
const std::vector<EarthquakeRecord> earthquakeDataset = {
    // Original 7 (Feb 8th)
    { "2026-02-08T14:32:51", 33.14, -116.44, 7.2, 7.5, "mw", 36, 49, 0.1, 0.2, "ci", "ci1", "2026-02-08", "13km SSW of Borrego Springs, CA", "earthquake", 0.2, 0.6, 0.1, 10, "auto", "ci", "ci" },
    { "2026-02-08T15:10:05", 35.68, 139.69, 45.0, 5.4, "mw", 120, 20, 0.5, 0.8, "us", "jp1", "2026-02-08", "25km E of Tokyo, Japan", "earthquake", 1.5, 3.2, 0.05, 55, "reviewed", "us", "us" },
    { "2026-02-08T16:05:12", -18.14, 178.43, 560.5, 4.8, "mb", 45, 88, 1.2, 0.6, "us", "fj1", "2026-02-08", "280km N of Suva, Fiji", "earthquake", 4.1, 5.5, 0.1, 12, "auto", "us", "us" },
    { "2026-02-08T16:55:01", 61.21, -149.90, 12.4, 1.8, "ml", 18, 110, 0.05, 0.3, "ak", "ak1", "2026-02-08", "5km N of Anchorage, Alaska", "earthquake", 0.4, 0.9, 0.15, 8, "reviewed", "ak", "ak" },
    { "2026-02-08T18:30:45", -33.44, -70.66, 22.0, 8.2, "mww", 210, 15, 0.8, 1.1, "guc", "ch1", "2026-02-08", "Offshore Valparaiso, Chile", "earthquake", 2.2, 1.8, 0.04, 150, "reviewed", "guc", "us" },
    { "2026-02-08T19:15:00", 37.56, -116.85, 5.0, 0.9, "md", 12, 150, 0.08, 0.15, "nn", "nv1", "2026-02-08", "20km S of Goldfield, Nevada", "earthquake", 0.3, 1.1, 0.2, 5, "auto", "nn", "nn" },
    { "2026-02-08T20:45:11", 15.12, -45.10, 10.0, 4.5, "mb", 60, 180, 2.5, 0.9, "us", "at1", "2026-02-08", "Northern Mid-Atlantic Ridge", "earthquake", 5.5, 4.0, 0.11, 22, "reviewed", "us", "us" },

    // Added 13 diverse records
    { "2026-02-01T08:12:33", 42.83, 13.25, 10.0, 6.1, "mw", 85, 30, 0.4, 0.5, "ingv", "it1", "2026-02-02", "10km N of Amatrice, Italy", "earthquake", 1.0, 2.0, 0.08, 40, "reviewed", "ingv", "ingv" },
    { "2026-02-03T22:14:05", -8.41, 115.18, 15.5, 5.8, "mww", 90, 45, 0.6, 0.7, "us", "id1", "2026-02-04", "15km S of Denpasar, Indonesia", "earthquake", 2.1, 3.5, 0.06, 60, "reviewed", "us", "us" },
    { "2026-02-05T03:45:21", 19.43, -99.13, 50.2, 7.1, "mww", 150, 25, 0.3, 0.9, "ssn", "mx1", "2026-02-05", "40km SE of Mexico City, Mexico", "earthquake", 1.8, 2.5, 0.05, 110, "reviewed", "ssn", "ssn" },
    { "2026-02-06T11:20:10", 38.89, -77.03, 5.0, 2.1, "md", 22, 100, 0.05, 0.2, "us", "dc1", "2026-02-06", "5km W of Washington, D.C.", "earthquake", 0.5, 1.0, 0.1, 15, "auto", "us", "us" },
    { "2026-02-07T09:05:44", -41.29, 174.78, 20.0, 6.5, "mw", 110, 35, 0.2, 0.6, "geonet", "nz1", "2026-02-07", "20km E of Wellington, New Zealand", "earthquake", 1.2, 1.8, 0.07, 85, "reviewed", "geonet", "geonet" },
    { "2026-02-09T01:10:00", 39.74, -104.99, 8.5, 3.2, "ml", 40, 80, 0.15, 0.4, "us", "co1", "2026-02-09", "10km S of Denver, Colorado", "earthquake", 0.8, 1.5, 0.12, 25, "reviewed", "us", "us" },
    { "2026-02-10T14:50:22", 64.14, -21.94, 5.5, 4.9, "mb", 65, 50, 0.3, 0.5, "vedur", "is1", "2026-02-10", "30km SW of Reykjavik, Iceland", "earthquake", 1.5, 2.2, 0.09, 45, "reviewed", "vedur", "vedur" },
    { "2026-02-11T18:33:11", -23.55, -46.63, 12.0, 1.2, "ml", 15, 140, 0.08, 0.1, "us", "br1", "2026-02-11", "5km N of Sao Paulo, Brazil", "earthquake", 0.4, 0.8, 0.2, 8, "auto", "us", "us" },
    { "2026-02-12T05:22:45", 35.30, 25.16, 25.0, 5.2, "mw", 75, 60, 0.5, 0.8, "noa", "gr1", "2026-02-12", "15km N of Heraklion, Greece", "earthquake", 2.0, 3.0, 0.1, 55, "reviewed", "noa", "noa" },
    { "2026-02-13T12:00:01", 37.77, -122.42, 10.2, 4.1, "mw", 55, 70, 0.1, 0.3, "nc", "nc1", "2026-02-13", "5km E of San Francisco, CA", "earthquake", 0.6, 1.2, 0.08, 30, "reviewed", "nc", "nc" },
    { "2026-02-13T16:45:30", 27.99, 86.92, 15.0, 6.8, "mww", 130, 20, 0.4, 0.6, "us", "np1", "2026-02-13", "50km NW of Mount Everest, Nepal", "earthquake", 1.8, 2.5, 0.05, 95, "reviewed", "us", "us" },
    { "2026-02-14T08:15:10", -33.87, 151.21, 8.0, 2.8, "ml", 25, 90, 0.2, 0.4, "ga", "au1", "2026-02-14", "10km W of Sydney, Australia", "earthquake", 0.9, 1.6, 0.15, 18, "auto", "ga", "ga" },
    { "2026-02-14T23:55:55", 55.75, 37.62, 18.5, 3.5, "mb", 35, 85, 0.25, 0.5, "us", "ru1", "2026-02-15", "20km S of Moscow, Russia", "earthquake", 1.1, 2.0, 0.11, 22, "reviewed", "us", "us" }
};