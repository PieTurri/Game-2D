//
// Created by piero on 10/3/18.
//

#include <iostream>
#include "ChoosCharacter.h"


using namespace std;
using namespace sf;

ChoosCharacter::ChoosCharacter() {}

ChoosCharacter::~ChoosCharacter() {}

void ChoosCharacter::setChooseCharacterScreen(sf::Texture &texture,sf::Sprite &sprite,sf::Font &font,sf::Texture *texture1,sf::Sprite *spriteC) {

    texture.loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/sfondopersonaggio.png");

    if(!texture.loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/sfondopersonaggio.png"))
        cout << "errore" << endl;

    texture1[0].loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/knight2.jpg"); //immagini da 200*300
    spriteC[0].setPosition(sf::Vector2f(100, 250));

    texture1[1].loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/deadpool.png"); //immagini da 200*300
    spriteC[1].setPosition(sf::Vector2f(350, 250));

    texture1[2].loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/deadpool.png"); //immagini da 200*300
    spriteC[2].setPosition(sf::Vector2f(600, 250));

    texture1[3].loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/deadpool.png"); //immagini da 200*300
    spriteC[3].setPosition(sf::Vector2f(850, 250));

    texture1[4].loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/deadpool.png"); //immagini da 200*300
    spriteC[4].setPosition(sf::Vector2f(1100, 250));

}

void ChoosCharacter::draw(sf::Sprite *spriteC, sf::Texture *texture1) {

    for(int i=0 ; i < 5 ; i++)
    spriteC[i].setTexture(texture1[i]);
}
