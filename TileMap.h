//
// Created by piero on 10/6/18.
//

#ifndef PROJECT_TILEMAP_H
#define PROJECT_TILEMAP_H

#include <iostream>
#include <fstream>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics.hpp>


using namespace sf;
using namespace std;

class TileMap  /*:public sf::Drawable*/{

public:

    TileMap();

    TileMap(unsigned int h, unsigned int w);

    unsigned int getMapHeight();

    unsigned int getMapWidth();

    ~TileMap();

    bool load(const string& tileset, Vector2u tileSize);


    void setTileMap();

    void draw(RenderWindow &window);

    bool getTileWalkability(Vector2f charPos);

    void followCharPos(View &view, Sprite &spritePlayer);

    void updateRoomsItems();

    void setTileWalkability(float x,float y,bool walkProperty);

    void setItemsProperty();

    void setFightRooms();

    bool getFightRoomAccessibility(int pos);

    int cellFloorCoords[9]={148, 175, 202, 2119, 2146, 2173, 4090, 4117, 4144};

private:

    sf::VertexArray m_vertices;

    sf::Texture m_tileset;

    unsigned int height;
    unsigned int width;

    bool fightRooms[9];

    int *tiles;

    bool* isWalkable;

    int cellDim;

    Clock clock;
    Time times;

    Sprite *spriteItems;

    int nTorch=1;
    int nMerchant=1;

    Texture texture[3];

    RenderStates states;


    int cellCoords[9]={74, 101, 128, 2099, 2045, 2072, 4043, 4070, 4016};;
    int corridorCoords[12]={1321,529, 1348,556, 1375,2500, 3292,2527, 3319,4471, 3346,4498};

    int corridorFloorCoords[12]={1322,1349,1376,3293,3320,3347,602,629,2573,2600,4544,4571};
};



#endif //PROJECT_TILEMAP_H
