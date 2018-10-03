//
// Created by piero on 9/28/18.
//

//#include "Rules.h"

#include <SFML/Graphics.hpp>



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
    sf::Text text[4];



};

#endif //PROJECT_MENULOOP_H
