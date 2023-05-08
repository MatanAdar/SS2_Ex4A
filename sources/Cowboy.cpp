#include "Cowboy.hpp"



namespace ariel{

    // Cowboy::Cowboy(const string& name, const Point& location, int health) : Character(name,location,110), amount_of_bullets(6){

    // }

    Cowboy::Cowboy(const string& name, const Point& location) : Character(name,location,110) , amount_of_bullets(6){

    }

    void Cowboy::shoot(Character* enemy){


    }

    bool Cowboy::hasboolets() const{

        return amount_of_bullets > 0;
    }

    void Cowboy::reload(){

        amount_of_bullets = 6;
    }


}