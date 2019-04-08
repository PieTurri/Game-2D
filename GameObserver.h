//
// Created by leogori on 07/04/19.
//

#ifndef PROJECT_GAMEOBSERVER_H
#define PROJECT_GAMEOBSERVER_H

#include "Observer.h"
#include "Game.h"

class GameObserver:public Observer {

public:

    GameObserver();

    void update(Subject *s);

    void setSubject(GraphicState *subject);

    int getEnemyDefeated();

    int getNumberOfEnemy();

private:

    Game* subject;

    int numberOfEnemy;
    int enemyDefeated;


};


#endif //PROJECT_GAMEOBSERVER_H
