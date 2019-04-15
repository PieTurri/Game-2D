//
// Created by piero on 3/28/19.
//
#include "Pause.h"
#include "ChooseCharacter.h"
#include "Menu.h"

Pause::Pause(RenderWindow &window) {
    setScreen();
    setPosition(window);
    setView(window);
}

Pause::~Pause() {}

void Pause::setPosition(RenderWindow &window) {

    width=window.getSize().x;
    height=window.getSize().y;

    size = Vector2i(window.getSize().x/2,window.getSize().y/2);

    text[0].setPosition(window.mapPixelToCoords(size));
    text[1].setPosition(window.mapPixelToCoords(size+ Vector2i(0,40)));
    text[2].setPosition(window.mapPixelToCoords(size+ Vector2i(0,80)));
}

void Pause::draw(RenderWindow &window) {

    for(int i=0;i<3;i++)
        window.draw(text[i]);
}

void Pause::getActivities(Event event, RenderWindow &window) {

    switch (event.type) {

        case sf::Event::KeyReleased:

            switch (event.key.code) {
                case sf::Keyboard::Up:
                    MoveUp();
                    break;

                case sf::Keyboard::Down:
                    MoveDown();
                    break;

                case sf::Keyboard::Return:
                    setState(true);
                    break;

                default:
                    break;
            }
            break;
        default:
            break;
    }
}

void Pause::MoveUp() {

    if (selectedTextIndex > 0)
    {
        text[selectedTextIndex].setFillColor(Color::White);
        selectedTextIndex--;
        text[selectedTextIndex].setFillColor(sf::Color::Red);
        cout<<"SelectedTextIndex"<<selectedTextIndex<<endl;
        cout<<"Movimento in su fatto"<<endl;
    }
}

void Pause::MoveDown() {

    if (selectedTextIndex < 2)
    {
        text[selectedTextIndex].setFillColor(Color::White);
        selectedTextIndex++;
        text[selectedTextIndex].setFillColor(sf::Color::Red);
        cout<<"SelectedTextIndex"<<selectedTextIndex<<endl;
        cout<<"Movimento in giu fatto"<<endl;
    }
}

GraphicState *Pause::getNextState(RenderWindow &window) {

    setState(false);

    switch(selectedTextIndex){
        case 0:
            return new ChooseCharacter(window);
        case 1:
            return new Menu(window);
        case 2:
            window.close();
        default:
            break;
    }
}

void Pause::setScreen() {

    selectedTextIndex=0;

    if(!font.loadFromFile("DIOGENES.ttf"))
        cout << "errore" << endl;

    text[0].setString("Scelta personaggio");
    text[0].setFont(font);
    text[0].setCharacterSize(18);
    text[0].setFillColor(sf::Color::Red);
    text[0].setOrigin(text[0].getGlobalBounds().width/2,text[0].getGlobalBounds().height/2);

    text[1].setString("Schermata Iniziale");
    text[1].setFont(font);
    text[1].setCharacterSize(18);
    text[1].setFillColor(sf::Color::White);
    text[1].setOrigin(text[1].getGlobalBounds().width/2,text[0].getGlobalBounds().height/2);

    text[2].setString("Esci dal gioco");
    text[2].setFont(font);
    text[2].setCharacterSize(18);
    text[2].setFillColor(sf::Color::White);
    text[2].setOrigin(text[2].getGlobalBounds().width/2,text[2].getGlobalBounds().height/2);
}

void Pause::setView(RenderWindow &window) {

    view.setSize(320,320);
    view.setCenter(window.mapPixelToCoords(size));
    window.setView(view);

}
