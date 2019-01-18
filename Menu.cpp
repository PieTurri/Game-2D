//
// Created by piero on 9/27/18.
//

#include <iostream>
#include "Menu.h"
#include "ChooseCharacter.h"
#include "Rules.h"


using namespace std;
using namespace sf;

Menu::Menu(float w,float h): width(w),height(h) ,GraphicState() {}

Menu::Menu():Menu(700,450) {

    selectedTextIndex=0;
    redText = true;

    texture.loadFromFile("SchermataIniziale.png");

    if(!texture.loadFromFile("SchermataIniziale.png"))
        cout << "errore" << endl;

    sprite.setTexture(texture);

    if(!font[0].loadFromFile("DIOGENES.ttf"))
        cout << "errore" << endl;
    if(!font[1].loadFromFile("Seagram tfb.ttf"))
        cout << "errore" << endl;
}


Menu::~Menu(){
}


void Menu::draw(RenderWindow &window)
{
    window.draw(sprite);
    for (int i = 0; i < 4; i++)
    {
        window.draw(text[i]);
    }
}

void Menu::MoveUp()
{
    if (selectedTextIndex - 1 >= 0)
    {
        redText=false;
        text[selectedTextIndex].setFillColor(sf::Color::Black);
        selectedTextIndex--;
        text[selectedTextIndex].setFillColor(sf::Color(168,31,000));
    }
}

void Menu::MoveDown()
{
    if (selectedTextIndex + 1 < 3)
    {
        redText=false;
        text[selectedTextIndex].setFillColor(sf::Color::Black);
        selectedTextIndex++;
        text[selectedTextIndex].setFillColor(sf::Color(168,31,000));
    }
}

void  Menu::setScreen(){

    text[0].setFont(font[0]);
    if( redText || selectedTextIndex == 0){ // a serve per far colorare la prima text del menu in modo corretto
        text[0].setFillColor(sf::Color(168,31,000));
    }else
        text[0].setFillColor(sf::Color::Black);
    text[0].setString("Start Game");
    text[0].setPosition(sf::Vector2f((width / 2)+700,height / (3+2) * 1));
    text[0].setCharacterSize(40);

    text[1].setFont(font[0]);
    text[1].setFillColor(sf::Color::Black);
    text[1].setString("Rules");
    text[1].setPosition(sf::Vector2f((width / 2)+730, height / (3+2) * 2));
    text[1].setCharacterSize(40);

    text[2].setFont(font[0]);

    if(selectedTextIndex != 2)
        text[2].setFillColor(sf::Color::Black);
    text[2].setString("Exit");
    text[2].setPosition(sf::Vector2f((width / 2)+730, height / (3+2) * 3));
    text[2].setCharacterSize(40);


    text[3].setFont(font[1]);
    text[3].setFillColor(sf::Color(168,31,000));
    text[3].setString("Nome Gioco");
    text[3].setPosition(sf::Vector2f((width / 2)-240, height / (3+2)));
    text[3].setCharacterSize(50);
}

void Menu::getActivities(Event event,RenderWindow &window) {

    switch (event.type) {

        case sf::Event::KeyReleased:

            switch (event.key.code) {

                case sf::Keyboard::Up:
                    MoveUp();
                    break;

                case sf::Keyboard::Down:
                    MoveDown();
                    break;

                case sf::Keyboard::Escape:
                    window.close();
                    break;

                case sf::Keyboard::Return:
                    if (selectedTextIndex == 2)
                        window.close();
                    else
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

GraphicState *Menu::getNextState() {

    switch (selectedTextIndex) {
        case 0:
            return new ChooseCharacter;
        case 1:
            return new Rules;
        default:
            break;
    }
    cout<<"ciao";

}



