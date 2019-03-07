//
// Created by piero on 10/13/18.
//

#include "Musica.h"

using namespace std;

void Musica::playMusic(sf::Music &music, int &index, int &mapScreen) {

    switch(index){

        case 0:
            music.openFromFile("Excalibur.ogg");
            music.play();
            break;

        case 1:
            if(mapScreen == 1){
                music.openFromFile("Courage.ogg");
                mapScreen = 0;
            }
            else
                music.openFromFile("AchillevsEttore.ogg");
            music.play();
            break;
    }


    /*std::string file = to_string(music) + ".ogg";
    if(!soundtrack.loadFromFile(file))  //carico soundtrack
        std::cout<<music<<" not found"<<std::endl;
    sound.setBuffer(soundtrack);
    //sound.play();*/

}
