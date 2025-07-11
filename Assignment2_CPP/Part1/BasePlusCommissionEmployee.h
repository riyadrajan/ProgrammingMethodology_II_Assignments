#ifndef BASEPLUSCOMMISSIONEMPLOYEE_H 
#define BASEPLUSCOMMISSIONEMPLOYEE_H

#include "ComissionEmployee.h" 
#include <iostream>
#include <string>
#include <sstream>


class BasePlusCommissionEmployee : public CommissionEmployee {
private:
    double baseSalary;

public:
    // Constructor
    BasePlusCommissionEmployee(const std::string& first, const std::string& last, const std::string& ssn, 
                               double sales, double rate, double salary);

    // Copy constructor
    BasePlusCommissionEmployee(const BasePlusCommissionEmployee& other);

    // Public member functions
    double earnings() const;
    std::string toString() const;

    // Friend function for output
    friend std::ostream& operator<<(std::ostream& os, const BasePlusCommissionEmployee& employee);
};

#endif
