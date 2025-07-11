#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H
#include <iostream>
#include "Quadrilateral.h"
#include <cmath>

class Parallelogram: public Quadrilateral{
    private:
        double shorterSide;
        double longerSide;
        double acuteAngle;
        const double PI = (22/7);

    public:
        Parallelogram(); //ensure longer>shorter, and angle less than pi/2
        // double area(); override area?? to be longerSide * shorterSide??

        double getLongerSide();
        double getShorterSide();
        double getAcuteAngleInRadian();

        ~Parallelogram();
};
#endif