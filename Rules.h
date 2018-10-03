//
// Created by piero on 9/28/18.
//
#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef PROJECT_RULES_H
#define PROJECT_RULES_H

using namespace sf;
using namespace std;

class Rules {
public:
    Rules();
    ~Rules();

    void setRulesScreen(Texture &texture,Sprite &sprite,Text *textRules,Font &font);
    void draw(RenderWindow &window,Text *textRules);

private:
    const float width=700;
    const float height=450;
};


#endif //PROJECT_RULES_H
