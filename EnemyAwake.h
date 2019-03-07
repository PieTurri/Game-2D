//
// Created by piero on 2/22/19.
//

#ifndef PROJECT_ENEMYAWAKE_H
#define PROJECT_ENEMYAWAKE_H


#include "EnemyStrategy.h"
#include "EnemySleeping.h"

class EnemyAwake: public EnemyStrategy {
public:
    EnemyAwake();

    ~EnemyAwake();

    EnemyStrategy * getState() override;

    void strategyDirection(TileMap &map, Sprite &sprite) override;

};


#endif //PROJECT_ENEMYAWAKE_H
