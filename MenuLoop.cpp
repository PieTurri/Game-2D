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
    Rules rules;
    //index=0;
    while (window.isOpen()) {

        while (window.pollEvent(event)) {

            if (getIndex() == 0) {

                menu.setMenuScreen(texture, sprite, font, text);

                switch (event.type) {

                    case sf::Event::KeyReleased:

                        switch (event.key.code) {

                            case sf::Keyboard::Up:
                                menu.MoveUp(text);
                                break;

                            case sf::Keyboard::Down:
                                menu.MoveDown(text);
                                break;

                            case sf::Keyboard::Escape:
                                window.close();
                                break;

                            case sf::Keyboard::Return:
                                switch (menu.GetPressedItem())
                                {
                                    case 0:
                                        index = 1;
                                        break;
                                    case 1:
                                        index = 2;
                                        rules.setRulesScreen(texture,sprite);
                                        break;
                                    case 2:
                                        window.close();
                                        break;
                                }
                                break;
                        }
                        break;

                    case sf::Event::Closed:
                        window.close();
                        break;
                }
            }else if(getIndex() == 2){
                switch (event.type){

                    case sf::Event::KeyReleased:

                        switch (event.key.code){

                            case sf::Keyboard::Escape:
                                window.close();
                                break;
                        }
                    case sf::Event::Closed:
                        window.close();
                        break;
                }
            }
        }
    window.clear();

    window.draw(sprite);
    if(index == 0)
        menu.draw(window,text);
    window.display();
    }
}


