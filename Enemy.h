//
// Created by piero on 9/7/18.
//

#ifndef PROJECT_ENEMY_H
#define PROJECT_ENEMY_H

#include "GameCharacter.h"
#include "TileMap.h"
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>


using namespace sf;

class Enemy : public GameCharacter {
public:

    Enemy(int Hp, int speed);

    Enemy();

    virtual ~Enemy();

    virtual void draw(Sprite &spritePlayer) = 0;
    //virtual void move(Sprite &spritePlayer,Texture &texturePlayer, int x_load, int y_load) = 0;

    void randomDirection(Sprite &Esprite, TileMap &map);

    void setPosition(Sprite &Esprite,TileMap map1);

protected:
    int Id;
    int CpuStrategy;
    Clock clockEnemy;
    Time timeEnemy;
    int direction;
    bool didEnemyMove;

};


#endif //PROJECT_ENEMY_H
