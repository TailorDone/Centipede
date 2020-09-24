//
//  Tests.cpp
//  groupProject
//
//  Created by Tyler Speegle & Taylor Dunn on 9/24/20.
//

#include <stdio.h>
#include "Centipede.hpp"
#include "Collision.hpp"
#include "PewPew.hpp"
#define CATCH_CONFIG_MAIN

#include "catch.hpp"

TEST_CASE("Making Centipede"){
    REQUIRE( Centipede().getBodyLength()==5);
}

TEST_CASE("Check Collisions"){
    Mushroom mushy(5,5);
    PewPew pew (250);
    pew.bullet.setPosition(260, 260);
    Centipede centiBoi;
    centiBoi.centipede[0].segment.setPosition(250,250);
    centiBoi.centipede[2].segment.setPosition(150,250);
    REQUIRE (CollisionTest(mushy.sprite, pew.bullet) == true);
    REQUIRE (CollisionTest(mushy.sprite, centiBoi.centipede[0].segment) == true);
    REQUIRE(CollisionTest(pew.bullet, centiBoi.centipede[0].segment) == true);
    REQUIRE(CollisionTest(pew.bullet, centiBoi.centipede[2].segment) == false);
    if (CollisionTest(pew.bullet, centiBoi.centipede[0].segment)){
        centiBoi.centipede.pop_back();
        centiBoi.setBodyLength(centiBoi.getBodyLength()-1);
        REQUIRE(centiBoi.getBodyLength()==4);
    }
}
