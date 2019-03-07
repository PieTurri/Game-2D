//
// Created by leogori on 21/12/18.
//

#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H

#include "GraphicState.h"
#include "Hero.h"
#include "Enemy.h"
#include "TileMap.h"


class Game: public GraphicState {
public:

    //Game();

    Game(int charInd, int levInd,RenderWindow& window);

    void draw(RenderWindow &window);

    void setScreen();

    void getActivities(Event event, RenderWindow &window);

    GraphicState *getNextState(RenderWindow &window);

    void setView(RenderWindow &window);

    void lookForCollision();

private:

    int characterIndex;
    int levelIndex;

    Hero* hero;
    vector<Enemy*> enemy;

    TileMap map;

};


#endif //PROJECT_GAME_H
