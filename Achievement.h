//
// Created by piero on 3/27/19.
//

#ifndef PROJECT_ACHIEVEMENT_H
#define PROJECT_ACHIEVEMENT_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObserver.h"

using namespace sf;
using namespace std;

class Achievement : public GraphicState{
public:

    Achievement();

    Achievement(RenderWindow& window);

    void setScreen() override;

    void draw(RenderWindow &window) override;

    void getActivities(Event event,RenderWindow &window);

    GraphicState *getNextState(RenderWindow &window);

    void setView(RenderWindow &window) override;

    int setGameObserver(GameObserver gameObs);

protected:

    unsigned int width;
    unsigned int height;

    GameObserver* gameObserver;

    Texture texture;
    Sprite sprite;
    Text text;
    Font font;

};


#endif //PROJECT_ACHIEVEMENT_H
