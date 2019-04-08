//
// Created by leogori on 21/12/18.
//

#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H

#include "GraphicState.h"
#include "Hero.h"
#include "Enemy.h"
#include "Pause.h"
#include "Heart.h"
#include <vector>
#include "Abstract_Factory.h"
#include "Subject.h"

class Game: public GraphicState {
public:

    Game(int characterIndex, int levInd, RenderWindow &window);

    ~Game();

    void draw(RenderWindow &window) override;

    void setScreen() override ;

    void getActivities(Event e1vent, RenderWindow &window) override;

    GraphicState *getNextState(RenderWindow &window) override;

    void setView(RenderWindow &window) override;

    void lookForCollision();

    void manageProjectile();

    void createProjectile();

    void update(RenderWindow &window);

    Vector2f getRandomPosition();

    vector <Enemy*>& getEnemy();

private:

    bool pause;

    Abstract_Factory* factory;

    //Texture heartT;
    //vector <Sprite> heartS;

    TileMap* map;

    //Heart heart;

    Time heroTime;

    Clock heroClock;

    vector <Time> enemyTime;

    vector <Clock> enemyClock;

    vector <Projectile*> heroProjectile;

    vector <Projectile*> enemyProjectile;

    Hero* hero;
    vector <Enemy*> enemy;

    Pause p;

};


#endif //PROJECT_GAME_H
