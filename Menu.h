//
// Created by piero on 9/27/18.
//

#include <SFML/Graphics.hpp>
#include "GraphicState.h"


#ifndef PROJECT_MENU_H
#define PROJECT_MENU_H

using namespace sf;


class Menu: public GraphicState{

public:
    Menu(float w,float h);

    Menu();

    ~Menu();

    void draw(sf::RenderWindow &window);

    void MoveUp();

    void MoveDown();

    void setScreen();

    void getActivities(Event event,RenderWindow &window);

    GraphicState* getNextState();

private:

    int selectedTextIndex;
    bool redText; //serve per avere la prima scritta già rossa;
    //bool menuOpen = true;

    const float width;
    const float height;
    Texture texture;
    Font font[2];
    Text text[4];
    Sprite sprite;


};


#endif //PROJECT_MENU_H
