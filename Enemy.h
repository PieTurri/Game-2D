//
// Created by piero on 9/7/18.
//

#ifndef PROJECT_ENEMY_H
#define PROJECT_ENEMY_H

#include "GameCharacter.h"
#include "TileBossMap.h"
#include "EnemyStrategy.h"
#include "Hero.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace sf;
using namespace std;

class Enemy : public GameCharacter {
public:

    Enemy(int Hp, int speed);

    Enemy();

    void draw(RenderWindow &window);

    void changeStrategy(Hero *h, TileBossMap *map);

    void moveEnemy(TileBossMap *map);

    void aim(Vector2f heroPos);

    bool hasFiringStrategy();

protected:

    EnemyStrategy* Es;

    bool EnemyEngaged;
};


#endif //PROJECT_ENEMY_H
