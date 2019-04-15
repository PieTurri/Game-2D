//
// Created by leogori on 14/04/19.
//

#include "BossMap1.h"

BossMap1::BossMap1() {

    setWall(1);

    setTextFileName("mappaBoss");

    setTileMap();

    findDimension();

    load("Tileset1.png",Vector2u(32,32));

}
