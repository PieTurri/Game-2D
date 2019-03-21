//
// Created by leogori on 20/03/19.
//

#ifndef PROJECT_OBSERVER_H
#define PROJECT_OBSERVER_H

#include <SFML/Graphics.hpp>
//#include "Subject.h"

using namespace sf;
using namespace std;

class Subject;

class Observer {

public:

    virtual void update(Subject *s)=0;

};


#endif //PROJECT_OBSERVER_H
