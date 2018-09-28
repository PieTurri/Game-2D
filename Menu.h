//
// Created by piero on 9/27/18.
//

#include <SFML/Graphics.hpp>
#include "MenuLoop.h"


#ifndef PROJECT_MENU_H
#define PROJECT_MENU_H


#define MAX_NUMBER_OF_ITEMS 3
class Menu : public MenuLoop {

public:
    Menu(float width,float height);
    virtual ~Menu();



    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex; }
    void setMenuScreen();

private:
    int selectedItemIndex;
    const float width=700;
    const float height=450;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];

};


#endif //PROJECT_MENU_H
//Menu m(window.getSize().x, window.getSize().y);