//
// Created by piero on 3/28/19.
//

#ifndef PROJECT_PAUSE_H
#define PROJECT_PAUSE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Hero.h"
#include "MyView.h"
#include "GraphicState.h"

using namespace sf;

class Pause: public GraphicState {
public:

    Pause(RenderWindow &window);

    ~Pause();

    void setPosition(RenderWindow &window);

    void draw(RenderWindow &window);

    void getActivities(Event event, RenderWindow &window);

    GraphicState* getNextState(RenderWindow& window);

    void setScreen();

    void setView(RenderWindow& window);

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
