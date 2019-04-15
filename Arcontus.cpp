//
// Created by leogori on 30/03/19.
//

#include <iostream>
#include "Arcontus.h"

Arcontus::Arcontus() {

    textFileName="ARCONTUS";

    wall=42;
    corridorFloor=110;
    fightFloor=111;
    other=478;
    heroStartingPosition=120;

    setTileMap();

    setItemsProperty();

    load("Tileset1.png",Vector2u(32,32));
}
