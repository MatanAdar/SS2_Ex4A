#ifndef POINT_HPP
#define POINT_HPP



#include <stdio.h>
namespace ariel{
    class Point{
        private:
            double point_x;
            double point_y;

        public:

            Point();

            Point(double point_x, double point_y);

            double getPointX() const;

            double getPointY() const;

            double distance(const Point& point) const;

            void print_point() const;

            Point moveTowards(const Point& destanation, double distance);

    };
}      


#endif