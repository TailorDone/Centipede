//
//  PewPew.cpp
//  groupProject
//
//  Created by Tyler Speegle & Taylor Dunn on 9/21/20.
//

#include "PewPew.hpp"
#include <iostream>

PewPew::PewPew(float startPosition) {
    bullet.setRadius(5);
    bullet.setFillColor(sf::Color(255, 255, 255));
    bullet.setPosition(sf::Vector2f(startPosition, 890));
}

void PewPew::drawBullet(sf::RenderWindow& window) {
    window.draw(bullet);
}

float PewPew::getYPosition() {
    return YPosition;
}

void PewPew::setYPosition(float value) {
    YPosition = value;
}

void PewPew::move(sf::Time dt){
    bullet.move(0, (-1000 * dt.asSeconds()));
}

void PewPew::removePewPews(std::vector<PewPew>& firedShots, int& bulletCount){
    if (bulletCount == 10){
        firedShots.erase(firedShots.begin());
        bulletCount--;
    }
}
