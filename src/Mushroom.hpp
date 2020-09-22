//
//  Mushroom.hpp
//  groupProject
//
//  Created by Tyler Speegle on 9/21/20.
//

#ifndef Mushroom_hpp
#define Mushroom_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Mushroom {
public:
    Mushroom(int row, int column);
    sf::RectangleShape sprite;
    int getRow();
    int getColumn();
    
private:
    sf::Vector2f rectSize = {50, 50};
    int row, column;
    int health = 3;
    int red, green, blue;
    
};



#endif /* Mushroom_hpp */
