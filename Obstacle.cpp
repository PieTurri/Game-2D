//
// Created by leogori on 28/02/19.
//

#include "Obstacle.h"
#include <iostream>

using namespace std;

Obstacle::Obstacle(string file, int numberOfFrame) : Item(file, numberOfFrame){
    destroyed=false;
    //cout<<file+to_string(index)+".png"<<endl;
}

Obstacle::~Obstacle() {}

void Obstacle::setDestroyed(bool state) {
    destroyed=state;
}

bool Obstacle::getDestroyed(){
    return destroyed;
}