//
// Created by piero on 9/3/18.
//

#include "GameCharacter.h"

GameCharacter::GameCharacter() : GameCharacter (10,10) {}

GameCharacter::GameCharacter(int hp, int speed) : Hp(hp), speed(speed) {}

void GameCharacter::setHp(int Hp) {
    GameCharacter::Hp = Hp;
    usingWeapon=false;
}


int GameCharacter::getHp() const {
    return Hp;
}

GameCharacter::~GameCharacter(){};

Vector2f GameCharacter::getPosition() {
    return sprite.getPosition();
}

void GameCharacter::setSpeed(int s) {

    speed=s;
}

int GameCharacter::getSpeed() {
    return speed;
}

void GameCharacter::setWeaponUse(bool statement) {

    usingWeapon=statement;
}

void GameCharacter::useWeapon() {

    if(usingWeapon)
        weapon->fire();

}

Weapon *GameCharacter::getWeapon() {
    return weapon;
}
/*
void GameCharacter::setWeapon(Weapon* Weapon) {
    this-> weapon = Weapon;
}
*/