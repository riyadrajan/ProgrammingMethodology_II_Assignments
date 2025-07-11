#include "Employee.h"
#include <iostream>


   Employee:: Employee(std::string x, std::string y, int z){
        firstName = x; 
        lastName = y;
        if (z<0){
            salary = 0;
        } else salary = z;
    }
//copy Contructor
    Employee::Employee(const Employee& x){
        firstName = x.firstName; 
        lastName = x.lastName;
        salary = x.salary;
    }

    Employee::~Employee(){
        std::cout<<"destroyed record for "<<firstName<<" "<<lastName<<std::endl;
    }

    void Employee::setFirstName(std::string x){
        firstName = x;
    }
    std::string Employee::getFirstName(){
        return firstName;
    }

     void Employee::setLastName(std::string y){
        lastName = y;
    }
    std::string Employee::getLastName(){
        return lastName;
    }

     void Employee::setSalary(int z){
        salary = z;
    }
    int Employee::getSalary(){
        return salary;
    }

