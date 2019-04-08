
//
// Created by piero on 4/3/19.
//
#include <gtest/gtest.h>
#include "../Knight.h"
#include "../Abstract_Factory.h"

struct ObstacleTest : public testing :: Test{
    Hero* hero;
    TileMap* map;
    Abstract_Factory* factory;
    vector<Obstacle*> obstacle;

    Obstacle* ob;

    int width;
    int height;

    int obstaclePosX;
    int obstaclePosY;

    Vector2f obpos;

protected:
    void SetUp() override{
        cout<<"ALIVE"<<endl;
        hero = new Knight(7,5,false);
        factory = Abstract_Factory::create(1);
        map = factory->createMap();

        ob = new Obstacle("barile/frame-",7);


        cout<<"ORCA BESTIA!!!!!!!"<<endl;
    }

    void TearDown() override{

        hero = nullptr;
        delete hero;

        map= nullptr;
        delete map;

        factory = nullptr;
        delete factory;

        cout<<"DEAD\n"<<endl;
    }
};

TEST_F(ObstacleTest,Creation_Test){

    cout<<"FUCK"<<endl;

    /*obstaclePosX = 32;
    obstaclePosY = 32;*/

    ob->setPosition(Vector2f(32,32));
    obstacle.push_back(ob);

    ASSERT_EQ(hero->getHp(),7);
    ASSERT_EQ(hero->getSpeed(),5);
    ASSERT_EQ(hero->isArmor(),false);

    hero->setPosition(Vector2f(64,512));

   // ASSERT_EQ(map,false);
    ASSERT_EQ(map->getTile(ob->getPosition()).getHeroWalkability(),false);
    cout<<"PIPPO"<<endl;

    //obpos = Vector2f(obstaclePosX,obstaclePosY);

    //ASSERT_EQ(map->getTile(obpos).getHeroWalkability(),false);

    cout<<"HO FINITO"<<endl;
}