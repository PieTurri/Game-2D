//
// Created by leogori on 21/12/18.
//

#ifndef PROJECT_GRAPHIC_H
#define PROJECT_GRAPHIC_H


#include "GraphicState.h"

class Graphic {
public:

    Graphic();

    Graphic(GraphicState* gContext);

    virtual ~Graphic();

    void changeState();

    void setScreen();

    void draw(RenderWindow &window);

    void movement(Event event,RenderWindow &window);

    bool getState();


private:

    GraphicState* graphicState;
};


#endif //PROJECT_GRAPHIC_H
