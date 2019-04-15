//
// Created by piero on 9/28/18.
//

#ifndef PROJECT_MENULOOP_H
#define PROJECT_MENULOOP_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>

#include "Musica.h"
#include "GameObserver.h"

#include <thread>
#include <chrono>

//#include "ChooseCharacter.h"

using namespace sf;

class MenuLoop {
public:
    MenuLoop();

    ~MenuLoop();

    void generateScreen();


private:

    int index = 0;

    sf::Event event;

    sf::RenderWindow window;

    sf::Music music;

    Musica songs;

    int mapScreen;

    GameObserver gameObserver;

    int h,w;

    //ChooseCharacter cc;


};

#endif //PROJECT_MENULOOP_H
//incapsulamento di una funzione di Rendering: CARICARE LE TEXTURE ALL'INIZIO
//State Pattern  <<<---