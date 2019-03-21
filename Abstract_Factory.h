//
// Created by piero on 9/7/18.
//

#ifndef PROJECT_ABSTRACT_FACTORY_H
#define PROJECT_ABSTRACT_FACTORY_H

#include "Hero.h"
//#include "Weapon.h"
#include "Enemy.h"
//#include "Companion.h"

#include <iostrem>

#include "Knight.h"
#include "Valkyrie.h"
#include "Ninja.h"
#include "Wizard.h"
#include "Planetar.h"
#include "Skeleton.h"
#include "Companion.h"
#include "MenuLoop.h"
#include <iostream>


enum HeroType {KNIGHT, VALKYRIE, NINJA, WIZARD, PLANETAR};
enum EnemyType{SKELETON};
using namespace std;

class Abstract_Factory{
public:


    virtual ~Abstract_Factory(){}

    virtual Hero *createHero(int index) = 0;

    //virtual Enemy *createEnemy(int index) = 0;

    //virtual Companion*createCompanion()=0;

protected:

    //virtual Weapon*createWeapon()=0;
    Hero * hero;

};

class HeroFactory : public Abstract_Factory{

public:
    Hero *createHero(int index) override {

        switch(index){
            case 0:
                return new Knight(8,8,true):
            case 1:
                return new Valkyrie(8,16,false);
            default:
                cout<<"ERRORE CREAZIONE EROE"<<endl;

        }
    }
};

class EnemyFactory : public Enemy_Abstract_Factory {
public:
    Enemy* createEnemy() override {

    }
};

#endif //PROJECT_ABSTRACT_FACTORY_H
