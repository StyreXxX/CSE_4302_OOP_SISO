<<<<<<< HEAD
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

=======
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

>>>>>>> 2b21d905ac29b1e2fa2531c3b3a4f7ff05c03515
#endif