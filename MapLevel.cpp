//
// Created by piero on 10/12/18.
//

#include "MapLevel.h"
#include <iostream>
#include "Game.h"
#include "ChooseCharacter.h"

using namespace std;

//MapLevel::MapLevel(RenderWindow &window) : MapLevel(0, window) {}

MapLevel::MapLevel(int charInd, RenderWindow &window) : characterIndex(charInd), GraphicState() {

    setScreen();
    setView(window);
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

        if(timer.asSeconds()>0){
            setState(true);
        }

        window.draw(spritel);
        for (int i = 0; i < 2; i++)
            window.draw(textl[i]);
    }
    else {

        window.draw(spritel);
        window.draw(spriteCharacterLevel);

        for(int j = 0;j<cloud.size();j++)
            window.draw(cloud[j]);

        //cout << "->cloud size : "<<cloud.size()<<endl;

        animation();

    }
}

void MapLevel::setScreen() {

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

    textureCharacterLevel.loadFromFile("soulKnight.png");
    spriteCharacterLevel.setTexture(textureCharacterLevel);
    spriteCharacterLevel.setPosition(sf::Vector2f(180, 595));

    ////Oridne mondi: 1.Arcontus; 2.Mirinthas; 3.Etras; 4.Castrisand; 5.Punk Hazard

    spritem.setTexture(texturem);

    cloud.push_back(spritem);
    cloud[0].setTexture(texturem);
    cloud[0].setPosition(sf::Vector2f(980, 220));

    cloud.push_back(spritem);
    cloud[1].setTexture(texturem);
    cloud[1].setPosition(sf::Vector2f(1000, 120));

    cloud.push_back(spritem);
    cloud[2].setTexture(texturem);
    cloud[2].setPosition(sf::Vector2f(980, 180));

    cloud.push_back(spritem);
    cloud[3].setTexture(texturem);
    cloud[3].setPosition(sf::Vector2f(900, 120));

    cloud.push_back(spritem);
    cloud[4].setTexture(texturem);
    cloud[4].setPosition(sf::Vector2f(1000, 380));

    cloud.push_back(spritem);
    cloud[5].setTexture(texturem);
    cloud[5].setPosition(sf::Vector2f(1100, 330));

    cloud.push_back(spritem);
    cloud[6].setTexture(texturem);
    cloud[6].setPosition(sf::Vector2f(1000, 280));

    cloud.push_back(spritem);
    cloud[7].setTexture(texturem);
    cloud[7].setPosition(sf::Vector2f(950, 300));

    cloud.push_back(spritem);
    cloud[8].setTexture(texturem);
    cloud[8].setPosition(sf::Vector2f(1000, 650));

    cloud.push_back(spritem);
    cloud[9].setTexture(texturem);
    cloud[9].setPosition(sf::Vector2f(1000, 550));

    cloud.push_back(spritem);
    cloud[10].setTexture(texturem);
    cloud[10].setPosition(sf::Vector2f(950, 600));

    cloud.push_back(spritem);
    cloud[11].setTexture(texturem);
    cloud[11].setPosition(sf::Vector2f(1100, 600));

    cloud.push_back(spritem);
    cloud[12].setTexture(texturem);
    cloud[12].setPosition(sf::Vector2f(150, 275));

    cloud.push_back(spritem);
    cloud[13].setTexture(texturem);
    cloud[13].setPosition(sf::Vector2f(250, 200));

    cloud.push_back(spritem);
    cloud[14].setTexture(texturem);
    cloud[14].setPosition(sf::Vector2f(150, 150));

    cloud.push_back(spritem);
    cloud[15].setTexture(texturem);
    cloud[15].setPosition(sf::Vector2f(25,200));

/*
    text.setString("Achievement");
    text.setFont(font);
    text.setFillColor(sf::Color::White);
    text.setPosition(sf::Vector2f((width / 2)+65, height / (3+2)-70));
    text.setCharacterSize(25);*/

}


void MapLevel::getActivities(Event event, RenderWindow &window) {

    if (!selected) {
        switch (event.type) {
            case sf::Event::KeyReleased:

                switch (event.key.code) {

                    case sf::Keyboard::Return:

                        /*setScreenLevel();
                        clock.restart();
                        */
                        selected = true;
                        setState(true);

                        /*levelIndex++;
                        deleteClouds(levelIndex);
                        */
                        break;

                    case sf::Keyboard::Escape:
                        setState(true);
                        break;

                    case sf::Keyboard::Right:
                        moveCharRight();
                        break;

                    case sf::Keyboard::Left:
                        moveCharLeft();
                        break;

                    case sf::Keyboard::C:
                        levelIndex++;
                        deleteClouds(levelIndex);
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

GraphicState *MapLevel::getNextState(RenderWindow &window) {
    if(selected)
        return new Game(characterIndex,levelIndex,window);
    else
        return new ChooseCharacter(window);
}

void MapLevel::animation() {

    timer=clock.getElapsedTime();

    if(timer.asSeconds()>0.5) {
        sign *= (-1);
        spriteCharacterLevel.move(0,sign*20);
        clock.restart();
    }
}

void MapLevel::setView(RenderWindow &window) {

    Vector2f v(texturel.getSize());
    view.setSize(v);
    view.setCenter(v.x/2,v.y/2);
    window.setView(view);
}

void MapLevel::deleteClouds(int levelIndex) {

    switch(levelIndex){
        case 1:
            for(int j = 0;j<4;j++)
                cloud.pop_back();
            levelLocked[levelIndex+1]=true;
            break;
        case 2:
            for(int j = 4;j<8;j++)
                cloud.pop_back();
            levelLocked[levelIndex+1]=true;
            break;
        case 3:
            for(int j = 8;j<12;j++)
                cloud.pop_back();
            levelLocked[levelIndex+1]=true;
            break;
        case 4:
            for(int j = 12;j<16;j++)
                cloud.pop_back();
            levelLocked[levelIndex+1]=true;
            break;
        default:
            break;
    }

}

void MapLevel::moveCharRight() {
    lineIndex++;
    if(levelLocked[levelIndex+1] && lineIndex<5){
        spriteCharacterLevel.setPosition(mapLevelPos[lineIndex][0],mapLevelPos[lineIndex][1]);
    }
    else if(lineIndex >= 5) lineIndex--;
}

void MapLevel::moveCharLeft() {
    lineIndex--;
    if(lineIndex>=0)
        spriteCharacterLevel.setPosition(mapLevelPos[lineIndex][0],mapLevelPos[lineIndex][1]);
    else lineIndex++;
}

