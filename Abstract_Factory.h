//
// Created by piero on 9/7/18.
//

#ifndef PROJECT_ABSTRACT_FACTORY_H
#define PROJECT_ABSTRACT_FACTORY_H

#include "Hero.h"
//#include "Weapon.h"
//#include "Enemy.h"
//#include "Companion.h"

#include "Knight.h"
#include "Valkyrie.h"
#include "Ninja.h"
#include "Wizard.h"
#include "Planetar.h"


class Abstract_Factory{
public:


    virtual ~Abstract_Factory(){}

    //enum CharacterType {Knight, Valkyrie, Ninja, Wizard, Planetar};

    virtual Hero * createHero() = 0;


    //virtual Enemy*createEnemy()=0;
    //virtual Companion*createCompanion()=0;

protected:

    //virtual Weapon*createWeapon()=0;

};

class KnightFactory : public Abstract_Factory{

public:
     Hero* createHero() {

        auto knight = new Knight(3,8,false);
        return knight;
     }
};

class ValkyrieFactory : public Abstract_Factory{

    Hero* createHero() {
        auto valkyrie = new Valkyrie(16,1,true);
        return valkyrie;
    }
};

#endif //PROJECT_ABSTRACT_FACTORY_H
