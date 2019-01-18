//
// Created by piero on 10/12/18.
//

#include "MapLevel.h"
#include <iostream>
#include "Game.h"
#include "ChooseCharacter.h"

using namespace std;

MapLevel::MapLevel() : MapLevel(0) {}

MapLevel::MapLevel(int charInd): characterIndex(charInd),GraphicState() {

    width=1400;
    height=896;
    levelIndex=0;
    selected=false;
    sign=1;

    if(!texturel.loadFromFile("sfondomappalivelli-modified.png"))
        cout << "errore" << endl;

    spritel.setTexture(texturel);

    if(!texturem.loadFromFile("cloud.png"))
        cout<<"errore"<<endl;

    for(int i=0 ; i < 16 ; i++) {
        spritem[i].setTexture(texturem);
    }
}

MapLevel::~MapLevel() {}

void MapLevel::setScreenLevel() {

    if(!texturel.loadFromFile("sfondolivello.png"))
        cout << "ERRORE" << endl;

    if(!font.loadFromFile("DIOGENES.ttf"))
        cout << "errore" << endl;

    textl[0].setFont(font);
    textl[1].setFont(font);

    spritel.setTexture(texturel);

    textl[0].setString("Livello "+to_string(levelIndex+1));

    textl[1].setString("Il gioco iniziera' a breve...");

    textl[0].setFillColor(sf::Color(168,31,000));
    textl[1].setFillColor(sf::Color::White);

    textl[0].setPosition(width/2-75,height/2-100);
    textl[1].setPosition(width/2-200,height-250);

    textl[0].setCharacterSize(50);



}

void MapLevel::draw(RenderWindow &window) {

    if(selected){

        timer=clock.getElapsedTime();

        if(timer.asSeconds()>3){
            setState(true);
        }

        window.draw(spritel);
        for (int i = 0; i < 2; i++)
            window.draw(textl[i]);
    }
    else {

        window.draw(spritel);
        window.draw(spriteCharacterLevel);
        for(int i=0;i<16;i++)
            window.draw(spritem[i]);
        animation();

    }

}

void MapLevel::setScreen() {


    spritem[0].setPosition(sf::Vector2f(25, 200));
    textureCharacterLevel.loadFromFile("soulKnight.png");
    spriteCharacterLevel.setTexture(textureCharacterLevel);
    spriteCharacterLevel.setPosition(sf::Vector2f(180, 595));


    spritem[1].setPosition(sf::Vector2f(150, 150));

    spritem[2].setPosition(sf::Vector2f(250, 200));

    spritem[3].setPosition(sf::Vector2f(150, 275));

    spritem[4].setPosition(sf::Vector2f(1100, 600));

    spritem[5].setPosition(sf::Vector2f(950, 600));

    spritem[6].setPosition(sf::Vector2f(1000, 550));

    spritem[7].setPosition(sf::Vector2f(1000, 650));

    spritem[8].setPosition(sf::Vector2f(950, 330));

    spritem[9].setPosition(sf::Vector2f(1000, 280));

    spritem[10].setPosition(sf::Vector2f(1100, 330));

    spritem[11].setPosition(sf::Vector2f(1000, 380));

    spritem[12].setPosition(sf::Vector2f(900, 120));

    spritem[13].setPosition(sf::Vector2f(980, 180));

    spritem[14].setPosition(sf::Vector2f(1000, 120));

    spritem[15].setPosition(sf::Vector2f(980, 220));

}


void MapLevel::getActivities(Event event, RenderWindow &window) {

    if (!selected) {
        switch (event.type) {
            case sf::Event::KeyReleased:

                switch (event.key.code) {

                    case sf::Keyboard::Return:

                        setScreenLevel();

                        clock.restart();

                        selected = true;

                        break;

                    case sf::Keyboard::Escape:
                        setState(true);
                        break;

                    default:
                        break;

                }
                break;
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
        }
    }
    //songs.playMusic(music, index, mapScreen);

}

GraphicState *MapLevel::getNextState() {
    if(selected)
        return new Game(characterIndex,levelIndex);
    else
        return new ChooseCharacter;
}

void MapLevel::animation() {


    timer=clock.getElapsedTime();

    if(timer.asSeconds()>0.5) {
        sign *= (-1);
        spriteCharacterLevel.move(0,sign*20);
        clock.restart();
    }
}




