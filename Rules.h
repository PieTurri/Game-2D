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

    void setScreen() override;
    void draw(RenderWindow &window) override;

    void getActivities(Event event,RenderWindow &window) override;

    GraphicState *getNextState(RenderWindow &window) override;

    void setView(RenderWindow &window) override;

private:
    const float width;
    const float height;

    Texture texture,textureWASD[5];
    Sprite sprite,spriteWASD[5];
    Text textRules[5];
    Font font;
};


#endif //PROJECT_RULES_H
