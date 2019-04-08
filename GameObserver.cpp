//
// Created by leogori on 07/04/19.
//

#include "GameObserver.h"

GameObserver::GameObserver() {

    enemyDefeated=0;
}

void GameObserver::update(Subject *s) {

    if(subject==s) {
        if (subject->getEnemy().size() != numberOfEnemy)
            enemyDefeated++;
    }

    cout<<"numero di nemici sconfitti: "<<enemyDefeated<<endl;

}

void GameObserver::setSubject(GraphicState *subject) {

    this->subject=dynamic_cast<Game*>(subject);
    this->subject->addObserver(this);
    numberOfEnemy=this->subject->getEnemy().size();
}

int GameObserver::getEnemyDefeated() {

    return enemyDefeated;
}

int GameObserver::getNumberOfEnemy() {

    return numberOfEnemy;
}
