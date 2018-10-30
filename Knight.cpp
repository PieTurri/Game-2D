//
// Created by piero on 10/10/18.
//

#include "Knight.h"

#include "MenuLoop.h"

using namespace sf;


Knight::Knight(int Hp, int speed, bool armor) : Hero(Hp, speed, armor) {}

Knight::~Knight() {}

void Knight::movement(int PosX, int PosY) {
/*

    if(!texturePlayer.loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/SoldierWalk.png"))
        cout << "ERRORE" << endl;

    spriteplayer(texturePlayer);

    spritePlayer.setPosition(ml.window.getSize().x/2,ml.window.getSize().y/2);
    spritePlayer.setTextureRect(IntRect(0,64*2,64,64));


    if(Keyboard::isKeyPressed(Keyboard::Right)){

        spritePlayer.move(playerMovmentSpeed,0);
        spritePlayer.setTextureRect(IntRect(64*passoUp,64*3,64,64));


    }
    if(Keyboard::isKeyPressed(Keyboard::Left)){

        spritePlayer.move(-playerMovmentSpeed,0);
        spritePlayer.setTextureRect(IntRect(64*passoUp,64,64,64));


    }
    if(Keyboard::isKeyPressed(Keyboard::Up)){

        spritePlayer.move(0,-playerMovmentSpeed);
        spritePlayer.setTextureRect(IntRect(64*passoUp,0,64,64));


    }
    if(Keyboard::isKeyPressed(Keyboard::Down)){

        spritePlayer.move(0,playerMovmentSpeed);
        spritePlayer.setTextureRect(IntRect(64*passoUp,64*2,64,64));

    }

    passoUp++;
    if(passoUp == 9)
        passoUp = 0;

*/

}


