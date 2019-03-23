//
// Created by piero on 10/6/18.
//

#include "TileMap.h"
#include <iostream>
#include <cmath>
#include <sstream>


using namespace std;

TileMap::TileMap() {

    setTileMap();
    findDimension();
    setItemsProperty();

    load("Tileset1.png",Vector2u(32,32));
}

TileMap::~TileMap() {}

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
    vector <Tile> lineTiles;
    Tile tile;

    while(getline(mapTextFile,line)) {

        istringstream iss(line);

        while(iss>>i) {

            tile.setValue(i);

            if (i == 42 || i == 478)
                tile.setWalkability(false);
            else
                tile.setWalkability(true);

            lineTiles.push_back(tile);
        }

        tiles.push_back(lineTiles);
        lineTiles.clear();
    }

    mapTextFile.close();
}

bool TileMap::getTileWalkability(Vector2f charPos) {

    int i=(int)(floor((charPos.y) / 32));
    int j=((int)floor((charPos.x) / 32));

    return tiles[i][j].getWalkability();
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

        while (!tiles[obstaclePosY][obstaclePosX].getWalkability()) {

            obstaclePosX = rand() % width;
            obstaclePosY = rand() % height;
        }

        Vector2f v(obstaclePosX*32+16,obstaclePosY*32+16);

        obstacles[x].setPosition(v);
        tiles[obstaclePosY][obstaclePosX].setWalkability(false);
    }

}

void TileMap::setTileWalkability(Vector2f pos, bool walkProperty) {

    int i=(int)(floor(pos.y) / 32);
    int j=(int)(floor(pos.x) / 32);


    tiles[i][j].setWalkability(walkProperty);
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

/*TileMap::getLevelName(int index) {
    switch(index){
        case 0:
            return "ARCONTUS";
        case 1:
            return "MIRINTHAS";
        case 2:
            return "PUNKHAZARD";
        case 3:
            return "CASTRISAND";
        case 4:
            return "ETRAS";
    }
}*/

/*TileMap TileMap::Create(LevelName name) {
    switch(name){
        case ARCONTUS:
            return TileMap("mappa");
        case MIRINTHAS:
            return TileMap("mappa2");
    }
}*/

void TileMap::findDimension() {

    height=tiles.size();
    width=tiles[0].size();

}

