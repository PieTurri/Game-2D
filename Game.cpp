//
// Created by leogori on 21/12/18.
//
#include "Game.h"
#include "Knight.h"
#include "Valkyrie.h"
#include "Skeleton.h"
#include "FireBall.h"
#include "ChooseCharacter.h"
#include <random>
#include <chrono>

using namespace std;
using namespace sf;

//Game::Game() : Game(-1,-1) {}

Game::Game(int characterIndex, int levInd, RenderWindow &window) : levelIndex(levInd), map() {

    cout<<"INIZIATO"<<endl;

    hero=Hero::Create(characterIndex);
    Vector2f pos=getRandomPosition();

    while(!map.getTileWalkability(pos))
        pos=getRandomPosition();

    hero->setPosition(pos);

    Clock clock;
    Time times;

    for(int i=0;i<10;i++){

        enemyTime.push_back(times);
        enemyClock.push_back(clock);

        pos=getRandomPosition();

        enemy.push_back(new Skeleton(8,3));

        while(!map.getTileWalkability(pos))
            pos=getRandomPosition();

        enemy[i]->setPosition(pos);
    }

    pause=false;

    setHeart(window);
    setView(window);

    view.setSubject(hero);
}

Game::~Game() {

    delete hero;
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

    return new ChooseCharacter(window);
}

void Game::draw(RenderWindow &window) {


    map.draw(window);

    for(int i=0; i<heartS.size();i++)
        window.draw(heartS[i]);

    hero->draw(window);

    for (int i = 0; i < heroProjectile.size(); i++)
        heroProjectile[i]->draw(window);

    for (int i = 0; i < enemyProjectile.size(); i++)
        enemyProjectile[i]->draw(window);

    for (int i = 0; i < enemy.size(); i++) {

        enemy[i]->draw(window);
    }

    if(!pause){
        update(window);
    }
}

void Game::setView(RenderWindow &window) {

    view.setSize(Vector2f(640,480));
    view.setCenter(hero->getPosition());
    window.setView(view);
}

void Game::lookForCollision() {

    vector<Obstacle> &obstacle = map.getObstacle();

    if (!heroProjectile.empty()) {

        for (int i = 0; i < heroProjectile.size(); i++) {

            vector<Enemy *>::iterator it = enemy.begin();

            for (int j = 0; j < enemy.size(); j++) {

                if((heroProjectile[i]->getDimension()).intersects(enemy[j]->getDimension())){
                    enemy[j]->setHp(enemy[j]->getHp() - heroProjectile[i]->getDamage());
                    cout << enemy[j]->getHp() << endl;
                    heroProjectile[i]->setDestroyed();
                }

                if (enemy[j]->getHp() <= 0) {
                    map.setTileWalkability(enemy[j]->getPosition(), true);
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

            if (!map.getTileWalkability(heroProjectile[i]->getPosition()))
                heroProjectile[i]->setDestroyed();
        }
    }

    if (!enemyProjectile.empty()) {

        for (int i = 0; i < enemyProjectile.size(); i++) {


            if (enemyProjectile[i]->getDimension().intersects(hero->getDimension())) {
                hero->setHp(hero->getHp() - enemyProjectile[i]->getDamage());

                //cout << hero->getHp() << endl;
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

            if (!map.getTileWalkability(enemyProjectile[i]->getPosition()))
                enemyProjectile[i]->setDestroyed();
        }
    }

    map.setObstacle(obstacle);
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

    if(hero->getWeaponUse()&&heroTime.asSeconds()>heroWeapon->getRateOfFire()){

        heroClock.restart();
        heroProjectile.push_back(new FireBall(hero->getPosition(),heroWeapon->getAimedPoint()));
        heroProjectile[heroProjectile.size()-1]->setSpeed(5);
    }

    for(int i=0;i<enemy.size();i++){

        Weapon* enemyWeapon=enemy[i]->getWeapon();

        enemyTime[i]=enemyClock[i].getElapsedTime();

        if(enemy[i]->getWeaponUse()&&enemyTime[i].asSeconds()>enemyWeapon->getRateOfFire()){
            enemyClock[i].restart();
            enemyProjectile.push_back(new FireBall(enemy[i]->getPosition(),enemyWeapon->getAimedPoint()));
            enemyProjectile[enemyProjectile.size()-1]->setSpeed(0.7);
        }
    }
}

void Game::update(RenderWindow &window) {

    if (!pause) {

        if (hero->isStill())
            view.followHero();

        hero->setDirection();

        if (hero->getDirRight())
            if (!map.getTileWalkability(hero->moveRight()))
                hero->moveLeft();


        if (hero->getDirLeft())
            if (!map.getTileWalkability(hero->moveLeft()))
                hero->moveRight();


        if (hero->getDirUp())
            if (!map.getTileWalkability(hero->moveUp()))
                hero->moveDown();


        if (hero->getDirDown())
            if (!map.getTileWalkability(hero->moveDown()))
                hero->moveUp();

        for (int i = 0; i < enemy.size(); i++) {

            enemy[i]->changeStrategy(hero, map);
            enemy[i]->moveEnemy(map);
            enemy[i]->aim(hero->getPosition());

            if (enemy[i]->hasFiringStrategy())
                enemy[i]->setWeaponUse(true);
            else
                enemy[i]->setWeaponUse(false);
        }

        window.setView(view);

        createProjectile();
        manageProjectile();
        lookForCollision();
    }

}

Vector2f Game::getRandomPosition() {

    unsigned seed=chrono::system_clock::now().time_since_epoch().count();

    default_random_engine generator(seed);

    uniform_int_distribution<int> distribution(0,72);

    float x=distribution(generator);
    float y=distribution(generator);

    Vector2f pos(x*32,y*32);

    cout<<pos.x<<" , "<<pos.y<<endl;

    return pos;
}

void Game::setHeart(RenderWindow &window) {

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

    heartS.push_back(sheart);
    heartS[4].setPosition(view.getCenter().x-window.getSize().x/2+hero->getPosition().x,view.getCenter().y-window.getSize().y+hero->getPosition().y);
    heartS[4].setOrigin(hero->getPosition()+Vector2f(window.getSize().x/6-110,window.getSize().y/6));

    //distance=Vector2f(hero->getPosition().x-window.getSize().x/2,hero->getPosition().y-window.getSize().y/2);
    //distance = Vector2f(window.getSize().x/2-250,window.getSize().y/2-80);

    distanceHeart=Vector2f(hero->getPosition().x-window.getSize().x/2,hero->getPosition().y-window.getSize().y/2);

    //distanceHeart = Vector2f(view.getCenter().x-window.getSize().x/2+hero->getPosition().x,view.getCenter().y-window.getSize().y+hero->getPosition().y);
}
