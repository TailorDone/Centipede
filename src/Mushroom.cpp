//
//  Mushroom.cpp
//  groupProject
//
//  Created by Tyler Speegle & Taylor Dunn on 9/21/20.
//

#include "Mushroom.hpp"

#include <cmath>

Mushroom::Mushroom(int row, int column) {
    sprite.setSize(rectSize);
    sprite.setPosition(sf::Vector2f(row*50, column*50));
    sprite.setFillColor(sf::Color(100, 250, 50));
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
    

