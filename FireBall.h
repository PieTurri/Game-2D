//
// Created by leogori on 09/02/19.
//

#ifndef PROJECT_FIREBALL_H
#define PROJECT_FIREBALL_H


#include "Projectile.h"

class FireBall: public Projectile {

public:
    FireBall(Vector2f pos, Vector2f aimedPos);

    FireBall(int mvmSpd, int dmg);

private:

};


#endif //PROJECT_FIREBALL_H
