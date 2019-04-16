//
// Created by leogori on 31/03/19.
//

#ifndef PROJECT_LEVELTWOFACTORY_H
#define PROJECT_LEVELTWOFACTORY_H

#include "Abstract_Factory.h"

class LevelTwoFactory : public Abstract_Factory{
public:

    Enemy* createEnemy();

    TileMap* createMap();

    TileBossMap* createBossMap();

    Enemy* createBoss();

};


#endif //PROJECT_LEVELTWOFACTORY_H
