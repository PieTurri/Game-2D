//
// Created by piero on 12/5/18.
//

#include "Projectile.h"
#include <iostream>
#include <cmath>


using namespace std;

Projectile::Projectile() {

    breakUp=false;
    movementSpeed=10;
    damage=2;
}

//Projectile::Projectile(Vector2f pos, Vector2f aimedP) {}

Projectile::~Projectile() {}

void Projectile::setSpeed(float speed) {

    movementSpeed=speed;
}

float Projectile::getSpeed() {

    return movementSpeed;
}

Vector2f Projectile::getPosition() {

    return sprite.getPosition();
}


void Projectile::move(TileMap &map) {

    float l=(float)sqrt(pow(aimedPoint.x,2)+pow(aimedPoint.y,2));

    sprite.move(movementSpeed*aimedPoint.x/l,movementSpeed*aimedPoint.y/l);

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
