//
// Created by piero on 11/21/18.
//

#include "Skeleton.h"
#include "TileMap.h"
Skeleton::Skeleton(int Hp, int speed) : Enemy(Hp, speed) {
    texture.loadFromFile("enemy2cropped.png");
}
/*void Skeleton::draw(Sprite &sprite) {

    texture.loadFromFile("enemy2cropped.png");

    sprite.setTexture(texture);

}*/



/*void Skeleton::move(Sprite &sprite, Texture &texture, int x_load) {

    TileMap map;

}*/
