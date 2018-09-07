//
// Created by piero on 9/3/18.
//

#ifndef PROJECT_GAMECHARACTER_H
#define PROJECT_GAMECHARACTER_H


#include "Weapon.h"

class GameCharacter {

public:

    GameCharacter();

    explicit GameCharacter(int Hp, int speed);

    virtual ~GameCharacter();

    void setHp(int Hp);

    void setPosX(int PosX);

    void setPosY(int PosY);

    int getHp() const;

    int getPosX() const;

    int getPosY() const;

    virtual int speedCharacter();

    virtual int fight();

    Weapon* getWeapon();

    void setWeapon(Weapon *Weapon);

    virtual void GameCharacter::move(int x, int y){};




protected:
    int Hp;
    int PosX;
    int PosY;
    int Speed;
    Weapon* weapon;
};


#endif //PROJECT_GAMECHARACTER_H
