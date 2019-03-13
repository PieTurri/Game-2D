//
// Created by piero on 10/6/18.
//

#ifndef PROJECT_TILEMAP_H
#define PROJECT_TILEMAP_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include "Obstacle.h"
#include "Tile.h"

using namespace sf;
using namespace std;

class TileMap{

    //enum LevelName{ARCONTUS,MIRINTHAS,PUNKHAZARD,CASTRISAND,ETRAS};

public:

    //string getLevelName(int index);

    //static TileMap Create(LevelName name);

    TileMap();

    void findDimension();

    ~TileMap();

    bool load(const string& tileset, Vector2u tileSize);

    void setTileMap();

    void draw(RenderWindow &window);

    bool getTileWalkability(Vector2f charPos);

    void updateRoomsItems();

    void setTileWalkability(Vector2f pos, bool walkProperty);

    void setItemsProperty();

    void setFightRooms();

    bool getFightRoomAccessibility(int pos);

    Vector2f getTileCoordinates(int index);

    vector<Obstacle> & getObstacle();

    void setObstacle(vector<Obstacle> &obstacle);

private:

    Sprite sprite;

    sf::VertexArray m_vertices;

    sf::Texture tilemapTexture;

    unsigned int height;
    unsigned int width;

    bool fightRooms[9];

    vector <Obstacle> obstacles;

    vector<Item> items;

    vector <vector<Tile>> tiles;

    RenderStates states;

    //string textFileName;

    fstream mapTextFile;
    fstream itemTextFile;
};



#endif //PROJECT_TILEMAP_H
