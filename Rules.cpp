//
// Created by piero on 9/28/18.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Rules.h"
#include "Menu.h"

using namespace std;
using namespace sf;


Rules::Rules() {}

Rules::~Rules() {}

bool Rules::isOpen() {
    return false;
}

void Rules::setRulesScreen(Texture &texture ) {

    Sprite sprite;

    texture.loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/schermatasole.png");
    sprite.setTexture(texture);

    //static Menu::~Menu();

    //static Texture::update(texture);


}


