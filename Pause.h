//
// Created by piero on 3/28/19.
//

#ifndef PROJECT_PAUSE_H
#define PROJECT_PAUSE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Hero.h"
#include "MyView.h"

using namespace sf;

class Pause {
public:

    Pause();
    ~Pause();

    void setMenuPause(RenderWindow &window);
    void draw(RenderWindow &window);
    void moveMenu(RenderWindow &window, Event event);
    void MoveUp();
    void MoveDown();
protected:
    Text text[3];
    Font font;
    Event event;

    float width;
    float height;

    int selectedTextIndex=0;

    Vector2i size;

};


#endif //PROJECT_PAUSE_H
