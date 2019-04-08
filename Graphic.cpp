//
// Created by leogori on 21/12/18.
//

#include "Graphic.h"
#include "Menu.h"
#include <iostream>

using namespace std;

Graphic::Graphic() {}

Graphic::Graphic(GraphicState *gContext) {

    graphicState = gContext;

}

Graphic::~Graphic() {}

void Graphic::changeState(RenderWindow &window) {

    if(graphicState!=nullptr){

        GraphicState* gContext = graphicState->getNextState(window);

        delete graphicState;

        graphicState = gContext;
    } else{

    }

}

void Graphic::setScreen() {

    graphicState->setScreen();

}

void Graphic::draw(RenderWindow &window) {

    graphicState->draw(window);

}

void Graphic::setInput(Event event, RenderWindow &window) {

    graphicState->getActivities(event,window);

}

bool Graphic::getState() {
    
    return graphicState->getState();
}

GraphicState *Graphic::getGraphicState() {

    return graphicState;
}

void Graphic::setGraphicState(GraphicState *graphicState) {

    this->graphicState=graphicState;
}

