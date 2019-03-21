//
// Created by piero on 10/12/18.
//

#ifndef PROJECT_LEVEL_H
#define PROJECT_LEVEL_H

#include <SFML/Graphics.hpp>
#include "GraphicState.h"
#include <ctime>

using namespace sf;

class MapLevel: public GraphicState {


public:

    //MapLevel(RenderWindow &window);

    MapLevel(int charInd, RenderWindow &window);

    ~MapLevel();

    void setScreenLevel(); //metodo che setta la schermata del livello

    void animation();

    void draw(RenderWindow &window);

    void moveRight();

    void moveLeft();

    //void setMapLevel(RenderWindow &window,int levelindex);

    void setScreen();

    void getActivities(Event event,RenderWindow &window);

    GraphicState *getNextState(RenderWindow &window);

    void setView(RenderWindow &window);

private:

    int levelIndex;
    int sign;
    float width;
    float height;
    //bool levelLocked = false;

    Clock clock;

    Time timer;

    Texture texturem;
    Texture texturel;
    Texture textureCharacterLevel;

    bool selected;

    Sprite spritel,spriteCharacterLevel,spritem[16];
    Text textl[2];
    Font font;

    int characterIndex;
    //bool shine=true;
};


#endif //PROJECT_LEVEL_H
