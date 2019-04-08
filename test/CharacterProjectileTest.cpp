/*

//
// Created by piero on 4/4/19.
//

#include <gtest/gtest.h>
#include "../Knight.h"
#include "../Abstract_Factory.h"
#include "../FireBall.h"

struct CharacterProjectileTest : public testing::Test{
    Hero* hero;

    Abstract_Factory* factory1;
    TileMap* map1;
    ///////////////////
    Enemy* enemy;
    */
/*vector<Projectile*> heroProjectile;
    vector<Projectile*> enemyProjectile;*//*



protected:
    void SetUp() override {
        cout<<"ALIVE"<<endl;

        factory1 = Abstract_Factory::create(0);
        map1 = factory1->createMap();

        hero = new Knight(7,5,false);

        //////////////////
        cout<<"eccomi1"<<endl;
*/
/*
        Weapon* heroWeapon = hero->getWeapon();
        heroProjectile.push_back(new FireBall);

        cout<<"eccomi2"<<endl;

        enemy = new Skeleton(8,3);
        Weapon* enemyWeapon = enemy->getWeapon();
        enemyProjectile.push_back(new FireBall);*//*

        //////////////////
    }
    void TearDown() override {cout<<"DEAD"<<endl; delete hero; delete map1; delete factory1;}
};

TEST_F(CharacterProjectileTest,Projectile_Collision){

    ASSERT_EQ(hero->getHp(),7);
    ASSERT_EQ(hero->getSpeed(),5);
    ASSERT_EQ(hero->isArmor(),false);

    hero->setPosition(Vector2f(64,64));
    cout<< "OCA" <<endl;

    ASSERT_EQ(map1->getTile(hero->getPosition()-Vector2f(32, 0)).getHeroWalkability(),false);
    ASSERT_EQ(map1->getTile(hero->getPosition()-Vector2f(0, 32)).getHeroWalkability(),false);

    hero->setPosition(Vector2f(512,64));
    cout<< "SURICATO" <<endl;

    ASSERT_EQ(map1->getTile(hero->getPosition()+Vector2f(32, 0)).getHeroWalkability(),false);
    ASSERT_EQ(map1->getTile(hero->getPosition()-Vector2f(0, 32)).getHeroWalkability(),false);

    hero->setPosition(Vector2f(512,512));
    cout<< "GIRAFFA" <<endl;

    ASSERT_EQ(map1->getTile(hero->getPosition()+Vector2f(32, 0)).getHeroWalkability(),false);
    ASSERT_EQ(map1->getTile(hero->getPosition()+Vector2f(0, 32)).getHeroWalkability(),false);

    hero->setPosition(Vector2f(64,512));
    cout<< "OPOSSUM"<<endl;

    ASSERT_EQ(map1->getTile(hero->getPosition()-Vector2f(32, 0)).getHeroWalkability(),false);
    ASSERT_EQ(map1->getTile(hero->getPosition()+Vector2f(0, 32)).getHeroWalkability(),false);

    /////////////////////////////////////////////////

    cout<<"RINOCERONTE"<<endl;

    bool dh, ibuh, de, ibue;

*/
/*
    dh = (heroProjectile[0]->getDimension()).intersects(enemy->getDimension());
    ibuh = heroProjectile[0]->isBrokeUp();
    ASSERT_EQ(dh,!ibuh);
    ASSERT_EQ(map1->getTile(heroProjectile[0]->getPosition()+Vector2f(32, 0)).getHeroWalkability(),false);


    de = enemyProjectile[0]->getDimension().intersects(hero->getDimension());
    ibue = enemyProjectile[0]->isBrokeUp();
    ASSERT_EQ(de,ibue);
*//*



}*/

