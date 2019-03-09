//
// Created by piero on 9/3/18.
//

#include "Hero.h"
#include "Kalashnikov.h"

Hero::Hero(int Hp, int speed, bool armor) : GameCharacter(Hp, speed) {
    Armor = armor;

    moveU = false;
    moveD = false;
    moveL = false;
    moveR = false;

    sprite.setOrigin(16,24);

    sprite.setPosition(128+16,128+24);

    weapon = new Kalashnikov;
}



Hero::~Hero() = default;

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

bool Hero::isArmor() const {
    return Armor;
}

void Hero::setArmor(bool Armor) {
    Hero::Armor = Armor;
}

void Hero::setDirUp(bool state) {

    moveU=state;
}

void Hero::setDirDown(bool state) {

    moveD=state;
}

void Hero::setDirLeft(bool state) {

    moveL=state;
}

void Hero::setDirRight(bool state) {

    moveR=state;
}

bool Hero::isStill() {

    if(!moveU&&!moveD&&!moveR&&!moveL)
        return true;
    else
        return false;
}

void Hero::aim(RenderWindow &window, Event event) {

    weapon->rotate(event, window);

}



