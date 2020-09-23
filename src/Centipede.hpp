//
//  Centipede.hpp
//  groupProject
//
//  Created by Tyler Speegle on 9/22/20.
//

#ifndef Centipede_hpp
#define Centipede_hpp

#include <stdio.h>
#include <vector>
#include <SFML/Graphics.hpp>


class Centipede {
public:
    Centipede();
    Centipede(int length);
    std::vector<sf::CircleShape> centipedeBody;
    void drawCentipede(sf::RenderWindow& window);
    void move(sf::Time dt);
    void moveRight(sf::Time dt);
    void moveLeft(sf::Time dt);
    void moveDown();
private:
    int bodyLength = 10;
    bool movingRight;
    sf::CircleShape head;
    sf::CircleShape body;
    
};

#endif /* Centipede_hpp */
