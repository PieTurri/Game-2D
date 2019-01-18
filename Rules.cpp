//
// Created by piero on 9/28/18.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Rules.h"
#include "Menu.h"

using namespace std;
using namespace sf;


Rules::Rules(): Rules(700,450)  {

    if(!texture.loadFromFile("schermatasole.png"))
        cout << "errore" << endl;

    sprite.setTexture(texture);

    if(!font.loadFromFile("DIOGENES.ttf"))
        cout << "errore" << endl;
}

Rules::Rules(float w, float h) : width(w), height(h), GraphicState() {}

Rules::~Rules() {}

void Rules::setScreen() {

    textRules[0].setString("Regole");
    textRules[0].setFont(font);
    textRules[0].setFillColor(sf::Color::Black);
    textRules[0].setPosition(sf::Vector2f((width / 2), height / (3+2) * 1));

    textRules[1].setString("Corpo delle regole");
    textRules[1].setFont(font);
    textRules[1].setFillColor(sf::Color::Black);
    textRules[1].setPosition(sf::Vector2f((width / 2), height / (3+2) * 2));

    textRules[2].setString("Premi esc per tornare alla home");
    textRules[2].setFont(font);
    textRules[2].setCharacterSize(45);
    textRules[2].setFillColor(sf::Color::Black);
    textRules[2].setPosition(sf::Vector2f((width / 2)+100, height / (3+2) * 9));
}

void Rules::draw(RenderWindow &window)
{

    window.draw(sprite);
    for (int i = 0; i < 3; i++)
    {
        window.draw(textRules[i]);
    }
}

void Rules::getActivities(Event event, RenderWindow &window) {

    switch (event.type) {

        case sf::Event::KeyReleased:

            switch (event.key.code) {

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

GraphicState *Rules::getNextState() {

    return new Menu;
}





