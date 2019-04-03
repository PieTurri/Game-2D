//
// Created by piero on 10/10/18.
//

#include "Knight.h"
#include <cmath>

Knight::Knight(int Hp, int speed, bool armor) : Hero(Hp, speed, armor) {

    texture.loadFromFile("npc3_fr1.png");
    sprite.setTexture(texture);
}

Knight::~Knight() = default;

void Knight::setDirection() {//void useWeapon(Sprite &spriteFire, Texture &textureFire);
    try {

        if (moveD&&!moveL&&!moveR&&!moveU) {

            if (TypeFoot) {
                if(!texture.loadFromFile("npc3_fr1.png"))
                    throw "Impossibile aprire immagine 1 ";
                TypeFoot = false;
            }
            else{
                if(!texture.loadFromFile("npc3_fr2.png"))
                    throw "Impossibile aprire immagine 2 ";
                TypeFoot = true;
            }

        }

        if (moveU&&!moveL&&!moveR&&!moveD) {

            if (TypeFoot) {
                if(!texture.loadFromFile("npc3_fr1.png"))
                    throw "Impossibile aprire immagine 1 ";
                TypeFoot = false;
            }
            else{
                texture.loadFromFile("npc3_fr2.png");
                TypeFoot = true;
            }

        }

        if (moveL&&!moveR) {

            if (TypeFoot) {
                texture.loadFromFile("npc3_lf1.png");
                TypeFoot = false;
            }
            else{
                texture.loadFromFile("npc3_lf2.png");
                TypeFoot = true;
            }

        }

        if (moveR&&!moveL) {

            if (TypeFoot) {
                texture.loadFromFile("npc3_rt1.png");
                TypeFoot = false;
            }
            else{
                texture.loadFromFile("npc3_rt2.png");
                TypeFoot = true;
            }

        }

        sprite.setTexture(texture);

    }
    catch  (...){"Impossibile aprire immagini cavaliere";}
}









