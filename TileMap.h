//
// Created by piero on 10/6/18.
//

#ifndef PROJECT_TILEMAP_H
#define PROJECT_TILEMAP_H

#include "Obstacle.h"
#include "TileBossMap.h"

using namespace sf;
using namespace std;

class TileMap:public TileBossMap{

public:

    TileMap();

    ~TileMap();

    void updateRoomsItems();

    void setItemsProperty();

    vector<Obstacle> & getObstacle();

    void setObstacle(vector<Obstacle> &obstacle);

    bool isFightingGround(Tile& tile);

    void openBossDoor();

    bool isBossDoor(Tile& tile);

    void draw(RenderWindow& window) override;

    void setTileMap() override;

    void setCorridorFloor(int value);

    void setFightFloor(int value);

    void setVacuum(int value);

protected:

    //static TileMap* instance;

    vector <Obstacle> obstacles;

    //Obstacle obstacle;

    vector<Item> items;

    fstream itemTextFile;

    int corridorFloor;
    int fightFloor;
    int other;


};


#endif //PROJECT_TILEMAP_H
