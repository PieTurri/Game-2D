//
// Created by piero on 10/6/18.
//

#include "TileMap.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include<sstream>


using namespace std;


TileMap::TileMap() : TileMap(73,73) {

    setTileMap();
    setItemsProperty();

    load("Tileset1.png",Vector2u(32,32));
}


TileMap::TileMap(unsigned int h, unsigned int w): height(h), width(w) {}


TileMap::~TileMap() {}

bool TileMap::load(const std::string &tileset, sf::Vector2u tileSize) {

    // load the map tileset texture

    if (!tilemapTexture.loadFromFile(tileset))
        return false;

    // resize the vertex array to fit the tile size

    m_vertices.setPrimitiveType(sf::Quads);

    m_vertices.resize(width * height * 4);

    // populate the vertex array, with one quad per tile

    for (unsigned int i = 0; i < width; ++i) {

        for (unsigned int j = 0; j < height; ++j) {

            // get the current tile number

            int tileNumber = tiles[i][j];


            // find its position in the tileset texture

            int tu = tileNumber % (tilemapTexture.getSize().x / tileSize.x);

            int tv = tileNumber / (tilemapTexture.getSize().x / tileSize.x);


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
            setTileWalkability(obstacles[i].getPosition(),true);
            obstacles.erase(it);
            i--;
        }
    }
}

void TileMap::setTileMap() {

    mapTextFile.open("mappa");

    int i=0;

    string line;

    vector <int> lineTiles;
    vector <bool> lineWalkable;

    while(getline(mapTextFile,line)) {

        istringstream iss(line);

        while(iss>>i) {

            lineTiles.push_back(i);
            if (i == 42 || i == 478)
                lineWalkable.push_back(false);
            else
                lineWalkable.push_back(true);
        }

        tiles.push_back(lineTiles);
        isWalkable.push_back(lineWalkable);
        lineTiles.clear();
        lineWalkable.clear();
    }

    mapTextFile.close();
}


unsigned int TileMap::getMapHeight() {
    return height;
}

unsigned int TileMap::getMapWidth() {
    return width;
}

bool TileMap::getTileWalkability(Vector2f charPos) {

    return isWalkable[(int)(floor((charPos.x) / 32))][((int)floor((charPos.y) / 32))];
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
    setTileWalkability(items[j].getPosition(),false);
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

    //setFightRooms();

    srand((unsigned) time(NULL));

    int obstaclePosX=0;
    int obstaclePosY=0;

    for (int x = 0; x < 10; x++) {

        Obstacle obstacle("barile/frame-",7);
        obstacle.setOrigin(48,51);

        obstacles.push_back(obstacle);

        while (!isWalkable[obstaclePosX][obstaclePosY]) {

            obstaclePosX = rand() % width;
            obstaclePosY = rand() % width;
        }

        Vector2f v(obstaclePosX*32+16,obstaclePosY*32+16);

        obstacles[x].setPosition(v);
        isWalkable[obstaclePosX][obstaclePosY]=false;
    }

}

void TileMap::setTileWalkability(Vector2f pos, bool walkProperty) {

    isWalkable[(int)(floor(pos.x) / 32)][((int)floor(pos.y) / 32)] = walkProperty;
}

void TileMap::setFightRooms() {

    srand((unsigned) time (NULL));

    bool fR;
    int v[4];

    cout<<"VETTORE v:";

    for (int i = 0; i < 4; i++) {
        v[i] = rand() % 9;
        for (int z = 0; z < i; z++) {
            if (v[z] == v[i])
                i--;
        }

    }

    for(int i=0;i<4;i++)
        cout<<" "<<v[i];


    for(int i=0;i<9;i++){
        fR=true;
        for(int j=0;j<4;j++) {
            if (i == v[j])
                fR = false;
        }

        fightRooms[i]=fR;
    }
    cout<<endl;
    cout<<"VETTORE fightRooms:";

    for(int i=0;i<9;i++)
        cout<<" "<<fightRooms[i];

    cout<<endl;
}

bool TileMap::getFightRoomAccessibility(int pos) {
    return fightRooms[pos];
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