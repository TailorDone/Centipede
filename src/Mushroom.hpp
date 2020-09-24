//
//  Mushroom.hpp
//  groupProject
//
//  Created by Tyler Speegle & Taylor Dunn on 9/21/20.
//

#ifndef Mushroom_hpp
#define Mushroom_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "PewPew.hpp"
#include "Collision.hpp"

class Mushroom {
public:
    Mushroom(int column, int row);
    sf::RectangleShape sprite;
    void mushroomHit();
    int getRow();
    int getColumn();
    int getHealth();
private:
    sf::Vector2f rectSize = {50, 50};
    int row, column;
    int health = 3;    
};

#endif /* Mushroom_hpp */
