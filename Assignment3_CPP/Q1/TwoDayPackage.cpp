#include "TwoDayPackage.h"

TwoDayPackage::TwoDayPackage(std::string senderName, std::string senderAddress, std::string senderCity,
                  std::string senderState, std::string senderZIP,
                  std::string recipientName, std::string recipientAddress, std::string recipientCity,
                  std::string recipientState, std::string recipientZIP,
                  double weight, double costPerOunce, double flatFee)
        : Package(senderName, senderAddress, senderCity, senderState, senderZIP,
                  recipientName, recipientAddress, recipientCity, recipientState, recipientZIP,
                  weight, costPerOunce), flatFee(flatFee > 0 ? flatFee : 0) {}

    double TwoDayPackage::calculateCost() const {
        return Package::calculateCost() + flatFee;
    }

    TwoDayPackage::~TwoDayPackage() {}