//
// Created by piero on 10/13/18.
//

#include "Musica.h"

using namespace std;

void Musica::playMusic(sf::Music &music, int &index, int &mapScreen) {

    switch(index){

        case 0:
            music.openFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/Excalibur.ogg");
            music.play();
            break;

        case 1:
            if(mapScreen == 1){
                music.openFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/Courage.ogg");
                mapScreen = 0;
            }
            else
                music.openFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/AchillevsEttore.ogg");
            music.play();
            break;
    }


    /*std::string file = to_string(music) + ".ogg";
    if(!soundtrack.loadFromFile(file))  //carico soundtrack
        std::cout<<music<<" not found"<<std::endl;
    sound.setBuffer(soundtrack);
    //sound.play();*/

}
