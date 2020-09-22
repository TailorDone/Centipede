//
//  Player.cpp
//  groupProject
//
//  Created by Tyler Speegle & Taylor Dunn on 9/21/20.
//

#include "Player.hpp"

Player::Player() {
    xPos = 600;
    sprite.setRadius(30);
    sprite.setPointCount(3);
    sprite.setFillColor(sf::Color(254, 127, 156));
    sprite.setPosition(sf::Vector2f(xPos, 900));
}

int Player::getXPosition() {
    return xPos;
}

void Player::setXPos(float newPos) {
    xPos += newPos;
    sprite.setPosition(sf::Vector2f(xPos, 900));
}

void Player::drawPlayer(sf::RenderWindow& window) {
    sprite.setPosition(sf::Vector2f(xPos, 900));
    window.draw(sprite);
}



//sf::CircleShape drawPlayer(int xPos) {
//    sf::CircleShape player(30,3);
//    player.setPosition(sf::Vector2f(xPos, 900));
//    player.setFillColor(sf::Color(254, 127, 156));
//    return player;
//}
