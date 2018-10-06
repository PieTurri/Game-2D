//
// Created by piero on 9/28/18.
//

//#include "Rules.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>


#ifndef PROJECT_MENULOOP_H
#define PROJECT_MENULOOP_H


class MenuLoop {
public:
    MenuLoop();

    int getIndex();
    void generateScreen();

    sf::RenderWindow window;

private:

    int index=0; // 0=Menù principale, 1=inizia gioco, 2=regole

    sf::Event event;
    sf::Texture texture;
    sf::Sprite sprite;

    sf::Font font;
    sf::Text text[4];
    sf::Text textRules[3];
    sf::Texture texture1[5];
    sf::Sprite spriteC[5];
    sf::Music music;
    sf::Text textC;
};

#endif //PROJECT_MENULOOP_H
