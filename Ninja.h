//
// Created by piero on 10/10/18.
//

#ifndef PROJECT_NINJA_H
#define PROJECT_NINJA_H

#include "Hero.h"

class Ninja : public Hero{
public:
    Ninja(int Hp, int speed, bool armor);

    ~Ninja();
};


#endif //PROJECT_NINJA_H
