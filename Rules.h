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

    bool isOpen();
    void setRulesScreen();

private:
    sf::Texture texture;
};


#endif //PROJECT_RULES_H
