//
// Created by piero on 9/28/18.
//

#include "MenuLoop.h"
#include "Game.h"

using namespace std;
using namespace sf;

MenuLoop::MenuLoop() {

    window.create(sf::VideoMode(1400, 896), "Leo&Pie Game");
    view.setSize(320,320);
    //view.zoom();
    view.setCenter(Vector2f(64,64));
    //view[1].setViewport(FloatRect(0.75f,0.f,0.25f,0.25f));
    index=0;
    mapScreen=0;
}

void MenuLoop::generateScreen() {

    Graphic graphic(new Menu);

    songs.playMusic(music, index, mapScreen);

    graphic.setScreen();

    while (window.isOpen()) {

        while (window.pollEvent(event)) {

            graphic.movement(event, window);
        }

        if (graphic.getState()) {
            graphic.changeState();
            graphic.setScreen();
        }

        //cout << graphic.getState() << endl;

        window.clear();

        graphic.draw(window);

        window.display();
    }
}


MenuLoop::~MenuLoop() = default;

