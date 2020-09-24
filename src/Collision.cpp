//
//  Collision.cpp
//  groupProject
//
//  Created by Tyler Speegle and Taylor Dunn on 9/22/20.
//

#include <SFML/Graphics.hpp>
#include "Collision.hpp"
#include <cmath>

 
bool CollisionTest(const sf::Shape& Object1, const sf::Shape& Object2) {
 
    sf::FloatRect one = Object1.getGlobalBounds();
    sf::FloatRect two = Object2.getGlobalBounds();
    return (one.intersects(two));
}
