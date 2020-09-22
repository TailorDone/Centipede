//
//  PewPew.cpp
//  groupProject
//
//  Created by Tyler Speegle on 9/21/20.
//

#include "PewPew.hpp"

PewPew::PewPew(Player& playerOne) {
    bullet.setRadius(5);
    //sprite.setPointCount();
    bullet.setFillColor(sf::Color(255, 255, 255));
    float xPos = playerOne.getXPosition();
    bullet.setPosition(sf::Vector2f(xPos, 850));
}

