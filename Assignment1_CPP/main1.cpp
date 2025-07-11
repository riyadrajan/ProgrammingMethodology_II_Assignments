#include "Invoice.h"
#include <iostream>
#include <string>
using namespace std;

bool testConstructors(){
    Invoice a("1234", "spanner", 2, 15);
    Invoice b(a); //call copy constructor
    return((a.getPartNum() == b.getPartNum()) && (a.getPartNum() == b.getPartNum()) && (a.getQty() == b.getQty()) && (a.getPrice() == b.getPrice()));
}
bool testClone(){
    Invoice a("1234", "spanner", 2, 15);
    Invoice b = a.clone();
    return((a.getPartNum() == b.getPartNum()) && (a.getPartDsp() == b.getPartDsp()) && (a.getQty() == b.getQty()) && (a.getPrice() == b.getPrice()));

}

bool testCloneByRef(){
    Invoice a("1234", "spanner", 2, 15);
    Invoice b = a.clone(a);
    return((a.getPartNum()== b.getPartNum()) && (a.getPartDsp() == b.getPartDsp()) && (a.getQty() == b.getQty()) && (a.getPrice() == b.getPrice()));

}

bool testInvoiceAmt(){
    Invoice a ("1234", "spanner", 6, 10);
    return (a.getInvoiceAmount() == 60)? true : false;
}



int main(){
//test if copy constructor matches default constructor
//test if destructor works
//clone returns same values as current invoice object 
//pbr clone returns same values as called invoice object
int counterpass = 0;
int counterfail = 0;

    string message = testConstructors() ? "pass" : "fail";
    cout<<"The case for copy constrcutor is "<<message<<endl;
    (message == "pass") ? (counterpass +=1) : (counterfail +=1);

//test destructor by seeing if memory location is free?


    message = testClone() ? "pass" : "fail";
    cout<<"The case for clone is "<<message<<endl;
    (message == "pass") ? (counterpass +=1) : (counterfail +=1);

    message = testCloneByRef() ? "pass" : "fail";
    cout<<"The case for clone by reference is "<<message<<endl;
    (message == "pass") ? (counterpass +=1) : (counterfail +=1);
    
    message = testInvoiceAmt() ? "pass" : "fail";
    cout<<"The case for invoice amount is "<<message<<endl;
    (message == "pass") ? (counterpass +=1) : (counterfail +=1);

    cout<<counterpass<<"/4 pass and " <<counterfail<<"/4 fail";
    
    return 0;

}
