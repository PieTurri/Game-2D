//
// Created by piero on 3/27/19.
//

#include "Achievement.h"
#include "Menu.h"
#include "GameObserver.h"

Achievement::Achievement(RenderWindow& window){

    if(!texture.loadFromFile("achievement.jpg"))
        cout<<"errore: immagine 'achievement.jpg' non trovata.";

    sprite.setTexture(texture);
    setView(window);

}

void Achievement::setScreen() {

    height=texture.getSize().y;
    width=texture.getSize().x;

    if(!font.loadFromFile("DIOGENES.ttf"))
        cout << "errore: stile carattere 'DIOGENES.ttf' non trovata." << endl;

    text[0].setString("Achievement");
    text[0].setFont(font);
    text[0].setFillColor(sf::Color::White);
    text[0].setPosition((width / 2), height / (3+2)-70);
    text[0].setOrigin(text[0].getGlobalBounds().width/2,text[0].getGlobalBounds().height/2);
    text[0].setCharacterSize(70);

    text[1].setString("Numero di nemici sconfitti: "+to_string(obs.getEnemyDefeated())+"/"+to_string(obs.getNumberOfEnemy()));
    text[1].setFont(font);
    text[1].setFillColor(sf::Color::White);
    text[1].setPosition((width / 2), height / (3+2));
    text[1].setOrigin(text[1].getGlobalBounds().width/2,text[1].getGlobalBounds().height/2);
    text[1].setCharacterSize(70);

    text[2].setString("Tempo impiegato: "+ to_string(obs.getTime().x)+" min e "+to_string(obs.getTime().y)+"sec");
    text[2].setFont(font);
    text[2].setFillColor(sf::Color::White);
    text[2].setPosition((width / 2), height / (3+2)+70);
    text[2].setOrigin(text[2].getGlobalBounds().width/2,text[2].getGlobalBounds().height/2);
    text[2].setCharacterSize(70);
}

void Achievement::draw(RenderWindow &window) {

    window.draw(sprite);
    for(int i=0;i<3;i++)
        window.draw(text[i]);
}

void Achievement::getActivities(Event event, RenderWindow &window) {

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

GraphicState *Achievement::getNextState(RenderWindow &window) {

    return new Menu(window);
}

void Achievement::setView(RenderWindow &window) {

    Vector2f v(texture.getSize());
    view.setSize(v);
    view.setCenter(v.x/2,v.y/2);
    window.setView(view);
}

void Achievement::setGameObserver(GameObserver gameObs) {

    obs=gameObs;
    setScreen();
}
