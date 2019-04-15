//
// Created by piero on 9/7/18.
//

#ifndef PROJECT_ABSTRACT_FACTORY_H
#define PROJECT_ABSTRACT_FACTORY_H

#include <iostream>
#include "TileMap.h"
#include "Enemy.h"

using namespace std;

class Abstract_Factory{
public:

    virtual ~Abstract_Factory(){}

    static Abstract_Factory *create(int index);

    virtual TileMap *createMap() =0;

    virtual Enemy *createEnemy() =0;

    virtual TileBossMap* createBossMap()=0;
};







#endif //PROJECT_ABSTRACT_FACTORY_H
