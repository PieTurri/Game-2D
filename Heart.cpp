//
// Created by piero on 3/29/19.
//

#include "Heart.h"
#include "Hero.h"

Heart::Heart() {}

Heart::~Heart() {

}

void Heart::setHeart(RenderWindow &window, Hero *hero, View view) {

    heartT.loadFromFile("heart.png");
    Sprite sheart;
    sheart.setTexture(heartT);

    size = Vector2f(view.getCenter().x-295,view.getCenter().y-210);
    heartS.push_back(sheart);
    heartS[0].setPosition(size);

    size = Vector2f(view.getCenter().x-265,view.getCenter().y-210);
    heartS.push_back(sheart);
    heartS[1].setPosition(size);

    size = Vector2f(view.getCenter().x-235,view.getCenter().y-210);
    heartS.push_back(sheart);
    heartS[2].setPosition(size);

    size = Vector2f(view.getCenter().x-205,view.getCenter().y-210);
    heartS.push_back(sheart);
    heartS[3].setPosition(size);

    size = Vector2f(view.getCenter().x-175,view.getCenter().y-210);
    heartS.push_back(sheart);
    heartS[4].setPosition(size);
}

void Heart::draw(RenderWindow &window) {
    for(int j = 0;j < 5;j++){
        window.draw(heartS[j]);
    }

}
