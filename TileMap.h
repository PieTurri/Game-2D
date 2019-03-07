//
// Created by piero on 10/6/18.
//

#ifndef PROJECT_TILEMAP_H
#define PROJECT_TILEMAP_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include "Obstacle.h"

using namespace sf;
using namespace std;

class TileMap{

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

    vector <vector<int>> tiles;

    vector <vector<bool>> isWalkable;

    RenderStates states;

    fstream mapTextFile;
    fstream itemTextFile;
};



#endif //PROJECT_TILEMAP_H
