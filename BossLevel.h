//
// Created by leogori on 02/04/19.
//

#ifndef PROJECT_BOSSLEVEL_H
#define PROJECT_BOSSLEVEL_H


#include "GraphicState.h"
#include "TileBossMap.h"
#include "Hero.h"
#include "Abstract_Factory.h"
#include "Enemy.h"
#include "Heart.h"

class BossLevel: public GraphicState {

public:

    BossLevel(Hero *hero, RenderWindow &window, Abstract_Factory *factory);

    ~BossLevel();

    void draw(RenderWindow &window);

    void setScreen();

    GraphicState *getNextState(RenderWindow &window);

    void getActivities(Event event,RenderWindow &window);

    void setView(RenderWindow &window);

    void update(RenderWindow &window);

    Vector2f getRandomPosition();

    void lookForCollision();

    void manageProjectile();

    void createProjectile();

private:

    TileBossMap* map;

    Abstract_Factory* factory;

    Hero* hero;

    Enemy* enemy;

    Time heroTime;

    Clock heroClock;

    Time enemyTime;

    Heart heart;

    Clock enemyClock;

    vector <Projectile*> heroProjectile;

    vector <Projectile*> enemyProjectile;

};


#endif //PROJECT_BOSSLEVEL_H
