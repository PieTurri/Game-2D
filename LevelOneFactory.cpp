//
// Created by leogori on 01/04/19.
//

#include "LevelOneFactory.h"

Enemy *LevelOneFactory::createEnemy() {

    return new Skeleton(8,6);
}

TileMap *LevelOneFactory::createMap() {

    return new Arcontus;
}
