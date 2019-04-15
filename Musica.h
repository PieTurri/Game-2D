//
// Created by piero on 10/13/18.
//

#ifndef PROJECT_MUSICA_H
#define PROJECT_MUSICA_H


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <stdio.h>


class Musica {
public:

    Musica();

    ~Musica();

    void playMusic(sf::Music &music, int &index, int &mapScreen);

    void setIndex(int index);

    //bool isChanged(int index);

    void changeMusic(sf::Music &music);

protected:

    sf::SoundBuffer soundtrack;
    sf::Sound sound;

    int index = 0;

};

#endif //PROJECT_MUSICA_H
