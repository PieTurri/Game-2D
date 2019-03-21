//
// Created by leogori on 09/02/19.
//

#include "Kalashnikov.h"

Kalashnikov::Kalashnikov() {

    texture.loadFromFile("gun.png");
    sprite.setTexture(texture);
    sprite.scale(0.10,0.10);
    sprite.setOrigin(200,200);
    rateOfFire=0.5;

}