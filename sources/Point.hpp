#ifndef POINT_HPP
#define POINT_HPP



#include <stdio.h>
namespace ariel{
    class Point{
        private:
            double point_x;
            double point_y;

        public:

            Point(double point_x, double point_y);

            double getPointX();

            double getPointY();

            double distance(Point point);

            void print_point();

            Point moveTowards(Point source, Point destanation, double distance);

    };
}      


#endif