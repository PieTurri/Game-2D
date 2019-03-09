//
// Created by leogori on 09/03/19.
//

#include "Tile.h"

Tile::Tile() {}

void Tile::setValue(int val) {

    value=val;
}

int Tile::getValue() {

    return value;
}

void Tile::setWalkability(bool state) {

    walkability=state;
}

bool Tile::getWalkability() {

    return walkability;
}
