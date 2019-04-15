//
// Created by leogori on 07/04/19.
//

#include "GameObserver.h"

GameObserver::GameObserver() {

    enemyDefeated=0;
    numberOfEnemy=0;
    time=Vector2i(0,0);
}

void GameObserver::update(Subject *s) {

    if(subject==s) {

        Game* sub=dynamic_cast<Game*>(subject);
        if (sub->getEnemy().size() != numberOfEnemy) {
            enemyDefeated++;
            numberOfEnemy=sub->getEnemy().size();
        }

        int timeInMinutes= static_cast<int>(sub->getCompletedGameTime().asSeconds())/60;

        int timeInSeconds= static_cast<int>(sub->getCompletedGameTime().asSeconds())-timeInMinutes*60;

        time=Vector2i(timeInMinutes,timeInSeconds);
    }
}

void GameObserver::setSubject(Subject *subject) {

    this->subject=subject;

    this->subject->addObserver(this);

    Game* sub=dynamic_cast<Game*>(subject);

    numberOfEnemy=sub->getEnemy().size();
}

int GameObserver::getEnemyDefeated() {

    return enemyDefeated;
}

int GameObserver::getNumberOfEnemy() {

    return numberOfEnemy+enemyDefeated;
}

Vector2i GameObserver::getTime() {
    return time;
}
