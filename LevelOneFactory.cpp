//
// Created by leogori on 01/04/19.
//

#include "LevelOneFactory.h"
#include "Skeleton.h"
#include "Arcontus.h"
#include "BossMap1.h"

Enemy *LevelOneFactory::createEnemy() {

    return new Skeleton(8,6);
}

TileMap *LevelOneFactory::createMap() {

    return new Arcontus;
}

TileBossMap *LevelOneFactory::createBossMap() {

    return new BossMap1;
}
