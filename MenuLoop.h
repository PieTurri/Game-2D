//
// Created by piero on 9/28/18.
//

//#include "Rules.h"





#ifndef PROJECT_MENULOOP_H
#define PROJECT_MENULOOP_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include "Abstract_Factory.h"
#include "Menu.h"
#include "ChooseCharacter.h"
#include "TileMap.h"

#include "Hero.h"
#include "Valkyrie.h"
#include "Knight.h"
#include "MapLevel.h"
#include "Rules.h"
#include "Menu.h"
#include "Musica.h"
#include "Graphic.h"
#include "GraphicState.h"

#include <thread>
#include <chrono>

using namespace sf;

class MenuLoop {
public:
    MenuLoop();

    ~MenuLoop();

    void generateScreen();

    Musica songs;
    //Skeleton skeleton;

private:

    int index;

    sf::Event event;
    sf::Texture texture;

    sf::Sprite sprite;
    sf::RenderWindow window;

    View view;

    sf::Music music;

    int mapScreen;

    //aggiunti da leo:
    //Abstract_Factory* factory;
    //Enemy_Abstract_Factory* Efactory;

    int h,w;


};

#endif //PROJECT_MENULOOP_H
