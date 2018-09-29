//
// Created by piero on 9/27/18.
//

#include <SFML/Graphics.hpp>
#include "MenuLoop.h"


#ifndef PROJECT_MENU_H
#define PROJECT_MENU_H



class Menu{

public:
    Menu(float width,float height);

    Menu();

    virtual ~Menu();



    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex; }

    void setMenuScreen(sf::Texture &texture,sf::Sprite &sprite,sf::Font &font,sf::RenderWindow &window);

private:
    int selectedItemIndex;
    const float width=700;
    const float height=450;

    sf::Text text[MAX_NUMBER_OF_ITEMS];



};


#endif //PROJECT_MENU_H
//Menu m(window.getSize().x, window.getSize().y);