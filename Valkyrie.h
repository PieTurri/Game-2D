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

    void draw(Sprite &Vsprite,Texture &Vtexture,int VtypeMove);

    void movement(Sprite &Vsprite,string dir,View &Vview);

private:
    bool TypeFoot = true;
class Valkyrie {
public:
    Valkyrie();
    ~Valkyrie();
};


#endif //PROJECT_VALKYRIE_H
