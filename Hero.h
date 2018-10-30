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

    virtual void movement(Sprite &sprite,string dir,View &view)=0;

    virtual void draw(Sprite &spritePlayer,Texture &texturePlayer,int TypeMove)=0;

protected:
    bool Locked;
    bool Mp;
    bool SpecialPower;
    bool FinalAttack;
    bool Armor;
    int HeroType; //non è detto


    int id=0;       // non e detto


};





#endif //PROJECT_HERO_H
