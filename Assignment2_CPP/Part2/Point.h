#ifndef POINT_H
#define POINT_H
#include <iostream>

class Point{
    private: 
        double x;
        double y;

    public:
        Point();
        Point(double, double);
        double getx();
        void setx(double);
        double gety();
        void sety(double);
        ~Point();

};

#endif