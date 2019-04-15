//
// Created by piero on 9/3/18.
//

#ifndef PROJECT_HERO_H
#define PROJECT_HERO_H

#include <iostream>
#include "GameCharacter.h"
#include "Subject.h"

using namespace std;
using namespace sf;

class Hero : public GameCharacter ,public Subject{

public:

    Hero(int Hp, int speed, bool armor);

    virtual ~Hero();

    bool isLocked() const;

    void setLocked(bool Locked);

    bool isMp() const;

    void setMp(bool Mp);

    bool isSpecialPower() const;

    void setSpecialPower(bool SpecialPower);

    bool isFinalAttack() const;

    void setFinalAttack(bool FinalAttack);

    bool isArmor() const;

    void setArmor(bool Armor);

    void draw(RenderWindow& window);

    virtual void setDirection()=0;

    void setDirUp(bool state);

    void setDirDown(bool state);

    void setDirLeft(bool state);

    void setDirRight(bool state);

    bool getDirRight();

    bool getDirLeft();

    bool getDirDown();

    bool getDirUp();

    void moveRight(TileBossMap *map);

    void moveLeft(TileBossMap *map);

    void moveUp(TileBossMap *map);

    void moveDown(TileBossMap *map);

    bool isStill();

    void aim(RenderWindow &window, Event event);

    static Hero* Create(int index);

protected:

    bool Locked;
    bool Mp;
    bool SpecialPower;
    bool FinalAttack;
    bool Armor;
    bool lastDirection;

    bool moveU;
    bool moveD;
    bool moveL;
    bool moveR;


};

#endif //PROJECT_HERO_H
