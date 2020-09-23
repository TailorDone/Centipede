//
//  Mushroom.cpp
//  groupProject
//
//  Created by Tyler Speegle & Taylor Dunn on 9/21/20.
//

#include "Mushroom.hpp"

#include <cmath>

Mushroom::Mushroom(int column_, int row_) {
    sprite.setSize(rectSize);
    sprite.setPosition(sf::Vector2f(column*50, row*50));
    sprite.setFillColor(sf::Color(100, 250, 50));
    column = column_;
    row = row_;
}

int Mushroom::getRow() {
    return row;
}

int Mushroom::getColumn() {
    return column;
}

int Mushroom::getHealth() {
    return health;
}

bool Mushroom::bulletCollision(PewPew& bullet){
    Collision check;
    return (check.BoundingBoxTest(sprite, bullet.bullet));
}

void Mushroom::mushroomHit() {
    health--;
    if (health == 2)
        sprite.setFillColor(sf::Color(255,255,0));
    else if (health == 1)
        sprite.setFillColor(sf::Color(255,0,0));
}
    

