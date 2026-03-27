#ifndef RISKMODEL_H
#define RISKMODEL_H

#include "Building.h"

class RiskModel {
public:
    virtual double calculateRisk(const Building& b) const = 0;
    virtual string getCountryName() const = 0;
    virtual void showRules() const = 0;
    virtual ~RiskModel() {}
};

#endif