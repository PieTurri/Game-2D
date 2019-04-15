//
// Created by piero on 9/28/18.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Rules.h"
#include "Menu.h"

using namespace std;
using namespace sf;


Rules::Rules(RenderWindow &window) : Rules(700, 450, window) {}

Rules::Rules(float w, float h, RenderWindow &window) : width(w), height(h), GraphicState() {

    pausable=false;
    setScreen();
    setView(window);
}

Rules::~Rules() {}

void Rules::setScreen() {

    if(!texture.loadFromFile("schermatasole.png"))
        cout << "errore" << endl;

    sprite.setTexture(texture);

    if(!font.loadFromFile("DIOGENES.ttf"))
        cout << "errore" << endl;

    textRules[0].setString("Rules");
    textRules[0].setFont(font);
    textRules[0].setFillColor(sf::Color::Black);
    textRules[0].setPosition(sf::Vector2f((width / 2)+300, height / (3+2) * 1));
    textRules[0].setCharacterSize(50);

    textRules[1].setString("Premi esc per tornare alla home");
    textRules[1].setFont(font);
    textRules[1].setCharacterSize(45);
    textRules[1].setFillColor(sf::Color::Yellow);
    textRules[1].setPosition(sf::Vector2f((width / 2)+100, height / (3+2) * 9));

    textRules[2].setString("Press :");
    textRules[2].setFont(font);
    textRules[2].setCharacterSize(40);
    textRules[2].setFillColor(sf::Color::Black);
    textRules[2].setPosition(sf::Vector2f(880,220));

    textRules[3].setString("P ->");
    textRules[3].setFont(font);
    textRules[3].setCharacterSize(50);
    textRules[3].setFillColor(sf::Color::Black);
    textRules[3].setPosition(sf::Vector2f(950,325));

    if(!textureWASD[0].loadFromFile("wasd_.png")){
        cout<<"errore"<<endl;
    }

    spriteWASD[0].setTexture(textureWASD[0]);
    spriteWASD[0].setPosition(sf::Vector2f(0,220));

    if(!textureWASD[1].loadFromFile("leftClick.png")){
        cout<<"errore"<<endl;
    }

    spriteWASD[1].setTexture(textureWASD[1]);
    spriteWASD[1].setPosition(sf::Vector2f(900,450));

    if(!textureWASD[2].loadFromFile("fireballR.png")){
        cout<<"errore"<<endl;
    }

    spriteWASD[2].setTexture(textureWASD[2]);
    spriteWASD[2].setPosition(sf::Vector2f(1100,490));

    if(!textureWASD[3].loadFromFile("playstop.png")){
        cout<<"errore"<<endl;
    }

    spriteWASD[3].setTexture(textureWASD[3]);
    spriteWASD[3].setPosition(sf::Vector2f(1050,275));

    if(!textureWASD[4].loadFromFile("g2.png")){
        cout<<"errore"<<endl;
    }

    spriteWASD[4].setTexture(textureWASD[4]);
    spriteWASD[4].setPosition(sf::Vector2f(470,220));

}

void Rules::draw(RenderWindow &window)
{

    window.draw(sprite);
    for(int j = 0;j < 5;j++)
        window.draw(spriteWASD[j]);
    for (int i = 0; i < 5; i++)
        window.draw(textRules[i]);

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

GraphicState *Rules::getNextState(RenderWindow &window) {

    return new Menu(window);
}

void Rules::setView(RenderWindow &window) {

    Vector2f v(texture.getSize());
    view.setSize(v);
    view.setCenter(v.x/2,v.y/2);
    window.setView(view);
}





