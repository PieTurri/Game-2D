//
// Created by piero on 10/10/18.
//

#ifndef PROJECT_VALKYRIE_H
#define PROJECT_VALKYRIE_H


#include "Hero.h"

class Valkyrie : public Hero{
public:

    Valkyrie(int Hp,int speed, bool armor);
    ~Valkyrie();

    void draw(RenderWindow &window);

    void movement(RenderWindow &window);

    void setDirection();

private:
    bool TypeFoot = true;
    Texture Vtexture;
    Sprite Vsprite;
};


#endif //PROJECT_VALKYRIE_H
