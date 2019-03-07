//
// Created by leogori on 28/02/19.
//

#include "MyView.h"
#include <iostream>

using namespace std;

MyView::MyView() {

}

void MyView::followCharPos(Hero *hero, RenderWindow &window) {

    View view=window.getView();

    float dy=hero->getPosition().y-view.getCenter().y;
    float dx=hero->getPosition().x-view.getCenter().x;

    times=clock.getElapsedTime();

    if(times.asMilliseconds()>0) {
        if (dx != 0 || dy != 0) {

            float m = dy / dx;

            if (dx > 0)
                view.move(1, m);
            else if (dx < 0)
                view.move(-1, -m);
            else
                view.move(0, abs(dy) / dy);


            //float l=(float)sqrt(pow(dx,2)+pow(dy,2));

            //view.move(dx/20,dy/20);
        }

        clock.restart();
    }

    window.setView(view);

}
