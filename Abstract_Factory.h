//
// Created by piero on 9/7/18.
//

#ifndef PROJECT_ABSTRACT_FACTORY_H
#define PROJECT_ABSTRACT_FACTORY_H

#include "Hero.h"
#include "Enemy.h"

//#include "Weapon.h"
//#include "Companion.h"

#include "Knight.h"
#include "Valkyrie.h"
#include "Ninja.h"
#include "Wizard.h"
#include "Planetar.h"
#include "Skeleton.h"
#include "Companion.h"
#include "MenuLoop.h"
#include <iostream>


using namespace std;

class Abstract_Factory{

public:
    virtual ~Abstract_Factory() {}

    virtual Hero * createHero() = 0;

    //virtual Companion*createCompanion()=0;

protected:


    //virtual Weapon*createWeapon()=0;

};

class Enemy_Abstract_Factory{

public:
    virtual Enemy * createEnemy() = 0;
};


class KnightFactory : public Abstract_Factory{

public:
    Hero* createHero() override {
        auto knight = new Knight(3,4,false);
        return knight;
     }
};

class ValkyrieFactory : public Abstract_Factory{
public:
    Hero* createHero() override {
        auto valkyrie = new Valkyrie(16,1,true);
        return valkyrie;
    }
};

class SkeletonFactory : public Enemy_Abstract_Factory {
public:
    Enemy* createEnemy() override {
        auto skeleton = new Skeleton(10,4);
        return skeleton;
    }
};

#endif //PROJECT_ABSTRACT_FACTORY_H
