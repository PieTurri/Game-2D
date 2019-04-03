//
// Created by leogori on 02/04/19.
//

#ifndef PROJECT_BOSSLEVEL_H
#define PROJECT_BOSSLEVEL_H


#include "GraphicState.h"
#include "TileMap.h"
#include "Hero.h"

class BossLevel: public GraphicState {

public:

    BossLevel(Hero *hero, RenderWindow &window);

    void draw(RenderWindow &window);

    void setScreen();

    GraphicState *getNextState(RenderWindow &window);

    void getActivities(Event event,RenderWindow &window);

    void setView(RenderWindow &window);

private:

    TileMap map;

    Hero* hero;

};


#endif //PROJECT_BOSSLEVEL_H
