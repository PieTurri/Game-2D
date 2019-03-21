//
// Created by leogori on 09/03/19.
//

#include "EnemySleeping.h"
#include "EnemyAwake.h"

EnemySleeping::EnemySleeping() {

    firingStrategy=false;
}

EnemySleeping::~EnemySleeping() {

}

EnemyStrategy *EnemySleeping::changeStrategy() {
    return new EnemyAwake;
}

void EnemySleeping::setDirection(TileMap &map, Sprite &Esprite) {

    timeEnemy=clockEnemy.getElapsedTime();

    direction=rand()%4;

    if(timeEnemy.asSeconds()>2) {
        updateMovement(map, Esprite);
        if(didEnemyMove)
            clockEnemy.restart();
    }

}