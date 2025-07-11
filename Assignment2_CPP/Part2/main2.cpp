#include <iostream>
#include <string>
#include "Point.h"
#include "Polygon.h"
#include "Quadrilateral.h"
#include "Parallelogram.h"

// Test function for Polygon
double testPolygon() {
    std::cout<<"Polygon test"<<std::endl;
    int size; 
    std::cout<<"Enter polygon size"<<std::endl;
    std::cin>>size;
    Polygon polygon(size);
    std::cout<<"area is "<<polygon.area()<<std::endl;
    double expectedArea = 27.0; // Points (1,1) (2,5) (5,4) (8,5) (7,1)
    return polygon.area();
}

// Test function for Quadrilateral
bool testQuadrilateral() {
    std::cout<<"Quadrilateral test"<<std::endl;
    //Point points[4] = { Point(0, 0), Point(0, 2), Point(2, 2), Point(2, 0) };
    Quadrilateral quadrilateral;

    double expectedArea = 4.0; // Area of the rectangle
    return quadrilateral.area() == expectedArea;
}

// Test function for Parallelogram
bool testParallelogramArea(Parallelogram& parallelogram) {
    std::cout<<"Parallelogram test"<<std::endl;
    
    std::cout<<"shorter side = "<<parallelogram.getShorterSide()<<std::endl;

    std::cout<<"longer side = "<<parallelogram.getLongerSide()<<std::endl;

    std::cout<<"acute angle (in radians) = "<<parallelogram.getAcuteAngleInRadian()<<std::endl;

    std::cout<<"area = "<<parallelogram.area()<<std::endl;


    double expectedArea = 1; // Area of the parallelogram

    return parallelogram.area() == expectedArea;
}

bool testParallelogramAngle(Parallelogram& parallelogram) {
    std::cout<<"Parallelogram Acute Angle test"<<std::endl;
    double expectedAngle = 0.785398;
    double epsilon = 0.001;
    return ((parallelogram.getAcuteAngleInRadian() - expectedAngle) <= epsilon);
}

bool testParallelogramShort(Parallelogram& parallelogram) {
    std::cout<<"Parallelogram Short Side test"<<std::endl;
    double expectedShorterSide = 1;

    return parallelogram.getShorterSide() == expectedShorterSide;
}

bool testParallelogramLong(Parallelogram& parallelogram) {
    std::cout<<"Parallelogram Longer Side test"<<std::endl;
    double expectedLongerSide = sqrt(2);

    return parallelogram.getLongerSide() == expectedLongerSide;
}


// Main function
int main() {
    std::string result;

    result = testPolygon() ? "Polygon Test: Pass!" : "Polygon Test: Fail!";
    std::cout << result << std::endl;

    result = testQuadrilateral() ? "Quadrilateral Test: Pass!" : "Quadrilateral Test: Fail!";
    std::cout << result << std::endl;

    Parallelogram parallelogram;
    //Point points[4] = { Point(0, 0), Point(1, 1), Point(2, 1), Point(1, 0) }; long side is root 2 and short side is 1
    result = testParallelogramArea(parallelogram) ? "Parallelogram Area Test: Pass!" : "Parallelogram Area Test: Fail!";
    std::cout << result << std::endl;

    result = testParallelogramAngle(parallelogram) ? "Parallelogram AngleTest: Pass!" : "Parallelogram Angle Test: Fail!";
    std::cout << result << std::endl;

    result = testParallelogramShort(parallelogram) ? "Parallelogram Short Side Test: Pass!" : "Parallelogram Short Side Test: Fail!";
    std::cout << result << std::endl;

    result = testParallelogramLong(parallelogram) ? "Parallelogram Long Side Test: Pass!" : "Parallelogram Long Side Test: Fail!";
    std::cout << result << std::endl;


    return 0;
}