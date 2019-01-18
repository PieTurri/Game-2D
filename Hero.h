//
// Created by piero on 9/3/18.
//

#ifndef PROJECT_HERO_H
#define PROJECT_HERO_H

#include "GameCharacter.h"
#include "Weapon.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Hero : public GameCharacter{

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

    bool isWeapon() const;

    bool isArmor() const;

    void setArmor(bool Armor);

    virtual void movement(RenderWindow &window) =0;

    virtual void draw(RenderWindow &window)=0;

    virtual void setDirection()=0;

    void setDirUp(bool state);

    void setDirDown(bool state);

    void setDirLeft(bool state);

    void setDirRight(bool state);


    //virtual void fire(Sprite &spriteFire, Texture &textureFire) = 0;

protected:
    bool Locked;
    bool Mp;
    bool SpecialPower;
    bool FinalAttack;
    bool Armor;
    int HeroType; //non è detto

    int id=0;       // non e detto

    bool moveU;
    bool moveD;
    bool moveL;
    bool moveR;

};





#endif //PROJECT_HERO_H
