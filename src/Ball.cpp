//
//  Ball.cpp
//  testSFML
//
//  Created by Sarah Bateman on 9/19/23.
//

#include "Ball.hpp"

Ball::Ball(float startX, float startY)
{
    m_position.x=startX;
    m_position.y=startY;
    ballShape_.setSize(sf::Vector2f(10,10));
    ballShape_.setPosition(m_position);
}

//function to get the position of the ball
sf::FloatRect Ball::getPosition(){
    return ballShape_.getGlobalBounds();
}

sf::RectangleShape Ball::getShape() const{
    return ballShape_;
}

float Ball::getSpeed() const{
    return m_speed;
}

float Ball::getXVelocity(){
    return m_directionx;
}

//bounces off the sides of the walls
void Ball::BounceOffWalls(){
    m_directionx = -m_directionx;
}

//tells us when the ball hits the bottom and if the player "misses"
void Ball::missBottom(){
    m_position.x=400; //put the ball back in the middle of the screen underneath the bricks
    m_position.y=350;
    m_speed = m_speed/2;
}

void Ball::hitBall(){
    m_directiony = -m_directiony;
}

void Ball::hitBricks(){
    m_directionx = - m_directionx;
    m_directiony = - m_directiony;
}

void Ball::update(sf::Time dt){
    //the dt measures time between frames and it allows all computers to run it at the same time - standardizes the movement
    m_position.x += m_directionx*m_speed * dt.asSeconds();
    m_position.y += m_directiony*m_speed * dt.asSeconds();
    //then we set the position to the new position
    ballShape_.setPosition(m_position);
}

void Ball::setPosition(float setX, float setY){
    ballShape_.setPosition(setX, setY);
}
