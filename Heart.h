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

    void setHeart(RenderWindow &window);

    void setHeroLife(int life);

    int getHeroLife();

    void draw(RenderWindow &window);

    void update(int life);

    void removeHeart();

protected:
    Texture heartT;
    vector <Sprite> heartS;

    int heroLife;
    int number;

    Vector2f size;
    Vector2f distanceHeart;

};


#endif //PROJECT_HEART_H
