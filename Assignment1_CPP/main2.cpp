#include "Employee.h"
#include <iostream>
#include <string>
using namespace std;


//minimal salary amongst array of employees
int testMinimalEmployeeSalary(Employee array[]){
    int minimum = array[0].getSalary();
    int arrSize = 10;
    //now compare values of each employee going thru a loop
    for(int i=1; i < (arrSize); i++){
        if( (array[i].getSalary() <= minimum) ) minimum = array[i].getSalary();
    }

    return minimum;
}


void raise (Employee& x){
    int newSalary = 1.1*x.getSalary();
    x.setSalary(newSalary);
}
int yearlySalary(Employee x){
    int y = x.getSalary();
    return y*12;
}

int main(){

    int counterpass = 0;
    int counterfail = 0;

    Employee Raj("Riyad", "Rajan", 50000);
    cout<<Raj.getFirstName()<<" "<<Raj.getLastName()<<" "<<Raj.getSalary()<<endl;
    cout<<yearlySalary(Raj)<<endl;
    //unit test 1
    string message = (yearlySalary(Raj) == 600000) ? "pass" : "fail";
    cout<< message << endl;
    (message == "pass") ? (counterpass +=1) : (counterfail +=1);
    
    //inc salary by 10%
    raise(Raj);
     //unit test 2
    message = (Raj.getSalary() == 55000)  ? "pass" : "fail";
    cout<<message<<endl;
    (message == "pass") ? (counterpass +=1) : (counterfail +=1);

    cout<<Raj.getFirstName()<<" "<<Raj.getLastName()<<" "<<Raj.getSalary()<<endl;
    cout<<yearlySalary(Raj)<<endl;
    //unit test 3
    message = (yearlySalary(Raj) == 660000) ? "pass" : "fail";
    cout<< message << endl;
    (message == "pass") ? (counterpass +=1) : (counterfail +=1);

    //create an array of Employees and pass through minimalSalfunction
    Employee Ram("Rami", "Thabet", 60000);
    Employee Bob("Bob", "1", 7500);
    Employee Bill("Bill", "2", 7200);
    Employee Frank("Frank", "3", 120000);
    Employee Jake("Jake", "4", 130000);
    Employee Jack("Jack", "5", 140000);
    Employee John("John", "6", 60000); 
    Employee Doe("Doe", "7", 700000);
    Employee Kate("Kate", "8", 160000);

    Employee arr[10] = {Raj, Ram, Bob, Bill, Frank, Jake, Jack, John, Doe, Kate};

    // cout<< " The minimum salary amongst the 10 employees is " << testMinimalEmployeeSalary(arr) << endl;
    
    //unit test 4
    message = (testMinimalEmployeeSalary(arr) == 7200) ? "pass" : "fail";
    cout<< message <<endl;
    (message == "pass") ? (counterpass +=1) : (counterfail +=1);

    cout<<counterpass<<"/4 pass and " <<counterfail<<"/4 fail";
    
    return 0;
}