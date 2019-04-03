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

    void setHeroWalkability(bool state);

    bool getHeroWalkability();

    bool getEnemyWalkability() const;

    void setEnemyWalkability(bool state);

    void reset();

private:

    int value;
    bool heroWalkability;
    bool enemyWalkability;
};


#endif //PROJECT_TILE_H