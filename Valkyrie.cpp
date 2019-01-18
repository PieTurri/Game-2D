//
// Created by piero on 10/10/18.
//

#include "Valkyrie.h"
#include "TileMap.h"

Valkyrie::Valkyrie(int Hp, int speed, bool armor) : Hero(Hp, speed, armor) {

    Vtexture.loadFromFile("npc4_fr1.gif");
    Vsprite.setTexture(Vtexture);
}

Valkyrie::~Valkyrie() {}

void Valkyrie::draw(RenderWindow& window) {

    window.draw(Vsprite);
}

void Valkyrie::movement(RenderWindow &window) {

    setDirection();

    View Vview=window.getView();

    if(moveL) {

        Vsprite.move(-Speed, 0);

        if(abs(Vsprite.getPosition().x-Vview.getCenter().x)<2*32)
            Vview.move(-Speed/2,0);
        else
            Vview.move(-Speed,0);

        cout<<"distanza tra pos cavaliere e pos visuale in x: "<<abs(Vsprite.getPosition().x-Vview.getCenter().x)<<endl;

        cout <<"centro visuale:"<< Vview.getCenter().x << " , " << Vview.getCenter().y << endl;
        cout <<"posizione cavaliere: "<< Vsprite.getPosition().x << " , " << Vsprite.getPosition().y << endl;


    }

    if(moveR) {


        Vsprite.move(Speed, 0);

        if(abs(Vsprite.getPosition().x-Vview.getCenter().x)<2*32)
            Vview.move(Speed/2,0);
        else
            Vview.move(Speed,0);

        cout<<"distanza tra pos cavaliere e pos visuale in x: "<<abs(Vsprite.getPosition().x-Vview.getCenter().x)<<endl;

        cout <<"centro visuale:"<< Vview.getCenter().x << " , " << Vview.getCenter().y << endl;
        cout <<"posizione cavaliere: "<< Vsprite.getPosition().x << " , " << Vsprite.getPosition().y << endl;

    }

    if(moveU) {

        Vsprite.move(0, -Speed);

        if(abs(Vsprite.getPosition().y-Vview.getCenter().y)<2*32)
            Vview.move(0,-Speed/2);
        else
            Vview.move(0,-Speed);

        cout<<"distanza tra pos cavaliere e pos visuale in y: "<<abs(Vsprite.getPosition().y-Vview.getCenter().y)<<endl;

        cout <<"centro visuale:"<< Vview.getCenter().x << " , " << Vview.getCenter().y << endl;
        cout <<"posizione cavaliere: "<< Vsprite.getPosition().x << " , " << Vsprite.getPosition().y << endl;

    }
    if(moveD) {

        Vsprite.move(0, Speed);

        if(abs(Vsprite.getPosition().y-Vview.getCenter().y)<2*32)
            Vview.move(0,Speed/2);
        else
            Vview.move(0,Speed);

        cout<<"distanza tra pos cavaliere e pos visuale in y: "<<abs(Vsprite.getPosition().y-Vview.getCenter().y)<<endl;

        cout <<"centro visuale:"<< Vview.getCenter().x << " , " << Vview.getCenter().y << endl;
        cout <<"posizione cavaliere: "<< Vsprite.getPosition().x << " , " << Vsprite.getPosition().y << endl;

    }

    window.setView(Vview);
}

void Valkyrie::setDirection() {

    if (moveD&&!moveL||moveD&&!moveR) {

        if (TypeFoot) {
            Vtexture.loadFromFile("npc4_fr1.gif");
            TypeFoot = false;
        }
        else{
            Vtexture.loadFromFile("npc4_fr2.gif");
            TypeFoot = true;
        }

    }

    if (moveU&&!moveL||moveU&&!moveR) {

        if (TypeFoot) {
            Vtexture.loadFromFile("npc4_bk1.gif");
            TypeFoot = false;
        }
        else{
            Vtexture.loadFromFile("npc4_bk2.gif");
            TypeFoot = true;
        }

    }

    if (moveL&&moveU||moveL&&moveD) {

        if (TypeFoot) {
            Vtexture.loadFromFile("npc4_lf1.gif");
            TypeFoot = false;
        }
        else{
            Vtexture.loadFromFile("npc4_lf2.gif");
            TypeFoot = true;
        }

    }

    if (moveR&&moveU||moveR&&moveD) {

        if (TypeFoot) {
            Vtexture.loadFromFile("npc4_rt1.gif");
            TypeFoot = false;
        }
        else{
            Vtexture.loadFromFile("npc4_rt2.gif");
            TypeFoot = true;
        }

    }

    Vsprite.setTexture(Vtexture);

}


