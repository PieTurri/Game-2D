//
// Created by leogori on 20/03/19.
//

#include "Subject.h"

void Subject::notify() {

    observer->update(this);

}

void Subject::addObserver(Observer *observer) {

    this->observer=observer;

}

void Subject::removeObserver(Observer *observer) {

    delete observer;

}