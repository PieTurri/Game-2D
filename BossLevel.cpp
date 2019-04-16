//
// Created by leogori on 02/04/19.
//

#include <chrono>
#include <random>
#include "BossLevel.h"
#include "Menu.h"

using namespace std;

BossLevel::BossLevel(Hero *hero, RenderWindow &window, Abstract_Factory *factory) {

    map=factory->createBossMap();

    pausable=true;

    this->hero=hero;

    hero->setPosition(Vector2f(128,128));

    heart.setHeroLife(hero->getHp());

    heart.setHeart(window);

    enemy=factory->createBoss();

    setView(window);

    Vector2f pos;

    do{
        pos=getRandomPosition();
    } while(!map->getTile(pos).getEnemyWalkability());

    enemy->setPosition(pos);

}

BossLevel::~BossLevel() {

    delete hero;
    delete enemy;
    delete map;
}

void BossLevel::draw(RenderWindow &window) {

    update(window);

    setView(window);

    map->draw(window);

    heart.draw(window);
    enemy->draw(window);
    hero->draw(window);

    for (int i = 0; i < heroProjectile.size(); i++)
        heroProjectile[i]->draw(window);

    for (int i = 0; i < enemyProjectile.size(); i++)
        enemyProjectile[i]->draw(window);
}

void BossLevel::setScreen() {}

GraphicState *BossLevel::getNextState(RenderWindow &window) {

    return new Menu(window);
}

void BossLevel::getActivities(Event event, RenderWindow &window) {

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

void BossLevel::setView(RenderWindow &window) {

    view.setSize(Vector2f(map->getWidth()*32,map->getHeight()*32));
    view.setCenter(map->getWidth()/2*32,map->getHeight()/2*32);
    window.setView(view);

}

void BossLevel::update(RenderWindow &window) {

    heart.setHeart(window);

    hero->setDirection();

    if (hero->getDirRight())
        hero->moveRight(map);

    if (hero->getDirLeft())
        hero->moveLeft(map);

    if (hero->getDirUp())
        hero->moveUp(map);

    if (hero->getDirDown())
        hero->moveDown(map);

    enemy->changeStrategy(hero, map);
    enemy->moveEnemy(map);
    enemy->aim(hero->getPosition());
    enemy->setWeaponUse(enemy->hasFiringStrategy());

    createProjectile();
    manageProjectile();
    lookForCollision();

    if (hero->getHp() <= 0||enemy->getHp()<=0){
        setState(true);
    }
}


Vector2f BossLevel::getRandomPosition() {

    unsigned seed= static_cast<unsigned int>(chrono::system_clock::now().time_since_epoch().count());

    default_random_engine generator(seed);

    uniform_int_distribution<int> heightDistribution(0,map->getWidth());
    uniform_int_distribution<int> widthDistribution(0,map->getHeight());

    cout<<"dimensioni mappa: "<<map->getHeight()<<" , ";
    cout<<map->getWidth()<<endl;

    float x=widthDistribution(generator);
    float y=heightDistribution(generator);

    cout<<"posizione casuale nemico: "<<x<<" , "<<y<<endl;

    Vector2f pos(y*32,x*32);

    return pos;
}

void BossLevel::lookForCollision() {

    if (!heroProjectile.empty()) {

        for (int i = 0; i < heroProjectile.size(); i++) {


            if((heroProjectile[i]->getDimension()).intersects(enemy->getDimension())){
                enemy->setHp(enemy->getHp() - heroProjectile[i]->getDamage());
                heroProjectile[i]->setDestroyed();
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

            if (!map->getTile(enemyProjectile[i]->getPosition()).getHeroWalkability())
                enemyProjectile[i]->setDestroyed();
        }
    }
}

void BossLevel::manageProjectile() {

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

void BossLevel::createProjectile() {

    Weapon* heroWeapon=hero->getWeapon();

    heroTime=heroClock.getElapsedTime();

    if(hero->getWeaponUse()&&heroTime.asSeconds()>heroWeapon->getRateOfFire()/*&&
       map->isFightingGround(map->getTile(hero->getPosition()))*/){

        heroClock.restart();

        Projectile *projectile=Projectile::create(heroWeapon->getProjectile());
        projectile->setPosition(heroWeapon->getPosition());
        projectile->setAimedPoint(heroWeapon->getAimedPoint());
        projectile->setOrientation();
        projectile->setSpeed(5);

        heroProjectile.push_back(projectile);
    }


    Weapon* enemyWeapon=enemy->getWeapon();

    enemyTime=enemyClock.getElapsedTime();

    if(enemy->getWeaponUse()&&enemyTime.asSeconds()>enemyWeapon->getRateOfFire()
       /*&&map->isFightingGround(map->getTile(hero->getPosition()))*/){
        enemyClock.restart();

        Projectile *projectile=Projectile::create(enemyWeapon->getProjectile());
        projectile->setPosition(enemyWeapon->getPosition());
        projectile->setAimedPoint(enemyWeapon->getAimedPoint());
        projectile->setOrientation();
        projectile->setSpeed(2);

        enemyProjectile.push_back(projectile);

    }
}
