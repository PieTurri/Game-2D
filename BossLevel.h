//
// Created by leogori on 02/04/19.
//

#ifndef PROJECT_BOSSLEVEL_H
#define PROJECT_BOSSLEVEL_H


#include "GraphicState.h"
#include "TileBossMap.h"
#include "Hero.h"
#include "Abstract_Factory.h"
#include "Enemy.h"

class BossLevel: public GraphicState {

public:

    BossLevel(Hero *hero, RenderWindow &window);

    void draw(RenderWindow &window);

    void setScreen();

    GraphicState *getNextState(RenderWindow &window);

    void getActivities(Event event,RenderWindow &window);

    void setView(RenderWindow &window);

    void update();

    Vector2f getRandomPosition();

private:

    TileBossMap* map;

    Abstract_Factory* factory;

    Hero* hero;

    vector <Enemy*> enemy;

    Sprite sprite;
    Texture texture;

    Vector2f pos;

};


#endif //PROJECT_BOSSLEVEL_H
