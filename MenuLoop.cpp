//
// Created by piero on 9/28/18.
//

#include <iostream>
#include "MenuLoop.h"
#include "Menu.h"
#include "Rules.h"

using namespace std;

MenuLoop::MenuLoop() {}

int MenuLoop::getIndex() {
    return index;
}

void MenuLoop::generateScreen() {
    window.create(sf::VideoMode(1400, 900), "Leo&Pie Game");
    Menu menu;
    //Text text;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            switch (event.type) {

                case sf::Event::KeyReleased:

                    switch (event.key.code) {
                        case sf::Keyboard::Escape:
                            window.close();
                            break;
                    }

                case sf::Event::Closed:
                    window.close();
                    break;
            }
            if(getIndex() == 0){

                menu.setMenuScreen(texture,sprite,font,text);

            }else if(getIndex() == 2){

                Rules rules;
                rules.setRulesScreen();

            }
        }
        window.clear();

        window.draw(sprite);

        menu.draw(window,text);

        window.display();
    }
}
