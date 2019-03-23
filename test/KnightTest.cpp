//
// Created by piero on 3/19/19.
//
#include <gtest/gtest.h>
#include "../Knight.h"

////FASI TEST: ARRANGE, ACT, ASSERT

struct KnightTest : public testing::Test{
    Hero* hero;
    TileMap map;
    Sprite sprite;
protected:
    void SetUp() override {cout<<"ALIVE"<<endl; hero = new Knight(7,5,false);}
    void TearDown() override {cout<<"DEAD"<<endl; delete hero;}
};

TEST_F(KnightTest, Costructor_Test) {
    ASSERT_EQ(hero->getHp(),7);
    ASSERT_EQ(hero->getSpeed(),5);
    ASSERT_EQ(hero->isArmor(),false);
    ASSERT_EQ(map.getTileWalkability(hero->getSprite().getPosition()-Vector2f(32, 0)),true);
    ASSERT_EQ(map.getTileWalkability(hero->getSprite().getPosition()-Vector2f(0, 32)),true);
    ASSERT_EQ(map.getTileWalkability(hero->getSprite().getPosition()+Vector2f(0, 32)),true);
    ASSERT_EQ(map.getTileWalkability(hero->getSprite().getPosition()+Vector2f(32, 0)),true);
}

