//
// Created by piero on 3/29/19.
//

#include "Heart.h"
#include "Hero.h"

Heart::Heart() {

    number=5;

    heartT.loadFromFile("heart.png");
    Sprite sheart;
    sheart.setTexture(heartT);
    for (int i = 0; i < number; i++) {
        heartS.push_back(sheart);
    }
}

Heart::~Heart() {}

void Heart::setHeart(RenderWindow &window) {

    for(int i=0;i<heartS.size();i++) {
        heartS[i].setPosition(window.mapPixelToCoords(Vector2i(10+i*heartT.getSize().x,10)));
    }
}

void Heart::draw(RenderWindow &window) {

    for(int j = 0;j < heartS.size();j++){
        window.draw(heartS[j]);
    }
}

void Heart::removeHeart() {

    heartS.pop_back();
}

void Heart::setHeroLife(int life) {

    heroLife=life;
}

int Heart::getHeroLife() {
    return heroLife;
}

void Heart::update(int life) {

    int numHeart=life/(heroLife/number);

    while(heartS.size()>numHeart+1)
        removeHeart();

}
