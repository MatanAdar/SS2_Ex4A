#include "Point.hpp"
#include <stdio.h>
#include <cmath>
#include <iostream>

using namespace std;




namespace ariel{

    Point::Point(double __x, double __y) : point_x(__x), point_y(__y){


    }

    double Point::getPointX(){

        return this->point_x;
    }

    double Point::getPointY(){

        return this->point_y;
    }

    double Point::distance(Point point){

        double dis_x = this->getPointX() - point.getPointX();
        double dis_y = this->getPointY() - point.getPointY();

        return sqrt((dis_x*dis_x) + (dis_y*dis_y));
    }

    void Point::print_point(){

        cout << "(" << this->getPointX() << "," << this->getPointY() << ")" << endl;
    }
}