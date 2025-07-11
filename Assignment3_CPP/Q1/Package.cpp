#include "Package.h"

Package::Package(std::string senderName, std::string senderAddress, std::string senderCity,
            std::string senderState, std::string senderZIP,
            std::string recipientName, std::string recipientAddress, std::string recipientCity,
            std::string recipientState, std::string recipientZIP,
            double weight, double costPerOunce)
        : senderName(senderName), senderAddress(senderAddress), senderCity(senderCity),
          senderState(senderState), senderZIP(senderZIP), recipientName(recipientName),
          recipientAddress(recipientAddress), recipientCity(recipientCity),
          recipientState(recipientState), recipientZIP(recipientZIP),
          weight(weight > 0 ? weight : 1), costPerOunce(costPerOunce > 0 ? costPerOunce : 1) {}

    double Package::calculateCost() const {
        return weight * costPerOunce;
    }

    // Getter functions
    std::string Package::getSenderName() const { return senderName; }
    std::string Package::getSenderAddress() const { return senderAddress; }
    std::string Package::getRecipientName() const { return recipientName; }
    std::string Package::getRecipientAddress() const { return recipientAddress; }

    Package::~Package() {}