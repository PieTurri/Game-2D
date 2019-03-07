//
// Created by piero on 9/7/18.
//

#ifndef PROJECT_ENEMY_H
#define PROJECT_ENEMY_H

#include "GameCharacter.h"
#include "TileMap.h"
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

    void draw(RenderWindow &window, TileMap &map) override;

    void changeStrategy(Hero *h, TileMap &map);

    void setPosition(TileMap &map);

    void moveEnemy(TileMap &map);

    void controlTarget();

protected:


    EnemyStrategy* Es;

    float r;

    int pos;
    int Posx;
    int Posy;

    bool EnemyEngaged = false;
    bool EnemyContol;
};


#endif //PROJECT_ENEMY_H
