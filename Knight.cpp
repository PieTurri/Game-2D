//
// Created by piero on 10/10/18.
//

#include "Knight.h"
#include <SFML/Graphics.hpp>
#include <cmath>

Knight::Knight(int Hp, int speed, bool armor) : Hero(Hp, speed, armor) {

    Ktexture.loadFromFile("npc3_fr1.png");
    Ksprite.setTexture(Ktexture);

    Ksprite.setPosition(64,64);
}

Knight::~Knight() {}



void Knight::draw(RenderWindow &window) {


    window.draw(Ksprite);

}

void Knight::movement(RenderWindow &window) {

    setDirection();

    View Kview=window.getView();

    if(moveL) {

        Ksprite.move(-Speed, 0);

        if(abs(Ksprite.getPosition().x-Kview.getCenter().x)<2*32)
            Kview.move(-Speed/2,0);
        else
            Kview.move(-Speed,0);

        cout<<"distanza tra pos cavaliere e pos visuale in x: "<<abs(Ksprite.getPosition().x-Kview.getCenter().x)<<endl;

        cout <<"centro visuale:"<< Kview.getCenter().x << " , " << Kview.getCenter().y << endl;
        cout <<"posizione cavaliere: "<< Ksprite.getPosition().x << " , " << Ksprite.getPosition().y << endl;

    }

    if(moveR) {


        Ksprite.move(Speed, 0);

        if(abs(Ksprite.getPosition().x-Kview.getCenter().x)<2*32)
            Kview.move(Speed/2,0);
        else
            Kview.move(Speed,0);

        cout<<"distanza tra pos cavaliere e pos visuale in x: "<<abs(Ksprite.getPosition().x-Kview.getCenter().x)<<endl;

            cout <<"centro visuale:"<< Kview.getCenter().x << " , " << Kview.getCenter().y << endl;
            cout <<"posizione cavaliere: "<< Ksprite.getPosition().x << " , " << Ksprite.getPosition().y << endl;

    }

    if(moveU) {

        Ksprite.move(0, -Speed);

        if(abs(Ksprite.getPosition().y-Kview.getCenter().y)<2*32)
            Kview.move(0,-Speed/2);
        else
            Kview.move(0,-Speed);

        cout<<"distanza tra pos cavaliere e pos visuale in y: "<<abs(Ksprite.getPosition().y-Kview.getCenter().y)<<endl;

            cout <<"centro visuale:"<< Kview.getCenter().x << " , " << Kview.getCenter().y << endl;
            cout <<"posizione cavaliere: "<< Ksprite.getPosition().x << " , " << Ksprite.getPosition().y << endl;

    }
    if(moveD) {

        Ksprite.move(0, Speed);

        if(abs(Ksprite.getPosition().y-Kview.getCenter().y)<2*32)
            Kview.move(0,Speed/2);
        else
            Kview.move(0,Speed);

        cout<<"distanza tra pos cavaliere e pos visuale in y: "<<abs(Ksprite.getPosition().y-Kview.getCenter().y)<<endl;

            cout <<"centro visuale:"<< Kview.getCenter().x << " , " << Kview.getCenter().y << endl;
            cout <<"posizione cavaliere: "<< Ksprite.getPosition().x << " , " << Ksprite.getPosition().y << endl;

    }

    //cout<<"dim  view: "<<Kview.getSize().x<<" , "<<Kview.getSize().y<<endl;

    window.setView(Kview);

}

void Knight::setDirection() {

    if (moveD) {

        if (TypeFoot) {
            Ktexture.loadFromFile("npc3_fr1.png");
            TypeFoot = false;
        }
        else{
            Ktexture.loadFromFile("npc3_fr2.png");
            TypeFoot = true;
        }

    }

    if (moveU) {

        if (TypeFoot) {
            Ktexture.loadFromFile("npc3_bk1.png");
            TypeFoot = false;
        }
        else{
            Ktexture.loadFromFile("npc3_bk2.png");
            TypeFoot = true;
        }

    }

    if (moveL) {

        if (TypeFoot) {
            Ktexture.loadFromFile("npc3_lf1.png");
            TypeFoot = false;
        }
        else{
            Ktexture.loadFromFile("npc3_lf2.png");
            TypeFoot = true;
        }

    }

    if (moveR) {

        if (TypeFoot) {
            Ktexture.loadFromFile("npc3_rt1.png");
            TypeFoot = false;
        }
        else{
            Ktexture.loadFromFile("npc3_rt2.png");
            TypeFoot = true;
        }

    }

    Ksprite.setTexture(Ktexture);
}










