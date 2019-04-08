//
// Created by piero on 9/3/18.
//

#include "GameCharacter.h"

GameCharacter::GameCharacter() : GameCharacter (10,10) {}

GameCharacter::GameCharacter(int hp, int speed) : Hp(hp), speed(speed) {

    usingWeapon=false;
    sprite.setOrigin(16,24);
}

void GameCharacter::setHp(int Hp) {
    GameCharacter::Hp = Hp;
}

int GameCharacter::getHp()  {
    return Hp;
}

GameCharacter::~GameCharacter(){};

Vector2f GameCharacter::getPosition() {
    return sprite.getPosition();
}

void GameCharacter::setPosition(Vector2f pos) {

    sprite.setPosition(pos+Vector2f(16,24));
    weapon->setPosition(sprite.getPosition());
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

Weapon *GameCharacter::getWeapon() {
    return weapon;
}

const Sprite &GameCharacter::getSprite() const {
    return sprite;
}

bool GameCharacter::getWeaponUse() {
    return usingWeapon;
}

FloatRect GameCharacter::getDimension() {
    return sprite.getGlobalBounds();
}

/*
void GameCharacter::setWeapon(Weapon* Weapon) {
    this-> weapon = Weapon;
}
*/