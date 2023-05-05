#ifndef TEAM_HPP
#define TEAM_HPP



#include "Point.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"

#include <vector>

using namespace ariel;


namespace ariel{

    class Team{

        private:

            vector<Character*> team;

            Character* team_leader;

        public:

            Team(Character* leader);

            void add(Character* player);

            void attack(Team* other_team);

            int stillAlive() const;
            
            void print() const;

            bool checking_player_in_team_already(Character* player);

            // ~Team();



    };
}



#endif