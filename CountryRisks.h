<<<<<<< HEAD
#ifndef COUNTRYRISKS_H
#define COUNTRYRISKS_H

#include "RiskModel.h"

class BangladeshRisk : public RiskModel {
public:
    double calculateRisk(const Building& b) const override;
    string getCountryName() const override;
    void showRules() const override;
};

class JapanRisk : public RiskModel {
public:
    double calculateRisk(const Building& b) const override;
    string getCountryName() const override;
    void showRules() const override;
};

class USARisk : public RiskModel {
public:
    double calculateRisk(const Building& b) const override;
    string getCountryName() const override;
    void showRules() const override;
};

class TurkeyRisk : public RiskModel {
public:
    double calculateRisk(const Building& b) const override;
    string getCountryName() const override;
    void showRules() const override;
};

class NepalRisk : public RiskModel {
public:
    double calculateRisk(const Building& b) const override;
    string getCountryName() const override;
    void showRules() const override;
};

class IndiaRisk : public RiskModel {
public:
    double calculateRisk(const Building& b) const override;
    string getCountryName() const override;
    void showRules() const override;
};

class IndonesiaRisk : public RiskModel {
public:
    double calculateRisk(const Building& b) const override;
    string getCountryName() const override;
    void showRules() const override;
};

class MexicoRisk : public RiskModel {
public:
    double calculateRisk(const Building& b) const override;
    string getCountryName() const override;
    void showRules() const override;
};

class ChileRisk : public RiskModel {
public:
    double calculateRisk(const Building& b) const override;
    string getCountryName() const override;
    void showRules() const override;
};

class ItalyRisk : public RiskModel {
public:
    double calculateRisk(const Building& b) const override;
    string getCountryName() const override;
    void showRules() const override;
};

RiskModel* createCountryModel(int choice);

=======
#ifndef COUNTRYRISKS_H
#define COUNTRYRISKS_H

#include "RiskModel.h"

class BangladeshRisk : public RiskModel {
public:
    double calculateRisk(const Building& b) const override;
    string getCountryName() const override;
    void showRules() const override;
};

class JapanRisk : public RiskModel {
public:
    double calculateRisk(const Building& b) const override;
    string getCountryName() const override;
    void showRules() const override;
};

class USARisk : public RiskModel {
public:
    double calculateRisk(const Building& b) const override;
    string getCountryName() const override;
    void showRules() const override;
};

class TurkeyRisk : public RiskModel {
public:
    double calculateRisk(const Building& b) const override;
    string getCountryName() const override;
    void showRules() const override;
};

class NepalRisk : public RiskModel {
public:
    double calculateRisk(const Building& b) const override;
    string getCountryName() const override;
    void showRules() const override;
};

class IndiaRisk : public RiskModel {
public:
    double calculateRisk(const Building& b) const override;
    string getCountryName() const override;
    void showRules() const override;
};

class IndonesiaRisk : public RiskModel {
public:
    double calculateRisk(const Building& b) const override;
    string getCountryName() const override;
    void showRules() const override;
};

class MexicoRisk : public RiskModel {
public:
    double calculateRisk(const Building& b) const override;
    string getCountryName() const override;
    void showRules() const override;
};

class ChileRisk : public RiskModel {
public:
    double calculateRisk(const Building& b) const override;
    string getCountryName() const override;
    void showRules() const override;
};

class ItalyRisk : public RiskModel {
public:
    double calculateRisk(const Building& b) const override;
    string getCountryName() const override;
    void showRules() const override;
};

RiskModel* createCountryModel(int choice);

>>>>>>> 2b21d905ac29b1e2fa2531c3b3a4f7ff05c03515
#endif