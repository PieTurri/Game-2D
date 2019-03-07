//
// Created by piero on 11/21/18.
//

#include "Skeleton.h"
#include "TileMap.h"
Skeleton::Skeleton(int Hp, int speed) : Enemy(Hp, speed) {
    texture.loadFromFile("enemy2cropped.png");

    sprite.setTexture(texture);

    sprite.setOrigin(16,16);
}

void Skeleton::draw(RenderWindow &window, TileMap &map) {

    window.draw(sprite);

}


/*void Skeleton::move(Sprite &Esprite, Texture &Etexture, int x_load) {

    TileMap map;

}*/
