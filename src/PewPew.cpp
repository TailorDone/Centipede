//
//  PewPew.cpp
//  groupProject
//
//  Created by Tyler Speegle & Taylor Dunn on 9/21/20.
//

#include "PewPew.hpp"

PewPew::PewPew() {
    bullet.setRadius(5);
    //sprite.setPointCount();
    bullet.setFillColor(sf::Color(255, 255, 255));
    bullet.setPosition(sf::Vector2f(startXPosition, startYPosition));
}

void PewPew::drawBullet(sf::RenderWindow& window) {
   
    window.draw(bullet);
//    while (startYPosition > 0){
//        startYPosition -= 5;
//        bullet.move(startXPosition, startYPosition);
//        window.draw(bullet);
//    }
}

void PewPew::move(){
   bullet.move(0, -5);
}
