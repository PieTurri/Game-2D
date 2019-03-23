//
// Created by piero on 2/21/19.
//

#ifndef PROJECT_ENEMYSTRATEGY_H
#define PROJECT_ENEMYSTRATEGY_H

#include <iostream>
#include "TileMap.h"
#include "Hero.h"
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace std;

class EnemyStrategy {

public:

    EnemyStrategy();

    explicit EnemyStrategy(Sprite &sprite);

    virtual EnemyStrategy *changeStrategy() = 0;

    virtual ~EnemyStrategy();

    virtual void setDirection(TileMap &map, Sprite &Esprite) = 0;

    void updateMovement(TileMap &map,Sprite &sprite);

    bool isFiringStrategy();

    void setHEdistance(float HEdistance);

    float getHEdistance() const;

    float getEnemyVel() const;

    void setEnemyVel(float enemyVel);

    bool isBetween(Vector2f enemy);

    bool isBetween2(float enemy);

    int getCharRange() const ;

protected:

    Vector2f pos_load;

    bool firingStrategy;

    int direction;
    int charMaxRange = 128;
    int charMinRange = 64;
    bool didEnemyMove;
    float enemyVel;
    Time timeEnemy;
    Clock clockEnemy;

    float HEdistance;
};

#endif //PROJECT_ENEMYSTRATEGY_H
