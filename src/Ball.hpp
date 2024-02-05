//
//  Ball.hpp
//  testSFML
//
//  Created by Sarah Bateman on 9/19/23.
//

#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>



class Ball {
private:
    sf::Vector2f m_position;
    sf::RectangleShape ballShape_;
    float m_speed=500;
    float m_directionx =1.0f;
    float m_directiony = 1.0f;
    
public:
    Ball(float startX, float startY);
    void Move(float startX, float startY);
    sf::FloatRect getPosition();
    sf::RectangleShape getShape()const;
    float getXVelocity();
    float getSpeed() const;
    void setPosition(float setX, float setY);
    void BounceOffWalls();
    void BounceTop();
    void missBottom();
    void hitBall();
    void update(sf::Time dt);
    void hitBricks();
};

#endif /* Ball_hpp */




