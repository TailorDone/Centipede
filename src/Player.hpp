//
//  Player.hpp
//  groupProject
//
//  Created by Tyler Speegle & Taylor Dunn on 9/21/20.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

struct Player {
    Player();
    sf::CircleShape sprite;
    void drawPlayer(sf::RenderWindow& window);
    void moveLeft(sf::Time dt);
    void moveRight(sf::Time dt);
    int getCenter();
};

#endif /* Player_hpp */
