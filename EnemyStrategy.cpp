//
// Created by piero on 2/21/19.
//

#include "EnemyStrategy.h"


EnemyStrategy::EnemyStrategy() {}

EnemyStrategy::EnemyStrategy(Sprite &sprite) {
    srand((unsigned)time(NULL));
}

EnemyStrategy::~EnemyStrategy() = default;

void EnemyStrategy::updateMovement(TileMap &map,Sprite &sprite) {

    pos_load = sprite.getPosition();


    switch (direction) {
        case 0:
            if (map.getTileWalkability(sprite.getPosition() + Vector2f(32, 0))) {

                map.setTileWalkability(pos_load, true);
                sprite.move(32, 0);
                map.setTileWalkability(pos_load+ Vector2f(32, 0), false);

                didEnemyMove = true;
            } else
                didEnemyMove = false;
            break;

        case 1:
            if (map.getTileWalkability(sprite.getPosition() - Vector2f(32, 0))) {

                map.setTileWalkability(pos_load, true);
                sprite.move(-32, 0);
                map.setTileWalkability(pos_load- Vector2f(32, 0), false);
                didEnemyMove = true;
            } else
                didEnemyMove = false;
            break;

        case 2:
            if (map.getTileWalkability(sprite.getPosition() - Vector2f(0, 32))) {

                map.setTileWalkability(pos_load, true);
                sprite.move(0, -32);
                map.setTileWalkability(pos_load- Vector2f(0, 32), false);

                didEnemyMove = true;
            } else
                didEnemyMove = false;
            break;

        case 3:
            if (map.getTileWalkability(sprite.getPosition() + Vector2f(0, 32))) {

                map.setTileWalkability(pos_load, true);
                sprite.move(0, 32);
                map.setTileWalkability(pos_load+ Vector2f(0, 32), false);

                didEnemyMove = true;
            } else
                didEnemyMove = false;
            break;
        default:
            break;
    }

}


