#include "Polygon.h"
#include <iostream>
#include <cmath>

        Polygon::Polygon(int size): size(size), points(new Point[size]) {
            double x_value;
            double y_value;
            for (int i = 0; i < size; ++i) {
                std::cout<<"Please enter values of x and y coordinates (separated by space):"<<std::endl;
                std::cin>>x_value>>y_value;
                points[i] = Point(x_value, y_value);
            }
        }

        void Polygon::setPoint(int index, const Point& p){
            if (index >= 0 && index < size) {
                points[index] = p;
            }
        } //set the point at the position of index 
            //with the value of p

        void Polygon::setPoint (int index, double x, double y){
            if (index >= 0 && index < size) {
            points[index] = Point(x, y);
            } /* set the point at the position of index 
            with the value of x and y. */
        }
        
        double Polygon::area(){
            /*implement formula for polygon area
            implement formula for polygon area
            loop from 0th point to n-1th point
	        point[i].getx()*point[i+1].gety()-point[i].gety()*point[i+1].getx();
            */
            int i = 0;
            double area = 0.0;
            while (i<(size-1)){ 
	             area += points[i].getx()*points[i+1].gety()-points[i].gety()*points[i+1].getx();
	             i++;
            }
	            area += points[0].getx()*points[size-1].gety()-points[0].gety()*points[size-1].getx();
	            area = std::abs(area) / 2.0;

        return area;
        } // return the area of a polygon 
        //need parameter as array of points 

        Polygon::~Polygon(){
            delete[] points;
        }
