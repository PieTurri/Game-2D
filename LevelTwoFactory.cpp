//
// Created by leogori on 01/04/19.
//
#include "LevelTwoFactory.h"

Enemy *LevelTwoFactory::createEnemy() {

    Enemy* enemy=new Enemy(4,10);
    enemy->setImage("enemy2cropped.png");

    return enemy;
}

TileMap *LevelTwoFactory::createMap() {

    TileMap* map=new TileMap;

    map->setTextFileName("MIRINTHAS");

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

TileBossMap *LevelTwoFactory::createBossMap() {

    TileBossMap* map= new TileBossMap;

    map->setWall(1);

    map->setTextFileName("mappaBoss2");

    map->setTileMap();

    map->findDimension();

    map->load("Tileset1.png",Vector2u(32,32));

    return map;
}

Enemy *LevelTwoFactory::createBoss() {

    Enemy* enemy=new Enemy(4,10);

    enemy->setImage("enemy2cropped.png");

    enemy->scale(2,2);

    return enemy;

}

