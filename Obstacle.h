//
// Created by leogori on 28/02/19.
//

#ifndef PROJECT_OBASTACLE_H
#define PROJECT_OBASTACLE_H

#include "Item.h"


using namespace sf;

class Obstacle : public Item{

public:

    //Obstacle();

    Obstacle(string file, int numberOfFrame);

    ~Obstacle();

/*    void setDestroyed(bool state);

    bool getDestroyed();*/

    void draw(RenderWindow& window) override;

private:

    bool destroyed;

};


#endif //PROJECT_OBASTACLE_H
