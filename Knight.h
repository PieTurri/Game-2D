//
// Created by piero on 10/10/18.
//

#ifndef PROJECT_KNIGHT_H
#define PROJECT_KNIGHT_H

#include <iostream>

using namespace std;

#include "Hero.h"

class Knight : public Hero{
public:
    Knight(int Hp, int speed, bool armor);

    ~Knight();


};


#endif //PROJECT_KNIGHT_H
