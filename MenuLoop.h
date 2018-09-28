//
// Created by piero on 9/28/18.
//

#include "Rules.h"


#ifndef PROJECT_MENULOOP_H
#define PROJECT_MENULOOP_H


class MenuLoop {
public:
    MenuLoop();
    int getIndex();

protected:
    int index=0; // 0=Menù principale

    sf::Event event;
    sf::Texture texture;
    sf::Sprite sprite;
};


#endif //PROJECT_MENULOOP_H
