//
// Created by leogori on 02/04/19.
//

#include <chrono>
#include <random>
#include "BossLevel.h"
#include "Menu.h"

using namespace std;

BossLevel::BossLevel(Hero *hero, RenderWindow &window) {

    factory=Abstract_Factory::create(0);

    map=factory->createBossMap();

    pausable=true;

    this->hero=hero;

    hero->setPosition(Vector2f(128,128));

    enemy.push_back(new Enemy);

    cout<<"NEMICO DISEGNATO"<<endl;

    setView(window);

    texture.loadFromFile("sclaus.jpg");
    sprite.setTexture(texture);

    pos=getRandomPosition();

    //sprite.setPosition(pos);

    sprite.setPosition(400,500);

}

void BossLevel::draw(RenderWindow &window) {

    update();

    setView(window);

    map->draw(window);
    hero->draw(window);
    enemy[0]->drawBoss(window,sprite);
    //enemy[0]->moveEnemy(map);

}

void BossLevel::setScreen() {

}

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

void BossLevel::update() {

    hero->setDirection();

    if (hero->getDirRight())
        hero->moveRight(map);

    if (hero->getDirLeft())
        hero->moveLeft(map);

    if (hero->getDirUp())
        hero->moveUp(map);

    if (hero->getDirDown())
        hero->moveDown(map);
}


Vector2f BossLevel::getRandomPosition() {

    unsigned seed= static_cast<unsigned int>(chrono::system_clock::now().time_since_epoch().count());

    default_random_engine generator(seed);

    uniform_int_distribution<int> distribution(0,72);

    float x=distribution(generator);
    float y=distribution(generator);

    Vector2f pos(x*64,y*67);

    return pos;
}
