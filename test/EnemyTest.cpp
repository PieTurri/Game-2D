/*
//
// Created by piero on 4/6/19.
//
#include <gtest/gtest.h>
#include "../Enemy.h"
#include "../Abstract_Factory.h"

struct EnemyTest : public testing::Test{
protected:
    Enemy* enemy;
    TileMap* mappa;
    Abstract_Factory* factory;
protected:
    void SetUp() override {
        cout<<"ALIVE"<<endl;

        factory = Abstract_Factory::create(0);
        //this->mappa = factory->createMap();
        enemy = factory->createEnemy();
        cout<<"PLUTO"<<endl;

    }
    void TearDown() override{
        delete enemy;
        delete mappa;
        delete factory;
        cout<<"DEAD"<<endl;
    }
};

TEST_F(EnemyTest,Constructor_Test){

    ASSERT_EQ(enemy->getHp(),8);
    ASSERT_EQ(enemy->getSpeed(),6);

    enemy->setPosition(Vector2f(32,32));
    //ASSERT_EQ(mappa->getTile(enemy->getPosition()).getHeroWalkability(),false);
}
*/
