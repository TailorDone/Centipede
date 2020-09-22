//
//  PewPew.cpp
//  groupProject
//
//  Created by Tyler Speegle & Taylor Dunn on 9/21/20.
//

#include "PewPew.hpp"

PewPew::PewPew(float startPosition) {
    bullet.setRadius(5);
    bullet.setFillColor(sf::Color(255, 255, 255));
    bullet.setPosition(sf::Vector2f(startPosition, startYPosition));
}

void PewPew::drawBullet(sf::RenderWindow& window) {
    window.draw(bullet);
}

void PewPew::move(){
   bullet.move(0, -1);
}
