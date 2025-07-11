#ifndef POLYGON_H
#define POLYGON_H
#include "Point.h"

#include <iostream>

class Polygon: public Point {
    protected: //so that subsequent classes may inherit
        int size; //number of vertices or edges
        Point* points; //array of points in a clockwise order
    public:
        Polygon(int);

        void setPoint(int, const Point&); //set the point at the position of index 
            //with the value of p

        void setPoint (int, double, double); /* set the point at the position of index 
            with the value of x and y. */
        
        virtual double area(); // return the area of a polygon 

        ~Polygon();
};

#endif


