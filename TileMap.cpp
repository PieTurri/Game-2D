//
// Created by piero on 10/6/18.
//

#include "TileMap.h"
#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

TileMap::TileMap() {}

TileMap::~TileMap() {
}

bool TileMap::load(const std::string &tileset, sf::Vector2u tileSize) {

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

            // define its 4 corners

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

void TileMap::draw(RenderWindow &window) {

    updateRoomsItems();

    window.draw(m_vertices,states);

    for(int i=0;i<items.size();i++)
        items[i].draw(window);

    vector<Obstacle>::iterator it=obstacles.begin();

    for(int i=0;i<obstacles.size();i++)
        obstacles[i].draw(window);

    for(int i=0;i<obstacles.size();i++){
        if(!obstacles[i].getDestroyed()) {

            it++;
        }
        else {

            getTile(obstacles[i].getPosition()).reset();
            obstacles.erase(it);
            i--;
        }
    }
}

void TileMap::setTileMap() {

    mapTextFile.open(textFileName);

    int i=0;
    string line;
    vector <Tile> lineTiles;
    Tile tile;

    while(getline(mapTextFile,line)) {

        istringstream iss(line);

        while(iss>>i) {

            tile.setValue(i);

            if (i == wall||i==other) {
                tile.setHeroWalkability(false);
                tile.setEnemyWalkability(false);
            }
            if (i == corridorFloor)
                tile.setEnemyWalkability(false);

            lineTiles.push_back(tile);
            tile.reset();
        }

        tiles.push_back(lineTiles);
        lineTiles.clear();
    }

    mapTextFile.close();
}

void TileMap::updateRoomsItems() {

    if(!items.empty()) {
        for (int i = 0; i < items.size(); i++) {
            if(items[i].getAnimation())
                items[i].animate();
        }
    }
}

void TileMap::setItemsProperty() {

    itemTextFile.open("elementiMappa");

    int i=0;
    int j=0;
    int k=0;

    Item item("mercante/frame-", 5);

    items.push_back(item);
    items[j].setPosition(Vector2f(960,128));
    tiles[960/32][128/32].setHeroWalkability(false);
    tiles[960/32][128/32].setEnemyWalkability(false);
    items[j].setAnimation(true);
    j++;

    while(itemTextFile>>i) {

        Item item1("torcia/frame-", 32);

        if(i!=0){

            items.push_back(item1);
            items[j].setPosition(getTileCoordinates(k));
            items[j].setAnimation(true);
            switch(i){
                case 1:
                    items[j].rotate(-30);
                    items[j].setOrigin(-8,0);
                    break;
                case 2:
                    items[j].rotate(+30);
                    items[j].setOrigin(8,0);
                    break;
                case 3:
                    items[j].rotate(180);
                    items[j].setOrigin(0,16);
                    break;
                default:
                    break;
            }
            j++;
        }
        k++;
    }

    itemTextFile.close();

    srand((unsigned int) time(NULL));

    int obstaclePosX;
    int obstaclePosY;

    for (int x = 0; x < 10; x++) {

        Obstacle obstacle("barile/frame-",7);
        obstacle.setOrigin(48,51);

        obstacles.push_back(obstacle);

        do {

            obstaclePosX = rand() % width;
            obstaclePosY = rand() % height;
        } while (!isFightingGround(tiles[obstaclePosY][obstaclePosX]));

        Vector2f v(obstaclePosX*32+16,obstaclePosY*32+16);

        obstacles[x].setPosition(v);
        tiles[obstaclePosY][obstaclePosX].setHeroWalkability(false);
        tiles[obstaclePosY][obstaclePosX].setEnemyWalkability(false);
    }

}

Vector2f TileMap::getTileCoordinates(int index) {

    float x=index%width;

    float y=(index-x)/width;

    return Vector2f(x*32,y*32);
}

vector<Obstacle> & TileMap::getObstacle() {

    return obstacles;
}

void TileMap::setObstacle(vector<Obstacle> &obstacle) {

    obstacles=obstacle;
}

void TileMap::findDimension() {

    height=tiles.size();
    width=tiles[0].size();
}

Tile & TileMap::getTile(Vector2f pos) {

    return tiles[pos.x/32][pos.y/32];
}

bool TileMap::isFightingGround(Tile &tile) {

    return tile.getValue()==fightFloor;
}

Vector2f TileMap::getHeroStartingPosition() {

    for(int i=0;i<width;i++){
        for(int j=0;j<height;j++){
            if(tiles[i][j].getValue()==heroStartingPosition)
                return Vector2f(j*32,i*32);
        }
    }
}

void TileMap::openBossDoor() {

    for(int i=0;i<width;i++){
        for(int j=0;j<height;j++){
            if(tiles[i][j].getValue()==heroStartingPosition) {
                tiles[i][j].setValue(121);
                heroStartingPosition=121;
            }
        }
    }

    load("Tileset1.png",Vector2u(32,32));
}

bool TileMap::isBossDoor(Tile &tile) {

    return tile.getValue()==heroStartingPosition;
}

void TileMap::setTextFileName(string fileName) {

    textFileName=fileName;

}

unsigned int TileMap::getHeight() {
    return height;
}

unsigned int TileMap::getWidth() {
    return width;
}

void TileMap::setWall(int wall) {

    this->wall=wall;

}
