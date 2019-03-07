//
// Created by leogori on 21/12/18.
//

#ifndef PROJECT_GRAPHICSTATE_H
#define PROJECT_GRAPHICSTATE_H

#include "MyView.h"


using namespace sf;

class GraphicState {
public:

    GraphicState();

    virtual bool getState();

    virtual void setState(bool state);

    virtual void draw(RenderWindow &window)=0;

    virtual void setScreen()=0;

    virtual GraphicState *getNextState(RenderWindow &window) =0;

    virtual void getActivities(Event event,RenderWindow &window)=0;

    virtual void setView(RenderWindow &window) =0;

private:

    bool stateChanged;
protected:
    MyView view;
};


#endif //PROJECT_GRAPHICSTATE_H
