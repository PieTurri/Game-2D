//
// Created by piero on 9/28/18.
//

//#include "Rules.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include "Abstract_Factory.h"
#include "Menu.h"
#include "Rules.h"
#include "ChoosCharacter.h"
#include "TileMap.h"

#include "Hero.h"
#include "Valkyrie.h"
#include "Knight.h"


#ifndef PROJECT_MENULOOP_H
#define PROJECT_MENULOOP_H


using namespace sf;

class MenuLoop {
public:
    MenuLoop();

    virtual ~MenuLoop();

    int getIndex();
    void generateScreen(sf::RenderWindow &window);

private:

    int index=0; // 0=Menù principale, 1=inizia gioco, 2=regole, 3=(schermata livello)/mappa



    sf::Event event;
    sf::Texture texture;
    sf::Sprite sprite;

    Menu menu;
    Rules rules;
    ChoosCharacter choose;
    TileMap map;

    sf::Font font;
    sf::Text text[4];
    sf::Text textRules[3];
    sf::Texture texture1[5];
    sf::Sprite spriteC[5];
    sf::Music music;
    sf::Text textC;

    //aggiunti da leo:
    Abstract_Factory* factory;
    Hero* hero;


    int* tilepos;

    Sprite spritePlayer;
    Texture texturePlayer;
    int typeMove=0;
    View view;
    View miniview;

    int spritex=32*20;
    int spritey=32*20;

};

#endif //PROJECT_MENULOOP_H
