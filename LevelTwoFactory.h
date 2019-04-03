//
// Created by leogori on 31/03/19.
//

#ifndef PROJECT_LEVELTWOFACTORY_H
#define PROJECT_LEVELTWOFACTORY_H

#include "Abstract_Factory.h"
#include "Mirinthas.h"

class LevelTwoFactory : public Abstract_Factory{
public:

    Enemy* createEnemy() override;

    TileMap* createMap() override;

};


#endif //PROJECT_LEVELTWOFACTORY_H
