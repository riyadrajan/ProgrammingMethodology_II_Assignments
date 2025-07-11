#include "Point.h"
#include <iostream>

        Point::Point(): x(0), y(0){}

        Point::Point(double x, double y): x(x), y(y){}

        double Point::getx(){
            return x;
        }

        void Point::setx(double x){
            this->x = x;
        }

        double Point::gety(){
            return y;
        }

        void Point::sety(double y){
            this->y = y;
        }
        
        Point::~Point(){}