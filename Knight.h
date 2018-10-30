//
// Created by piero on 10/10/18.
//

#ifndef PROJECT_KNIGHT_H
#define PROJECT_KNIGHT_H

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#include "Hero.h"

class Knight : public Hero{
public:
    Knight(int Hp, int speed, bool armor);

    ~Knight();


    void movement(int PosX, int PosY);
protected:

    float playerMovmentSpeed=0.3;
    int passoUp=0;
    Texture texturePlayer;


    //inserisco la texure in una sprite...

    Sprite spritePlayer;


};


#endif //PROJECT_KNIGHT_H
