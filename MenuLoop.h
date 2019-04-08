//
// Created by piero on 9/28/18.
//

//#include "Rules.h"





#ifndef PROJECT_MENULOOP_H
#define PROJECT_MENULOOP_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>

#include "Musica.h"
#include "GameObserver.h"

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

    sf::RenderWindow window;

    sf::Music music;

    int mapScreen;

    GameObserver gameObserver;

    int h,w;


};

#endif //PROJECT_MENULOOP_H
//incapsulamento di una funzione di Rendering: CARICARE LE TEXTURE ALL'INIZIO
//State Pattern  <<<---