//
// Created by piero on 9/28/18.
//

#include "MenuLoop.h"
#include "Graphic.h"
#include "Menu.h"

using namespace std;
using namespace sf;

MenuLoop::MenuLoop() {

    window.create(sf::VideoMode(700,450), "Leo&Pie Game");
    index=0;
    mapScreen=0;
}

void MenuLoop::generateScreen() {

    Graphic graphic(new Menu(window));

    //songs.playMusic(music, index, mapScreen);

    graphic.setScreen();

    while (window.isOpen()) {

        while (window.pollEvent(event)) {

            graphic.movement(event, window);
        }

        if (graphic.getState()) {
            graphic.changeState(window);
        }

        //cout << graphic.changeStrategy() << endl;

        window.clear();

        graphic.draw(window);

        window.display();
    }
}

MenuLoop::~MenuLoop() = default;