#include "Invoice.h"
#include <iostream>

using namespace std;

Invoice::Invoice(string p, string q, int r, int s) {
    partNum = p;
    partDsp = q;

    if (r < 0) {
        qty = 0;
    } else {
        qty = r;
    }

    if (s < 0) {
        price = 0;
    } else {
        price = s;
    }
}

// Copy constructor
Invoice::Invoice(const Invoice& x) {
    partNum = x.partNum;
    partDsp = x.partDsp;
    qty = x.qty;
    price = x.price;
}

// Destructor
Invoice::~Invoice() {
    cout << "Destroyed old invoice" << endl;
}

// Setters and Getters
void Invoice::setPartNum(std::string p) {
    partNum = p;
}

std::string Invoice::getPartNum() {
    return partNum;
}

void Invoice::setPartDsp(std::string p) {
    partDsp = p;
}

std::string Invoice::getPartDsp() {
    return partDsp;
}

void Invoice::setQty(int p) {
    qty = p;
}

int Invoice::getQty() {
    return qty;
}

void Invoice::setPrice(int p) {
    price = p;
}

int Invoice::getPrice() {
    return price;
}

// Calculate total invoice amount
int Invoice::getInvoiceAmount() {
    return getPrice() * getQty();
}

// Clone methods
Invoice Invoice::clone() {
    return *this;
}

Invoice Invoice::clone(const Invoice& y) {
    return y;
}
