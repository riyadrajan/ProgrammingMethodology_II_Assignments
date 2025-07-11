#include "ComissionEmployee.h"
#include "BasePlusCommissionEmployee.h"
#include <iostream>
#include <cassert>

// Friend function to check if the employee's gross sales meet a baseline
bool checkGrossSales(const CommissionEmployee& employee, double baseline) {
    return employee.grossSales >= baseline;
}

// Overloaded output operator for CommissionEmployee
std::ostream& operator<<(std::ostream& os, const CommissionEmployee& employee) {
    os << employee.toString();
    return os;
}

// Overloaded output operator for BasePlusCommissionEmployee
std::ostream& operator<<(std::ostream& os, const BasePlusCommissionEmployee& employee) {
    os << employee.toString();
    return os;
}

void testEmployee() {
    // Test with CommissionEmployee
    CommissionEmployee original("John", "Doe", "111-11-1111", 10000, 0.06);
    std::cout << "Original Commission Employee: \n" << original << std::endl;
    std::cout << "Earnings: " << original.earnings() << std::endl;

    double baseline = 5000;
    std::cout << "Does gross sales meet the baseline of " << baseline << "? "
              << (checkGrossSales(original, baseline) ? "Yes" : "No") << std::endl;

    // Test with BasePlusCommissionEmployee
    BasePlusCommissionEmployee baseOriginal("Jane", "Smith", "222-22-2222", 15000, 0.05, 3000);
    std::cout << "Original BasePlusCommission Employee: \n" << baseOriginal << std::endl;
    std::cout << "Earnings: " << baseOriginal.earnings() << std::endl;

    std::cout << "Does gross sales meet the baseline of " << baseline << "? "
              << (checkGrossSales(baseOriginal, baseline) ? "Yes" : "No") << std::endl;
}


void testFriendAndInheritance() {
    // Create an instance of BasePlusCommissionEmployee
    BasePlusCommissionEmployee emp1("abc", "def", "0987654321", 250000, 0.15, 5000);

    // Define baseline values
    double baseline1 = 100000;
    double baseline2 = 5000;

    // Check if gross sales meet the first baseline using the friend function
    bool result1 = checkGrossSales(emp1, baseline1);
    std::cout << "Checking gross sales against baseline of " << baseline1 << ":\n";
    std::cout << "Gross sales: " << emp1.getGrossSales() << ", meets baseline? "
              << (result1 ? "pass" : "fail") << std::endl;

    // Assertion for the first baseline
    assert(result1 == (emp1.getGrossSales() >= baseline1)); 

    // Check if gross sales meet the second baseline
    bool result2 = checkGrossSales(emp1, baseline2);
    std::cout << "Checking gross sales against baseline of " << baseline2 << ":\n";
    std::cout << "Gross sales: " << emp1.getGrossSales() << ", meets baseline? "
              << (result2 ? "pass" : "fail") << std::endl;

    // Assertion for the second baseline
    assert(result2 == (emp1.getGrossSales() >= baseline2)); 
}

int main() {
    testEmployee();
    testFriendAndInheritance();
    return 0;
}
