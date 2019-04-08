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

    void changeState(RenderWindow &window);

    void setScreen();

    void draw(RenderWindow &window);

    void setInput(Event event, RenderWindow &window);

    bool getState();

    GraphicState* getGraphicState();

    void setGraphicState(GraphicState* graphicState);


private:

    GraphicState* graphicState;
};


#endif //PROJECT_GRAPHIC_H
