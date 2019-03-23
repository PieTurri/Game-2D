//
// Created by piero on 3/21/19.
//

#include <gtest/gtest.h>
#include "../Projectile.h"

struct ProjectileTest : public testing::Test{

    vector <Projectile> projectile;
    TileMap map;

protected:
    virtual void SetUp() override {cout<<"ALIVE"<<endl;}


    virtual void TearDown() override {cout<<"DEAD"<<endl;}

};

/*

TEST_F(ProjectileTest,Wall_Collision){
    ASSERT_EQ(map.getTileWalkability(projectile.getPosition()),true);
}*/
