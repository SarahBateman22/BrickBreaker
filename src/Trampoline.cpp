//
//  Trampoline.cpp
//  testSFML
//
//  Created by Sarah Bateman on 9/20/23.
//

#include "Trampoline.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>



//TRAMPOLINE--------------------------------------------------

Trampoline::Trampoline(float startX, float startY){
    
    position_.x = startX;
    position_.y = startY;
    
    shape_.setSize(sf::Vector2f(100,8));
    shape_.setFillColor(sf::Color::Green);
    shape_.setOutlineColor(sf::Color::White);
    shape_.setOutlineThickness(1);
    
    shape_.setPosition(position_);
}

sf::FloatRect Trampoline::getBounds(){
    return shape_.getGlobalBounds();
}

sf::Vector2f Trampoline::getPosition(){
    return shape_.getPosition();
}

sf::RectangleShape Trampoline::getshape(){
    return shape_;
}

void Trampoline::moveLeft(){
    float xPos, yPos;
    xPos = shape_.getPosition().x;
    yPos = shape_.getPosition().y;
    shape_.setPosition(xPos-10, yPos);
}

void Trampoline::moveRight(){
    float xPos, yPos;
    xPos = shape_.getPosition().x;
    yPos = shape_.getPosition().y;
    shape_.setPosition(xPos+10, yPos);
}

void Trampoline::move(float x, float y){
    shape_.move(x, y);
}

void Trampoline::stopLeft(){
    TMovingLeft_=false;
}

void Trampoline::stopRight(){
    TMovingRight_=false;
}

void Trampoline::update(sf::Time dt){
    if(TMovingLeft_==true){
        position_.x -= Tspeed_ * dt.asSeconds();
    }
    if(TMovingRight_==true){
        position_.x += Tspeed_ * dt.asSeconds();
    }
    shape_.setPosition(position_);
}

void Trampoline::setPosition(float setX, float setY){
    shape_.setPosition(setX, setY);
}

void Trampoline::Draw(sf::RenderWindow& window) {
  window.draw(shape_);
}

