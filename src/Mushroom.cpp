//
//  Mushroom.cpp
//  groupProject
//
//  Created by Tyler Speegle on 9/21/20.
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



