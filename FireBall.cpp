//
// Created by leogori on 09/02/19.
//

#include "FireBall.h"
#include <iostream>
#include <cmath>

using namespace std;

FireBall::FireBall(Vector2f pos, Vector2f aimedPos) {

    texture.loadFromFile("fireball2.png");
    sprite.setTexture(texture);

    sprite.setOrigin(16,16);

    sprite.setPosition(pos);
    aimedPoint=aimedPos;

    float angle=atan(aimedPos.y/aimedPos.x)*180/M_PI;

    if(aimedPos.x<0)
        angle+=180;

    sprite.rotate(angle);
}

FireBall::FireBall(int mvmSpd, int dmg) {

}
