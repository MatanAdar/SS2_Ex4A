#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <stdio.h>
#include <string>

using namespace std;



namespace ariel{
    class  Character{
        private:
            Point c_location;

            int c_health;

            string c_name;

        public:

            Character(const string& name,const Point& location , int health);

            Character(const string& name,const Point& location);

            bool isAlive() const;

            double distance(const Character* other_c) const;

            void hit(int hits);

            const string& getName() const{
                return c_name;
            }

            const Point& getLocation() const{
                return c_location;
            }

            void print();


    };
}






#endif