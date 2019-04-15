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

    void setSubject(Subject *subject);

    int getEnemyDefeated();

    int getNumberOfEnemy();

    Vector2i getTime();

private:

    Vector2i time;

    int numberOfEnemy;

    int enemyDefeated;


};


#endif //PROJECT_GAMEOBSERVER_H
