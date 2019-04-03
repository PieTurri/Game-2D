//
// Created by leogori on 09/03/19.
//

#include "Tile.h"

Tile::Tile() {

    reset();
}

void Tile::setValue(int val) {

    value=val;
}

int Tile::getValue() {

    return value;
}

void Tile::setHeroWalkability(bool state) {

    heroWalkability=state;
}

bool Tile::getHeroWalkability() {

    return heroWalkability;
}

bool Tile::getEnemyWalkability() const {
    return enemyWalkability;
}

void Tile::setEnemyWalkability(bool state) {
    enemyWalkability = state;
}

void Tile::reset() {

    enemyWalkability=true;
    heroWalkability=true;

}
