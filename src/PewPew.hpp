//
//  PewPew.hpp
//  groupProject
//
//  Created by Tyler Speegle & Taylor Dunn on 9/21/20.
//

#ifndef PewPew_hpp
#define PewPew_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Player.hpp"


class PewPew {
public:
    PewPew(float startPosition);
    sf::CircleShape bullet;
    int startXPosition;
    float getYPosition();
    void setYPosition(float value);
    void drawBullet(sf::RenderWindow& window);
    void move(sf::Time dt);
    void removePewPews(std::vector<PewPew>& firedShots, int& bulletCount);
private:
    int YPosition;
    
    
};


#endif /* PewPew_hpp */
