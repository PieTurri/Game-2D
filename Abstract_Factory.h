//
// Created by piero on 9/7/18.
//

#ifndef PROJECT_ABSTRACT_FACTORY_H
#define PROJECT_ABSTRACT_FACTORY_H

#include "Hero.h"
#include "Weapon.h"
#include "Enemy.h"
#include "Companion.h"

class Abstract_Factory{
public:

    virtual ~Abstract_Factory(){}
    virtual Hero*createHero()=0;
    virtual Enemy*createEnemy()=0;
    virtual Companion*createCompanion()=0;

protected:

    virtual Weapon*createWeapon()=0;

};


class Hero_Factory : public Abstract_Factory{

public:
    virtual Hero* createHero(){
        Hero new Hero;
    }

};

#endif //PROJECT_ABSTRACT_FACTORY_H
