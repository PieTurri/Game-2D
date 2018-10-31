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

    void movement(Sprite &Ksprite,string dir,View &Kview);


    void draw(Sprite &Ksprite,Texture &Ktexture,int KtypeMove);
private:

    bool TypeFoot=true;
    int i=0;

};


#endif //PROJECT_KNIGHT_H
