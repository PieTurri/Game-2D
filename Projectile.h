//
// Created by piero on 12/5/18.
//

#ifndef PROJECT_PROJECTILE_H
#define PROJECT_PROJECTILE_H


#include "MenuLoop.h"

class Projectile  {
public:
    int movementSpeed = 10;
    int attackDamage = 5;

    Projectile();
    sf::Sprite fireS;
    sf::Text fireT;

};


#endif //PROJECT_PROJECTILE_H
