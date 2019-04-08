//
// Created by leogori on 03/04/19.
//

#ifndef PROJECT_TILEBOSSMAP_H
#define PROJECT_TILEBOSSMAP_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <iostream>
#include "Obstacle.h"
#include "Tile.h"

class TileBossMap {

public:

    TileBossMap();

    bool load(const string& tileset, Vector2u tileSize);

    void findDimension();

    virtual void setTileMap();

    virtual void draw(RenderWindow &window);

    Vector2f getTileCoordinates(int index);

    Tile & getTile(Vector2f pos);

    Vector2f getHeroStartingPosition();

    void setTextFileName(string fileName);

    void setWall(int wall);

    unsigned int getHeight();

    unsigned int getWidth();

protected:

    Sprite sprite;

    int wall;

    sf::VertexArray m_vertices;

    sf::Texture tilemapTexture;

    unsigned int height;
    unsigned int width;

    vector <vector<Tile>> tiles;

    RenderStates states;

    string textFileName;

    fstream mapTextFile;

    int heroStartingPosition;

};


#endif //PROJECT_TILEBOSSMAP_H
