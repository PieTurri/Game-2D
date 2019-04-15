//
// Created by leogori on 01/04/19.
//
#include "LevelTwoFactory.h"
#include "Skeleton.h"
#include "Mirinthas.h"
#include "BossMap1.h"

Enemy *LevelTwoFactory::createEnemy() {

    return new Skeleton(4,10);
}

TileMap *LevelTwoFactory::createMap() {

    return new Mirinthas;
}

TileBossMap *LevelTwoFactory::createBossMap() {

    return new BossMap1;
}

