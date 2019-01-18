//
// Created by leogori on 21/12/18.
//

#include "Game.h"
#include <iostream>

using namespace std;

Game::Game() : Game(-1,-1) {}

Game::Game(int charInd, int levInd) : characterIndex(charInd),levelIndex(levInd) {

    switch (characterIndex) {
        case 0:
            hero = new Knight(10, 8, 0);
            break;
        case 1:
            hero = new Valkyrie(10, 8, 1);
            break;
        default:
            break;
    }
}

void Game::setScreen() {

    cout<<"schermo settato"<<endl;
}

void Game::getActivities(Event event, RenderWindow &window) {

    switch (event.type) {

        case Event::KeyReleased:
            switch (event.key.code) {
                case Keyboard::Up:
                    hero->setDirUp(false);
                    break;
                case Keyboard::Down:
                    hero->setDirDown(false);
                    break;
                case Keyboard::Left:
                    hero->setDirLeft(false);
                    break;
                case Keyboard::Right:
                    hero->setDirRight(false);
                    break;

                default:
                    break;
            }
            break;

        case Event::KeyPressed:
            switch (event.key.code) {
                case Keyboard::Up:
                    hero->setDirUp(true);
                    break;
                case Keyboard::Down:
                    hero->setDirDown(true);
                    break;
                case Keyboard::Left:
                    hero->setDirLeft(true);
                    break;
                case Keyboard::Right:
                    hero->setDirRight(true);
                    break;
                default:
                    break;
            }
            break;

        case Event::Closed:
            window.close();
        default:
            break;
    }
    hero->movement(window);
}

GraphicState *Game::getNextState() {
    return nullptr;
}

void Game::draw(RenderWindow &window) {

    View view=window.getView();

    cout<<"dim  view: "<<view.getSize().x<<" , "<<view.getSize().y<<endl;

    map.updateRoomsItems();
    map.draw(window);
    hero->draw(window);
}