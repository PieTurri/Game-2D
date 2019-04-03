//
// Created by piero on 9/3/18.
//

//#include "Hero.h"
#include "Kalashnikov.h"
#include "Knight.h"
#include "Valkyrie.h"
#include "Hero.h"

Hero::Hero(int Hp, int speed, bool armor) : GameCharacter(Hp, speed) {

    Armor = armor;

    moveU = false;
    moveD = false;
    moveL = false;
    moveR = false;

    weapon = new Kalashnikov;
    weapon->setRateOfFire(0.1);
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

    View view=window.getView();

    Vector2f size=(Vector2f)window.getSize();

    float targetX=event.mouseMove.x-(size.x/2)+view.getCenter().x;

    float targetY=event.mouseMove.y-(size.y/2)+view.getCenter().y;

    Vector2f posTarget(targetX,targetY);

    weapon->rotate(posTarget);

}

Hero *Hero::Create(int index) {
    switch(index){
        case 0:
            return new Knight(256,16,false);
        case 1:
            return new Valkyrie(8,5,true);
    }
}

bool Hero::getDirRight() {

    return moveR;
}

bool Hero::getDirLeft() {
    return moveL;
}

bool Hero::getDirDown() {
    return moveD;
}

bool Hero::getDirUp() {
    return moveU;
}

void Hero::moveRight(TileMap *map) {

    Tile tile=map->getTile(getPosition() + Vector2f(speed + getDimension().width / 2, 0));

    if(tile.getHeroWalkability()) {
        sprite.move(speed, 0);
        weapon->move(speed, 0);
        notify();
    }
}

void Hero::moveLeft(TileMap *map) {

    Tile tile=map->getTile(getPosition() + Vector2f(-speed - getDimension().width / 2, 0));

    if(tile.getHeroWalkability()) {

        sprite.move(-speed, 0);
        weapon->move(-speed, 0);
        notify();
    }
}

void Hero::moveUp(TileMap *map) {

    Tile tile=map->getTile(getPosition() + Vector2f(0, -speed - getDimension().height / 2));

    if(tile.getHeroWalkability()) {

        sprite.move(0, -speed);
        weapon->move(0, -speed);
        notify();
    }
}

void Hero::moveDown(TileMap *map) {

    Tile tile=map->getTile(getPosition() + Vector2f(0, speed + getDimension().height / 2));

    if(tile.getHeroWalkability()) {

        sprite.move(0, speed);
        weapon->move(0, speed);
        notify();
    }
}



