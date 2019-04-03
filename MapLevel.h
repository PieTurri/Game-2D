//
// Created by piero on 10/12/18.
//

#ifndef PROJECT_LEVEL_H
#define PROJECT_LEVEL_H

#include <SFML/Graphics.hpp>
#include "GraphicState.h"
#include <ctime>
#include <vector>

using namespace sf;

class MapLevel: public GraphicState {


public:

    //MapLevel(RenderWindow &window);

    MapLevel(int charInd, RenderWindow &window);

    ~MapLevel();

    void setScreenLevel(); //metodo che setta la schermata del livello

    void animation();

    void draw(RenderWindow &window);

    //void setMapLevel(RenderWindow &window,int levelindex);

    void setScreen() override;

    void getActivities(Event event,RenderWindow &window);

    GraphicState *getNextState(RenderWindow &window);

    void setView(RenderWindow &window);

    void deleteClouds(int levelIndex);

    void moveCharRight();

    void moveCharLeft();

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

    Text text;

    bool selected;

    Sprite spritel,spriteCharacterLevel;
    Sprite spritem,sprite;

    vector <Sprite> cloud;

    Text textl[2];
    Font font;

    bool levelLocked[5]={true,false,false,false, false};

    int mapLevelPos[5][2]={{180, 580},{370,200},{1000, 615},{1125, 330},{1080, 125}};

    int lineIndex = 0;

    int characterIndex;
    //bool shine=true;
};


#endif //PROJECT_LEVEL_H
