//
// Created by leogori on 28/02/19.
//

#ifndef PROJECT_MYVIEW_H
#define PROJECT_MYVIEW_H

#include <SFML/Graphics.hpp>
#include "Hero.h"

class MyView: public View{

public:

    MyView();

    void followCharPos(Hero *hero, RenderWindow &window);

private:

    Clock clock;
    Time times;
};


#endif //PROJECT_MYVIEW_H
