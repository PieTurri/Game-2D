//
// Created by leogori on 21/12/18.
//
#include "Game.h"
#include "ChooseCharacter.h"
#include "BossLevel.h"
#include <random>
#include <chrono>

using namespace std;
using namespace sf;

Game::Game(int characterIndex, int levInd, RenderWindow &window) {

    hero=Hero::Create(characterIndex);

    factory=Abstract_Factory::create(levInd);

    map=factory->createMap();

    Vector2f pos;
    Tile tile;

    hero->setPosition(map->getHeroStartingPosition());

    Clock clock;
    Time times;

    for(int i=0;i<2;i++){

        enemyTime.push_back(times);
        enemyClock.push_back(clock);
        enemy.push_back(factory->createEnemy());

        do{
            pos=getRandomPosition();
            tile=map->getTile(pos);
        } while(!map->isFightingGround(tile));

        enemy[i]->setPosition(pos);
    }

    pause=false;

    //setHeart(window);
    setView(window);

    view.setSubject(hero);
}

Game::~Game() {

    delete hero;
    delete map;
}

void Game::setScreen() {
}

void Game::getActivities(Event event, RenderWindow &window) {

    switch (event.type) {

        case Event::KeyReleased:
            switch (event.key.code) {
                case Keyboard::W:
                    hero->setDirUp(false);
                    break;
                case Keyboard::S:
                    hero->setDirDown(false);
                    break;
                case Keyboard::A:
                    hero->setDirLeft(false);
                    break;
                case Keyboard::D:
                    hero->setDirRight(false);
                    break;
                case Keyboard::Escape:
                    if(pause)
                        setState(true);
                    break;
                case Keyboard::P:
                    pause= !pause;
                    break;

                default:
                    break;
            }
            break;

        case Event::KeyPressed:
            switch (event.key.code) {
                case Keyboard::W:
                    hero->setDirUp(true);
                    break;
                case Keyboard::S:
                    hero->setDirDown(true);
                    break;
                case Keyboard::A:
                    hero->setDirLeft(true);
                    break;
                case Keyboard::D:
                    hero->setDirRight(true);
                    break;
                default:
                    break;
            }
            break;

        case Event::MouseMoved:
            if(!pause)
                hero->aim(window, event);
            break;

        case Event::MouseButtonPressed:
            hero->setWeaponUse(true);
            break;

        case Event::MouseButtonReleased:
            hero->setWeaponUse(false);
            break;

        case Event::Closed:
            window.close();
        default:
            break;
    }
}

GraphicState *Game::getNextState(RenderWindow &window) {

    if (!pause)
        return new BossLevel(hero, window);
    else
        return new ChooseCharacter(window);
}

void Game::draw(RenderWindow &window) {


    map->draw(window);

    for(int i=0; i<heartS.size();i++)
        window.draw(heartS[i]);

    hero->draw(window);

    for (int i = 0; i < heroProjectile.size(); i++)
        heroProjectile[i]->draw(window);

    for (int i = 0; i < enemyProjectile.size(); i++)
        enemyProjectile[i]->draw(window);

    for (int i = 0; i < enemy.size(); i++)
        enemy[i]->draw(window);

    if(!pause)
        update(window);
}

void Game::setView(RenderWindow &window) {

    view.setSize(Vector2f(640,480));
    view.setCenter(hero->getPosition());
    window.setView(view);
}

void Game::lookForCollision() {

    vector<Obstacle> &obstacle = map->getObstacle();

    if (!heroProjectile.empty()) {

        for (int i = 0; i < heroProjectile.size(); i++) {

            vector<Enemy *>::iterator it = enemy.begin();

            for (int j = 0; j < enemy.size(); j++) {

                if((heroProjectile[i]->getDimension()).intersects(enemy[j]->getDimension())){
                    enemy[j]->setHp(enemy[j]->getHp() - heroProjectile[i]->getDamage());
                    heroProjectile[i]->setDestroyed();
                }

                if (enemy[j]->getHp() <= 0) {
                    enemy.erase(it);
                    j--;
                } else
                    it++;

            }

            for (int j = 0; j < obstacle.size(); j++) {

                if (heroProjectile[i]->getDimension().intersects(obstacle[j].getDimension())){
                    obstacle[j].setDestroyed(true);
                    heroProjectile[i]->setDestroyed();
                }
            }

            if (!map->getTile(heroProjectile[i]->getPosition()).getHeroWalkability())
                heroProjectile[i]->setDestroyed();
        }
    }

    if (!enemyProjectile.empty()) {

        for (int i = 0; i < enemyProjectile.size(); i++) {

            if (enemyProjectile[i]->getDimension().intersects(hero->getDimension())) {
                //hero->setHp(hero->getHp() - enemyProjectile[i]->getDamage());
                enemyProjectile[i]->setDestroyed();
            }

            if (hero->getHp() <= 0) {

                setState(true);
            }

            for (int j = 0; j < obstacle.size(); j++) {

                if (enemyProjectile[i]->getDimension().intersects(obstacle[j].getDimension())) {
                    obstacle[j].setDestroyed(true);
                    enemyProjectile[i]->setDestroyed();
                }
            }

            if (!map->getTile(enemyProjectile[i]->getPosition()).getHeroWalkability())
                enemyProjectile[i]->setDestroyed();
        }
    }

    map->setObstacle(obstacle);
}

void Game::manageProjectile() {

    if(!heroProjectile.empty()) {

        vector<Projectile *>::iterator heroIt = heroProjectile.begin();

        for (int i = 0; i < heroProjectile.size(); i++) {
            heroProjectile[i]->move(map);
            if (heroProjectile[i]->isBrokeUp()) {
                heroProjectile.erase(heroIt);
                i--;
            } else
                heroIt++;

        }
    }

    if(!enemyProjectile.empty()) {

        vector<Projectile *>::iterator enemyIt = enemyProjectile.begin();

        for (int i = 0; i < enemyProjectile.size(); i++) {
            enemyProjectile[i]->move(map);
            if (enemyProjectile[i]->isBrokeUp()) {
                enemyProjectile.erase(enemyIt);
                i--;
            } else
                enemyIt++;
        }
    }
}

