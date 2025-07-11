#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "Package.h"
#include <string>

// Derived class OvernightPackage
class OvernightPackage : public Package {
private:
    double additionalFee;

public:
    OvernightPackage(std::string senderName, std::string senderAddress, std::string senderCity,
                     std::string senderState, std::string senderZIP,
                     std::string recipientName, std::string recipientAddress, std::string recipientCity,
                     std::string recipientState, std::string recipientZIP,
                     double weight, double costPerOunce, double additionalFee);

    double calculateCost() const override;
    ~OvernightPackage() override;
};

#endif