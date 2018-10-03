//
// Created by piero on 9/28/18.
//

#include <iostream>
#include "MenuLoop.h"
#include "Menu.h"
#include "Rules.h"
#include "ChoosCharacter.h"
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

MenuLoop::MenuLoop() {}

int MenuLoop::getIndex() {
    return index;
}

void MenuLoop::generateScreen() {

    window.create(sf::VideoMode(1400, 900), "Leo&Pie Game");

    Menu menu;
    Rules rules;
    ChoosCharacter choose;


    music.openFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/Excalibur.ogg");
    music.play();

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
                                switch (menu.GetPressedItem()) {
                                    case 0:
                                        index = 1;
                                        choose.setChooseCharacterScreen(texture, sprite, font,texture1,spriteC);
                                        break;
                                    case 1:
                                        index = 2;
                                        rules.setRulesScreen(texture, sprite, textRules, font);
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

            } else if (getIndex() == 1) {

                switch (event.type) {

                    case sf::Event::KeyReleased:

                        switch (event.key.code) {

                            case sf::Keyboard::Escape:
                                index = 0;
                                menu.selectedMenuIndex = 0;
                                menu.a = true;
                                menu.setMenuScreen(texture, sprite, font, text);
                                break;
                        }
                        break;
                    case sf::Event::Closed:
                        window.close();
                        break;
                }

            } else if (getIndex() == 2) {
                switch (event.type) {

                    case sf::Event::KeyReleased:

                        switch (event.key.code) {

                            case sf::Keyboard::Escape:
                                index = 0;
                                menu.selectedMenuIndex = 0;
                                menu.a = true;
                                menu.setMenuScreen(texture, sprite, font, text);
                                break;
                        }
                        break;
                    case sf::Event::Closed:
                        window.close();
                        break;
                }
            }
        }
        window.clear();

        window.draw(sprite);
        if (index == 0)
            menu.draw(window, text);

        if (index == 1){
            choose.draw(spriteC, texture1);
            for(int i=0; i < 5 ; i++)
                window.draw(spriteC[i]);
        }
        if (index == 2)
            rules.draw(window, textRules);

        window.display();
    }
}