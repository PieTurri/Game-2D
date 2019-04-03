//
// Created by piero on 3/27/19.
//

#ifndef PROJECT_ACHIEVEMENT_H
#define PROJECT_ACHIEVEMENT_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GraphicState.h"

using namespace sf;

class Achievement : public GraphicState{
public:

    Achievement(RenderWindow& window);

    Achievement( float width, float height);

    void setScreen() override;
    void draw(RenderWindow &window) override;

    void getActivities(Event event,RenderWindow &window);

    GraphicState *getNextState(RenderWindow &window);

    void setView(RenderWindow &window) override;



protected:

    const float width;
    const float height;

    Texture texture;
    Sprite sprite;
    Text text;
    Font font;

};


#endif //PROJECT_ACHIEVEMENT_H
