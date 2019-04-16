//
// Created by piero on 2/21/19.
//

#include "EnemyStrategy.h"

EnemyStrategy::EnemyStrategy() {
    srand((unsigned)time(NULL));
    didEnemyMove=false;
}

EnemyStrategy::EnemyStrategy(Sprite &sprite) {}

EnemyStrategy::~EnemyStrategy() = default;

void EnemyStrategy::updateMovement(TileBossMap *map, Sprite &sprite) {

    switch (direction) {
        case 0:
            if (map->getTile(sprite.getPosition() + Vector2f(32, 0)).getEnemyWalkability()) {

                sprite.move(32, 0);

                didEnemyMove = true;
            } else
                didEnemyMove = false;
            break;

        case 1:
            if (map->getTile(sprite.getPosition() - Vector2f(32, 0)).getEnemyWalkability()) {

                sprite.move(-32, 0);

                didEnemyMove = true;
            } else
                didEnemyMove = false;
            break;

        case 2:
            if (map->getTile(sprite.getPosition() - Vector2f(0, 32)).getEnemyWalkability()) {

                sprite.move(0, -32);

                didEnemyMove = true;
            } else
                didEnemyMove = false;
            break;

        case 3:
            if (map->getTile(sprite.getPosition() + Vector2f(0, 32)).getEnemyWalkability()) {

                sprite.move(0, 32);

                didEnemyMove = true;
            } else
                didEnemyMove = false;
            break;
        default:
            break;
    }
    //}

}

int EnemyStrategy::getCharRange() const {
    return charMaxRange;
}

void EnemyStrategy::setHEdistance(float HEdistance) {
    EnemyStrategy::HEdistance = HEdistance;
}

float EnemyStrategy::getHEdistance() const {
    return HEdistance;
}

float EnemyStrategy::getEnemyVel() const {
    return enemyVel;
}

void EnemyStrategy::setEnemyVel(float enemyVel) {
    EnemyStrategy::enemyVel = enemyVel;
}

bool EnemyStrategy::isFiringStrategy() {

    return firingStrategy;
}

bool EnemyStrategy::isBetween(Vector2f enemy) {
    double eRange =  sqrt(pow(enemy.x,2)+pow(enemy.y,2));
    if(eRange < charMaxRange && eRange > charMinRange)
        return true;
    else return false;
}

bool EnemyStrategy::isBetween2(float enemy) {

    if(enemy < charMaxRange && enemy > charMinRange)
        return true;
    else return false;
}

