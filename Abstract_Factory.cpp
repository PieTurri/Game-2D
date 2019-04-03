//
// Created by leogori on 31/03/19.
//

#include "Abstract_Factory.h"
#include "LevelOneFactory.h"
#include "LevelTwoFactory.h"

Abstract_Factory * Abstract_Factory::create(int index){
    switch(index){
        case 0:
            return new LevelOneFactory;
        case 1:
            return new LevelTwoFactory;
        default:
            return nullptr;
    }
}