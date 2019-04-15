//
// Created by leogori on 21/12/18.
//

#include "GraphicState.h"

GraphicState::GraphicState() {

    stateChanged=false;
}

bool GraphicState::getState() {
    return stateChanged;
}

void GraphicState::setState(bool state) {

    stateChanged=state;
}

bool GraphicState::isPausable() const {
    return pausable;
}

void GraphicState::setPausable(bool pausable) {
    GraphicState::pausable = pausable;
}

const MyView &GraphicState::getView() const {
    return view;
}

