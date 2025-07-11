#pragma once
#include <iostream>

class Invoice{
    private: //change to private**
        std::string partNum;
        std::string partDsp;
        int qty;
        int price;

    public:
        Invoice (std::string p, std::string q, int r, int s);

//copy constructor
        Invoice (const Invoice& x);
        
        ~Invoice();


        void setPartNum(std::string p);
        std::string getPartNum();

        void setPartDsp(std::string p);
        std::string getPartDsp();

        void setQty(int p);
        int getQty();

        void setPrice(int p);
        int getPrice();

        int getInvoiceAmount();

        Invoice clone();

        Invoice clone (const Invoice &y);
};