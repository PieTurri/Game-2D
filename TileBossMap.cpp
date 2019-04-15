//
// Created by leogori on 03/04/19.
//

#include "TileBossMap.h"
#include <cmath>
#include <sstream>

TileBossMap::TileBossMap() {}

bool TileBossMap::load(const std::string &tileset, sf::Vector2u tileSize) {

    // load the map tileset texture

    if (!tilemapTexture.loadFromFile(tileset))
        return false;

    // resize the vertex array to fit the tile size

    m_vertices.setPrimitiveType(sf::Quads);

    m_vertices.resize(height * width * 4);

    // populate the vertex array, with one quad per tile

    for (unsigned int i = 0; i < height; i++) {

        for (unsigned int j = 0; j < width; j++) {

            // get the current tile number

            int tileNumber = tiles[i][j].getValue();


            // find its position in the tileset texture

            int tu = tileNumber % (tilemapTexture.getSize().x / tileSize.x);

            int tv = tileNumber / (tilemapTexture.getSize().x / tileSize.x);


            // get a pointer to the current tile's quad

            sf::Vertex *quad = &m_vertices[(j + i * width) * 4];

            // define its 4 cornvoid findDimension();ers

            quad[0].position = sf::Vector2f(j * tileSize.x, i * tileSize.y);

            quad[1].position = sf::Vector2f((j + 1) * tileSize.x, i * tileSize.y);

            quad[2].position = sf::Vector2f((j + 1) * tileSize.x, (i + 1) * tileSize.y);

            quad[3].position = sf::Vector2f(j * tileSize.x, (i + 1) * tileSize.y);

            // define its 4 texture coordinates

            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);

            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);

            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);

            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);

        }
    }

    states.texture=&tilemapTexture;

    return true;

}

void TileBossMap::findDimension() {

    height=tiles.size();
    width=tiles[0].size();
}

void TileBossMap::draw(RenderWindow &window) {

    window.draw(m_vertices,states);
}

void TileBossMap::setTileMap() {

    mapTextFile.open(textFileName);

    cout<<textFileName<<endl;

    int i=0;
    string line;
    vector <Tile> lineTiles;
    Tile tile;

    while(getline(mapTextFile,line)) {

        istringstream iss(line);

        while(iss>>i) {

            tile.setValue(i);

            if (i == wall) {
                tile.setHeroWalkability(false);
                tile.setEnemyWalkability(false);
            }

            lineTiles.push_back(tile);
            tile.reset();
        }

        tiles.push_back(lineTiles);
        lineTiles.clear();
    }

    mapTextFile.close();

    findDimension();
}

Vector2f TileBossMap::getTileCoordinates(int index) {

    float x=index%width;

    float y=(index-x)/width;

    return Vector2f(x*32,y*32);
}

Tile & TileBossMap::getTile(Vector2f pos) {

    return tiles[pos.y/32][pos.x/32];
}


Vector2f TileBossMap::getHeroStartingPosition() {

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(tiles[i][j].getValue()==heroStartingPosition)
                return Vector2f(j*32,i*32);
        }
    }
}

void TileBossMap::setTextFileName(string fileName) {

    textFileName=fileName;

}

unsigned int TileBossMap::getHeight() {

    return height;
}

unsigned int TileBossMap::getWidth() {

    return width;
}

void TileBossMap::setWall(int wall) {

    this->wall=wall;
}