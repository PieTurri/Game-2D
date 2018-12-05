//
// Created by piero on 9/7/18.
//

#include "Enemy.h"
#include "TileMap.h"
#include <iostream>
using namespace std;

Enemy::Enemy(int Hp, int speed) : GameCharacter(Hp, speed) {}

Enemy::Enemy() {}

Enemy::~Enemy() {}

void Enemy::randomDirection(int &direction) { //tirare fuori dal ctime

    int preistoricDirection = direction;

    do{

        srand(unsigned(time(NULL)));
        direction = rand() % 4;

    }while(direction == preistoricDirection);

}

void Enemy::setPosition(Sprite &Esprite, TileMap map1) {

    srand(unsigned(time(NULL)));
    int casualPos = rand() % 225;

    int Posx = casualPos % 15;
    int Posy = (casualPos - Posx)/15;

    for(int i = 0; i < 9;i ++){

        if(map1.fightRooms)

    }

}



