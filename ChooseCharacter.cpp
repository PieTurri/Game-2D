//
// Created by piero on 10/3/18.
//
#include <iostream>
#include "ChooseCharacter.h"
#include "MapLevel.h"
#include "Menu.h"

using namespace std;
using namespace sf;

ChooseCharacter::ChooseCharacter(RenderWindow &window, bool Mchange) : ChooseCharacter(700, 450, window) {

    if(Mchange){
        music.openFromFile("Music/Living_Room.ogg");
        music.play();
    }
}

ChooseCharacter::ChooseCharacter(float w, float h, RenderWindow &window) : width(w), height(h), GraphicState() {

    pausable=false;
    setScreen();
    setView(window);
    int a=0;
    int b=0;
    //songs.playMusic(music, a, b);
}

ChooseCharacter::~ChooseCharacter() {}

void ChooseCharacter::setScreen() {


    if(!tBackground.loadFromFile("sfondopersonaggio.png"))
        cout << "errore" << endl;

    setindex = 0;
    Selected = false;

    sprite.setTexture(tBackground);

    if(!font.loadFromFile("DIOGENES.ttf"))
        cout << "errore" << endl;

    tMessage.setString("Scegli il personaggio");
    tMessage.setFont(font);
    tMessage.setFillColor(Color::Black);
    tMessage.setPosition(sf::Vector2f((width-120), height / (3+2) * 1));

    //immagini da 200*300

    try {
        if(!tCharacter[0].loadFromFile("deadpool.png"))
            throw "Impossibile aprire immagine cavaliere";
        spriteC[0].setPosition(sf::Vector2f(100, 250));

        if(!tCharacter[1].loadFromFile("deadpool.png"))
            throw "Impossibile aprire file";
        spriteC[1].setPosition(sf::Vector2f(350, 250));

        if(!tCharacter[2].loadFromFile("deadpool.png"))
            throw "Impossibile aprire file";
        spriteC[2].setPosition(sf::Vector2f(600, 250));

        if(!tCharacter[3].loadFromFile("deadpool.png"))
            throw "Impossibile aprire file";
        spriteC[3].setPosition(sf::Vector2f(850, 250));

        if(!tCharacter[4].loadFromFile("deadpool.png"))
            throw "Impossibile aprire musica";
        spriteC[4].setPosition(sf::Vector2f(1100, 250));
    }
    catch (...){cout<<"Errore caricamento immagini scelta personaggii"<<endl;}

    for(int i=0 ; i < 5 ; i++)
        spriteC[i].setTexture(tCharacter[i]);

}

void ChooseCharacter::draw(RenderWindow &window) {

    window.draw(sprite);
    for(int i=0 ; i < 5 ; i++)
        window.draw(spriteC[i]);
    window.draw(tMessage);
}
void ChooseCharacter::MoveRight(sf::Sprite *spriteC) {

    if ( setindex >= 0 && setindex < 4)
    {
        animate(setindex, false);
        //spriteC[setindex].setColor(sf::Color::Yellow);
        setindex++;
        //spriteC[setindex].setColor(sf::Color(168,31,000));
        animate(setindex, true);
    }

}
void ChooseCharacter::MoveLeft(sf::Sprite *spriteC) {

    if (setindex > 0 && setindex <=4)
    {
        animate(setindex, false);
        //spriteC[setindex].setColor(sf::Color::Yellow);
        setindex--;
        //spriteC[setindex].setColor(sf::Color(168,31,000));
        animate(setindex, true);
    }
}
bool ChooseCharacter::isSelected() {
    return Selected;
}

void ChooseCharacter::getActivities(Event event, RenderWindow &window) {

    switch (event.type) {

        case sf::Event::KeyReleased:

            switch (event.key.code) {

                case sf::Keyboard::Left:
                    MoveLeft(spriteC);
                    break;

                case sf::Keyboard::Right:
                    MoveRight(spriteC);
                    break;

                case sf::Keyboard::Escape:
                    setState(true);
                    break;

                case sf::Keyboard::Return:
                    Selected=true;
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

GraphicState *ChooseCharacter::getNextState(RenderWindow &window) {

    if (Selected){
        music.stop();
        return new MapLevel(setindex, window);
    }
    else
        return new Menu(window);
}

void ChooseCharacter::setView(RenderWindow &window) {

    Vector2f v(tBackground.getSize());
    view.setSize(v);
    view.setCenter(v.x/2,v.y/2);
    window.setView(view);
}

void ChooseCharacter::animate(int i, bool change) {

    switch(change){
        case true:
            switch(i){
                case 0:
                    cout<<"0"<<endl;
                    tCharacter[i].loadFromFile("kn.png");
                    spriteC[i].setTexture(tCharacter[i]);
                    break;
                case 1:
                    cout<<"1"<<endl;
                    tCharacter[i].loadFromFile("pinguin.jpg");
                    spriteC[i].setTexture(tCharacter[i]);
                    break;//change = Mchange;
    cout<<"ECCOMI STRONZO"<<endl;
                case 2:
                    cout<<"2"<<endl;
                    tCharacter[i].loadFromFile("pinguin.jpg");
                    spriteC[i].setTexture(tCharacter[i]);
                    break;
                case 3:
                    cout<<"3"<<endl;
                    tCharacter[i].loadFromFile("pinguin.jpg");
                    spriteC[i].setTexture(tCharacter[i]);
                    break;
                case 4:
                    cout<<"4"<<endl;
                    tCharacter[i].loadFromFile("pinguin.jpg");
                    spriteC[i].setTexture(tCharacter[i]);
                    break;
                default:break;
            }
            break;
        case false:
            switch(i) {
                case 0:
                    cout << "0" << endl;
                    tCharacter[i].loadFromFile("knight2.jpg");
                    spriteC[i].setTexture(tCharacter[i]);
                    break;
                case 1:
                    cout << "1" << endl;
                    tCharacter[i].loadFromFile("deadpool.png");
                    spriteC[i].setTexture(tCharacter[i]);
                    break;
                case 2:
                    cout << "2" << endl;
                    tCharacter[i].loadFromFile("deadpool.png");
                    spriteC[i].setTexture(tCharacter[i]);
                    break;
                case 3:
                    cout << "3" << endl;
                    tCharacter[i].loadFromFile("deadpool.png");
                    spriteC[i].setTexture(tCharacter[i]);
                    break;
                case 4:
                    cout << "4" << endl;
                    tCharacter[i].loadFromFile("deadpool.png");
                    spriteC[i].setTexture(tCharacter[i]);
                    break;
                default:
                    break;
            }
    }
}