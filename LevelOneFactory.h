//
// Created by leogori on 31/03/19.
//

#ifndef PROJECT_LEVELONEFACTORY_H
#define PROJECT_LEVELONEFACTORY_H

#include "Abstract_Factory.h"
#include <iostream>

using namespace std;

class LevelOneFactory :public Abstract_Factory{
public:

    Enemy* createEnemy();

    TileMap* createMap();

    TileBossMap* createBossMap();

};


#endif //PROJECT_LEVELONEFACTORY_H
