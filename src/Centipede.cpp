//
//  Centipede.cpp
//  groupProject
//
//  Created by Tyler Speegle and Taylor Dunn on 9/22/20.
//

#include "Centipede.hpp"
 
Centipede::Centipede() {
    movingRight = true;
    head.setRadius(25);
    head.setFillColor(sf::Color(0,0,255));
    head.setPosition(0, 0);
    centipedeBody.push_back(head);
    for (int i = 1; i < 10; i++) {
        body.setRadius(25);
        body.setFillColor(sf::Color(255,0,255));
        body.setPosition(-i * 50, 0);
        centipedeBody.push_back(body);
    }
    
}

Centipede::Centipede(int length) {
    //std::vector<sf::CircleShape> centipedeBody;
    head.setRadius(25);
    head.setFillColor(sf::Color(0,0,255));
    head.setPosition(0, 0);
    centipedeBody.push_back(head);
    for (int i = 1; i < length; i++) {
        body.setRadius(25);
        body.setFillColor(sf::Color(255,0,255));
        body.setPosition(-i * 50, 0);
        centipedeBody.push_back(body);
    }
    
}

void Centipede::drawCentipede(sf::RenderWindow& window) {
    for (sf::CircleShape bodyPart : centipedeBody)
        window.draw(bodyPart);
}

void Centipede::move() {
    if (movingRight) {
        if (centipedeBody[0].getPosition().x < 1200)
            moveRight();
        else if (centipedeBody[0].getPosition().x >= 1200) {
            moveDown();
            movingRight = false;
        }
    }
    else if (!movingRight) {
        if (centipedeBody[0].getPosition().x > 0)
            moveLeft();
        else if (centipedeBody[0].getPosition().x <= 0) {
            moveDown();
            movingRight = true;
        }
    }
    
}

void Centipede::moveRight() {
    for (int i = 0; i < centipedeBody.size(); i++) {
        sf::Vector2f currentPosition = centipedeBody[i].getPosition();
        centipedeBody[i].setPosition(currentPosition.x + 0.3, currentPosition.y);
    }
}

void Centipede::moveLeft() {
    for (int i = 0; i < centipedeBody.size(); i++) {
        sf::Vector2f currentPosition = centipedeBody[i].getPosition();
        centipedeBody[i].setPosition(currentPosition.x - 0.3, currentPosition.y);
    }
}

void Centipede::moveDown() {
    for (int i = 0; i < centipedeBody.size(); i++) {
        sf::Vector2f currentPosition = centipedeBody[i].getPosition();
        centipedeBody[i].setPosition(currentPosition.x, currentPosition.y + 50);
    }
}
