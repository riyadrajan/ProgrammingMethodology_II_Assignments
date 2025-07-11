#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>
#include <string>

// Base class Package
class Package {
protected:
    std::string senderName, senderAddress, senderCity, senderState, senderZIP;
    std::string recipientName, recipientAddress, recipientCity, recipientState, recipientZIP;
    double weight, costPerOunce;

public:
    Package(std::string senderName, std::string senderAddress, std::string senderCity,
            std::string senderState, std::string senderZIP,
            std::string recipientName, std::string recipientAddress, std::string recipientCity,
            std::string recipientState, std::string recipientZIP,
            double weight, double costPerOunce);

    virtual double calculateCost() const;

    // Getter functions
    std::string getSenderName() const;
    std::string getSenderAddress() const;
    std::string getRecipientName() const;
    std::string getRecipientAddress() const;

    virtual ~Package(); // Virtual destructor for deletion in polymorphism
};
#endif