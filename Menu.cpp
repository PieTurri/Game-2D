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

void Menu::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(text[i]);
    }
}

void Menu::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        text[selectedItemIndex].setFillColor(sf::Color::Red);
        selectedItemIndex--;
        text[selectedItemIndex].setFillColor(sf::Color::White);
    }
}

void Menu::MoveDown()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        text[selectedItemIndex].setFillColor(sf::Color::Red);
        selectedItemIndex++;
        text[selectedItemIndex].setFillColor(sf::Color::White);
    }
}



void  Menu::setMenuScreen(Texture &texture,Sprite &sprite,sf::Font &font,sf::RenderWindow &window){


    texture.loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/SchermataIniziale.png");
    sprite.setTexture(texture);

    if(!font.loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/DIOGENES.ttf"))
        cout << "errore" << endl;

    text[0].setFont(font);
    text[0].setFillColor(sf::Color::White);
    text[0].setString("Start Game");
    text[0].setPosition(sf::Vector2f(width / 2,height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    text[1].setFont(font);
    text[1].setFillColor(sf::Color::Red);
    text[1].setString("Rules");
    text[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    text[2].setFont(font);
    text[2].setFillColor(sf::Color::Red);
    text[2].setString("Exit");
    text[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

    //selectedItemIndex = 0;

    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(text[i]);
    }
};


