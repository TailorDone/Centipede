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
