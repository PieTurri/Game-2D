//
// Created by piero on 9/7/18.
//

#include "Companion.h"

Companion::Companion(int Hp, int speed, bool ability) : GameCharacter(Hp, speed) {
    ability=true;
}

bool Companion::isAbility() const {
    return ability;
}

void Companion::setAbility(bool ability) {
    Companion::ability = ability;
}

Companion::~Companion() {

}
