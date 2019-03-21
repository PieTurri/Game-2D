//
// Created by piero on 10/10/18.
//

#include "Valkyrie.h"

Valkyrie::Valkyrie(int Hp, int speed, bool armor) : Hero(Hp, speed, armor) {

    texture.loadFromFile("npc4_fr1.gif");
    sprite.setTexture(texture);

}

Valkyrie::~Valkyrie() {}

void Valkyrie::setDirection() {

    if (moveD&&!moveL&&!moveR&&!moveU) {

        if (TypeFoot) {
            texture.loadFromFile("npc4_fr1.gif");
            TypeFoot = false;
        }
        else{
            texture.loadFromFile("npc4_fr2.gif");
            TypeFoot = true;
        }

    }

    if (moveU&&!moveL&&!moveR&&!moveD) {

        if (TypeFoot) {
            texture.loadFromFile("npc4_bk1.gif");
            TypeFoot = false;
        }
        else{
            texture.loadFromFile("npc4_bk2.gif");
            TypeFoot = true;
        }

    }

    if (moveL&&!moveR) {

        if (TypeFoot) {
            texture.loadFromFile("npc4_lf1.gif");
            TypeFoot = false;
        }
        else{
            texture.loadFromFile("npc4_lf2.gif");
            TypeFoot = true;
        }

    }

    if (moveR&&!moveL) {

        if (TypeFoot) {
            texture.loadFromFile("npc4_rt1.gif");
            TypeFoot = false;
        }
        else{
            texture.loadFromFile("npc4_rt2.gif");
            TypeFoot = true;
        }

    }

    sprite.setTexture(texture);

}


