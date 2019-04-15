//
// Created by piero on 10/13/18.
//

#include "Musica.h"

using namespace std;

Musica::Musica() {}

void Musica::playMusic(sf::Music &music, int &index, int &mapScreen) {

    try {
        switch(index){

            case 0:
                if(!music.openFromFile("Music/Living_Room.ogg"))
                    throw "Impossibile aprire musica";
                music.play();
                break;

            case 1:
                //music.stop();
                if(!music.openFromFile("Music/Forest.ogg"))
                    throw "Impossibile aprire musica";
                music.play();
                break;
            default:
                break;
        }

    }
    catch (...){
        cout<<"ERRORE MUSICA"<<endl;
    }
}

Musica::~Musica() {

}

void Musica::setIndex(int index) {
    Musica::index = index;
}

void Musica::changeMusic(sf::Music &music) {
    music.openFromFile("Music/Living_Room.ogg");
    music.play();
}



