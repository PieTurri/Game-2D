//
// Created by piero on 10/12/18.
//

#ifndef PROJECT_LEVEL_H
#define PROJECT_LEVEL_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Level {

public:

    Level();

    ~Level();

    void setScreenLevel(Texture &texturel, Sprite &spritel, Text *textl, Font &font); //metodo che setta la schermata del livello

    void draw(RenderWindow &window, Text *textl);

    //void setMapLevel(RenderWindow &window,int levelindex);

    void drawCloud(Texture *texturem, Sprite *spritem);

    void setMapLevelScreen(Texture &texturel,Sprite &spritel, Texture *texturem,Sprite *spritem, Texture &textureCharacterLevel, Sprite &spriteCharacterLevel);

    //void drawM(sf::Sprite *spritem, sf::Texture *texturem);

    int levelIndex = 0;
    const float width=1400;
    const float height=896;

protected:

    bool levelLocked = false;



};


#endif //PROJECT_LEVEL_H
