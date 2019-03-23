//
// Created by piero on 2/22/19.
//

#include "EnemyAwake.h"

EnemyAwake::EnemyAwake() {

    firingStrategy=true;
    enemyVel = 1;
}

void EnemyAwake::setDirection(TileMap &map, Sprite &sprite) {
    direction = rand() % 4;
    timeEnemy = clockEnemy.getElapsedTime();

    if (timeEnemy.asSeconds() > enemyVel) {
        updateMovement(map, sprite);
        if (didEnemyMove)
            clockEnemy.restart();
    } /*else {


        //direction = rand() % 4;

        if (timeEnemy.asSeconds() > enemyVel) {
            updateMovement(map, sprite);
            if (didEnemyMove)
                clockEnemy.restart();
        }
    }*/
}


EnemyStrategy* EnemyAwake::changeStrategy() {
    return new EnemySleeping;
}

EnemyAwake::~EnemyAwake() {}

/*
void EnemyAwake::upgradeMovementLocked(TileMap &map, Sprite &sprite, Hero *h) {

    ////Trovare un metodo per riuscire a fare un controllo a posteriori; Risolvere problema float vector2f

    pos_load = sprite.getPosition();


        switch (direction) {
            case 0:
                if (map.getTileWalkability(sprite.getPosition() + Vector2f(32, 0)) && ((sprite.getPosition() + Vector2f(32,0)) >  && (sprite.getPosition() + Vector2f(32,0)) < )) {

                    map.setTileWalkability(pos_load, true);
                    sprite.move(32, 0);
                    map.setTileWalkability(pos_load + Vector2f(32, 0), false);

                    didEnemyMove = true;
                } else
                    didEnemyMove = false;
                break;

            case 1:
                if (map.getTileWalkability(sprite.getPosition() - Vector2f(32, 0))) {

                    map.setTileWalkability(pos_load, true);
                    sprite.move(-32, 0);
                    map.setTileWalkability(pos_load - Vector2f(32, 0), false);

                    didEnemyMove = true;
                } else
                    didEnemyMove = false;
                break;

            case 2:
                if (map.getTileWalkability(sprite.getPosition() - Vector2f(0, 32))) {

                    map.setTileWalkability(pos_load, true);
                    sprite.move(0, -32);
                    map.setTileWalkability(pos_load - Vector2f(0, 32), false);

                    didEnemyMove = true;
                } else
                    didEnemyMove = false;
                break;

            case 3:
                if (map.getTileWalkability(sprite.getPosition() + Vector2f(0, 32))) {

                    map.setTileWalkability(pos_load, true);
                    sprite.move(0, 32);
                    map.setTileWalkability(pos_load + Vector2f(0, 32), false);

                    didEnemyMove = true;
                } else
                    didEnemyMove = false;
                break;
            default:
                break;
        }

}

*/
