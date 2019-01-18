//
// Created by piero on 11/21/18.
//

#include "Skeleton.h"
#include "TileMap.h"
Skeleton::Skeleton(int Hp, int speed) : Enemy(Hp, speed) {}

void Skeleton::draw(Sprite &Esprite) {

    Etexture.loadFromFile("enemy2cropped.png");

    Esprite.setTexture(Etexture);

}


/*void Skeleton::move(Sprite &Esprite, Texture &Etexture, int x_load) {

    TileMap map;

}*/
