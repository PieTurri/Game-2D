//
// Created by piero on 2/22/19.
//

#ifndef PROJECT_ENEMYAWAKE_H
#define PROJECT_ENEMYAWAKE_H


#include "EnemyStrategy.h"
#include "EnemySleeping.h"
#include "Hero.h"

class EnemyAwake: public EnemyStrategy {
public:
    EnemyAwake();

    ~EnemyAwake();

    EnemyStrategy * changeStrategy() override;

    void setDirection(TileMap *map, Sprite &sprite) override;


    void upgradeMovementLocked(TileMap &map, Sprite &sprite, Hero *h);

};


#endif //PROJECT_ENEMYAWAKE_H
