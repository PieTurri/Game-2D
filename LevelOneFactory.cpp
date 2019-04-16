//
// Created by leogori on 01/04/19.
//

#include "LevelOneFactory.h"

Enemy *LevelOneFactory::createEnemy() {

    Enemy* enemy=new Enemy(4,10);
    enemy->setImage("enemy2cropped.png");

    return enemy;
}

TileMap *LevelOneFactory::createMap() {

    TileMap* map=new TileMap;

    map->setTextFileName("ARCONTUS");

    map->setWall(42);
    map->setCorridorFloor(110);
    map->setFightFloor(111);
    map->setVacuum(478);
    map->setHeroStartingPosition(120);

    map->setTileMap();

    map->setItemsProperty();

    map->load("Tileset1.png",Vector2u(32,32));

    return map;
}

TileBossMap *LevelOneFactory::createBossMap() {

    TileBossMap* map= new TileBossMap;

    map->setWall(1);

    map->setTextFileName("mappaBoss1");

    map->setTileMap();

    map->findDimension();

    map->load("Tileset1.png",Vector2u(32,32));

    return map;
}

Enemy *LevelOneFactory::createBoss() {

    Enemy* enemy=new Enemy(4,10);

    enemy->setImage("enemy2cropped.png");

    enemy->scale(2,2);

    return enemy;
}
