#include "Character.hpp"
#include <stdio.h>
#include <iostream>
#include <ostream>

using namespace std;

namespace ariel{

    Character::Character(const string& name,const Point& location , int health) : c_name(name), c_location(location), c_health(health) {
        
    }

    Character::Character(const string& name,const Point& location) : c_name(name) , c_location(location){
        
    }

    bool Character::isAlive() const{

        return c_health > 0;
    }

    double Character::distance(const Character* other_c) const{

        return c_location.distance(other_c->getLocation());

        // return 2.3;
    }

    void Character::hit(int hits){

        c_health -= hits;
    }

    //need to check if need the word virtual before ??????????????????????????
    string Character::print() const{

        return "hii";
    }


}


