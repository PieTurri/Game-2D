//
// Created by piero on 9/3/18.
//

#ifndef PROJECT_HERO_H
#define PROJECT_HERO_H


#include <iostream>
#include "GameCharacter.h"

using namespace std;
using namespace sf;

class Hero : public GameCharacter {

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

    virtual void movement(RenderWindow &window) =0;

    virtual void draw(RenderWindow &window, TileMap &map) =0;

    virtual void setDirection()=0;

    void setDirUp(bool state);

    void setDirDown(bool state);

    void setDirLeft(bool state);

    void setDirRight(bool state);

    bool isStill();

    void aim(RenderWindow &window, Event event);



protected:

    bool Locked;
    bool Mp;
    bool SpecialPower;
    bool FinalAttack;
    bool Armor;

    int HeroType; //non è detto

    bool moveU;
    bool moveD;
    bool moveL;
    bool moveR;


};

#endif //PROJECT_HERO_H
