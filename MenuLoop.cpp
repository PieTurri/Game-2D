/*
//
// Created by piero on 9/28/18.
//

#include "MenuLoop.h"
#include "Graphic.h"
#include "Menu.h"
#include "Game.h"
#include "Achievement.h"

using namespace std;
using namespace sf;

MenuLoop::MenuLoop() {

    window.create(sf::VideoMode(1400,900), "Leo&Pie Game");
    index=0;
    mapScreen=0;
}

void MenuLoop::generateScreen() {

    Graphic graphic(new Menu(window));

    int a=0;
    songs.playMusic(music, a, mapScreen);
    music.setLoop(true);

    while (window.isOpen()) {

        while (window.pollEvent(event)) {

            graphic.setInput(event, window);
        }

        if (graphic.getState()) {
            graphic.changeState(window);

            if(dynamic_cast<Game*>(graphic.getGraphicState())!=NULL){
                gameObserver.setSubject(graphic.getGraphicState());
            if(dynamic_cast<Achievement*>(graphic.getGraphicState())!=NULL) {
                dynamic_cast<Achievement*>(graphic.getGraphicState())->setGameObserver(gameObserver);

            }
                //music.openFromFile("Music/Forest.ogg");
                music.setLoop(false);
                music.stop();
            }

        }

        window.clear();

        graphic.draw(window);

        window.display();
    }
}

MenuLoop::~MenuLoop()=default;

*/

//
// Created by piero on 9/28/18.
//

#include "MenuLoop.h"
#include "Graphic.h"
#include "Menu.h"
#include "Game.h"
#include "Achievement.h"

using namespace std;
using namespace sf;

MenuLoop::MenuLoop() {

    window.create(sf::VideoMode(1400,900), "Leo&Pie Game");
    index=0;
    mapScreen=0;
}

void MenuLoop::generateScreen() {

    Graphic graphic(new Menu(window));

    songs.playMusic(music, index, mapScreen);

    while (window.isOpen()) {

        while (window.pollEvent(event)) {

            graphic.setInput(event, window);
        }

        if (graphic.getState()) {
            graphic.changeState(window);
            if(dynamic_cast<Game*>(graphic.getGraphicState())!=NULL){
                gameObserver.setSubject(graphic.getGraphicState());
                //music.openFromFile("Music/Forest.ogg");
                music.setLoop(false);
                music.stop();
            }
            if(dynamic_cast<Achievement*>(graphic.getGraphicState())!=NULL) {
                dynamic_cast<Achievement*>(graphic.getGraphicState())->setGameObserver(gameObserver);

            }
        }

        window.clear();

        graphic.draw(window);

        window.display();
    }
}

MenuLoop::~MenuLoop()=default;