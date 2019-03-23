//
// Created by leogori on 04/03/19.
//

#ifndef PROJECT_ITEMS_H
#define PROJECT_ITEMS_H

#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

class Item {

public:

    Item(string file, int numberOfFrame);

    virtual void draw(RenderWindow &window);

    void setPosition(Vector2f pos);

    Vector2f getPosition();

    void rotate(float angle);

    void setOrigin(float x,float y);

    void animate();

    void setAnimation(bool state);

    bool getAnimation();

    FloatRect getDimension();



protected:

    Sprite sprite;
    Texture texture;

    int numFrame;

    string nameFile;

    bool animation;

    int index;

};


#endif //PROJECT_ITEMS_H
