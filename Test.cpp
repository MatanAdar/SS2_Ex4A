#include "doctest.h"
#include <stdexcept>
#include <sstream>
#include "Point.hpp"
#include "Character.hpp"
#include "Team.hpp"

using namespace ariel;


TEST_CASE("Checking if point created succsessfully"){

    CHECK_NOTHROW(Point p1(1,2));
    
    //checking point get the currect values
    Point a(2.3,4);
    CHECK(a.getPointX() == 2.3);
    CHECK(a.getPointY() == 4);

    Point b(-1.3,-5);
    CHECK(b.getPointX() == -1.3);
    CHECK(b.getPointY() == -5);


}

TEST_CASE("Checking distance calculation is correct"){

    Point p1(5.2,6);
    Point p2(5.2,6);

    CHECK(p1.distance(p2) == 0.0);

    Point p3(0,0);
    Point p4(0,0);

    CHECK(p3.distance(p4) == 0.0);

    Point p5(0,0);
    Point p6(4,3);

    CHECK(p5.distance(p6) == 5.0);

    Point p7(4.5,2.3);
    Point p8(5.2,3.7);

    CHECK(p7.distance(p8) == 1.565247584);
}

TEST_CASE("Checking print function"){
    
    
}

TEST_CASE("Checking MoveTowards function"){

    Point a(1,0);

    Point b(8,2);

    //checking that point a cant get to point b
    Point check1 = a.moveTowards(b,3);

    CHECK(check1.getPointX() != b.getPointX());
    CHECK(check1.getPointY() != b.getPointY());

    //checking that point cant get to point b
    Point check2 = a.moveTowards(b,a.distance(b));

    CHECK(check2.getPointX() == b.getPointX());
    CHECK(check2.getPointY() == b.getPointY());

    //thorw error if distance negative
    CHECK_THROWS(a.moveTowards(b,-2));

}


TEST_CASE("Checking isAlive function"){

    Cowboy *a = new Cowboy("Matan" , Point(1,1));

    CHECK(a->isAlive() == true);

    Cowboy *b = new Cowboy("Roni" , Point(3,4));

    //making sure that cowboy will die(will have 0 health)
    for(int i=0; i<11 ; i++){
        a->shoot(b);
    }

    CHECK(b->isAlive() == false);

    //free all alloctated memory(for valgrind)
    delete a;
    delete b;
}

TEST_CASE("Checking that dead cowboy cant shoot"){

    Cowboy *a = new Cowboy("Tom" , Point(1,1));
    
    Cowboy *b = new Cowboy("Ben"  , Point(5,5));

    //making sure that cowboy will die(will have 0 health)
    for(int i=0;i<11;i++){
        a->shoot(b);
    }

    //thorw an error beccause b is dead he cant shot
    CHECK_THROWS(b->shoot(a));

    //free all alloctated memory(for valgrind)
    delete a;
    delete b;

}


TEST_CASE("Checking Shoot function"){

    Cowboy *a = new Cowboy("Yoni" , Point(1,1));

    YoungNinja *enemy = new YoungNinja("Hod" , Point(4,4));

    OldNinja *temp = new OldNinja("Shalom" , Point(2,2));

    a->shoot(enemy);

    //checking that enemy lose health
    CHECK(enemy->getHealth() == 90);
    CHECK(enemy->isAlive() == true);

    //using all his bullets
    for(int i=0 ; i<5 ; i++){
        a->shoot(enemy);
    }

    CHECK(a->hasboolets() == false);

    //try to shoot when dont have any bullets left
    CHECK_THROWS(a->shoot(temp));

    //checking temp dont lose life because cowboy dont have anymore bullets
    CHECK(temp->getHealth() == 100);

    //checking after reload we relly have bullets
    a->reload();

    CHECK(a->hasboolets() == true);

    //keep shooting until enemy dead(0 health)
    for(int i=0;i<4;i++){
        a->shoot(enemy);
    }

    //checking that enemy lost all his health(dead)
    CHECK(enemy->getHealth() == 0);
    CHECK(enemy->isAlive() == false);

    //free all alloctated memory(for valgrind)
    delete a;
    delete enemy;
    delete temp;

}


