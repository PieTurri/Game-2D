//
// Created by piero on 9/27/18.
//

#include <iostream>
#include "Menu.h"
#include "MenuLoop.h"
#include <SFML/Graphics.hpp>


using namespace std;

Menu::Menu(float width,float height) {
}






Menu::~Menu(){

}

void Menu::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}

void Menu::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::White);
    }
}

void Menu::MoveDown()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::White);
    }
}

void Menu::setMenuScreen() {

    texture.loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/SchermataIniziale.png");
    sprite.setTexture(texture);

    if(!font.loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/DIOGENES.ttf"))
        cout << "errore" << endl;

    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::White);
    menu[0].setString("Start Game");
    menu[0].setPosition(sf::Vector2f(width / 2,height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::Red);
    menu[1].setString("Rules");
    menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::Red);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

    selectedItemIndex = 0;

}
