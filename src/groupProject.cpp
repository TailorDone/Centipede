#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>
#include "Mushroom.hpp"
#include "MushroomGrid.hpp"
#include "Player.hpp"
#include "PewPew.hpp"
#include "Centipede.hpp"
#include "Collision.hpp"
#include "catch.hpp"



int main()
{
    srand (time(NULL));
    sf::Clock clock;
    // create the window
    sf::RenderWindow window(sf::VideoMode(1250, 1000), "Centipede");
    window.setFramerateLimit(60);

    //loading sounds
    sf::SoundBuffer buffer;
    buffer.loadFromFile("pew.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setVolume(10);

    sf::SoundBuffer buffer2;
    buffer2.loadFromFile("Chiptronical.ogg");
    sf::Sound backgroundMusic;
    backgroundMusic.setBuffer(buffer2);
    backgroundMusic.setVolume(10);
    backgroundMusic.setLoop(true);
    backgroundMusic.play();
    
    //loading images
    sf::Image startScreenImage;
    startScreenImage.loadFromFile("StartScreen.png");
    sf::Texture startScreenTexture;
    startScreenTexture.loadFromImage(startScreenImage);
    
    sf::Image loseScreenImage;
    loseScreenImage.loadFromFile("GameOver.png");
    sf::Texture loseScreenTexture;
    loseScreenTexture.loadFromImage(loseScreenImage);
    
    sf::Image winScreenImage;
    winScreenImage.loadFromFile("YouWin.png");
    sf::Texture winScreenTexture;
    winScreenTexture.loadFromImage(winScreenImage);

    //loading game class variables
    MushroomGrid mushroomGrid;
    int difficultyLevel = 5;
    Centipede centipede;
    Centipede centipedeReset;
    Player playerOne;
    std::vector<PewPew> firedShot;
    std::vector<PewPew> clearBullets;
    int bulletCount = 0;
    bool gameStarted = false;
    bool youLose = false;
    bool youWin = false;
    
    // run the program as long as the window is open
    while (window.isOpen())
    {
        
        sf::Time dt = clock.restart();

        if (gameStarted == false) {
            sf::RectangleShape screen({1250, 1000});
            screen.setTexture(&startScreenTexture);
            window.draw(screen);
            sf::Event event;
            while (window.pollEvent(event)) {
                window.setKeyRepeatEnabled(false);
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Enter)
                        gameStarted = true;
                }
            }
        }
        
        //display lose screen
        else if (youLose == true) {
            sf::RectangleShape screen({1250, 1000});
            screen.setTexture(&loseScreenTexture);
            window.draw(screen);
            sf::Event event;
            while (window.pollEvent(event)) {
                window.setKeyRepeatEnabled(false);
                if (event.type == sf::Event::Closed)
                    window.close();
                //replace this with button click
//                if (event.type == sf::Event::KeyPressed) {
//                    if (event.key.code == sf::Keyboard::Enter) {
//                        youLose = false;
//                        difficultyLevel = 5;
//                        centipedeReset.setBodyLength(difficultyLevel);
//                        centipede = centipedeReset;
//                    }
//                }
            }
        }
        
        //display victory screen
        else if (youWin == true) {
            sf::RectangleShape screen({1250, 1000});
            screen.setTexture(&winScreenTexture);
            window.draw(screen);
            sf::Event event;
            while (window.pollEvent(event)) {
                window.setKeyRepeatEnabled(false);
                if (event.type == sf::Event::Closed)
                    window.close();
            //add "try again" button click
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Enter) {
                        youWin = false;
                        firedShot = clearBullets;
                        bulletCount = 0;
                        difficultyLevel += 2;
                        centipedeReset.setBodyLength(difficultyLevel);
                        centipede = centipedeReset;
                        mushroomGrid.respawn();
                    }
                }
            }
        }
            
        else {
            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event;
            while (window.pollEvent(event)) {
                window.setKeyRepeatEnabled(false);
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    window.close();
                
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Space && bulletCount < 26) {
                        float startPosition = playerOne.getCenter();
                        PewPew newBullet(startPosition);
                        sound.play();
                        firedShot.push_back(newBullet);
                        bulletCount++;
                    }
                }
            }
        
            // clear the window with black color
            window.clear(sf::Color::Black);
            
            mushroomGrid.drawMushrooms(window);
            
            //Player playerOne;
            //Handles Movement of Player
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { // move left...
                if (playerOne.sprite.getPosition().x > 0) {
                    playerOne.moveLeft(dt);
                }
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { // move right...
                if (playerOne.sprite.getPosition().x < 1190) {
                    playerOne.moveRight(dt);
                }
            }
            
            playerOne.drawPlayer(window);
            
            centipede.move(mushroomGrid);
            centipede.drawCentipede(window);

            

            for (int i = 0; i < firedShot.size(); i++){
                firedShot[i].move(dt);
                firedShot[i].removePewPews(firedShot, bulletCount);
                firedShot[i].drawBullet(window);
                for (int j = 0; j < mushroomGrid.getSize(); j++){
                    if (CollisionTest(mushroomGrid[j].sprite, firedShot[i].bullet)){
                        firedShot.erase(firedShot.begin() + i);
                        bulletCount--;
                        mushroomGrid[j].mushroomHit();
                        if (mushroomGrid[j].getHealth() == 0) {
                            mushroomGrid[j].sprite.setPosition(sf::Vector2f(-1 * 50, -1 * 50));
                        }
                    }
                }
                if (CollisionTest(centipede[0].segment, firedShot[i].bullet)){
                    firedShot.erase(firedShot.begin() + i);
                    bulletCount--;
                    centipede.centipede.pop_back();
                    centipede.setBodyLength(centipede.getBodyLength()-1);
                }
            }
            
            //check if you win! :)
            if (centipede.centipede.size() == 0) {
                youWin = true;
            }

            //check if centipede is on player row. If so, you lose :(
            if (centipede.centipede[0].segment.getPosition().y == 900) {
                youLose = true;
            }
                
        }
        // end the current frame
        window.display();
        
    }
    

    return 0;
}
