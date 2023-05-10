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

            bool checking_in_team = false;

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

            int getHealth() const{
                return c_health;
            }

            bool getInTeam() const{

                return checking_in_team;
            }

            void setInTeam(bool temp){

                checking_in_team = temp;
            }
            
            //need to check if need the word virtual before ??????????????????????????
            virtual string print() const = 0;

            //virtual destructor
            virtual ~Character() {}


    };
}






#endif