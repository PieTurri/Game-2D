//
// Created by piero on 10/6/18.
//

#include "TileMap.h"
#include <iostream>
#include <cmath>
#include <ctime>

#define BLACK 478;
#define WALL 42;
#define MOUNT 49;
#define FLOOR 111;


using namespace std;

unsigned int TileMap::height=73;
unsigned int TileMap::width=73;

TileMap::TileMap() {}


//TileMap::TileMap(unsigned int h, unsigned int w): height(h), width(w) {}


TileMap::~TileMap() {}

bool TileMap::load(const std::string &tileset, sf::Vector2u tileSize, int *tiles) {

    // load the tileset texture


    if (!m_tileset.loadFromFile(tileset))

        return false;


    // resize the vertex array to fit the level size

    m_vertices.setPrimitiveType(sf::Quads);

    m_vertices.resize(width * height * 4);



    // populate the vertex array, with one quad per tile

    for (unsigned int i = 0; i < width; ++i) {

        for (unsigned int j = 0; j < height; ++j) {

            // get the current tile number

            int tileNumber = tiles[i + j * width];



            // find its position in the tileset texture

            int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);

            int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);



            // get a pointer to the current tile's quad

            sf::Vertex *quad = &m_vertices[(i + j * width) * 4];



            // define its 4 corners

            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);

            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);

            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);

            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);



            // define its 4 texture coordinates

            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);

            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);

            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);

            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);

        }
    }

    return true;

}

void TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    // apply the transform
    states.transform *= getTransform();

    // apply the tileset texture
    states.texture = &m_tileset;


    // draw the vertex array
    target.draw(m_vertices, states);

}

void TileMap::SetTileMap(int *lv,unsigned int h,unsigned int w) {

    height = h;
    width = w;
    isWalkable = new bool[height * width];


    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            lv[(i * width) + j] = BLACK;
            isWalkable[(i * width) + j] = true;
        }
    }

    for (int j = 0; j < 9; j++) {
        for (int i = 0; i < cellDim; i++) {

            int v[] = {74, 101, 128, 2099, 2045, 2072, 4043, 4070, 4016};

            if (i != 7 && i != 8 && i != 9) {
                lv[v[j] + i] = WALL;
                isWalkable[v[j] + i] = false;
                lv[v[j] + i * width] = WALL;
                isWalkable[v[j] + i * width] = false;
                lv[v[j] + (cellDim - 1) + i * width] = WALL;
                isWalkable[v[j] + (cellDim - 1) + i * width] = false;
                lv[v[j] + (cellDim - 1) * width + i] = WALL;
                isWalkable[v[j] + (cellDim - 1) * width + i] = false;
            } else {
                lv[v[j] + i] = MOUNT;
                isWalkable[v[j] + i] = true;
                lv[v[j] + i * width] = MOUNT;
                isWalkable[v[j] + i * width] = true;
                lv[v[j] + (cellDim - 1) + i * width] = MOUNT;
                isWalkable[v[j] + (cellDim - 1) + i * width] = true;
                lv[v[j] + (cellDim - 1) * width + i] = MOUNT;
                isWalkable[v[j] + (cellDim - 1) * width + i] = true;
            }
        }
    }


    for (int j = 0; j < 6; j++) {

        int i = 0;
        int v[] = {1321, 1348, 1375, 3292, 3319, 3346};

        while (isWalkable[v[j] + i * width] && isWalkable[v[j] + i * width + 4]) {

            lv[v[j] + i * width] = WALL;
            lv[v[j] + 4 + i * width] = WALL;
            isWalkable[v[j] + i * width] = false;
            isWalkable[v[j] + i * width + 4] = false;
            i++;
        }

        int v1[] = {529, 556, 2500, 2527, 4471, 4498};
        i = 0;
        while (isWalkable[v1[j] + i] && isWalkable[v1[j] + i + 4 * width]) {

            lv[v1[j] + i] = WALL;
            lv[v1[j] + 4 * width + i] = WALL;
            isWalkable[v1[j] + i] = false;
            isWalkable[v1[j] + i + 4 * width] = false;
            i++;
        }

    }

    for (int i = 0; i < 9; i++) {
        int v[] = {148, 175, 202, 2119, 2146, 2173, 4090, 4117, 4144};

        for (int j = 0; j < 15; j++) {
            for (int k = 0; k < 15; k++) {
                lv[v[i] + j * width + k] = FLOOR;
            }
        }
    }

    for(int i=0;i<12;i++){
        int v[]={1322,1349,1376,3293,3320,3347,602,629,2573,2600,4544,4571};

        if(i<6) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 3; k++) {
                    lv[v[i] + j * width + k] = FLOOR;
                }
            }
        } else{
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 10; k++) {
                    lv[v[i] + j * width + k] = FLOOR;
                }
            }
        }


    }
}


unsigned int TileMap::getMapHeight() {
    return height;
}

unsigned int TileMap::getMapWidth() {
    return width;
}

bool TileMap::getTileWalkability(Vector2f charPos) {

            return isWalkable[(int)(floor((charPos.x) / 32)) +((int)floor((charPos.y) / 32)) * width];
}

void TileMap::followCharPos(View &view,Sprite &spritePlayer) {

    float dy=spritePlayer.getPosition().y+16-view.getCenter().y;
    float dx=spritePlayer.getPosition().x+16-view.getCenter().x;

    if(dx!=0 || dy!=0) {

        float m=dy/dx;

        if(dx>0)
            view.move(1,m);
        else if(dx<0)
            view.move(-1,-m);
        else
            view.move(0,abs(dy)/dy);
    }
}

