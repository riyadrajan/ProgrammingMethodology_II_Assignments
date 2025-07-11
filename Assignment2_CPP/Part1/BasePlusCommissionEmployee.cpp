#include "BasePlusCommissionEmployee.h"
#include "ComissionEmployee.h"
#include <iostream>

// Constructor with base salary validation
BasePlusCommissionEmployee::BasePlusCommissionEmployee(const std::string& first, const std::string& last, const std::string& ssn, 
                               double sales, double rate, double salary)
    : CommissionEmployee(first, last, ssn, sales, rate), baseSalary(salary) {
    if (baseSalary < 0.0) {
        throw std::invalid_argument("Base salary must be >= 0.0");
    }
}

// Copy constructor
BasePlusCommissionEmployee::BasePlusCommissionEmployee(const BasePlusCommissionEmployee& other)
    : CommissionEmployee(other), baseSalary(other.baseSalary) {}

// Earnings function
double BasePlusCommissionEmployee::earnings() const {
    return baseSalary + (commissionRate * grossSales);
}

// toString function to display employee details including base salary
std::string BasePlusCommissionEmployee::toString() const {
    std::ostringstream output;
    output << CommissionEmployee::toString()
           << "\nBase Salary: " << baseSalary;
    return output.str();
}
