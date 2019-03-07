//
// Created by leogori on 21/12/18.
//

#include "Game.h"
#include <cmath>

using namespace std;
using namespace sf;

//Game::Game() : Game(-1,-1) {}

Game::Game(int charInd, int levInd,RenderWindow& window) : characterIndex(charInd),levelIndex(levInd) {

    switch (characterIndex) {
        case 0:
            hero = new Knight(10, 16, 0);
            break;
        case 1:
            hero = new Valkyrie(10, 8, 1);
            break;
        default:
            break;
    }

    srand((unsigned)time(NULL));

    for(int i=0;i<10;i++){
        enemy.push_back(new Enemy);
       // cout <<"alert"<<endl;
        enemy[i]->setPosition(map);
    }

    setView(window);
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

                default:
                    break;
            }
            break;

        case Event::KeyPressed:
            switch (event.key.code) {
                case Keyboard::W:
                    hero->setDirUp(true);
                    if(map.getTileWalkability(hero->getPosition()-Vector2f(0,hero->getSpeed())))
                        hero->movement(window);
                    else
                        hero->setDirUp(false);
                    break;
                case Keyboard::S:
                    hero->setDirDown(true);
                    if(map.getTileWalkability(hero->getPosition()+Vector2f(0,hero->getSpeed())))
                        hero->movement(window);
                    else
                        hero->setDirDown(false);
                    break;
                case Keyboard::A:
                    hero->setDirLeft(true);
                    if(map.getTileWalkability(hero->getPosition()-Vector2f(hero->getSpeed(),0)))
                        hero->movement(window);
                    else
                        hero->setDirLeft(false);
                    break;
                case Keyboard::D:
                    hero->setDirRight(true);
                    if(map.getTileWalkability(hero->getPosition()+Vector2f(hero->getSpeed(),0)))
                        hero->movement(window);
                    else
                        hero->setDirRight(false);
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

    hero->setDirection();

}

GraphicState *Game::getNextState(RenderWindow &window) {
    return nullptr;
}

void Game::draw(RenderWindow &window) {

    lookForCollision();

    hero->useWeapon();

    if(hero->isStill())
        view.followCharPos(hero, window);

    map.draw(window);
    hero->draw(window, map);

    for(int i=0;i<enemy.size();i++){

        enemy[i]->changeStrategy(hero,map);

        enemy[i]->moveEnemy(map);

        enemy[i]->draw(window,map);
    }
}

void Game::setView(RenderWindow &window) {

    view.setSize(Vector2f(640,480));
    view.setCenter(hero->getPosition());
    window.setView(view);
}

void Game::lookForCollision() {

    Weapon *weapon=hero->getWeapon();

    vector<Projectile*> projectile=weapon->getProjectile();

    vector <Obstacle>& obstacle=map.getObstacle();

    float radius=0;

    Vector2f distance;

    if(!projectile.empty()) {

        for (int i = 0; i < projectile.size(); i++) {

            for(int j=0;j<enemy.size();j++) {
                distance = projectile[i]->getPosition() - enemy[j]->getPosition();
                radius = (float) sqrt(pow(distance.x, 2) + pow(distance.y, 2));

                if (radius <= 16)
                    enemy[j]->setHp(enemy[j]->getHp() - projectile[i]->getDamage());
            }

            for(int j=0;j<obstacle.size();j++)
            {
                distance=projectile[i]->getPosition()-obstacle[j].getPosition();
                radius= (float)sqrt(pow(distance.x, 2) + pow(distance.y, 2));

                if(radius<=16) {
                    obstacle[j].setDestroyed(true);
                    projectile[i]->setDestroyed();
                    cout<<"ostacolo distrutto"<<endl;
                }
            }
            map.setObstacle(obstacle);

            if(!map.getTileWalkability(projectile[i]->getPosition()))
                projectile[i]->setDestroyed();
        }
    }
}
