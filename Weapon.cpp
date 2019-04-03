//
// Created by piero on 9/5/18.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <string>
#include "FireBall.h"
#include "Weapon.h"

using namespace sf;
using namespace std;

#define PI 3.141592654

Weapon::Weapon() {

    aimedAngle=0;
    isFlipped=false;
}

bool Weapon::isCompatible() const {
    return compatibility;
}

Weapon::~Weapon() {
}

void Weapon::rotate(Vector2f posTarget) {

    float dy=posTarget.y-getPosition().y;
    float dx=posTarget.x-getPosition().x;

    aimedPoint=Vector2f(dx,dy);

    angle=(float)(atan(dy/dx)*180/PI);

    if(dx<0)
        flip("left");
    else
        flip("right");

    sprite.rotate(angle-aimedAngle);

    aimedAngle=angle;

}

void Weapon::draw(RenderWindow &window) {

    window.draw(sprite);
}

void Weapon::move(float x, float y) {

    sprite.move(x,y);

}

Vector2f Weapon::getPosition() {

    return sprite.getPosition();
}

void Weapon::flip(String dir) {

    Vector2u size=texture.getSize();

    if(dir=="left"&&!isFlipped) {

        sprite.setTextureRect(IntRect(size.x, 0, -size.x, size.y));
        isFlipped = true;
    }
    else if(dir=="right"&&isFlipped){
        sprite.setTextureRect(IntRect(0, 0, size.x, size.y));
        isFlipped = false;
    }

}

float Weapon::getRateOfFire() {
    return rateOfFire;
}

Vector2f Weapon::getAimedPoint() {
    return aimedPoint;
}

void Weapon::setPosition(Vector2f pos) {

    sprite.setPosition(pos);
}

void Weapon::setRateOfFire(float rateOfFire) {
    this->rateOfFire = rateOfFire;
}



