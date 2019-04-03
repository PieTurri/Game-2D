//
// Created by leogori on 01/04/19.
//
#include "LevelTwoFactory.h"

Enemy *LevelTwoFactory::createEnemy() {

    return new Skeleton(4,10);
}

TileMap *LevelTwoFactory::createMap() {

    return new Mirinthas;
}
