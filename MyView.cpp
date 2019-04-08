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

    Vector2f range = subject->getPosition() - getCenter();

    if(!subject->getDirDown()&&!subject->getDirRight()&&!subject->getDirLeft()&&!subject->getDirUp()) {

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
            speed=subject->getSpeed()/2;
        else
            speed=subject->getSpeed();

        if(subject->getDirUp())
            move(0,-speed);

        if(subject->getDirDown())
            move(0,speed);

        if(subject->getDirLeft())
            move(-speed,0);

        if(subject->getDirRight())
            move(speed,0);

    }

}

void MyView::update(Subject *s) {

    if(subject==s)
        followHero();

}

void MyView::setSubject(Hero *subject) {

    this->subject=subject;
    subject->addObserver(this);

}
