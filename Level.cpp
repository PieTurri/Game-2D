//
// Created by piero on 10/12/18.
//

#include "Level.h"
#include <iostream>

using namespace std;
Level::Level() {}

Level::~Level() {}

void Level::setScreenLevel(Texture &texturel, Sprite &spritel, Text *textl, Font &font) {

    if(!texturel.loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/sfondolivello.png"))
        cout << "ERRORE" << endl;

    if(!font.loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/DIOGENES.ttf"))
        cout << "errore" << endl;
    textl[0].setFont(font);
    textl[1].setFont(font);

    spritel.setTexture(texturel);

    switch (levelIndex){

        case 0:

            textl[0].setString("Livello 1");

            break;

        case 1:

            textl[0].setString("Livello 2");

            break;

        case 2:

            textl[0].setString("Livello 3");

            break;

        case 3:

            textl[0].setString("Livello 4");

            break;

        case 4:

            textl[0].setString("Livello 5");

            break;

        default:
            break;
    }


    textl[1].setString("Premi Enter per iniziare");

    textl[0].setFillColor(sf::Color(168,31,000));
    textl[1].setFillColor(sf::Color::White);

    textl[0].setPosition(width/2-75,height/2-100);

    textl[0].setCharacterSize(50);



}

void Level::draw(RenderWindow &window, Text *textl) {

    for(int i = 0; i < 2; i++)
        window.draw(textl[i]);
}

void Level::setMapLevelScreen(Texture &texturel,Sprite &spritel,Texture *texturem,Sprite *spritem,Texture &textureCharacterLevel, Sprite &spriteCharacterLevel) {

    if(!texturel.loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/sfondomappalivelli-modified.png"))
        cout << "errore" << endl;

    spritel.setTexture(texturel);

    texturem[0].loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/cloud1.png");
    spritem[0].setPosition(sf::Vector2f(25, 200));
    textureCharacterLevel.loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/soulKnight.png");
    spriteCharacterLevel.setTexture(textureCharacterLevel);
    spriteCharacterLevel.setPosition(sf::Vector2f(180, 595));


    texturem[1].loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/cloud1.png");
    spritem[1].setPosition(sf::Vector2f(150, 150));

    texturem[2].loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/cloud1.png");
    spritem[2].setPosition(sf::Vector2f(250, 200));

    texturem[3].loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/cloud1.png");
    spritem[3].setPosition(sf::Vector2f(150, 275));

    texturem[4].loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/cloud1.png");
    spritem[4].setPosition(sf::Vector2f(1100, 600));

    texturem[5].loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/cloud1.png");
    spritem[5].setPosition(sf::Vector2f(950, 600));

    texturem[6].loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/cloud1.png");
    spritem[6].setPosition(sf::Vector2f(1000, 550));

    texturem[7].loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/cloud1.png");
    spritem[7].setPosition(sf::Vector2f(1000, 650));

    texturem[8].loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/cloud1.png");
    spritem[8].setPosition(sf::Vector2f(950, 330));

    texturem[9].loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/cloud1.png");
    spritem[9].setPosition(sf::Vector2f(1000, 280));

    texturem[10].loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/cloud1.png");
    spritem[10].setPosition(sf::Vector2f(1100, 330));

    texturem[11].loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/cloud1.png");
    spritem[11].setPosition(sf::Vector2f(1000, 380));

    texturem[12].loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/cloud1.png");
    spritem[12].setPosition(sf::Vector2f(900, 120));

    texturem[13].loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/cloud1.png");
    spritem[13].setPosition(sf::Vector2f(980, 180));

    texturem[14].loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/cloud1.png");
    spritem[14].setPosition(sf::Vector2f(1000, 120));

    texturem[15].loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/cloud1.png");
    spritem[15].setPosition(sf::Vector2f(980, 220));

}

void Level::drawCloud(Texture *texturem, Sprite *spritem) {
    for(int i=0 ; i < 16 ; i++) {
        spritem[i].setTexture(texturem[i]);
    }
}





