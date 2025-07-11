#ifndef COMMISSIONEMPLOYEE_H  
#define COMMISSIONEMPLOYEE_H

#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>

class CommissionEmployee {
protected:
    std::string firstName;
    std::string lastName;
    std::string socialSecurityNumber;
    double grossSales;
    double commissionRate;

public:
    // Constructor
    CommissionEmployee(const std::string& first, const std::string& last, const std::string& ssn, double sales, double rate);

    // Copy constructor
    CommissionEmployee(const CommissionEmployee& other);

    // Public member functions
    double earnings() const;
    std::string toString() const;

    double getGrossSales();

    // Friend functions
    friend bool checkGrossSales(const CommissionEmployee&, double baseline);
    friend std::ostream& operator<<(std::ostream& os, const CommissionEmployee& employee);
};

#endif
