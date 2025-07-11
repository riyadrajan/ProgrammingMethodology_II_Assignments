#ifndef BASETENSOR_H
#define BASETENSOR_H

#include <iostream>
#include <vector>
#include <random>

//base class for all tensors
class BaseTensor{
public:
    
    virtual void loadData() = 0; //pure virtual

    double valueGen(){ 
        std::random_device rd;
        std::mt19937 mt(rd());

        // Create a uniform distribution between 0 and 1 
        std::uniform_real_distribution<double> dist(0.0, 1.0);
        // Generate and print a random double value 
        double randomValue = dist(mt); 
        return randomValue;
    }

};
#endif 