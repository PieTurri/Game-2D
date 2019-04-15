//
// Created by leogori on 20/03/19.
//

#ifndef PROJECT_SUBJECT_H
#define PROJECT_SUBJECT_H

#include "Observer.h"

class Observer;

class Subject {

public:

    virtual void notify();

    virtual void addObserver(Observer* observer);

    virtual void removeObserver();

protected:

    Observer* observer;

};


#endif //PROJECT_SUBJECT_H
