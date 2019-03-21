//
// Created by piero on 12/5/18.
//

#include "Projectile.h"
#include <iostream>
#include <cmath>


using namespace std;

Projectile::Projectile() {}

Projectile::Projectile(Vector2f pos, Vector2f aimedPos) {

    texture.loadFromFile("fireball2.png");
    sprite.setTexture(texture);

    sprite.setOrigin(16,16);

    aimedPoint=aimedPos;

    /*float increment=(float)sqrt(pow(16,2)+pow(16,2));
    float l=(float)sqrt(pow(aimedPoint.x,2)+pow(aimedPoint.y,2));

    sprite.setPosition(pos+Vector2f(increment*aimedPos.x/l,aimedPos.y*increment/l));*/

    sprite.setPosition(pos);

    float angle= static_cast<float>(atan(aimedPos.y / aimedPos.x) * 180 / M_PI);

    if(aimedPos.x<0) {
        angle += 180;
    }

    sprite.rotate(angle);

    breakUp=false;
    movementSpeed=10;
    damage=2;
}

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

FloatRect Projectile::getDimension() {

    return sprite.getGlobalBounds();
}
