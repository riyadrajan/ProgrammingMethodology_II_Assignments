// Derived class TwoDayPackage
#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H
#include "Package.h"

class TwoDayPackage : public Package {
private:
    double flatFee;

public:
    TwoDayPackage(std::string senderName, std::string senderAddress, std::string senderCity,
                  std::string senderState, std::string senderZIP,
                  std::string recipientName, std::string recipientAddress, std::string recipientCity,
                  std::string recipientState, std::string recipientZIP,
                  double weight, double costPerOunce, double flatFee);

    double calculateCost() const override;

    ~TwoDayPackage() override;
};
#endif