//
// Created by piero on 9/28/18.
//

#include "MenuLoop.h"

using namespace std;
using namespace sf;

 MenuLoop::MenuLoop() {}
int MenuLoop::getIndex() {
    return index;
}

void MenuLoop::generateScreen() {


    Menu menu;
    Rules rules;
    ChoosCharacter choose;
    TileMap map;
    Level level;
    Musica songs;


    window.create(sf::VideoMode(1400, 896), "Leo&Pie Game");

    songs.playMusic(music, index, mapScreen);

    while (window.isOpen()) {

        while (window.pollEvent(event)) {

            if (getIndex() == 0) {

                menu.setMenuScreen(texture, sprite, font, text, font1);

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
                                        choose.setChooseCharacterScreen(texture, sprite, font, texture1, spriteC,
                                                                        textC);
                                        break;
                                    case 1:
                                        index = 2;
                                        rules.setRulesScreen(texture, sprite, textRules, font);
                                        break;
                                    case 2:
                                        window.close();
                                        break;
                                    default:
                                        break;
                                }
                                break;
                            default:
                                break;
                        }
                        break;

                    case sf::Event::Closed:
                        window.close();
                        break;
                    default:
                        break;
                }

            } else if (getIndex() == 1) {

                switch (event.type) {

                    case sf::Event::KeyReleased:

                        switch (event.key.code) {

                            case sf::Keyboard::Left:
                                choose.MoveLeft(texture1, spriteC);
                                break;

                            case sf::Keyboard::Right:
                                choose.MoveRight(texture1, spriteC);
                                break;

                            case sf::Keyboard::Escape:

                                switch (flag) {
                                    case 0:
                                        index = 0;
                                        menu.selectedMenuIndex = 0;
                                        menu.a = true;
                                        menu.setMenuScreen(texture, sprite, font, text, font1);
                                        break;
                                    case 1:
                                        index = 1;
                                        choose.setChooseCharacterScreen(texture, sprite, font, texture1, spriteC,
                                                                        textC);

                                        break;
                                    default:
                                        break;
                                }
                                break;

                            case sf::Keyboard::Return:

                                switch (choose.GetPressedItem()) {
                                    case 0 :

                                        permission = true;

                                        flag = 1;

                                        if (drawMapLevel) {

                                            level.setMapLevelScreen(texturel, spritel, texturem, spritem, textureCharacterLevel, spriteCharacterLevel);
                                            mapScreen = 1;


                                            switch (event.key.code) {

                                                case sf::Keyboard::Return:
                                                    flag = 1;
                                                    drawMapLevel = false;
                                                    flagMap = 1;
                                                    break;

                                                default:
                                                    break;
                                            }
                                            songs.playMusic(music, index, mapScreen);

                                        } else {


                                            flagMap = 0;
                                            level.setScreenLevel(texturel, spritel, textl, font);
                                            musicLoop = false;
                                            songs.playMusic(music, index, mapScreen);
                                        }

                                        break;

                                    default:
                                        break;
                                }
                                break;
                            default:
                                break;
                        }
                        break;

                    case sf::Event::Closed:
                        window.close();
                        break;

                    default:
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
                                menu.setMenuScreen(texture, sprite, font, text, font1);
                                break;

                            default:
                                break;
                        }
                        break;
                    case sf::Event::Closed:
                        window.close();
                        break;

                    default:
                        break;
                }
            }

        }

        window.clear();

        window.draw(sprite);
        if (index == 0)
            menu.draw(window, text);

        else if (index == 1) {

            choose.draw(spriteC, texture1);
            for (int i = 0; i < 5; i++)
                window.draw(spriteC[i]);
            choose.drawC(window, textC);

            if (!drawMapLevel) {
                if (permission) {   //disegna la schermata dei livelli
                    window.draw(spritel);

                    level.draw(window, textl);
                    if (shine) {
                        textl[1].setCharacterSize(40);
                        textl[1].setPosition(level.width / 2 - 180, level.height / 2 + 245);
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        shine = false;

                    } else if (!shine) {
                        textl[1].setCharacterSize(30);
                        textl[1].setPosition(level.width / 2 - 150, level.height / 2 + 250);
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        shine = true;
                    }

                }
            }

        }

        if (flagMap == 1) {
            level.drawCloud(texturem, spritem);

            for (int i = 0; i < 16; i++)
                    window.draw(spritem[i]);

            window.draw(spriteCharacterLevel);
            if (shineLevel) {
                spriteCharacterLevel.setPosition(sf::Vector2f(180, 595));
                std::this_thread::sleep_for(std::chrono::milliseconds(25));
                shineLevel = false;

            } else if (!shineLevel) {
                spriteCharacterLevel.setPosition(sf::Vector2f(180, 585));
                std::this_thread::sleep_for(std::chrono::milliseconds(25));
                shineLevel = true;
            }

        }

        if (index == 2) {
            rules.draw(window, textRules);
        }


            window.display();


    }
}

MenuLoop::~MenuLoop() = default;
