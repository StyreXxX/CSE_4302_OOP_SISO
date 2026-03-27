<<<<<<< HEAD
#include "CountryRisks.h"

static double baseScore(const Building& b) {
    double score = 0.0;

    if (b.getFloors() > 12) score += 2.5;
    else if (b.getFloors() > 8) score += 2.0;
    else if (b.getFloors() > 4) score += 1.2;
    else score += 0.6;

    if (b.getMaterial() == "brick") score += 2.5;
    else if (b.getMaterial() == "concrete") score += 1.8;
    else if (b.getMaterial() == "steel") score += 0.8;
    else score += 1.5;

    if (b.getYearBuilt() < 2000) score += 2.0;
    else if (b.getYearBuilt() < 2010) score += 1.2;
    else score += 0.5;

    if (!b.isRetrofitted()) score += 1.8;

    if (b.getSoilType() == "soft") score += 2.0;
    else if (b.getSoilType() == "medium") score += 1.0;
    else if (b.getSoilType() == "rock") score += 0.3;

    return score;
}

static double clamp10(double x) {
    if (x < 0) return 0;
    if (x > 10) return 10;
    return x;
}

double BangladeshRisk::calculateRisk(const Building& b) const {
    double score = baseScore(b);
    if (b.getMaterial() == "brick") score += 0.8;
    if (b.getSoilType() == "soft") score += 0.6;
    if (b.getYearBuilt() < 2005) score += 0.5;
    return clamp10(score);
}

string BangladeshRisk::getCountryName() const {
    return "Bangladesh";
}

void BangladeshRisk::showRules() const {
    cout << "\nBuilding factors considered for Bangladesh:\n";
    cout << "1. Number of floors\n";
    cout << "2. Construction material\n";
    cout << "3. Year built\n";
    cout << "4. Retrofitting status\n";
    cout << "5. Soil type\n";
    cout << "Higher penalty is given to older brick buildings on soft soil.\n";
}

double JapanRisk::calculateRisk(const Building& b) const {
    double score = baseScore(b) - 1.4;
    if (b.isRetrofitted()) score -= 0.7;
    if (b.getMaterial() == "steel") score -= 0.6;
    return clamp10(score);
}

string JapanRisk::getCountryName() const {
    return "Japan";
}

void JapanRisk::showRules() const {
    cout << "\nBuilding factors considered for Japan:\n";
    cout << "1. Number of floors\n";
    cout << "2. Material\n";
    cout << "3. Year built\n";
    cout << "4. Retrofitting\n";
    cout << "5. Soil type\n";
    cout << "Japan model rewards retrofitting and steel-frame construction more.\n";
}

double USARisk::calculateRisk(const Building& b) const {
    double score = baseScore(b) - 0.8;
    if (b.getFloors() > 10) score += 0.4;
    if (b.getMaterial() == "steel") score -= 0.5;
    return clamp10(score);
}

string USARisk::getCountryName() const {
    return "USA";
}

void USARisk::showRules() const {
    cout << "\nBuilding factors considered for USA:\n";
    cout << "1. Height of building\n";
    cout << "2. Material type\n";
    cout << "3. Construction year\n";
    cout << "4. Retrofitting status\n";
    cout << "5. Soil condition\n";
    cout << "Mid/high-rise structures on weak soil get extra penalty.\n";
}

double TurkeyRisk::calculateRisk(const Building& b) const {
    double score = baseScore(b);
    if (b.getYearBuilt() < 2001) score += 0.9;
    if (!b.isRetrofitted()) score += 0.7;
    return clamp10(score);
}

string TurkeyRisk::getCountryName() const {
    return "Turkey";
}

void TurkeyRisk::showRules() const {
    cout << "\nBuilding factors considered for Turkey:\n";
    cout << "1. Floors\n";
    cout << "2. Material\n";
    cout << "3. Age of building\n";
    cout << "4. Retrofitting\n";
    cout << "5. Soil type\n";
    cout << "Older non-retrofitted apartment blocks are penalized more.\n";
}

double NepalRisk::calculateRisk(const Building& b) const {
    double score = baseScore(b);
    if (b.getMaterial() == "brick") score += 0.9;
    if (b.getFloors() > 8) score += 0.5;
    return clamp10(score);
}

string NepalRisk::getCountryName() const {
    return "Nepal";
}

