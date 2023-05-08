#include "doctest.h"
#include <stdexcept>
#include <sstream>
#include "Point.hpp"
#include "Character.hpp"
#include "Team.hpp"



TEST_CASE("Checking if point created succsessfully"){

    CHECK_NOTHROW(Point p1(1,2));
    
    //checking point get the currect values
    Point a(2.3,4);
    CHECK(a.getPointX() == 2.3);
    CHECK(a.getPointY() == 4);
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

}

TEST_CASE("Checking valid input for health object"){

    //throw error if input negetive health or zero
    CHECK_THROWS(Character("Hod", Point(1,0) ,-5));
    CHECK_THROWS(Character("Adi", Point(0,0) , 0));


}


TEST_CASE("Checking isAlive function"){

    Character a("Matan" , Point(1,1) , 70);

    CHECK(a.isAlive() == true);

    Character b("Roni" , Point(3,4) , 0);

    CHECK(b.isAlive() == false);
}

TEST_CASE("Checking that dead cowboy cant shoot"){

    Cowboy a("Tom" , Point(1,1));
    
}


TEST_CASE("Checking Shoot function"){

    Cowboy a("Yoni" , Point(1,1));

    Character enemy("Hod" , Point(4,4) , 60);

    Character temp("Shalom" , Point(2,2), 100);

    a.shoot(&enemy);

    //checking that enemy lose health
    CHECK(enemy.getHealth() == 50);
    CHECK(enemy.isAlive() == true);

    //using all his bullets
    for(int i=0 ; i<5 ; i++){
        a.shoot(&enemy);
    }

    //checking that enemy lost all his health(dead)
    CHECK(enemy.getHealth() == 0);
    CHECK(enemy.isAlive() == false);

    //try to shoot when dont have any bullets left
    CHECK_THROWS(a.shoot(&temp));

    //checking temp dont lose life because cowboy dont have anymore bullets
    CHECK(temp.getHealth() == 100);

}


TEST_CASE("Checking cowboy bullets"){

    Cowboy t("Matan" , Point(10,10));

    Character a("Hod" , Point(5,5) , 120);

    //when created cowboy have 6 bullets so its true
    CHECK(t.hasboolets() == true );

    //taking 6 shots
    for(int i=0; i<6 ; i++){
        t.shoot(&a);
    }
    
    // need to be false becaue cowboy used all his bullets
    CHECK(t.hasboolets() == false);

}


TEST_CASE("Checking cowboy relod function"){

    Cowboy t("Matan" , Point(10,10));

    Character a("Hod" , Point(5,5) , 120);

    //taking 6 shots
    for(int i=0; i<6 ; i++){
        t.shoot(&a);
    }
    
    // need to be false becaue cowboy used all his bullets
    CHECK(t.hasboolets() == false);

    t.reload();

    //checking after reload that cowboy have bullets
    CHECK(t.hasboolets() == true);

}

// TEST_CASE("Checking adding same char to another team"){

//     Cowboy a("Matan" , Point(2,2));

//     Team b(&a);

//     CHECK_THROWS(Team(&a));
// }


// TEST_CASE("Checking Move function"){

//     YoungNinja a("Matan" , Point(1,1));

//     Character b("Adi" , Point(2,2) , 100);

//     Point loc = a.getLocation();

//     a.move(&b);

//     CHECK(a.getLocation() == (loc + a.move(&b)));
// }


TEST_CASE("Checking slash function"){

    OldNinja a("Matan" , Point(1,1));

    YoungNinja b("Adi" , Point(10,10));

    if(a.distance(&b) < 1){

        CHECK_NOTHROW(a.slash(&b));
        CHECK(b.getHealth() == 87);

    }
    else{

        CHECK_THROWS(a.slash(&b));
    }

}

TEST_CASE("Checking all ninja's health is correct"){

    OldNinja a("Tom"  , Point(2,2));

    CHECK(a.getHealth() == 150);

    TrainedNinja b("Shachar" , Point(5,5));

    CHECK(b.getHealth() == 120);

    YoungNinja c("Ron" , Point(10,10));

    CHECK(c.getHealth() == 100);

}




