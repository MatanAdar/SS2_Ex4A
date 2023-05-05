#include "Team.hpp"

#include <cmath>
#include <stdexcept>




namespace ariel{

    Team::Team(Character* leader) : team_leader(leader) {
        

    }

    void Team::add(Character* player){

        if(team.size() < 10){
            team.push_back(player);
        }
        else{
            throw std::runtime_error("Team is Max capacity!");
        }
    }


    void Team::attack(Team* other_team){

    }

    int Team::stillAlive() const{

        return 1;
    }
            
    void Team::print() const{

    }

    // Team::~Team(){
    //     for (auto player : team) {
    //         delete player;
    //     }
    // }

}