#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Mushroom.hpp"
#include "Player.hpp"
#include "PewPew.hpp"

int main()
{
    srand (time(NULL));
    sf::Clock clock;

    // create the window
    sf::RenderWindow window(sf::VideoMode(1250, 1000), "Centipede");
    
    std::vector<std::vector<int>> mushroomGrid;
    createMushrooms(mushroomGrid);
    Player playerOne;

    // run the program as long as the window is open
    while (window.isOpen())
    {
        sf::Time dt = clock.restart();
        
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        

        // clear the window with black color
        window.clear(sf::Color::Black);
        
        
        for (int i = 0; i < mushroomGrid.size(); i++) {
            window.draw(drawMushroom(mushroomGrid[i][0], mushroomGrid[i][1]));
        }
        
        //Player playerOne;
        //Handles Movement of Player
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { // move left...
            if (playerOne.getXPosition() > 0) {
                playerOne.setXPos(-0.4);
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { // move right...
            if (playerOne.getXPosition() < 1190) {
                playerOne.setXPos(0.4);
            }
        }
        
        playerOne.drawPlayer(window);
        
        

        //window.draw(drawPlayer(xPos));
        
        //Shoot pew pew
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
//            window.draw(drawPewPew(**PLAYER**)
//        }
        
        
        

        
        // end the current frame
        window.display();

    }

    return 0;
}
