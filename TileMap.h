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

public:

    TileMap();

    void findDimension();

    ~TileMap();

    bool load(const string& tileset, Vector2u tileSize);

    void setTileMap();

    void draw(RenderWindow &window);

    void updateRoomsItems();

    void setItemsProperty();

    Vector2f getTileCoordinates(int index);

    Tile & getTile(Vector2f pos);

    vector<Obstacle> & getObstacle();

    void setObstacle(vector<Obstacle> &obstacle);

    bool isFightingGround(Tile& tile);

    Vector2f getHeroStartingPosition();

    void openBossDoor();

    bool isBossDoor(Tile& tile);

    void setTextFileName(string fileName);

    void setWall(int wall);

    unsigned int getHeight();

    unsigned int getWidth();

protected:

    static TileMap* instance;

    Sprite sprite;

    sf::VertexArray m_vertices;

    sf::Texture tilemapTexture;

    unsigned int height;
    unsigned int width;

    vector <Obstacle> obstacles;

    vector<Item> items;

    vector <vector<Tile>> tiles;

    RenderStates states;

    string textFileName;

    fstream mapTextFile;
    fstream itemTextFile;

    int wall;
    int corridorFloor;
    int fightFloor;
    int other;
    int heroStartingPosition;


};


#endif //PROJECT_TILEMAP_H
