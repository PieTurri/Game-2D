//
// Created by leogori on 21/12/18.
//

#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H


#include "GraphicState.h"
#include "TileMap.h"
#include "Hero.h"
#include "Abstract_Factory.h"

class Game: public GraphicState {
public:

    Game();

    Game(int charInd, int levInd);

    void draw(RenderWindow &window);

    void setScreen();

    void getActivities(Event event, RenderWindow &window);

    GraphicState* getNextState();


private:

    int characterIndex;
    int levelIndex;

    TileMap map;

    Hero* hero;

};


#endif //PROJECT_GAME_H
