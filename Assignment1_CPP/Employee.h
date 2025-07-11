#pragma once
#include <iostream>

class Employee {
    private:
        std::string firstName;
        std::string lastName;
        int salary;

    public:

    Employee(std::string x, std::string y, int z);
//copy Contructor
    Employee(const Employee& x);

    ~Employee();

    void setFirstName(std::string x);

    std::string getFirstName();

    void setLastName(std::string y);

    std::string getLastName();

    void setSalary(int z);

    int getSalary();

};