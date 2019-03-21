//
// Created by piero on 11/21/18.
//

#include "Skeleton.h"
#include "TileMap.h"

Skeleton::Skeleton(int Hp, int speed) : Enemy(Hp, speed) {

    texture.loadFromFile("enemy2cropped.png");
    sprite.setTexture(texture);
}
