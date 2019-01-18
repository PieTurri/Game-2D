//
// Created by piero on 10/6/18.
//

#include "TileMap.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
#include <fstream>

#define BLACK 478;
#define WALL 42;
#define MOUNT 49;
#define FLOOR 111;
#define VOLCANO 342;
#define STATUE 251;
#define BOSSDOOR 153;
#define LADDER 247;


using namespace std;


TileMap::TileMap() : TileMap(73,73) {

    spriteItems=new Sprite[145];

    setTileMap();
    load("Tileset1.png",Vector2u(32,32));
    updateRoomsItems();
    setItemsProperty();
}


TileMap::TileMap(unsigned int h, unsigned int w): height(h), width(w) , cellDim(17) {}


TileMap::~TileMap() {}

bool TileMap::load(const std::string &tileset, sf::Vector2u tileSize) {

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

    states.texture=&m_tileset;

    return true;

}

void TileMap::draw(RenderWindow &window) {



    window.draw(m_vertices,states);

    for(int i=0;i<145;i++)
        window.draw(spriteItems[i]);
}

void TileMap::setTileMap() {

    ifstream mapTextFile;

    isWalkable = new bool[height * width];

    tiles=new int[height*width];

    mapTextFile.open("mappa");

    char ch;
    int i=0;

    while(!mapTextFile.eof()) {
        if (!isspace(ch)) {
            mapTextFile >> tiles[i];
            if(tiles[i]==42)
                isWalkable[i]=false;
            else
                isWalkable[i]=true;
            i++;
        }
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

            return isWalkable[(int)(floor((charPos.x) / 32)) +((int)floor((charPos.y) / 32)) * width];
}

void TileMap::followCharPos(View &view,Sprite &spritePlayer) {

    float dy=spritePlayer.getPosition().y+16-view.getCenter().y;
    float dx=spritePlayer.getPosition().x+16-view.getCenter().x;

    times=clock.getElapsedTime();

    if(times.asMilliseconds()>10) {
        if (dx != 0 || dy != 0) {

            float m = dy / dx;

            if (dx > 0)
                view.move(1, m);
            else if (dx < 0)
                view.move(-1, -m);
            else
                view.move(0, abs(dy) / dy);

        }
        clock.restart();
    }

}

void TileMap::updateRoomsItems() {


    string s1,s2;

    s2 = "Room items/torch frames sequence/formato png/frame-" + to_string(nTorch) + ".png";

    texture[0].loadFromFile(s2);


    for(int i=0;i<84;i++) {
        spriteItems[i].setTexture(texture[0]);
    }

    texture[1].loadFromFile("Room items/barrel frame sequences/png senza ombra/frame-1.png");

    for(int i=84;i<144;i++) {
        spriteItems[i].setTexture(texture[1]);
    }

    s1="Room items/merchant frames sequence/mercante senza sfondo png/frame-"+to_string(nMerchant)+".png";

    texture[2].loadFromFile(s1);

    spriteItems[144].setTexture(texture[2]);

    nTorch++;
    if(nTorch%15==0)
        nMerchant++;
    if(nTorch==33)
        nTorch=1;
    if(nMerchant==6)
        nMerchant=1;


}

void TileMap::setItemsProperty() {

    int j = 0;

    for (int i = 0; i < 84; i++) {
        spriteItems[i].setScale(0.25, 0.25);
    }

    for (int i = 84; i < 144; i++) {
        spriteItems[i].setScale(0.30, 0.30);
        spriteItems[i].setOrigin(-16, -10);
    }

    for (int i = 0; i < 18; i = i + 2) {

        spriteItems[i].setPosition((cellFloorCoords[j] % 73) * 32, (float) (floor(cellFloorCoords[j] / 73) * 32));
        spriteItems[i + 1].setPosition((cellFloorCoords[j] % 73) * 32,
                                       (float) (floor(cellFloorCoords[j] / 73) * 32 + 32 * 13 + 16));
        spriteItems[i].rotate(30);
        spriteItems[i + 1].rotate(30);
        j++;
    }

    j = 0;
    for (int i = 18; i < 36; i = i + 2) {

        spriteItems[i].setPosition((cellFloorCoords[j] % 73) * 32 + 32 * 14 + 4,
                                   (float) (floor(cellFloorCoords[j] / 73) * 32 + 16));
        spriteItems[i + 1].setPosition((cellFloorCoords[j] % 73) * 32 + 32 * 14 + 4,
                                       (float) (floor(cellFloorCoords[j] / 73) * 32 + 32 * 14));
        spriteItems[i].rotate(-30);
        spriteItems[i + 1].rotate(-30);
        j++;
    }

    j = 0;
    for (int i = 36; i < 84; i = i + 8) {
        spriteItems[i].setPosition((corridorCoords[j] % 73) * 32, (float) (floor(corridorCoords[j] / 73) * 32 - 52));
        spriteItems[i + 1].setPosition((corridorCoords[j] % 73) * 32 + 32 * 4,
                                       (float) (floor(corridorCoords[j] / 73) * 32 - 52));
        spriteItems[i].scale(1, 0.75);
        spriteItems[i + 1].scale(1, 0.75);
        spriteItems[i + 2].setPosition((corridorCoords[j] % 73) * 32 + 32,
                                       (float) (floor(corridorCoords[j] / 73) * 32 + 32 * 11 + 20));
        spriteItems[i + 3].setPosition((corridorCoords[j] % 73) * 32 + 32 * 5,
                                       (float) (floor(corridorCoords[j] / 73) * 32 + 32 * 11 + 20));
        spriteItems[i + 2].scale(1, 0.75);
        spriteItems[i + 3].scale(1, 0.75);
        spriteItems[i + 2].rotate(180);
        spriteItems[i + 3].rotate(180);

        j++;

        spriteItems[i + 4].setPosition((corridorCoords[j] % 73) * 32 - 60,
                                       (float) (floor(corridorCoords[j] / 73) * 32));
        spriteItems[i + 5].setPosition((corridorCoords[j] % 73) * 32 - 60,
                                       (float) (floor(corridorCoords[j] / 73) * 32 + 32 * 4));
        spriteItems[i + 4].rotate(-30);
        spriteItems[i + 5].rotate(-30);
        spriteItems[i + 6].setPosition((corridorCoords[j] % 73) * 32 + 32 * 11,
                                       (float) (floor(corridorCoords[j] / 73) * 32 - 16));
        spriteItems[i + 7].setPosition((corridorCoords[j] % 73) * 32 + 32 * 11,
                                       (float) (floor(corridorCoords[j] / 73) * 32 + 32 * 4 - 16));
        spriteItems[i + 6].rotate(30);
        spriteItems[i + 7].rotate(30);

        j++;

    }

    srand((unsigned) time(NULL));

    int c = 84;

    int obPossiblePos;
    int k;
    int adderx;
    int addery;
    int obstaclePos;
    int dispType=0;
    int posx;
    int posy;
    int pos[2];
    int store[5]={5,5,5,5,5};
    int store1[4]={4,4,4,4};
    int s=0;
    int s1=0;
    bool variation;

    setFightRooms();

    for (int i = 0; i < 9; i++) {

        variation=false;
        if (fightRooms[i]) {

            while(!variation) {
                variation=true;
                dispType = rand() % 5;
                for (int m = 0; m < 4; m++) {
                    if (dispType == store[m])
                        variation=false;
                }
            }

            store[s]=dispType;
            s++;

            if (dispType == 0) {

                cout << "tipo di disposizione: " << dispType << endl;

                obPossiblePos = rand() % 99;

                k = 0;
                adderx = obPossiblePos % 12;
                addery = ((obPossiblePos - adderx) / 12);

                cout << "aggiunta ostacolo x e y: " << adderx << " , " << addery << endl;

                obstaclePos = cellFloorCoords[i] + 1 + adderx + (addery+1) * width;
                posx = (obstaclePos % width) * 32;
                posy = ((obstaclePos - (posx / 32)) / width) * 32;

                cout << "posizione possibile: " << obPossiblePos << " in stanza " << i << endl;
                cout << "posizione ostacolo x e y: " << posx << " , " << posy << endl;

                for (int z = c; z < c + 15; z++) {


                    spriteItems[z].setPosition(posx + 32 * (k % 3), posy);

                    setTileWalkability(posx + 32 * (k % 3), posy, false);

                    k++;

                    if (k % 3 == 0) {
                        posy = posy + 32;
                    }
                }

                c += 15;
            } else if (dispType == 1) {

                cout << "tipo di disposizione: " << dispType << endl;

                for (int z = c; z < c + 15; z++) {


                    obPossiblePos = rand() % 169;

                    adderx = obPossiblePos % 13;
                    addery = ((obPossiblePos - adderx) / 13);

                    obstaclePos = cellFloorCoords[i] + 1 + adderx + width * (addery + 1);

                    cout << "posizione possibile " << obstaclePos << " in stanza " << i << endl;

                    posx = (obstaclePos % width) * 32;
                    posy = ((obstaclePos - (posx / 32)) / width) * 32;

                    if(getTileWalkability(Vector2f(posx,posy))) {
                        spriteItems[z].setPosition(posx, posy);
                        setTileWalkability(posx, posy, false);
                    }
                    else
                        z--;
                }
                c += 15;

            } else if (dispType == 2) {
                cout << "tipo di disposizione: " << dispType << endl;

                obPossiblePos = rand() % 81;

                k = 0;

                adderx = obPossiblePos % 9;
                addery = ((obPossiblePos - adderx) / 9);

                cout << "aggiunta ostacolo x e y: " << adderx << " , " << addery << endl;

                obstaclePos = cellFloorCoords[i] + 74 + adderx + addery * width;
                posx = (obstaclePos % width) * 32;
                posy = ((obstaclePos - (posx / 32)) / width) * 32;

                cout << "posizione possibile: " << obPossiblePos << " in stanza " << i << endl;
                cout << "posizione ostacolo x e y: " << posx << " , " << posy << endl;

                for (int z = c; z < c + 15; z++) {

                    spriteItems[z].setPosition(posx, posy + 32 * (k % 3));

                    setTileWalkability(posx, posy + 32 * (k % 3), false);

                    k++;

                    if (k % 3 == 0) {
                        posx = posx + 32;
                    }
                }

                c += 15;
            } else if(dispType ==3){

                cout << "tipo di disposizione: " << dispType << " in stanza " << i << endl;

                pos[0] = cellFloorCoords[i] + 3 * width + 5;
                pos[1] = cellFloorCoords[i] + 11 * width + 5;
                for (int y = 0; y < 2; y++) {
                    for (int z = 0; z < 5; z++) {
                        tiles[pos[y] + z] = WALL;
                        isWalkable[pos[y] + z] = false;
                    }
                }

                pos[0] += 4;
                pos[1] -= 4 * width;
                for (int y = 0; y < 2; y++) {
                    for (int z = 0; z < 5; z++) {
                        tiles[pos[y] + z * width] = WALL;
                        isWalkable[pos[y] + z * width] = false;
                    }
                }

                pos[0] += 4 * width;
                pos[1] -= 2;

                for (int y = 0; y < 2; y++) {
                    for (int z = 0; z < 3; z++) {
                        tiles[pos[y] + z] = WALL;
                        isWalkable[pos[y] + z] = false;
                    }
                }


                pos[0] += 2;
                for (int y = 0; y < 2; y++) {
                    for (int z = 0; z < 3; z++) {
                        tiles[pos[y] + z * width] = WALL;
                        isWalkable[pos[y] + z * width] = false;
                        tiles[pos[y] - z * width] = WALL;
                        isWalkable[pos[y] - z * width] = false;
                    }
                }

                posx = ((cellFloorCoords[i] + 7 * (width + 1)) % width) * 32;
                posy = (cellFloorCoords[i] + 7 * (width + 1) - (posx / 32)) / width * 32;

                spriteItems[c].setPosition(posx, posy);
                isWalkable[cellFloorCoords[i] + 7 * (width + 1)] = false;

                c++;

                pos[0] = cellFloorCoords[i] + 9 * width;
                pos[1] = cellFloorCoords[i] + 12 + 5 * width;

                for (int y = 0; y < 2; y++) {
                    for (int z = c; z < c + 3; z++) {
                        posx = (pos[y] % width) * 32;
                        posy = (pos[y] - posx / 32) / width * 32;
                        spriteItems[z].setPosition(posx + (z - c) * 32, posy);
                        isWalkable[pos[y] + (z - c)] = false;
                    }
                    c += 3;
                }

                pos[0] = cellFloorCoords[i] + 10 * width;
                pos[1] = cellFloorCoords[i] + 11 + 4 * width;

                for (int y = 0; y < 2; y++) {
                    for (int z = c; z < c + 4; z++) {
                        posx = (pos[y] % width) * 32;
                        posy = (pos[y] - posx / 32) / width * 32;
                        spriteItems[z].setPosition(posx + (z - c) * 32, posy);
                        isWalkable[pos[y] + (z - c)] = false;
                    }
                    c += 4;
                }
            }
            else{

                cout << "tipo di disposizione: " << dispType << endl;

                for(int z=0;z<15;z++){
                    obPossiblePos = rand() % 169;

                    adderx = obPossiblePos % 13;
                    addery = ((obPossiblePos - adderx) / 13);

                    obstaclePos = cellFloorCoords[i] + 1 + adderx + width * (addery + 1);

                    cout << "posizione possibile " << obstaclePos << " in stanza " << i << endl;

                    tiles[obstaclePos] = VOLCANO;
                    isWalkable[obstaclePos] = false;
                }

            }
        }
        else{
            while(!variation) {
                variation=true;
                dispType = rand() % 4;
                for (int m = 0; m < 3; m++) {
                    if (dispType == store1[m])
                        variation=false;
                }
            }

            store1[s1]=dispType;
            s1++;

            if(dispType==0) {
                tiles[cellFloorCoords[i] + (width + 1) * 7] = LADDER;
                isWalkable[cellFloorCoords[i] + (width + 1) * 7] = false;
            }
            else if(dispType==1){
                posx = ((cellFloorCoords[i] + 7 * (width + 1)) % width) * 32;
                posy = (cellFloorCoords[i] + 7 * (width + 1) - (posx / 32)) / width * 32;

                spriteItems[144].setPosition(posx, posy);
                cout<<"scala dimensioni mercante: "<<spriteItems[144].getScale().x<<"  , "<<spriteItems[144].getScale().y<<endl;
                spriteItems[144].setOrigin(300,300);
                isWalkable[cellFloorCoords[i] + 7 * (width + 1)] = false;
            }
        }
    }
}

void TileMap::setTileWalkability(float x, float y, bool walkProperty) {

    isWalkable[(int)(floor(x) / 32) +((int)floor(y) / 32) * width] = walkProperty;
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




