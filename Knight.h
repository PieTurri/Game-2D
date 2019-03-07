//
// Created by piero on 10/10/18.
//

#ifndef PROJECT_KNIGHT_H
#define PROJECT_KNIGHT_H

#include "Hero.h"

using namespace std;
using namespace sf;

class Knight : public Hero{
public:

    Knight(int Hp, int speed, bool armor);

    ~Knight();

    void movement(RenderWindow &window);

    void draw(RenderWindow &window, TileMap &map);

    void setDirection();

private:

    bool TypeFoot;

};


#endif //PROJECT_KNIGHT_H
