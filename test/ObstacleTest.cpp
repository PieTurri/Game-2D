//
// Created by piero on 4/3/19.
//

#include <gtest/gtest.h>
#include "../Hero.h"
//#include "../Enemy.h"
#include "../Knight.h"

/*
struct ObstacleTest : public testing::Test{
public:

    Hero* hero;
    TileMap map;
    vector <vector<Tile>> tiles;

    Obstacle* obstacle;

protected:

    void SetUp() override {cout<<"ALIVE"<<endl; hero = new Knight(7,5,false);}
    void TearDown() override {cout<<"DEAD"<<endl; delete hero;}

};

TEST_F(ObstacleTest,Collision_Test){

    Vector2f obDist = obstacle->getPosition();
    Vector2f herDist = hero->getPosition();

    if(((herDist + Vector2f(32,0) - obDist) == Vector2f(0,0)))
        ASSERT_EQ(map.getTileWalkability(hero->getSprite().getPosition()+Vector2f(32, 0)),false);

}*/
