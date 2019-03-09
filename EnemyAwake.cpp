//
// Created by piero on 2/22/19.
//

#include "EnemyAwake.h"

EnemyAwake::EnemyAwake() {}

void EnemyAwake::strategyDirection(TileMap &map, Sprite &sprite) {

}

EnemyStrategy * EnemyAwake::changeStrategy() {
    return new EnemySleeping;
}

EnemyAwake::~EnemyAwake() = default;
