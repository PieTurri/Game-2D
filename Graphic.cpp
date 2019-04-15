//
// Created by leogori on 21/12/18.
//

#include "Graphic.h"
#include "Menu.h"
#include "Pause.h"
#include <iostream>

using namespace std;

Graphic::Graphic() {}

Graphic::Graphic(GraphicState *gContext) {

    graphicState.push_back(gContext);
}

Graphic::~Graphic() {}

void Graphic::changeState(RenderWindow &window) {

    GraphicState *gContext = graphicState.size()==1 ? graphicState[0]->getNextState(window) : graphicState[1]->getNextState(window);

    graphicState.clear();

    graphicState.push_back(gContext);
}

void Graphic::draw(RenderWindow &window) {

    if(graphicState.size()==1)
        graphicState[0]->draw(window);
    else
        graphicState[1]->draw(window);
}

void Graphic::setInput(Event event, RenderWindow &window) {

    if (graphicState.size()==1)
        graphicState[0]->getActivities(event, window);
    else
        graphicState[1]->getActivities(event, window);

    if (graphicState[0]->isPausable()) {

        switch (event.type) {

            case Event::KeyReleased:
                switch (event.key.code) {
                    case Keyboard::P:
                        if(graphicState.size()==1) {
                            graphicState.push_back(new Pause(window));
                        }
                        else
                            graphicState.pop_back();
                        break;
                    default:
                        break;
                }
            default:
                break;
        }
    }
}

bool Graphic::getState() {

    if(graphicState.size()==1)
        return graphicState[0]->getState();
    else
        return graphicState[1]->getState();
}

GraphicState *Graphic::getGraphicState() {

    return graphicState[0];
}
