//
// Created by piero on 9/28/18.
//

#include "MenuLoop.h"



MenuLoop::MenuLoop() {




    sf::RenderWindow window(sf::VideoMode(1400, 900), "Leo&Pie Game");

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            switch (event.type)

                switch (getIndex()) {
                    case 0: //menu
                        cout << "Start Game button has been pressed" << endl;
                        break;
                    case 1: //Start game
                        Rules::setRulesScreen(texture);
                        break;
                    case 2: //rules
                        Rules::setRulesScreen(texture);
                        break;
                    case 3: //exit
                        window.close();
                        break;
                }



        }
    }
    window.clear();
    window.draw(sprite);
    window.display();
}

int MenuLoop::getIndex() {

    return index;
}
