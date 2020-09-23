//
//  Centipede.cpp
//  groupProject
//
//  Created by Tyler Speegle and Taylor Dunn on 9/22/20.
//

#include "Centipede.hpp"
 
CentipedeSegment::CentipedeSegment(int i){
    if (i == 0){
        segment.setRadius(25);
        segment.setFillColor(sf::Color(0,0,255));
        segment.setPosition(0,0);
    } else {
        segment.setRadius(25);
        segment.setFillColor(sf::Color(255,0,255));
        segment.setPosition(-i * 50, 0);
    }
}

CentipedeSegment Centipede::operator[](int index) const{
    return centipede[index];
}

CentipedeSegment& Centipede::operator[](int index){
    return centipede[index];
}

Centipede::Centipede(){
    for (int i = 0; i < 3; i++) {
        CentipedeSegment buggyBoi(i);
        centipede.push_back(buggyBoi);
        centipede[i].movingRight = true;
    }
}

void Centipede::drawCentipede(sf::RenderWindow& window) {
    for (int i = 0; i < centipede.size(); i++){
        window.draw(centipede[i].segment);
    }
}

void Centipede::move(sf::Time dt) {
    for(int i = 0; i < centipede.size(); i++){
        if (centipede[i].movingRight) {
            if (centipede[i].segment.getPosition().x < 1200)
                centipede[i].moveRight(dt);
            else if (centipede[i].segment.getPosition().x >= 1200) {
                centipede[i].moveDown();
                centipede[i].movingRight = false;
            }
        }
        else if (!centipede[i].movingRight) {
            if (centipede[i].segment.getPosition().x > 0)
                centipede[i].moveLeft(dt);
            else if (centipede[i].segment.getPosition().x <= 0) {
                centipede[i].moveDown();
                centipede[i].movingRight = true;
            }
        }
    }
}

void CentipedeSegment::moveRight(sf::Time dt) {
    sf::Vector2f currentPosition = segment.getPosition();
    segment.move(625 * dt.asSeconds(), 0);
}

void CentipedeSegment::moveLeft(sf::Time dt) {
    sf::Vector2f currentPosition = segment.getPosition();
    segment.move(-625 * dt.asSeconds(), 0);
}

void CentipedeSegment::moveDown() {
        sf::Vector2f currentPosition = segment.getPosition();
        segment.setPosition(currentPosition.x, currentPosition.y + 50);
}
