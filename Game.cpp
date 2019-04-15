//
// Created by leogori on 21/12/18.
//
#include "Game.h"
#include "Menu.h"
#include "BossLevel.h"
#include <random>
#include <chrono>

using namespace std;
using namespace sf;

Game::Game(int characterIndex, int levInd, RenderWindow &window) : heart() {

    pausable=true;

    hero=Hero::Create(characterIndex);

    factory=Abstract_Factory::create(levInd);

    map=factory->createMap();

    Vector2f pos;
    Tile tile;

    hero->setPosition(map->getHeroStartingPosition());

    Clock clock;
    Time times;

    for(int i=0;i<25;i++){

        enemyTime.push_back(times);
        enemyClock.push_back(clock);
        enemy.push_back(factory->createEnemy());

        do{
            pos=getRandomPosition();
            tile=map->getTile(pos);
        } while(!map->isFightingGround(tile));

        enemy[i]->setPosition(pos);
    }

    heart.setHeroLife(hero->getHp());
    heart.setHeart(window);
    setView(window);
    view.setSubject(hero);
    int a=1;
    int b=0;

    songs->playMusic(music, a, b);

}

Game::~Game() {

    hero->removeObserver();
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
                        setState(true);
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

    if(hero->getHp()>0)
        return new BossLevel(hero, window);
    else
        return new Menu(window);
}

void Game::draw(RenderWindow &window) {

    update(window);

    map->draw(window);

    heart.draw(window);

    hero->draw(window);

    for (int i = 0; i < heroProjectile.size(); i++)
        heroProjectile[i]->draw(window);

    for (int i = 0; i < enemyProjectile.size(); i++)
        enemyProjectile[i]->draw(window);

    for (int i = 0; i < enemy.size(); i++){
        enemy[i]->draw(window);
    }
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
                    notify();
                    j--;
                } else
                    it++;

            }

            for (int j = 0; j < obstacle.size(); j++) {

                if (heroProjectile[i]->getDimension().intersects(obstacle[j].getDimension())){
                    //obstacle[j].setDestroyed(true);
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
                hero->setHp(hero->getHp() - enemyProjectile[i]->getDamage());
                enemyProjectile[i]->setDestroyed();
                heart.update(hero->getHp());
            }

            if (hero->getHp() <= 0)
                setState(true);

            for (int j = 0; j < obstacle.size(); j++) {

                if (enemyProjectile[i]->getDimension().intersects(obstacle[j].getDimension())) {
                    //obstacle[j].setDestroyed(true);
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
            projectile->setSpeed(2);

            enemyProjectile.push_back(projectile);

        }
    }
}

void Game::update(RenderWindow &window) {

    heart.setHeart(window);

    time=clock.getElapsedTime();
    notify();

    if (hero->isStill())
        hero->notify();

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

    if (enemy.empty())
        map->openBossDoor();

    if (enemy.empty() && map->isBossDoor(map->getTile(hero->getPosition())))
        setState(true);

    window.setView(view);

    createProjectile();
    manageProjectile();
    lookForCollision();

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

vector<Enemy *> &Game::getEnemy() {
    return enemy;
}

Time Game::getCompletedGameTime() {

    return time;
}
