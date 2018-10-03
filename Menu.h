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



    void draw(sf::RenderWindow &window,sf::Text *text);
    void MoveUp(sf::Text *text);
    void MoveDown(sf::Text *text);
    int GetPressedItem() { return selectedMenuIndex; }

    void setMenuScreen(sf::Texture &texture,sf::Sprite &sprite,sf::Font &font,sf::Text *text);

    int selectedMenuIndex=0;
    bool a = true;
    bool menuOpen = true;

private:

    const float width=700;
    const float height=450;
};


#endif //PROJECT_MENU_H
