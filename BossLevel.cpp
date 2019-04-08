//
// Created by leogori on 02/04/19.
//

#include "BossLevel.h"
#include <iostream>
#include "Menu.h"

using namespace std;

BossLevel::BossLevel(Hero *hero, RenderWindow &window) {

    map.setWall(1);

    map.setTextFileName("mappaBoss");

    map.setTileMap();

    map.findDimension();

    map.load("Tileset1.png",Vector2u(32,32));

    this->hero=hero;

    hero->setPosition(Vector2f(128,128));

    setView(window);

}

void BossLevel::draw(RenderWindow &window) {

    map.draw(window);
    hero->draw(window);

}

void BossLevel::setScreen() {

    cout<<"non servo a niente"<<endl;
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

    view.setSize(Vector2f(map.getWidth()*32,map.getHeight()*32));
    view.setCenter(map.getWidth()/2*32,map.getHeight()/2*32);
    window.setView(view);

}

/*void BossLevel::update() {

    hero->setDirection();

    if (hero->getDirRight())
        hero->moveRight(map);

    if (hero->getDirLeft())
        hero->moveLeft(map);

    if (hero->getDirUp())
        hero->moveUp(map);

    if (hero->getDirDown())
        hero->moveDown(map);
}*/
