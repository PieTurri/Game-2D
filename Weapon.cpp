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

int Weapon::getDamage() const {
    return damage;
}

void Weapon::setDamage(int Demage) {
    Weapon::damage = Demage;
}

Weapon::~Weapon() {
}

void Weapon::rotate(Event event, RenderWindow &window) {

    View view=window.getView();

    Vector2f size=(Vector2f)window.getSize();

    Vector2f distance=view.getCenter()-getPosition();

    float dy=event.mouseMove.y-(size.y/2)+distance.y;
    float dx=event.mouseMove.x-(size.x/2)+distance.x;

    aimedPoint=Vector2f(dx,dy);

    angle=(float)(atan(dy/dx)*180/PI);

    if(dx<0)
        flip("left");
    else
        flip("right");

    sprite.rotate(angle-aimedAngle);

    aimedAngle=angle;

}

void Weapon::draw(RenderWindow &window, TileMap &map) {

    window.draw(sprite);

    for (int i = 0; i < projectile.size(); i++)
        projectile[i]->draw(window);

    if(!projectile.empty()) {

        vector<Projectile*>::iterator it;

        it = projectile.begin();

        for (int i = 0; i < projectile.size(); i++) {
            projectile[i]->move(map);
            if (projectile[i]->isBrokeUp()) {
                projectile.erase(it);
                i--;
            } else
                it++;
        }
    }
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

void Weapon::fire() {

    times=clock.getElapsedTime();

    if(times.asSeconds()>rateOfFire) {

        projectile.push_back(new FireBall(getPosition(), aimedPoint));
        times = clock.restart();
    }
}

vector<Projectile *> Weapon::getProjectile() {

    return projectile;

}


