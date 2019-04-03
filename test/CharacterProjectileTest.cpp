//
// Created by piero on 3/23/19.
//
#include <gtest/gtest.h>
#include "../Projectile.h"
#include "../Enemy.h"
#include "../FireBall.h"
#include "../Knight.h"
#include "../Skeleton.h"



struct CharacterProjectileTest : public testing::Test{
public:
    Hero* hero;
    Enemy* enemy;
    vector<Projectile*> heroProjectile;
    vector<Projectile*> enemyProjectile;

protected:
    void SetUp() override {

        cout<<"ALIVE"<<endl;

        hero = new Knight(7,5,false);
        Weapon* heroWeapon = hero->getWeapon();
        heroProjectile.push_back(new FireBall);
        enemy = new Skeleton(8,3);
        Weapon* enemyWeapon = enemy->getWeapon();
        enemyProjectile.push_back(new FireBall);

    }
    void TearDown() override {

        cout<<"DEAD"<<endl;
        delete hero;
    }
};

TEST_F(CharacterProjectileTest,Projectile_Collision_Test){

    bool dh, ibuh, de, ibue;

    dh = (heroProjectile[0]->getDimension()).intersects(enemy->getDimension());
    ibuh = heroProjectile[0]->isBrokeUp();
    de = enemyProjectile[0]->getDimension().intersects(hero->getDimension());
    ibue = enemyProjectile[0]->isBrokeUp();

    ASSERT_EQ(dh,ibuh);
    ASSERT_EQ(de,ibue);
}
