//
// Created by piero on 3/29/19.
//

#ifndef PROJECT_HEART_H
#define PROJECT_HEART_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Hero.h"

using namespace sf;
using namespace std;

class Heart {
public:
    Heart();
    ~Heart();

    void setHeart(RenderWindow &window, Hero *hero, View view);
    void draw(RenderWindow &window);

protected:
    Texture heartT;
    vector <Sprite> heartS;
    Vector2f size;
    Vector2f distanceHeart;

};


#endif //PROJECT_HEART_H
