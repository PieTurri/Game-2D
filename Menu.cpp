//
// Created by piero on 9/27/18.
//

#include <iostream>
#include "Menu.h"



using namespace std;
using namespace sf;

Menu::Menu(float width,float height) {
}

Menu::Menu() {}

Menu::~Menu(){
}


void Menu::draw(RenderWindow &window,Text *text)
{
    for (int i = 0; i < 4; i++)
    {
        window.draw(text[i]);
    }
}

void Menu::MoveUp(Text *text)
{
    if (selectedMenuIndex - 1 >= 0)
    {
        a=false;
        text[selectedMenuIndex].setFillColor(sf::Color::Black);
        selectedMenuIndex--;
        text[selectedMenuIndex].setFillColor(sf::Color(168,31,000));
    }
}

void Menu::MoveDown(Text *text)
{
    if (selectedMenuIndex + 1 < 3)
    {
        a=false;
        text[selectedMenuIndex].setFillColor(sf::Color::Black);
        selectedMenuIndex++;
        text[selectedMenuIndex].setFillColor(sf::Color(168,31,000));
    }
}




void  Menu::setMenuScreen(Texture &texture,Sprite &sprite,sf::Font &font,sf::Text *text){

    texture.loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/SchermataIniziale.png");

    if(!texture.loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/SchermataIniziale.png"))
        cout << "errore" << endl;

    sprite.setTexture(texture);

    if(!font.loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/DIOGENES.ttf"))
        cout << "errore" << endl;

    text[0].setFont(font);
    if( a || selectedMenuIndex == 0){ // a serve per far colorare la prima text del menu in modo corretto
        text[0].setFillColor(sf::Color(168,31,000));
    }else
        text[0].setFillColor(sf::Color::Black);
    text[0].setString("Start Game");
    text[0].setPosition(sf::Vector2f((width / 2)+700,height / (3+2) * 1));

    text[1].setFont(font);
    text[1].setFillColor(sf::Color::Black);
    text[1].setString("Rules");
    text[1].setPosition(sf::Vector2f((width / 2)+700, height / (3+2) * 2));

    text[2].setFont(font);
    if(selectedMenuIndex != 2)
        text[2].setFillColor(sf::Color::Black);
    text[2].setString("Exit");
    text[2].setPosition(sf::Vector2f((width / 2)+700, height / (3+2) * 3));

    text[3].setFont(font);
    text[3].setFillColor(sf::Color(168,31,000));
    text[3].setString("Nome Gioco");
    text[3].setPosition(sf::Vector2f((width / 2)-150, height / (3+2)));
}

void Menu::Menuclear(sf::Text *text) {
    for (int i = 0; i < 4; i++)
    {

        text[i].setString("");
    }
};


