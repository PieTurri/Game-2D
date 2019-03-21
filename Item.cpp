//
// Created by leogori on 04/03/19.
//

#include "Item.h"

Item::Item(string file, int numberOfFrame) : nameFile(file), numFrame(numberOfFrame){

    index=1;
    animation=false;
    texture.loadFromFile(file+to_string(index)+".png");
    sprite.setTexture(texture);
    sprite.scale(0.30, 0.30);

}

void Item::draw(RenderWindow &window) {

    window.draw(sprite);

}

void Item::setPosition(Vector2f pos) {

    sprite.setPosition(pos);
}

Vector2f Item::getPosition() {
    return sprite.getPosition();
}

void Item::rotate(float angle) {

    sprite.rotate(angle);

}

void Item::setOrigin(float x, float y) {

    sprite.setOrigin(x,y);

}

void Item::animate() {

    if(animation) {
        if (index == numFrame)
            index = 1;

        string s = nameFile + to_string(index) + ".png";

        texture.loadFromFile(s);
        sprite.setTexture(texture);
        index++;
    }
}

void Item::setAnimation(bool state) {

    animation=state;
}


bool Item::getAnimation() {

    return animation;
}

FloatRect Item::getDimension() {

    return sprite.getGlobalBounds();
}
