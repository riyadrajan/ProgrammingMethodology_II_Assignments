#include "Parallelogram.h"
#include <cmath>

//input points and calculate the sl, ss and ang
        Parallelogram::Parallelogram():Quadrilateral(){
            double side1 = sqrt(pow(points[0].getx() - points[1].getx(), 2) + pow(points[0].gety() - points[1].gety(), 2)); 
            double side2 = sqrt(pow(points[1].getx() - points[2].getx(), 2) + pow(points[1].gety() - points[2].gety(), 2));
            longerSide = side1>side2 ? side1 : side2;
            shorterSide = side1<side2 ? side1 : side2;
            //do dot product to get angle in degrees
            acuteAngle = acos( (points[1].getx()*points[3].getx() + points[1].gety()*points[3].gety()) / (longerSide*shorterSide) );
            
        } 

        double Parallelogram::getLongerSide(){
            return longerSide;
        }
        double Parallelogram::getShorterSide(){
            return shorterSide;
        }
        double Parallelogram::getAcuteAngleInRadian(){
            return acuteAngle; //since it is already in radians 
        }

        Parallelogram::~Parallelogram(){}
