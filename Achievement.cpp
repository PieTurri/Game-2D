//
// Created by piero on 3/27/19.
//

#include "Achievement.h"
#include "Menu.h"

Achievement::Achievement(RenderWindow& window) : Achievement(1400,900){
    setScreen();
    setView(window);
}

Achievement::Achievement(float width, float height) : width(width), height(height) {}


void Achievement::setScreen() {

    if(!texture.loadFromFile("achievement.jpg"))
        cout<<"errore";
    sprite.setTexture(texture);

    if(!font.loadFromFile("DIOGENES.ttf"))
        cout << "errore" << endl;

    text.setString("Achievement");
    text.setFont(font);
    text.setFillColor(sf::Color::White);
    text.setPosition(sf::Vector2f((width / 2)+65, height / (3+2)-70));
    text.setCharacterSize(70);
}

void Achievement::draw(RenderWindow &window) {

    window.draw(sprite);
    window.draw(text);

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

