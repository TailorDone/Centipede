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

class Player {
public:
    Player();
    sf::CircleShape sprite;
    int getCenter();
    void moveLeft(sf::Time dt);
    void moveRight(sf::Time dt);
    void drawPlayer(sf::RenderWindow& window);
private:
//    float xPos;
    
};

#endif /* Player_hpp */
