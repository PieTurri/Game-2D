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
#include "ChoosCharacter.h"
#include "TileMap.h"

#include "Hero.h"
#include "Valkyrie.h"
#include "Knight.h"
#include "Level.h"
#include "Rules.h"
#include "Menu.h"
#include "Musica.h"
#include <thread>
#include <chrono>

using namespace sf;

class MenuLoop {
public:
    MenuLoop();

    ~MenuLoop();

    int getIndex();
    void generateScreen();

    bool permission=false;

    int index=0; // 0=Menù principale, 1=inizia gioco, 2=regole , 3=schermata mappa livelli

    Menu menu;
    Rules rules;
    ChoosCharacter choose;
    TileMap map;
    Level level;
    Musica songs;
    //Skeleton skeleton;

    int x_load=64;
    int y_load=64;
    bool noWall = true;

    int direction = 0; //indica la direzione in cui il nemico sta andando
                       //0->verso dx,1->verso sx,2->verso up,3->verso down
    void drawPlay();


private:

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
    sf::Sprite Esprite;
    sf::Texture Etexture;


    int flag = 0; // almeno la funzione escape una volta iniziato il gioco non può essere più usata

    bool shine = true;
    bool shineLevel = true;
    bool musicLoop = true;
    bool drawMapLevel = true;
    int mapScreen = 0;
    bool mapLevel = false;
    int flagMap = 0;


    //aggiunti da leo:
    Abstract_Factory* factory;
    Enemy_Abstract_Factory* Efactory;

    Hero* hero;
    Enemy* enemy;

    int* tilepos;

    Sprite spritePlayer;
    Texture texturePlayer;
    int typeMove=0;
    View view;
    View miniview;


    int h,w,spritex,spritey;

    bool startGame = false;
    bool firstK = true;

    bool moveU=false;
    bool moveD=false;
    bool moveL=false;
    bool moveR=false;

    Clock clockEnemy;
    Time timeEnemy;



    //forse si mette:
    Sprite* spriteItems;

};

#endif //PROJECT_MENULOOP_H
