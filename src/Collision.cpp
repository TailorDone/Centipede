/*
 * File:   collision.cpp
 * Author: Nick
 *
 * Created on 30 January 2009, 11:02
 */
#include <SFML/Graphics.hpp>
#include "Collision.hpp"
#include <cmath>
 
Collision::Collision() {
}
 
Collision::~Collision() {
}

//From Rotated Rectangles Collision Detection, Oren Becker, 2001
 
bool Collision::BoundingBoxTest(const sf::Shape& Object1, const sf::Shape& Object2) {
 
    sf::Vector2f A, B, C, BL, TR;
      sf::Vector2f HalfSize1 = {2.5 , 2.5};
      sf::Vector2f HalfSize2 = {25 , 25};
      //Normalise the Center of Object2 so its axis aligned an represented in
      //relation to Object 1
      C = Object1.getPosition();
      C -= Object2.getPosition();
      C += {25,0};
      //Get the Corners
      BL = TR = C;
      BL -= HalfSize2; //Bottom Left
      TR += HalfSize2; //Top Right
    
    //Get the Angle we're working on
    float Angle = 0;
    float CosA = cos(Angle * RADIANS_PER_DEGREE);
    float SinA = sin(Angle * RADIANS_PER_DEGREE);
 
    float t, x, a, dx, ext1, ext2;

 
    //Calculate the vertices of the rotate Rect
    A.x = -HalfSize1.y*SinA;
    B.x = A.x;
    t = HalfSize1.x*CosA;
    A.x += t;
    B.x -= t;
 
    A.y = HalfSize1.y*CosA;
    B.y = A.y;
    t = HalfSize1.x*SinA;
    A.y += t;
    B.y -= t;
 
    t = SinA * CosA;
 
    // verify that A is vertical min/max, B is horizontal min/max
    if (t < 0) {
        t = A.x;
        A.x = B.x;
        B.x = t;
        t = A.y;
        A.y = B.y;
        B.y = t;
    }
 
    // verify that B is horizontal minimum (leftest-vertex)
    if (SinA < 0) {
        B.x = -B.x;
        B.y = -B.y;
    }
 
    // if rr2(ma) isn't in the horizontal range of
    // colliding with rr1(r), collision is impossible
    if (B.x > TR.x || B.x > -BL.x) return false;
 
    // if rr1(r) is axis-aligned, vertical min/max are easy to get
    if (t == 0) {
        ext1 = A.y;
        ext2 = -ext1;
    }// else, find vertical min/max in the range [BL.x, TR.x]
    else {
        x = BL.x - A.x;
        a = TR.x - A.x;
        ext1 = A.y;
        // if the first vertical min/max isn't in (BL.x, TR.x), then
        // find the vertical min/max on BL.x or on TR.x
        if (a * x > 0) {
            dx = A.x;
            if (x < 0) {
                dx -= B.x;
                ext1 -= B.y;
                x = a;
            } else {
                dx += B.x;
                ext1 += B.y;
            }
            ext1 *= x;
            ext1 /= dx;
            ext1 += A.y;
        }
 
        x = BL.x + A.x;
        a = TR.x + A.x;
        ext2 = -A.y;
        // if the second vertical min/max isn't in (BL.x, TR.x), then
        // find the local vertical min/max on BL.x or on TR.x
        if (a * x > 0) {
            dx = -A.x;
            if (x < 0) {
                dx -= B.x;
                ext2 -= B.y;
                x = a;
            } else {
                dx += B.x;
                ext2 += B.y;
            }
            ext2 *= x;
            ext2 /= dx;
            ext2 -= A.y;
        }
    }
 
    // check whether rr2(ma) is in the vertical range of colliding with rr1(r)
    // (for the horizontal range of rr2)
    return !((ext1 < BL.y && ext2 < BL.y) ||
            (ext1 > TR.y && ext2 > TR.y));
 
}
