//
// Created by piero on 10/13/18.
//

#include "Musica.h"

using namespace std;

void Musica::playMusic(sf::Music &music, int &index, int &mapScreen) {

    try {
        switch(index){

            case 0:
                if(!music.openFromFile("Excalibur.ogg"))
                    throw "Impossibile aprire musica";
                music.play();
                break;

            case 1:
                if(mapScreen == 1){
                    if(!music.openFromFile("Courage.ogg"))
                        throw "Impossibile aprire musica";
                    mapScreen = 0;
                }
                else
                    if(!music.openFromFile("AchillevsEttore.ogg"))
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
