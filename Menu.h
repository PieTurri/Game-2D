//
// Created by piero on 9/27/18.
//

#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include "GraphicState.h"


#ifndef PROJECT_MENU_H
#define PROJECT_MENU_H

using namespace sf;


class Menu: public GraphicState{

public:
    Menu(float w, float h, RenderWindow &window);

    Menu(RenderWindow &window);

    ~Menu();

    void draw(sf::RenderWindow &window);

    void MoveUp();

    void MoveDown();

    void setScreen();

    void getActivities(Event event,RenderWindow &window);

    GraphicState *getNextState(RenderWindow &window);

    void setView(RenderWindow &window);

private:

    int selectedTextIndex;

    const float width;
    const float height;

    Texture texture;
    Font font[2];
    Text text[5];
    Sprite sprite;

    Music music;

};


#endif //PROJECT_MENU_H
