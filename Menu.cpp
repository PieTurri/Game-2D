//
// Created by piero on 9/27/18.
//

#include<iostream>
#include "Menu.h"
#include "ChooseCharacter.h"
#include "Rules.h"
#include "Achievement.h"

#define RED sf::Color(168,31,000)


using namespace std;
using namespace sf;

Menu::Menu(RenderWindow &window) : Menu(700, 450, window) {}

Menu::Menu(float w, float h, RenderWindow &window) : width(w), height(h) , GraphicState() {

    pausable=false;
    setScreen();
    setView(window);
}

Menu::~Menu(){
}


void Menu::draw(RenderWindow &window)
{

    window.draw(sprite);
    for (int i = 0; i < 5; i++)
    {
        window.draw(text[i]);
    }
}

void Menu::MoveUp()
{
    if (selectedTextIndex > 0)
    {
        text[selectedTextIndex].setFillColor(Color::Black);
        selectedTextIndex--;
        text[selectedTextIndex].setFillColor(RED);
    }
}

void Menu::MoveDown()
{
    if (selectedTextIndex < 3)
    {
        text[selectedTextIndex].setFillColor(Color::Black);
        selectedTextIndex++;
        text[selectedTextIndex].setFillColor(RED);
    }
}

void  Menu::setScreen(){

    selectedTextIndex=0;

    texture.loadFromFile("SchermataIniziale.png");

    if(!texture.loadFromFile("SchermataIniziale.png"))
        cout << "errore" << endl;

    sprite.setTexture(texture);

    if(!font[0].loadFromFile("DIOGENES.ttf"))
        cout << "errore" << endl;
    if(!font[1].loadFromFile("Seagram tfb.ttf"))
        cout << "errore" << endl;

    text[0].setFont(font[0]);
    text[0].setFillColor(sf::Color(RED));
    text[0].setString("Start Game");
    text[0].setPosition(sf::Vector2f((width / 2)+700,height / (3+2) * 1));
    text[0].setCharacterSize(40);

    text[1].setFont(font[0]);
    text[1].setFillColor(sf::Color::Black);
    text[1].setString("Rules");
    text[1].setPosition(sf::Vector2f((width / 2)+730, height / (3+2) * 2));
    text[1].setCharacterSize(40);

    text[2].setFont(font[0]);
    text[2].setFillColor(sf::Color::Black);
    text[2].setString("Achievement");
    text[2].setPosition(sf::Vector2f((width / 2)+730, height / (3+2) * 3));
    text[2].setCharacterSize(40);

    text[3].setFont(font[0]);
    text[3].setFillColor(sf::Color::Black);
    text[3].setString("Exit");
    text[3].setPosition(sf::Vector2f((width / 2)+730, height / (3+2) * 4));
    text[3].setCharacterSize(40);

    text[4].setFont(font[1]);
    text[4].setFillColor(sf::Color(RED));
    text[4].setString("Nome Gioco");
    text[4].setPosition(sf::Vector2f((width / 2)-240, height / (3+2)));
    text[4].setCharacterSize(50);
}

void Menu::getActivities(Event event,RenderWindow &window) {

    window.setView(view);

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

GraphicState *Menu::getNextState(RenderWindow &window) {

    switch (selectedTextIndex) {
        case 0:
            return new ChooseCharacter(window,false);

        case 1:
            return new Rules(window);

        case 2:
            return new Achievement(window);
        case 3:
            window.close();

        default:
            break;
    }

}

void Menu::setView(RenderWindow &window) {

    Vector2f v(texture.getSize());
    view.setSize(v);
    view.setCenter(v.x/2,v.y/2);
    window.setView(view);

}
