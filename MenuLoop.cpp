//
// Created by piero on 9/28/18.
//
#include <SFML/Audio.hpp>
#include <iostream>
#include "MenuLoop.h"
#include "Menu.h"
#include "Rules.h"
#include "ChoosCharacter.h"
#include "TileMap.h"
#include "Dungeon.h"
#include "Hero.h"
#include "Abstract_Factory.h"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;

 MenuLoop::MenuLoop(RenderWindow &window) {

    window.create(sf::VideoMode(1400, 896), "Leo&Pie Game");

    Menu menu;
    Rules rules;
    ChoosCharacter choose;
    TileMap map;
    //Dungeon map;



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
                                        choose.setChooseCharacterScreen(texture, sprite, font,texture1,spriteC,textC);
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

                            case sf::Keyboard::Left:
                                choose.MoveLeft(texture1,spriteC);
                                break;

                            case sf::Keyboard::Right:
                                choose.MoveRight(texture1,spriteC);
                                break;

                            case sf::Keyboard::Return:

                                switch (choose.GetPressedItem()) {

                                    case 0 :
                                        k=0;

                                        //if (!map.load("/home/piero/Documents/Programmazione/Project2/Project/Risorse/Tileset.png", sf::Vector2u(32, 32), map.level, 45, 28))
                                        //  cout << "Errore caricamento mappa" << endl;


                                        /*switch(event.type){
                                            case sf::Event::Closed:
                                                window.close();
                                                break;
                                        }*/
                                        break;

                                        /*case 1 :
                                            if (!map.load("/home/piero/Documents/Programmazione/Project2/Project/Risorse/Tileset.png", sf::Vector2u(32, 32), map.level, 45, 28))
                                                cout << "Errore caricamento mappa" << endl;

                                           *//* switch(event.type){
                                            case sf::Event::Closed:
                                                window.close();
                                                break;
                                        }*//*
                                        break;*/
                                }
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
            choose.drawC(window,textC);
        }
        if (index == 2)
            rules.draw(window, textRules);

        if(choose.getIndex())
            window.draw(map);

        window.display();
    }
}

int MenuLoop::getIndex() {
    return index;
}

void MenuLoop::generateScreen() {


}

MenuLoop::~MenuLoop() {

}
