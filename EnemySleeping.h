//
// Created by piero on 2/22/19.
//

#ifndef PROJECT_ENEMYSLEEPING_H
#define PROJECT_ENEMYSLEEPING_H


#include "TileMap.h"
#include "EnemyStrategy.h"
#include "EnemyAwake.h"


class EnemySleeping : public EnemyStrategy{

public:

    EnemySleeping();

    ~EnemySleeping();

    EnemyStrategy* getState() override;

    void strategyDirection(TileMap &map, Sprite &Esprite) override;

};


#endif //PROJECT_ENEMYSLEEPING_H
