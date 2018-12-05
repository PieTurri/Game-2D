//
// Created by piero on 10/3/18.
//

#include <iostream>
#include "ChoosCharacter.h"


using namespace std;
using namespace sf;

ChoosCharacter::ChoosCharacter() {}

ChoosCharacter::~ChoosCharacter() {}

void ChoosCharacter::setChooseCharacterScreen(sf::Texture &texture,sf::Sprite &sprite,sf::Font &font,sf::Texture *texture1,sf::Sprite *spriteC,sf::Text &textC) {

    texture.loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/sfondopersonaggio.png");

    if(!texture.loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/sfondopersonaggio.png"))
        cout << "errore" << endl;
    if(!font.loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/DIOGENES.ttf"))
        cout << "errore" << endl;

    textC.setString("Scegli il personaggio");
    textC.setFont(font);
    textC.setFillColor(Color::Black);
    textC.setPosition(sf::Vector2f((width-120), height / (3+2) * 1));

    texture1[0].loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/knight2.jpg"); //immagini da 200*300
    spriteC[0].setPosition(sf::Vector2f(100, 250));
    index[0] = 0;

    texture1[1].loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/deadpool.png"); //immagini da 200*300
    spriteC[1].setPosition(sf::Vector2f(350, 250));
    index[1] = 1;

    texture1[2].loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/deadpool.png"); //immagini da 200*300
    spriteC[2].setPosition(sf::Vector2f(600, 250));
    index[2] = 2;

    texture1[3].loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/deadpool.png"); //immagini da 200*300
    spriteC[3].setPosition(sf::Vector2f(850, 250));
    index[3] = 3;

    texture1[4].loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/deadpool.png"); //immagini da 200*300
    spriteC[4].setPosition(sf::Vector2f(1100, 250));
    index[4] = 4;

}

void ChoosCharacter::draw(sf::Sprite *spriteC, sf::Texture *texture1) {

    for(int i=0 ; i < 5 ; i++)
        spriteC[i].setTexture(texture1[i]);
}

void ChoosCharacter::drawC(sf::RenderWindow &window, sf::Text &textC) {
    window.draw(textC);
}

bool ChoosCharacter::isLocked(int setindex) {

    switch(setindex){
        case 0:
            return knightLocked;

        case 1:
            return valkyrieLocked;

        case 2:
            return ninjaLocked;

        case 3:
            return wizardLocked;

        case 4:
            return planetarLocked;
        default:
            break;
    }
}

bool ChoosCharacter::setLocked(int setindex) {
    switch(setindex){
        case 0:
            knightLocked = true;
            return knightLocked;
        case 1:
            valkyrieLocked = true;
            return valkyrieLocked;

    }
}

void ChoosCharacter::MoveRight(sf::Texture *texture1,sf::Sprite *spriteC) {

    if ( setindex <= 4 && setindex >= 0)
    {
        first = false;
        if(!isLocked(setindex+1)){
            spriteC[setindex].setColor(sf::Color::Black);
            setindex++;
            spriteC[setindex].setColor(sf::Color(168,31,000));
        }
    }

}
void ChoosCharacter::MoveLeft(sf::Texture *texture1,sf::Sprite *spriteC) {

    if (setindex > 0 && setindex <=4)
    {
        first = false;
        spriteC[setindex].setColor(sf::Color::Black);
        setindex--;
        if(setindex >= 0)
            spriteC[setindex].setColor(sf::Color(168,31,000));

    }

}
bool ChoosCharacter::setFree() {
    return false;
}

const int *ChoosCharacter::getIndex() const {
    return index;
}

bool ChoosCharacter::isSelected() {
    if(iselected)
        return true;
    else
        return false;
}


