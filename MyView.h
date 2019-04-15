//
// Created by leogori on 28/02/19.
//

#ifndef PROJECT_MYVIEW_H
#define PROJECT_MYVIEW_H

#include <SFML/Graphics.hpp>
#include "Hero.h"
#include "Observer.h"

class MyView: public View, public Observer{

public:

    MyView();

    void followHero();

    void update(Subject *s);

    void setSubject(Subject *subject);

private:

    int speed;

    Clock clock;
    Time times;
};


#endif //PROJECT_MYVIEW_H
