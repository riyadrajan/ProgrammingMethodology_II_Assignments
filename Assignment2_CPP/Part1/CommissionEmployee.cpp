#include "ComissionEmployee.h"

// Constructor with argument validation
CommissionEmployee::CommissionEmployee(const std::string& first, const std::string& last, const std::string& ssn, double sales, double rate)
    : firstName(first), lastName(last), socialSecurityNumber(ssn), grossSales(sales), commissionRate(rate) {
    
    if (grossSales < 0.0) {
        throw std::invalid_argument("Gross sales must be >= 0.0");
    }
    if (commissionRate <= 0.0 || commissionRate > 1.0) {
        throw std::invalid_argument("Commission rate must be > 0.0 and <= 1.0");
    }
}

// Copy constructor
CommissionEmployee::CommissionEmployee(const CommissionEmployee& other)
    : firstName(other.firstName), lastName(other.lastName), 
      socialSecurityNumber(other.socialSecurityNumber), 
      grossSales(other.grossSales), commissionRate(other.commissionRate) {}

// Earnings function
double CommissionEmployee::earnings() const {
    return commissionRate * grossSales;
}

// toString function to display employee details
std::string CommissionEmployee::toString() const {
    std::ostringstream output;
    output << "Commission Employee: " << firstName << ' ' << lastName
           << "\nSSN: " << socialSecurityNumber
           << "\nGross Sales: " << grossSales
           << "\nCommission Rate: " << commissionRate;
    return output.str();
}

double CommissionEmployee::getGrossSales(){
    return grossSales;
}