void NepalRisk::showRules() const {
    cout << "\nBuilding factors considered for Nepal:\n";
    cout << "1. Floors\n";
    cout << "2. Material\n";
    cout << "3. Year built\n";
    cout << "4. Retrofitting\n";
    cout << "5. Soil condition\n";
    cout << "Brick and taller structures are treated as more vulnerable.\n";
}

double IndiaRisk::calculateRisk(const Building& b) const {
    double score = baseScore(b);
    if (b.getMaterial() == "brick") score += 0.5;
    if (b.getSoilType() == "soft") score += 0.4;
    return clamp10(score);
}

string IndiaRisk::getCountryName() const {
    return "India";
}

void IndiaRisk::showRules() const {
    cout << "\nBuilding factors considered for India:\n";
    cout << "1. Height\n";
    cout << "2. Material\n";
    cout << "3. Age\n";
    cout << "4. Retrofitting\n";
    cout << "5. Soil type\n";
    cout << "Soft-soil and older masonry buildings get extra penalty.\n";
}

double IndonesiaRisk::calculateRisk(const Building& b) const {
    double score = baseScore(b);
    if (b.getSoilType() == "soft") score += 0.7;
    if (b.getFloors() > 10) score += 0.5;
    return clamp10(score);
}

string IndonesiaRisk::getCountryName() const {
    return "Indonesia";
}

void IndonesiaRisk::showRules() const {
    cout << "\nBuilding factors considered for Indonesia:\n";
    cout << "1. Floors\n";
    cout << "2. Material\n";
    cout << "3. Year built\n";
    cout << "4. Retrofitting\n";
    cout << "5. Soil type\n";
    cout << "Soft soil and taller urban buildings are penalized more.\n";
}

double MexicoRisk::calculateRisk(const Building& b) const {
    double score = baseScore(b);
    if (b.getSoilType() == "soft") score += 0.9;
    if (b.getMaterial() == "concrete") score += 0.2;
    return clamp10(score);
}

string MexicoRisk::getCountryName() const {
    return "Mexico";
}

void MexicoRisk::showRules() const {
    cout << "\nBuilding factors considered for Mexico:\n";
    cout << "1. Floors\n";
    cout << "2. Material\n";
    cout << "3. Building year\n";
    cout << "4. Retrofitting\n";
    cout << "5. Soil type\n";
    cout << "Soft lake-bed or weak soil gets a higher penalty.\n";
}

double ChileRisk::calculateRisk(const Building& b) const {
    double score = baseScore(b) - 1.0;
    if (b.getMaterial() == "steel") score -= 0.5;
    if (b.isRetrofitted()) score -= 0.4;
    return clamp10(score);
}

string ChileRisk::getCountryName() const {
    return "Chile";
}

void ChileRisk::showRules() const {
    cout << "\nBuilding factors considered for Chile:\n";
    cout << "1. Floors\n";
    cout << "2. Material\n";
    cout << "3. Construction year\n";
    cout << "4. Retrofitting\n";
    cout << "5. Soil type\n";
    cout << "Modern steel and retrofitted buildings are rewarded more.\n";
}

double ItalyRisk::calculateRisk(const Building& b) const {
    double score = baseScore(b);
    if (b.getYearBuilt() < 2000) score += 0.7;
    if (b.getMaterial() == "brick") score += 0.6;
    return clamp10(score);
}

string ItalyRisk::getCountryName() const {
    return "Italy";
}

void ItalyRisk::showRules() const {
    cout << "\nBuilding factors considered for Italy:\n";
    cout << "1. Floors\n";
    cout << "2. Material\n";
    cout << "3. Year built\n";
    cout << "4. Retrofitting\n";
    cout << "5. Soil type\n";
    cout << "Older masonry buildings get higher risk.\n";
}

