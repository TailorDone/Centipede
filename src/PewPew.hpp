//
//  PewPew.hpp
//  groupProject
//
//  Created by Tyler Speegle on 9/21/20.
//

#ifndef PewPew_hpp
#define PewPew_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Player.hpp"


class PewPew {
public:
    PewPew(Player& playerOne);
    sf::CircleShape bullet;
    
    
private:
    int xPos;
    
};


#endif /* PewPew_hpp */
