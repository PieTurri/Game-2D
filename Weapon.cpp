//
// Created by piero on 9/5/18.
//

#include "Weapon.h"

Weapon::Weapon() {}

bool Weapon::isCompatible() const {
    return Compatibility;
}

int Weapon::getDemage() const {
    return Demage;
}

void Weapon::setDemage(int Demage) {
    Weapon::Demage = Demage;
}

Weapon::~Weapon() {}


