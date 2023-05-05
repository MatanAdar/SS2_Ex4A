#include "Point.hpp"
#include <stdio.h>
#include <cmath>
#include <iostream>

using namespace std;




namespace ariel{

    Point::Point() : point_x(0),point_y(0){

    }

    Point::Point(double __x, double __y) : point_x(__x), point_y(__y){


    }

    double Point::getPointX() const{

        return this->point_x;
    }

    double Point::getPointY() const{

        return this->point_y;
    }

    double Point::distance(const Point& other_point) const{

        double dis_x = this->getPointX() - other_point.getPointX();
        double dis_y = this->getPointY() - other_point.getPointY();

        return sqrt((dis_x*dis_x) + (dis_y*dis_y));
    }

    void Point::print_point() const{

        cout << "(" << this->getPointX() << "," << this->getPointY() << ")" << endl;
    }

    Point Point::moveTowards(Point& source, const Point& destanation, double distance){

        return Point(1.0,1.0);
    }
}