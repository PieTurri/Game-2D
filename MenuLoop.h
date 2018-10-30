//
// Created by piero on 9/28/18.
//

//#include "Rules.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>



#ifndef PROJECT_MENULOOP_H
#define PROJECT_MENULOOP_H

#include "ChoosCharacter.h"

#include "TileMap.h"
#include "Level.h"
#include "Rules.h"
#include "Menu.h"
#include "Musica.h"
#include <thread>
#include <chrono>

class MenuLoop {
public:
    MenuLoop();

    ~MenuLoop();

    int getIndex();
    void generateScreen();


    bool permission=false;

    int index=0; // 0=Menù principale, 1=inizia gioco, 2=regole , 3=schermata mappa livelli




protected:

    sf::Event event;
    sf::Texture texture;
    sf::Texture texture2;
    sf::Sprite sprite;
    sf::RenderWindow window;
    sf::Font font;
    sf::Text text[4];
    sf::Text textRules[3];
    sf::Texture texture1[5];
    sf::Sprite spriteC[5];
    sf::Music music;
    sf::Music music1;
    sf::Text textC;
    sf::Texture texturel;
    sf::Texture texturem[16];
    sf::Sprite spritel;
    sf::Sprite spritem[16];
    sf::Text textl[2];
    sf::Font font1;
    sf::Texture textureCharacterLevel;
    sf::Sprite spriteCharacterLevel;





    int flag = 0; // almeno la funzione escape una volta iniziato il gioco non può essere più usata

    bool shine = true;
    bool shineLevel = true;
    bool musicLoop = true;
    bool drawMapLevel = true;
    int mapScreen = 0;
    bool mapLevel = false;
    int flagMap = 0;


};

#endif //PROJECT_MENULOOP_H
