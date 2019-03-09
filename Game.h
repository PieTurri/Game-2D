//
// Created by leogori on 21/12/18.
//

#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H

#include "GraphicState.h"
#include "Hero.h"
#include "Enemy.h"
#include <vector>

class Game: public GraphicState {
public:

    //Game();

    Game(int charInd, int levInd,RenderWindow& window);

    void draw(RenderWindow &window) override;

    void setScreen() override ;

    void getActivities(Event e1vent, RenderWindow &window) override;

    GraphicState *getNextState(RenderWindow &window) override;

    void setView(RenderWindow &window) override;

    void lookForCollision();

private:

    int characterIndex;
    int levelIndex;

    TileMap map;

    Hero* hero;
    vector <Enemy*> enemy;

};


#endif //PROJECT_GAME_H
