//
// Created by leogori on 28/02/19.
//

#include "MyView.h"
#include <iostream>
#include <tgmath.h>
#include "Knight.h"

using namespace std;

MyView::MyView() {}

void MyView::followHero() {

    Hero* sub= dynamic_cast<Hero*>(subject);

    Vector2f range = sub->getPosition() - getCenter();

    if(!sub->getDirDown()&&!sub->getDirRight()&&!sub->getDirLeft()&&!sub->getDirUp()) {

        times = clock.getElapsedTime();

        float l = (float) sqrt(pow(range.x, 2) + pow(range.y, 2));

        if (times.asMilliseconds() > 0) {
            if (abs(l) > 0.5) {

                move(range.x / l, range.y / l);
            }

            clock.restart();
        }
    }
    else{

        if(abs(range.x)<=64&&abs(range.y)<=64)
            speed=sub->getSpeed()/2;
        else
            speed=sub->getSpeed();

        if(sub->getDirUp())
            move(0,-speed);

        if(sub->getDirDown())
            move(0,speed);

        if(sub->getDirLeft())
            move(-speed,0);

        if(sub->getDirRight())
            move(speed,0);

    }

}

void MyView::update(Subject *s) {

    if(subject==s)
        followHero();

}

void MyView::setSubject(Subject *subject) {

    this->subject=subject;
    subject->addObserver(this);
}
