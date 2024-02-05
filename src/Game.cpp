//
//  Game.cpp
//  testSFML
//
//  Created by Sarah Bateman on 9/19/23.
//

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>
#include "Ball.hpp"
#include "Game.hpp"
#include "Bricks.hpp"
#include "Test.hpp"
#include <vector>


void runGame(){
    //initialize ball
    Ball myBall(300, 400);

    //initialize trampoline
    Trampoline myTrampoline(450, 570);
    
    //initialize Game Over Sprite
    sf::Sprite gameOver;
    
    sf::Texture texture;
        if(!texture.loadFromFile("../art/GameOver.jpg", sf::IntRect(50, 0, 800, 600)))
            {
                std::cout << "texture failure";
            }
        
    gameOver.setTexture(texture);

    //initialize bounce timer
    float bounceTimer = 0.10f;
    
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    //----------------TIME FOR THE BALL----------
    //need a clock to run the time of the ball
    sf::Clock clock;
    sf::Time dt;
    
    //initialize the bricks vector for the first level
    //std::vector<sf::RectangleShape> bricksVec = exampleLevel();
    std::vector<sf::RectangleShape> bricksVec = levelOneBricks();
    //std::vector<sf::RectangleShape> bricksVec = levelTwoBricks();
        
    // run the program as long as the window is open
    while (window.isOpen())
    {
        dt = clock.restart();
        bounceTimer -= dt.asSeconds();
        
        // clear the window with black color
        window.clear(sf::Color::Black);
        
        
        
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            
        }
        
        //makes the ball bounce off the trampoline when they collide
        if (myBall.getPosition().intersects(myTrampoline.getBounds())){
            
            if(bounceTimer<0){
                myBall.hitBall();
                bounceTimer=0.10f;
            }
        }
        
        //this makes the ball move, as it updated by dt (time). this is made into seconds in the function update
        myBall.update(dt);

        //controls for if the ball hits the end of the screen on either the right or left sides
        if (myBall.getPosition().left<0 || (myBall.getPosition().left +myBall.getPosition().width)>800){
            myBall.BounceOffWalls();
        }
        //controls for if the ball hits the top of the screen
        if(myBall.getPosition().top<0){
            myBall.hitBall();
        }
        
        //controls for when the ball goes below the sdcreen aka the player lost! ball respawns to old location. probably will want to change this when we get a reset button
        if(myBall.getPosition().top + myBall.getPosition().height > 610){
            myBall.missBottom();
        }
    
    
        //if left key is hit move tramp left
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                    if(myTrampoline.getPosition().x > 0){
                        myTrampoline.move(-0.1, 0);
                    }
                }
        
        //if right key is hit move tramp right
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                    if(myTrampoline.getPosition().x < 700){
                        myTrampoline.move(0.1, 0);
                    }
                }
              
        //if the ball hits a brick that brick should disappear
        for(int i =0; i < bricksVec.size(); i++){
            if(myBall.getPosition().intersects(bricksVec[i].getGlobalBounds())){
                bricksVec.erase(bricksVec.begin()+i);
                //if(bounceTimer<0)
                    myBall.hitBricks();
                    bounceTimer=0.10f;
            }
        }
             
        
        //draw everything on the screen
        for(int i =0; i < bricksVec.size(); i++){
            window.draw(bricksVec[i]);
        }
        window.draw(myBall.getShape());
        window.draw(myTrampoline.getshape());
        
        //when the player beats the game show the game over sprite
        if(bricksVec.size() == 0){
        window.draw(gameOver);
        }
            
            // end the current frame
            window.display();
        }
        
}