TEST_CASE("Checking cowboy bullets"){

    Cowboy *t = new Cowboy("Matan" , Point(10,10));

    TrainedNinja *a = new TrainedNinja("Hod" , Point(5,5));

    //when created cowboy have 6 bullets so its true
    CHECK(t->hasboolets() == true );

    //taking 6 shots
    for(int i=0; i<6 ; i++){
        t->shoot(a);
    }
    
    // need to be false becaue cowboy used all his bullets
    CHECK(t->hasboolets() == false);


    //free all alloctated memory(for valgrind)
    delete t;
    delete a;
}


TEST_CASE("Checking cowboy relod function"){

    Cowboy *t = new Cowboy("Matan" , Point(10,10));

    Cowboy *a = new Cowboy("Hod" , Point(5,5));

    //taking 6 shots
    for(int i=0; i<6 ; i++){
        t->shoot(a);
    }
    
    // need to be false becaue cowboy used all his bullets
    CHECK(t->hasboolets() == false);

    t->reload();

    //checking after reload that cowboy have bullets
    CHECK(t->hasboolets() == true);

    //throw an error if we try to reload when we have already bullets in our pistol
    CHECK_THROWS(t->reload());


    //free all alloctated memory(for valgrind)
    delete t;
    delete a;

}

TEST_CASE("Checking adding same character to another team"){

    Cowboy *a = new Cowboy("Matan" , Point(2,2));

    Team b(a);

    CHECK_THROWS(Team(a));

}


TEST_CASE("Checking Move function"){

    YoungNinja *a = new YoungNinja("Matan" , Point(1,1));

    Cowboy *b = new Cowboy("Adi" , Point(2,2));

    Point location_before_moving = a->getLocation();

    a->move(b);

    CHECK(((a->getLocation().getPointX() != location_before_moving.getPointX()) || (a->getLocation().getPointY() != location_before_moving.getPointY())));
    

    //free all allocated memeory
    delete a;
    delete b;
}


TEST_CASE("Checking slash function"){

    OldNinja *a = new OldNinja("Matan" , Point(1,1));

    YoungNinja *b = new YoungNinja("Adi" , Point(10,10));

    if(a->distance(b) < 1){

        CHECK_NOTHROW(a->slash(b));
        CHECK(b->getHealth() == 87);

    }
    else{

        CHECK_THROWS(a->slash(b));
    }


    //free all allocated memeory
    delete a;
    delete b;

}

TEST_CASE("Checking all ninja's health is correct"){

    OldNinja *a = new OldNinja("Tom"  , Point(2,2));

    CHECK(a->getHealth() == 150);

    TrainedNinja *b = new TrainedNinja("Shachar" , Point(5,5));

    CHECK(b->getHealth() == 120);

    YoungNinja *c = new YoungNinja("Ron" , Point(10,10));

    CHECK(c->getHealth() == 100);


    //free all allocated memory
    delete a;
    delete b;
    delete c;

}


TEST_CASE("Checking attack function"){

    Cowboy *a = new Cowboy("Tom" , Point(1,1));

    Team team_a(a);

    team_a.add(new Cowboy("Asher" , Point(5,5)));

    TrainedNinja *b = new TrainedNinja("Roy",Point(5.5,5.5));

    Team team_b(b);

    for(int i=0;i<10;i++){

        team_b.attack(&team_a);

    }

    CHECK(a->getHealth() <= 0);

    CHECK(team_a.stillAlive() < 2);

    //checking how to check if the leader change
    CHECK(team_a.getLeader() != NULL);











}


TEST_CASE("Checking stillAlive function"){

    Cowboy *a = new Cowboy("Yoni" , Point(2,2));

    Team team_a(a);

    Cowboy *b = new Cowboy("Dani" , Point(5,5));

    Team team_b(b);

    //checking after added, stillAlive is 1
    CHECK(team_b.stillAlive() == 1);

    //making sure that leader of team b is dead
    // while(b->getHealth() > 0){
    //     team_a.attack(&team_b);
    // }

    //checking that after he dead, stillAlive is 0
    CHECK(team_b.stillAlive() == 0);


}