RiskModel* createCountryModel(int choice) {
    switch (choice) {
        case 1: return new BangladeshRisk();
        case 2: return new JapanRisk();
        case 3: return new USARisk();
        case 4: return new TurkeyRisk();
        case 5: return new NepalRisk();
        case 6: return new IndiaRisk();
        case 7: return new IndonesiaRisk();
        case 8: return new MexicoRisk();
        case 9: return new ChileRisk();
        case 10: return new ItalyRisk();
        default: return nullptr;
    }
=======
#include "CountryRisks.h"

static double baseScore(const Building& b) {
    double score = 0.0;

    if (b.getFloors() > 12) score += 2.5;
    else if (b.getFloors() > 8) score += 2.0;
    else if (b.getFloors() > 4) score += 1.2;
    else score += 0.6;

    if (b.getMaterial() == "brick") score += 2.5;
    else if (b.getMaterial() == "concrete") score += 1.8;
    else if (b.getMaterial() == "steel") score += 0.8;
    else score += 1.5;

    if (b.getYearBuilt() < 2000) score += 2.0;
    else if (b.getYearBuilt() < 2010) score += 1.2;
    else score += 0.5;

    if (!b.isRetrofitted()) score += 1.8;

    if (b.getSoilType() == "soft") score += 2.0;
    else if (b.getSoilType() == "medium") score += 1.0;
    else if (b.getSoilType() == "rock") score += 0.3;

    return score;
}

static double clamp10(double x) {
    if (x < 0) return 0;
    if (x > 10) return 10;
    return x;
}

double BangladeshRisk::calculateRisk(const Building& b) const {
    double score = baseScore(b);
    if (b.getMaterial() == "brick") score += 0.8;
    if (b.getSoilType() == "soft") score += 0.6;
    if (b.getYearBuilt() < 2005) score += 0.5;
    return clamp10(score);
}

string BangladeshRisk::getCountryName() const {
    return "Bangladesh";
}

void BangladeshRisk::showRules() const {
    cout << "\nBuilding factors considered for Bangladesh:\n";
    cout << "1. Number of floors\n";
    cout << "2. Construction material\n";
    cout << "3. Year built\n";
    cout << "4. Retrofitting status\n";
    cout << "5. Soil type\n";
    cout << "Higher penalty is given to older brick buildings on soft soil.\n";
}

double JapanRisk::calculateRisk(const Building& b) const {
    double score = baseScore(b) - 1.4;
    if (b.isRetrofitted()) score -= 0.7;
    if (b.getMaterial() == "steel") score -= 0.6;
    return clamp10(score);
}

string JapanRisk::getCountryName() const {
    return "Japan";
}

void JapanRisk::showRules() const {
    cout << "\nBuilding factors considered for Japan:\n";
    cout << "1. Number of floors\n";
    cout << "2. Material\n";
    cout << "3. Year built\n";
    cout << "4. Retrofitting\n";
    cout << "5. Soil type\n";
    cout << "Japan model rewards retrofitting and steel-frame construction more.\n";
}

double USARisk::calculateRisk(const Building& b) const {
    double score = baseScore(b) - 0.8;
    if (b.getFloors() > 10) score += 0.4;
    if (b.getMaterial() == "steel") score -= 0.5;
    return clamp10(score);
}

string USARisk::getCountryName() const {
    return "USA";
}

void USARisk::showRules() const {
    cout << "\nBuilding factors considered for USA:\n";
    cout << "1. Height of building\n";
    cout << "2. Material type\n";
    cout << "3. Construction year\n";
    cout << "4. Retrofitting status\n";
    cout << "5. Soil condition\n";
    cout << "Mid/high-rise structures on weak soil get extra penalty.\n";
}

double TurkeyRisk::calculateRisk(const Building& b) const {
    double score = baseScore(b);
    if (b.getYearBuilt() < 2001) score += 0.9;
    if (!b.isRetrofitted()) score += 0.7;
    return clamp10(score);
}

string TurkeyRisk::getCountryName() const {
    return "Turkey";
}

void TurkeyRisk::showRules() const {
    cout << "\nBuilding factors considered for Turkey:\n";
    cout << "1. Floors\n";
    cout << "2. Material\n";
    cout << "3. Age of building\n";
    cout << "4. Retrofitting\n";
    cout << "5. Soil type\n";
    cout << "Older non-retrofitted apartment blocks are penalized more.\n";
}

double NepalRisk::calculateRisk(const Building& b) const {
    double score = baseScore(b);
    if (b.getMaterial() == "brick") score += 0.9;
    if (b.getFloors() > 8) score += 0.5;
    return clamp10(score);
}

string NepalRisk::getCountryName() const {
    return "Nepal";
}

void NepalRisk::showRules() const {
    cout << "\nBuilding factors considered for Nepal:\n";
    cout << "1. Floors\n";
    cout << "2. Material\n";
    cout << "3. Year built\n";
    cout << "4. Retrofitting\n";
    cout << "5. Soil condition\n";
    cout << "Brick and taller structures are treated as more vulnerable.\n";
}

double IndiaRisk::calculateRisk(const Building& b) const {
    double score = baseScore(b);
    if (b.getMaterial() == "brick") score += 0.5;
    if (b.getSoilType() == "soft") score += 0.4;
    return clamp10(score);
}

string IndiaRisk::getCountryName() const {
    return "India";
}

void IndiaRisk::showRules() const {
    cout << "\nBuilding factors considered for India:\n";
    cout << "1. Height\n";
    cout << "2. Material\n";
    cout << "3. Age\n";
    cout << "4. Retrofitting\n";
    cout << "5. Soil type\n";
    cout << "Soft-soil and older masonry buildings get extra penalty.\n";
}

double IndonesiaRisk::calculateRisk(const Building& b) const {
    double score = baseScore(b);
    if (b.getSoilType() == "soft") score += 0.7;
    if (b.getFloors() > 10) score += 0.5;
    return clamp10(score);
}

string IndonesiaRisk::getCountryName() const {
    return "Indonesia";
}

void IndonesiaRisk::showRules() const {
    cout << "\nBuilding factors considered for Indonesia:\n";
    cout << "1. Floors\n";
    cout << "2. Material\n";
    cout << "3. Year built\n";
    cout << "4. Retrofitting\n";
    cout << "5. Soil type\n";
    cout << "Soft soil and taller urban buildings are penalized more.\n";
}

double MexicoRisk::calculateRisk(const Building& b) const {
    double score = baseScore(b);
    if (b.getSoilType() == "soft") score += 0.9;
    if (b.getMaterial() == "concrete") score += 0.2;
    return clamp10(score);
}

string MexicoRisk::getCountryName() const {
    return "Mexico";
}

void MexicoRisk::showRules() const {
    cout << "\nBuilding factors considered for Mexico:\n";
    cout << "1. Floors\n";
    cout << "2. Material\n";
    cout << "3. Building year\n";
    cout << "4. Retrofitting\n";
    cout << "5. Soil type\n";
    cout << "Soft lake-bed or weak soil gets a higher penalty.\n";
}

double ChileRisk::calculateRisk(const Building& b) const {
    double score = baseScore(b) - 1.0;
    if (b.getMaterial() == "steel") score -= 0.5;
    if (b.isRetrofitted()) score -= 0.4;
    return clamp10(score);
}

string ChileRisk::getCountryName() const {
    return "Chile";
}

void ChileRisk::showRules() const {
    cout << "\nBuilding factors considered for Chile:\n";
    cout << "1. Floors\n";
    cout << "2. Material\n";
    cout << "3. Construction year\n";
    cout << "4. Retrofitting\n";
    cout << "5. Soil type\n";
    cout << "Modern steel and retrofitted buildings are rewarded more.\n";
}

double ItalyRisk::calculateRisk(const Building& b) const {
    double score = baseScore(b);
    if (b.getYearBuilt() < 2000) score += 0.7;
    if (b.getMaterial() == "brick") score += 0.6;
    return clamp10(score);
}

string ItalyRisk::getCountryName() const {
    return "Italy";
}

void ItalyRisk::showRules() const {
    cout << "\nBuilding factors considered for Italy:\n";
    cout << "1. Floors\n";
    cout << "2. Material\n";
    cout << "3. Year built\n";
    cout << "4. Retrofitting\n";
    cout << "5. Soil type\n";
    cout << "Older masonry buildings get higher risk.\n";
}

RiskModel* createCountryModel(int choice) {
    switch (choice) {
        case 1: return new BangladeshRisk();
        case 2: return new JapanRisk();
        case 3: return new USARisk();
        case 4: return new TurkeyRisk();
        case 5: return new NepalRisk();
        case 6: return new IndiaRisk();
        case 7: return new IndonesiaRisk();
        case 8: return new MexicoRisk();
        case 9: return new ChileRisk();
        case 10: return new ItalyRisk();
        default: return nullptr;
    }
>>>>>>> 2b21d905ac29b1e2fa2531c3b3a4f7ff05c03515
}