void Game::createProjectile() {

    Weapon* heroWeapon=hero->getWeapon();

    heroTime=heroClock.getElapsedTime();

    if(hero->getWeaponUse()&&heroTime.asSeconds()>heroWeapon->getRateOfFire()&&
            map->isFightingGround(map->getTile(hero->getPosition()))){

        heroClock.restart();

        Projectile *projectile=Projectile::create(heroWeapon->getProjectile());
        projectile->setPosition(heroWeapon->getPosition());
        projectile->setAimedPoint(heroWeapon->getAimedPoint());
        projectile->setOrientation();
        projectile->setSpeed(5);

        heroProjectile.push_back(projectile);
    }

    for(int i=0;i<enemy.size();i++){

        Weapon* enemyWeapon=enemy[i]->getWeapon();

        enemyTime[i]=enemyClock[i].getElapsedTime();

        if(enemy[i]->getWeaponUse()&&enemyTime[i].asSeconds()>enemyWeapon->getRateOfFire()
                &&map->isFightingGround(map->getTile(hero->getPosition()))){
            enemyClock[i].restart();

            Projectile *projectile=Projectile::create(enemyWeapon->getProjectile());
            projectile->setPosition(enemyWeapon->getPosition());
            projectile->setAimedPoint(enemyWeapon->getAimedPoint());
            projectile->setOrientation();
            projectile->setSpeed(0.7);

            enemyProjectile.push_back(projectile);

        }
    }
}

void Game::update(RenderWindow &window) {

    if (!pause) {

        if (hero->isStill())
            view.followHero();

        hero->setDirection();

        if (hero->getDirRight())
            hero->moveRight(map);

        if (hero->getDirLeft())
            hero->moveLeft(map);

        if (hero->getDirUp())
            hero->moveUp(map);

        if (hero->getDirDown())
            hero->moveDown(map);

        for (int i = 0; i < enemy.size(); i++) {

            enemy[i]->changeStrategy(hero, map);
            enemy[i]->moveEnemy(map);
            enemy[i]->aim(hero->getPosition());

            enemy[i]->setWeaponUse(enemy[i]->hasFiringStrategy());
        }

        if(enemy.size()==0)
            map->openBossDoor();

        cout<<map->isBossDoor(map->getTile(hero->getPosition()))<<" , "<<enemy.size()<<endl;

        if(enemy.size()==0&&map->isBossDoor(map->getTile(hero->getPosition())))
            setState(true);

        window.setView(view);

        createProjectile();
        manageProjectile();
        lookForCollision();
    }

}


Vector2f Game::getRandomPosition() {

    unsigned seed= static_cast<unsigned int>(chrono::system_clock::now().time_since_epoch().count());

    default_random_engine generator(seed);

    uniform_int_distribution<int> distribution(0,72);

    float x=distribution(generator);
    float y=distribution(generator);

    Vector2f pos(x*32,y*32);

    return pos;
}

/*void Game::setHeart(RenderWindow &window) {

    heartT.loadFromFile("heart.png");
    Sprite sheart;
    sheart.setTexture(heartT);

    heartS.push_back(sheart);
    heartS[0].setPosition(view.getCenter().x-window.getSize().x/2+hero->getPosition().x,view.getCenter().y-window.getSize().y+hero->getPosition().y);
    heartS[0].setOrigin(hero->getPosition()+Vector2f(window.getSize().x/6+10,window.getSize().y/6));

    heartS.push_back(sheart);
    heartS[1].setPosition(view.getCenter().x-window.getSize().x/2+hero->getPosition().x,view.getCenter().y-window.getSize().y+hero->getPosition().y);
    heartS[1].setOrigin(hero->getPosition()+Vector2f(window.getSize().x/6-20,window.getSize().y/6));

    heartS.push_back(sheart);
    heartS[2].setPosition(view.getCenter().x-window.getSize().x/2+hero->getPosition().x,view.getCenter().y-window.getSize().y+hero->getPosition().y);
    heartS[2].setOrigin(hero->getPosition()+Vector2f(window.getSize().x/6-50,window.getSize().y/6));

    heartS.push_back(sheart);
    heartS[3].setPosition(view.getCenter().x-window.getSize().x/2+hero->getPosition().x,view.getCenter().y-window.getSize().y+hero->getPosition().y);
    heartS[3].setOrigin(hero->getPosition()+Vector2f(window.getSize().x/6-80,window.getSize().y/6));
    cout<<pos.x<<" , "<<pos.y<<endl;
    heartS.push_back(sheart);
    heartS[4].setPosition(view.getCenter().x-window.getSize().x/2+hero->getPosition().x,view.getCenter().y-window.getSize().y+hero->getPosition().y);
    heartS[4].setOrigin(hero->getPosition()+Vector2f(window.getSize().x/6-110,window.getSize().y/6));

    //distance=Vector2f(hero->getPosition().x-window.getSize().x/2,hero->getPosition().y-window.getSize().y/2);
    //distance = Vector2f(window.getSize().x/2-250,window.getSize().y/2-80);

    distanceHeart=Vector2f(hero->getPosition().x-window.getSize().x/2,hero->getPosition().y-window.getSize().y/2);

    //distanceHeart = Vector2f(view.getCenter().x-window.getSize().x/2+hero->getPosition().x,view.getCenter().y-window.getSize().y+hero->getPosition().y);
}*/
