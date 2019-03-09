//
// Created by leogori on 09/03/19.
//

#ifndef PROJECT_TILE_H
#define PROJECT_TILE_H


class Tile {

public:

    Tile();

    void setValue(int val);

    int getValue();

    void setWalkability(bool state);

    bool getWalkability();

private:

    int value;
    bool walkability;
};


#endif //PROJECT_TILE_H
