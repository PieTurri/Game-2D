//
// Created by piero on 9/7/18.
//

#ifndef PROJECT_ENEMY_H
#define PROJECT_ENEMY_H

#include "GameCharacter.h"

class Enemy : public GameCharacter {
public:
    Enemy(int Hp, int speed);

protected:
    int Id;
    int CpuStrategy;

};


#endif //PROJECT_ENEMY_H
