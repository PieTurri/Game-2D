//
// Created by piero on 3/19/19.
//
#include <gtest/gtest.h>
#include "../Knight.h"
#include "../Abstract_Factory.h"
#include "../FireBall.h"

////FASI TEST: ARRANGE, ACT, ASSERT

struct KnightTest : public testing::Test{
    Hero* hero;
    TileMap* map;
    Abstract_Factory* factory;
    ///////////////////
    Enemy* enemy;
    vector<Projectile*> heroProjectile;
    vector<Projectile*> enemyProjectile;
    //////////////////
    vector<Obstacle*> ob;
    int obstaclePosX;
    int obstaclePosY;

    Vector2f obpos;
protected:
    void SetUp() override {

        cout<<"ALIVE"<<endl;

        factory = Abstract_Factory::create(0);
        map = factory->createMap();

        hero = new Knight(7,5,false);

        //////////////////
        Weapon* heroWeapon = hero->getWeapon();
        heroProjectile.push_back(new FireBall);

        enemy = factory->createEnemy();
        Weapon* enemyWeapon = enemy->getWeapon();
        enemyProjectile.push_back(new FireBall);


    }
    void TearDown() override {cout<<"DEAD"<<endl; delete hero; delete map; delete factory;}
};

TEST_F(KnightTest, Costructor_Test) {

    cout<<"INIZIO"<<endl;

    /////////////////HERO//////////////////////////////

    ASSERT_EQ(hero->getHp(),7);
    ASSERT_EQ(hero->getSpeed(),5);
    ASSERT_EQ(hero->isArmor(),false);

    hero->setPosition(Vector2f(64,64));

    ASSERT_EQ(map->getTile(hero->getPosition()-Vector2f(32, 0)).getHeroWalkability(),false);
    ASSERT_EQ(map->getTile(hero->getPosition()-Vector2f(0, 32)).getHeroWalkability(),false);

    hero->setPosition(Vector2f(512,64));

    ASSERT_EQ(map->getTile(hero->getPosition()+Vector2f(32, 0)).getHeroWalkability(),false);
    ASSERT_EQ(map->getTile(hero->getPosition()-Vector2f(0, 32)).getHeroWalkability(),false);

    hero->setPosition(Vector2f(512,512));

    ASSERT_EQ(map->getTile(hero->getPosition()+Vector2f(32, 0)).getHeroWalkability(),false);
    ASSERT_EQ(map->getTile(hero->getPosition()+Vector2f(0, 32)).getHeroWalkability(),false);

    hero->setPosition(Vector2f(64,512));

    ASSERT_EQ(map->getTile(hero->getPosition()-Vector2f(32, 0)).getHeroWalkability(),false);
    ASSERT_EQ(map->getTile(hero->getPosition()+Vector2f(0, 32)).getHeroWalkability(),false);

    /////////////////////FIRE////////////////////////////

    bool dh, ibuh, de, ibue;

    dh = (heroProjectile[0]->getDimension()).intersects(enemy->getDimension());
    ibuh = heroProjectile[0]->isBrokeUp();
    ASSERT_EQ(dh,!ibuh);
    ASSERT_EQ(map->getTile(heroProjectile[0]->getPosition()+Vector2f(32, 0)).getHeroWalkability(),false);

    de = enemyProjectile[0]->getDimension().intersects(hero->getDimension());
    ibue = enemyProjectile[0]->isBrokeUp();
    ASSERT_EQ(de,ibue);

    enemy->setPosition(Vector2f(32,32));
    ASSERT_EQ(map->getTile(enemy->getPosition()).getHeroWalkability(),false);


    /////////////////OBSTACLE//////////////////////////////

    obstaclePosX = 32;
    obstaclePosY = 32;

    ob.push_back(new Obstacle("barile/frame-",7));
    ob[0]->setPosition(Vector2f(32,32));

    ASSERT_EQ(hero->getHp(),7);
    ASSERT_EQ(hero->getSpeed(),5);
    ASSERT_EQ(hero->isArmor(),false);

    hero->setPosition(Vector2f(64,512));

    map->getTile(Vector2f(32,32)).setHeroWalkability(false);

    ASSERT_EQ(map->getTile(Vector2f(32,32)).getHeroWalkability(),false);

    obpos = Vector2f(obstaclePosX,obstaclePosY);

    ASSERT_EQ(map->getTile(Vector2f(32,32)).getHeroWalkability(),false);

    cout<<"HO FINITO"<<endl;
}
