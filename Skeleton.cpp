//
// Created by piero on 11/21/18.
//

#include "Skeleton.h"
#include "TileMap.h"
Skeleton::Skeleton(int Hp, int speed) : Enemy(Hp, speed) {}

void Skeleton::draw(Sprite &Esprite,Texture &Etexture,int x_load, int y_load) {

    Etexture.loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/enemy2cropped.png");

    Esprite.setTexture(Etexture);

    Esprite.setPosition(x_load,y_load);

}






/*void Skeleton::move(Sprite &Esprite, Texture &Etexture, int x_load) {

    TileMap map;

}*/
