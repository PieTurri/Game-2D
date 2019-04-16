//
// Created by piero on 12/5/18.
//

#include "Projectile.h"
#include <iostream>
#include <cmath>
#include "FireBall.h"


using namespace std;


Projectile *Projectile::create(Projectile::type t) {
    switch(t){
        case fire:
            return new FireBall();
        case ice:
            return nullptr;
    }
}

Projectile::Projectile() {

    try {
        if(!texture.loadFromFile("fireball2.png"))
            throw "Impossibile aprire immagine proiettile";
        sprite.setTexture(texture);
    }
    catch (...) {cout<<"Errore caricamento immagini proiettile\n"<<endl;}


    sprite.setOrigin(16,16);

    breakUp=false;
    speed=10;
    damage=2;
}

Projectile::~Projectile() {}

void Projectile::setSpeed(float speed) {

    this->speed=speed;
}

float Projectile::getSpeed() {

    return speed;
}

Vector2f Projectile::getPosition() {

    return sprite.getPosition();
}


void Projectile::move(TileBossMap *map) {

    float l=(float)sqrt(pow(aimedPoint.x,2)+pow(aimedPoint.y,2));

    sprite.move(speed*aimedPoint.x/l,speed*aimedPoint.y/l);

}

void Projectile::draw(RenderWindow &window) {

    window.draw(sprite);

}

bool Projectile::isBrokeUp() {

    return breakUp;
}

int Projectile::getDamage() {
    return damage;
}

void Projectile::setDestroyed() {

    breakUp=true;
}

FloatRect Projectile::getDimension() {

    return sprite.getGlobalBounds();
}

void Projectile::setPosition(Vector2f pos) {

    sprite.setPosition(pos);
}

void Projectile::setAimedPoint(Vector2f pos) {

    aimedPoint=pos;

}

void Projectile::setOrientation() {

    orientation= static_cast<float>(atan(aimedPoint.y / aimedPoint.x) * 180 / M_PI);

    if(aimedPoint.x<0) {
        orientation += 180;
    }

    sprite.rotate(orientation);

}
