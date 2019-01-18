//
// Created by leogori on 21/12/18.
//

#include "Graphic.h"
#include "Menu.h"
#include <iostream>

using namespace std;

Graphic::Graphic() {


}

Graphic::Graphic(GraphicState *gContext) {

    graphicState = gContext;

}

Graphic::~Graphic() {}

void Graphic::changeState() {

    if(graphicState){

        GraphicState* gContext = graphicState->getNextState();

        delete graphicState;

        graphicState = gContext;
    }

}

void Graphic::setScreen() {

    graphicState->setScreen();

}

void Graphic::draw(RenderWindow &window) {

    graphicState->draw(window);

}

void Graphic::movement(Event event,RenderWindow &window) {

    graphicState->getActivities(event,window);

}

bool Graphic::getState() {


    return graphicState->getState();
}

