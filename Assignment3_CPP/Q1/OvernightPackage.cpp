#include "OvernightPackage.h"

OvernightPackage::OvernightPackage(std::string senderName, std::string senderAddress, std::string senderCity,
                                   std::string senderState, std::string senderZIP,
                                   std::string recipientName, std::string recipientAddress, std::string recipientCity,
                                   std::string recipientState, std::string recipientZIP,
                                   double weight, double costPerOunce, double additionalFee)
    : Package(senderName, senderAddress, senderCity, senderState, senderZIP,
              recipientName, recipientAddress, recipientCity, recipientState, recipientZIP,
              weight, costPerOunce), additionalFee(additionalFee > 0 ? additionalFee : 0) {}

// Calculate cost
double OvernightPackage::calculateCost() const {
    return (costPerOunce + additionalFee) * weight;
}

// Destructor
OvernightPackage::~OvernightPackage() {}
