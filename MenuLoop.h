//
// Created by piero on 9/28/18.
//

//#include "Rules.h"

#include <SFML/Graphics.hpp>

#define MAX_NUMBER_OF_ITEMS 3

#ifndef PROJECT_MENULOOP_H
#define PROJECT_MENULOOP_H


class MenuLoop {
public:
    MenuLoop();

    int getIndex();
    void generateScreen();


protected:
    int index=0; // 0=Menù principale, 1=inizia gioco, 2=regole

    sf::Event event;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::RenderWindow window;
    sf::Font font;



};

#endif //PROJECT_MENULOOP_H
