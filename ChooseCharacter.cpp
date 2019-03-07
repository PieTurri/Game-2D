//
// Created by piero on 10/3/18.
//


#include <iostream>
#include "ChooseCharacter.h"
#include "MapLevel.h"
#include "Menu.h"


using namespace std;
using namespace sf;

ChooseCharacter::ChooseCharacter(RenderWindow &window) : ChooseCharacter(700, 450, window) {}

ChooseCharacter::ChooseCharacter(float w, float h, RenderWindow &window) : width(w), height(h), GraphicState() {

    setScreen();
    setView(window);
}

ChooseCharacter::~ChooseCharacter() {}

void ChooseCharacter::setScreen() {


    if(!tBackground.loadFromFile("sfondopersonaggio.png"))
        cout << "errore" << endl;

    setindex = 0;

    valkyrieLocked = false;
    knightLocked = false;
    ninjaLocked = true;
    wizardLocked = true;
    planetarLocked = true;
    Selected = false;

    sprite.setTexture(tBackground);

    if(!font.loadFromFile("DIOGENES.ttf"))
        cout << "errore" << endl;

    tMessage.setString("Scegli il personaggio");
    tMessage.setFont(font);
    tMessage.setFillColor(Color::Black);
    tMessage.setPosition(sf::Vector2f((width-120), height / (3+2) * 1));

    tCharacter[0].loadFromFile("knight2.jpg"); //immagini da 200*300
    spriteC[0].setPosition(sf::Vector2f(100, 250));

    tCharacter[1].loadFromFile("deadpool.png"); //immagini da 200*300
    spriteC[1].setPosition(sf::Vector2f(350, 250));

    tCharacter[2].loadFromFile("deadpool.png"); //immagini da 200*300
    spriteC[2].setPosition(sf::Vector2f(600, 250));

    tCharacter[3].loadFromFile("deadpool.png"); //immagini da 200*300
    spriteC[3].setPosition(sf::Vector2f(850, 250));

    tCharacter[4].loadFromFile("deadpool.png"); //immagini da 200*300
    spriteC[4].setPosition(sf::Vector2f(1100, 250));

    for(int i=0 ; i < 5 ; i++)
        spriteC[i].setTexture(tCharacter[i]);

}

void ChooseCharacter::draw(RenderWindow &window) {

    window.draw(sprite);
    for(int i=0 ; i < 5 ; i++)
        window.draw(spriteC[i]);
    window.draw(tMessage);
    //window.draw(textC);
}


bool ChooseCharacter::isLocked(int setindex) {

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

bool ChooseCharacter::setLocked(int setindex) {
    switch(setindex){
        case 0:
            knightLocked = true;
            return knightLocked;
        case 1:
            valkyrieLocked = true;
            return valkyrieLocked;
        default:
            break;

    }
}

void ChooseCharacter::MoveRight(sf::Sprite *spriteC) {

    if ( setindex >= 0 && setindex < 4)
    {
        if(!isLocked(setindex+1)){
            spriteC[setindex].setColor(sf::Color::Black);
            setindex++;
            spriteC[setindex].setColor(sf::Color(168,31,000));
        }
    }

}
void ChooseCharacter::MoveLeft(sf::Sprite *spriteC) {

    if (setindex > 0 && setindex <=4)
    {
        spriteC[setindex].setColor(sf::Color::Black);
        setindex--;
        spriteC[setindex].setColor(sf::Color(168,31,000));

    }

}
bool ChooseCharacter::setFree() {
    return false;
}

/*const int *ChooseCharacter::getIndex() const {
    return index;
}*/

bool ChooseCharacter::isSelected() {
    return Selected;
}

void ChooseCharacter::getActivities(Event event, RenderWindow &window) {

    switch (event.type) {

        case sf::Event::KeyReleased:

            switch (event.key.code) {

                case sf::Keyboard::Left:
                    MoveLeft(spriteC);
                    break;

                case sf::Keyboard::Right:
                    MoveRight(spriteC);
                    break;

                case sf::Keyboard::Escape:
                    setState(true);
                    break;

                case sf::Keyboard::Return:
                    Selected=true;
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

GraphicState *ChooseCharacter::getNextState(RenderWindow &window) {

    if (Selected)
        return new MapLevel(setindex, window);
    else
        return new Menu(window);


}

void ChooseCharacter::setView(RenderWindow &window) {

    Vector2f v(tBackground.getSize());
    view.setSize(v);
    view.setCenter(v.x/2,v.y/2);
    window.setView(view);
}





