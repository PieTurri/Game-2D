//
// Created by piero on 9/28/18.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GraphicState.h"

#ifndef PROJECT_RULES_H
#define PROJECT_RULES_H

using namespace sf;
//using namespace std;

class Rules: public GraphicState {
public:
    Rules(RenderWindow &window);

    Rules(float w, float h, RenderWindow &window);

    ~Rules();

    void setScreen();
    void draw(RenderWindow &window);

    void getActivities(Event event,RenderWindow &window);

    GraphicState *getNextState(RenderWindow &window);

    virtual void setView(RenderWindow &window);

private:
    const float width;
    const float height;

    Texture texture;
    Sprite sprite;
    Text textRules[3];
    Font font;
};


#endif //PROJECT_RULES_H
