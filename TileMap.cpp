//
// Created by piero on 10/6/18.
//

#include "TileMap.h"
#include <iostream>

using namespace std;

unsigned int TileMap::height=40;
unsigned int TileMap::width=40;

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

    for (unsigned int i = 0; i < width; ++i)

        for (unsigned int j = 0; j < height; ++j)

        {

            // get the current tile number

            int tileNumber = tiles[i + j * width];



            // find its position in the tileset texture

            int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);

            int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);



            // get a pointer to the current tile's quad

            sf::Vertex* quad = &m_vertices[(i + j * width) * 4];



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

    height=h;
    width=w;

    for(int i=0;i<height;i++) {
        for(int j = 0; j <  width; j++)
            if(i==0 || i==height-1 || j==0 || j==width-1)
                lv[(i*width)+j]=478;
            else
                if(i==1 || i==height-2 || j==1 || j==width-2)
                    lv[(i*width)+j] =42 ;
                else
                    lv[(i*width)+j] =11 ;
    }


        /*srand((unsigned)time(NULL));

        int ULcellVertex=rand()%519;*/

        //int ULcellVertex[]={40,14,68,600,334,628,654};

        /*
        for(int i=0;i<7;i++) {


            for (int j = 0; j < 7; j++) {

                lv[ULcellVertex[i] + 40 * j] = 3;
                lv[ULcellVertex[i] + 11 + 40 * j] = 3;
            }
            for (int j = 0; j < 12; j++) {

                lv[ULcellVertex[i] + j] = 3;
                lv[ULcellVertex[i] + 40 * 6 + j] = 3;
            }

        }

        */

}

unsigned int TileMap::getMapHeight() {
    return height;
}

unsigned int TileMap::getMapWidth() {
    return width;
}


