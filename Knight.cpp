//
// Created by piero on 10/10/18.
//

#include "Knight.h"
#include <SFML/Graphics.hpp>
#include <cmath>

Knight::Knight(int Hp, int speed, bool armor) : Hero(Hp, speed, armor) {}

Knight::~Knight() {}



void Knight::draw(Sprite &Ksprite,Texture &Ktexture,int KtypeMove) {

    if (KtypeMove==0) {

        if (TypeFoot) {
            Ktexture.loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/npc3_fr1.png");
            TypeFoot = false;
        }
        else{
            Ktexture.loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/npc3_fr2.png");
            TypeFoot = true;
        }

    }

    if (KtypeMove==1) {

        if (TypeFoot) {
            Ktexture.loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/npc3_bk1.png");
            TypeFoot = false;
        }
        else{
            Ktexture.loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/npc3_bk2.png");
            TypeFoot = true;
        }

    }

    if (KtypeMove==2) {

        if (TypeFoot) {
            Ktexture.loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/npc3_lf1.png");
            TypeFoot = false;
        }
        else{
            Ktexture.loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/npc3_lf2.png");
            TypeFoot = true;
        }

    }

    if (KtypeMove==3) {

        if (TypeFoot) {
            Ktexture.loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/npc3_rt1.png");
            TypeFoot = false;
        }
        else{
            Ktexture.loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/npc3_rt2.png");
            TypeFoot = true;
        }

    }
    Ksprite.setTexture(Ktexture);

}

void Knight::movement(Sprite &Ksprite,string dir,View &Kview) {


    if(dir=="left") {

        Ksprite.move(-Speed, 0);

        if(abs(Ksprite.getPosition().x-Kview.getCenter().x)<3*32)
            Kview.move(-Speed/2,0);
        else
            Kview.move(-Speed,0);

        cout<<"distanza tra pos cavaliere e pos visuale in x: "<<abs(Ksprite.getPosition().x-Kview.getCenter().x)<<endl;

        cout <<"centro visuale:"<< Kview.getCenter().x << " , " << Kview.getCenter().y << endl;
        cout <<"posizione cavaliere: "<< Ksprite.getPosition().x << " , " << Ksprite.getPosition().y << endl;


    }

    if(dir=="right") {


        Ksprite.move(Speed, 0);

        if(abs(Ksprite.getPosition().x-Kview.getCenter().x)<3*32)
            Kview.move(Speed/2,0);
        else
            Kview.move(Speed,0);

        cout<<"distanza tra pos cavaliere e pos visuale in x: "<<abs(Ksprite.getPosition().x-Kview.getCenter().x)<<endl;

            cout <<"centro visuale:"<< Kview.getCenter().x << " , " << Kview.getCenter().y << endl;
            cout <<"posizione cavaliere: "<< Ksprite.getPosition().x << " , " << Ksprite.getPosition().y << endl;

    }

    if(dir=="up") {

        Ksprite.move(0, -Speed);

        if(abs(Ksprite.getPosition().y-Kview.getCenter().y)<3*32)
            Kview.move(0,-Speed/2);
        else
            Kview.move(0,-Speed);

        cout<<"distanza tra pos cavaliere e pos visuale in y: "<<abs(Ksprite.getPosition().y-Kview.getCenter().y)<<endl;

            cout <<"centro visuale:"<< Kview.getCenter().x << " , " << Kview.getCenter().y << endl;
            cout <<"posizione cavaliere: "<< Ksprite.getPosition().x << " , " << Ksprite.getPosition().y << endl;

    }
    if(dir=="down") {

        Ksprite.move(0, Speed);

        if(abs(Ksprite.getPosition().y-Kview.getCenter().y)<3*32)
            Kview.move(0,Speed/2);
        else
            Kview.move(0,Speed);

        cout<<"distanza tra pos cavaliere e pos visuale in y: "<<abs(Ksprite.getPosition().y-Kview.getCenter().y)<<endl;

            cout <<"centro visuale:"<< Kview.getCenter().x << " , " << Kview.getCenter().y << endl;
            cout <<"posizione cavaliere: "<< Ksprite.getPosition().x << " , " << Ksprite.getPosition().y << endl;

    }

}








