//
// Created by piero on 9/3/18.
//

#include "Hero.h"


Hero::Hero(int Hp, int speed) : GameCharacter(Hp, speed) {}
Hero::~Hero() {}

bool Hero::isLocked() const {
    return Locked;
}

void Hero::setLocked(bool Locked) {
    Hero::Locked = Locked;
}

bool Hero::isMp() const {
    return Mp;
}

void Hero::setMp(bool Mp) {
    Hero::Mp = Mp;
}

bool Hero::isSpecialPower() const {
    return SpecialPower;
}

void Hero::setSpecialPower(bool SpecialPower) {
    Hero::SpecialPower = SpecialPower;
}

bool Hero::isFinalAttack() const {
    return FinalAttack;
}

void Hero::setFinalAttack(bool FinalAttack) {
    Hero::FinalAttack = FinalAttack;
}

bool Hero::isWeapon() const {
    return Weapon;
}

void Hero::setWeapon(bool Weapon) {
    Hero::Weapon = Weapon;
}

bool Hero::isArmor() const {
    return Armor;
}

void Hero::setArmor(bool Armor) {
    Hero::Armor = Armor;
}


