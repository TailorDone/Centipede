//
//  Player.cpp
//  groupProject
//
//  Created by Tyler Speegle & Taylor Dunn on 9/21/20.
//

#include "Player.hpp"

Player::Player() {
    sprite.setRadius(30);
    sprite.setPointCount(3);
    sprite.setFillColor(sf::Color(254, 127, 156));
    sprite.setPosition(sf::Vector2f(600, 900));
}

void Player::drawPlayer(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Player::moveLeft(sf::Time dt) {
    sprite.move(-750 * dt.asSeconds(), 0);
}

void Player::moveRight(sf::Time dt) {
    sprite.move(750 * dt.asSeconds(), 0);
}

int Player::getCenter() {
    return sprite.getPosition().x + 25;
}
