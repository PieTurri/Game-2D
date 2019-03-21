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

void EnemyStrategy::updateMovement(TileMap &map,Sprite &sprite) {

    switch (direction) {
        case 0:
            if (map.getTileWalkability(sprite.getPosition() + Vector2f(32, 0))) {

                sprite.move(32, 0);

                didEnemyMove = true;
            } else
                didEnemyMove = false;
            break;

        case 1:
            if (map.getTileWalkability(sprite.getPosition() - Vector2f(32, 0))) {

                sprite.move(-32, 0);

                didEnemyMove = true;
            } else
                didEnemyMove = false;
            break;

        case 2:
            if (map.getTileWalkability(sprite.getPosition() - Vector2f(0, 32))) {

                sprite.move(0, -32);

                didEnemyMove = true;
            } else
                didEnemyMove = false;
            break;

        case 3:
            if (map.getTileWalkability(sprite.getPosition() + Vector2f(0, 32))) {

                sprite.move(0, 32);

                didEnemyMove = true;
            } else
                didEnemyMove = false;
            break;
        default:
            break;
    }

}

bool EnemyStrategy::isFiringStrategy() {

    return firingStrategy;
}


