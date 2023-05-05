#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"


namespace ariel{

    class Ninja : public Character{

        private:
            int speed;

        public:

            Ninja(const string& name, const Point& location, int health , int speed);

            void move(Character* enemy);

            void slash(Character* enemy);
    };

}




#endif