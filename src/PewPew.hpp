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
    PewPew();
    sf::CircleShape bullet;
    int startXPosition;
    int startYPosition = 890;
    void drawBullet(sf::RenderWindow& window);
    void move();
    //TODO get start position
private:
    
    
};


#endif /* PewPew_hpp */
