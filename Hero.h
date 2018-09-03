//
// Created by piero on 9/3/18.
//

#ifndef PROJECT_HERO_H
#define PROJECT_HERO_H
#include "GameCharacter.h"

class Hero : public GameCharacter{

public:

    Hero(int Hp, int speed);

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

    void setWeapon(bool Weapon);

    bool isArmor() const;

    void setArmor(bool Armor);

private:
    bool Locked;
    bool Mp;
    bool SpecialPower;
    bool FinalAttack;
    bool Weapon;
    bool Armor;
    int HeroType; //non è detto
    int id;       // non e detto
};


#endif //PROJECT_HERO_H
