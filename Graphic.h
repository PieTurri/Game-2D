//
// Created by leogori on 21/12/18.
//

#ifndef PROJECT_GRAPHIC_H
#define PROJECT_GRAPHIC_H


#include "GraphicState.h"
#include <vector>
#include "Pause.h"

class Graphic {
public:

    Graphic();

    Graphic(GraphicState* gContext);

    virtual ~Graphic();

    void changeState(RenderWindow &window);

    void draw(RenderWindow &window);

    void setInput(Event event, RenderWindow &window);

    bool getState();

    GraphicState* getGraphicState();

private:

    vector<GraphicState*> graphicState;
};


#endif //PROJECT_GRAPHIC_H
