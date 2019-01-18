//
// Created by piero on 10/10/18.
//

#ifndef PROJECT_KNIGHT_H
#define PROJECT_KNIGHT_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "TileMap.h"

using namespace std;
using namespace sf;

#include "Hero.h"

class Knight : public Hero{
public:
    Knight(int Hp, int speed, bool armor);

    ~Knight();

    void movement(RenderWindow &window);


    void draw(RenderWindow &window);

    void setDirection();

    //void fire(Sprite &spriteFire, Texture &textureFire);

private:

    bool TypeFoot;

    Texture Ktexture;

    Sprite Ksprite;
};


#endif //PROJECT_KNIGHT_H
