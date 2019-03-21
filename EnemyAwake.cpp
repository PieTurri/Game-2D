//
// Created by piero on 2/22/19.
//

#include "EnemyAwake.h"

EnemyAwake::EnemyAwake() {

    firingStrategy=true;
}

void EnemyAwake::setDirection(TileMap &map, Sprite &sprite) {

}

EnemyStrategy * EnemyAwake::changeStrategy() {
    return new EnemySleeping;
}

EnemyAwake::~EnemyAwake() = default;
