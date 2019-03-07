//
// Created by piero on 11/21/18.
//

#ifndef PROJECT_SKELETON_H
#define PROJECT_SKELETON_H

#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

class Skeleton : public Enemy{
public:

    Skeleton(int Hp, int speed);

    //void draw(Sprite &sprite) override;

   // void move(Sprite &spritePlayer,Texture &texturePlayer, int x_load, int y_load) override;



private:

};




#endif //PROJECT_SKELETON_H
