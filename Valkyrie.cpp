//
// Created by piero on 10/10/18.
//

#include "Valkyrie.h"
#include "TileMap.h"

Valkyrie::Valkyrie(int Hp, int speed, bool armor) : Hero(Hp, speed, armor) {}

Valkyrie::~Valkyrie() {}

void Valkyrie::draw(Sprite &Vsprite, Texture &Vtexture, int VtypeMove) {


    if (VtypeMove==0) {

        if (TypeFoot) {
            Vtexture.loadFromFile("/home/leogori/Scaricati/immagini progetto/Risorse/player2/npc4_fr1.gif");
            TypeFoot = false;
        }
        else{
            Vtexture.loadFromFile("/home/leogori/Scaricati/immagini progetto/Risorse/player2/npc4_fr2.gif");
            TypeFoot = true;
        }

    }

    if (VtypeMove==1) {

        if (TypeFoot) {
            Vtexture.loadFromFile("/home/leogori/Scaricati/immagini progetto/Risorse/player2/npc4_bk1.gif");
            TypeFoot = false;
        }
        else{
            Vtexture.loadFromFile("/home/leogori/Scaricati/immagini progetto/Risorse/player2/npc4_bk2.gif");
            TypeFoot = true;
        }

    }

    if (VtypeMove==2) {

        if (TypeFoot) {
            Vtexture.loadFromFile("/home/leogori/Scaricati/immagini progetto/Risorse/player2/npc4_lf1.gif");
            TypeFoot = false;
        }
        else{
            Vtexture.loadFromFile("/home/leogori/Scaricati/immagini progetto/Risorse/player2/npc4_lf2.gif");
            TypeFoot = true;
        }

    }

    if (VtypeMove==3) {

        if (TypeFoot) {
            Vtexture.loadFromFile("/home/leogori/Scaricati/immagini progetto/Risorse/player2/npc4_rt1.gif");
            TypeFoot = false;
        }
        else{
            Vtexture.loadFromFile("/home/leogori/Scaricati/immagini progetto/Risorse/player2/npc4_rt2.gif");
            TypeFoot = true;
        }

    }

    //if(!Ktexture.loadFromFile("/home/leogori/Scaricati/immagini progetto/Risorse/player2/npc4_fr1.gif"))
      //  cout << "ERRORE" << endl;



    Vsprite.setTexture(Vtexture);

}

void Valkyrie::movement(Sprite &Vsprite, string dir,View &Vview) {

    if(dir=="left") {

        Vsprite.move(-Speed, 0);

        if(abs(Vsprite.getPosition().x-Vview.getCenter().x)<2*32)
            Vview.move(-Speed/2,0);
        else
            Vview.move(-Speed,0);

        cout<<"distanza tra pos cavaliere e pos visuale in x: "<<abs(Vsprite.getPosition().x-Vview.getCenter().x)<<endl;

        cout <<"centro visuale:"<< Vview.getCenter().x << " , " << Vview.getCenter().y << endl;
        cout <<"posizione cavaliere: "<< Vsprite.getPosition().x << " , " << Vsprite.getPosition().y << endl;


    }

    if(dir=="right") {


        Vsprite.move(Speed, 0);

        if(abs(Vsprite.getPosition().x-Vview.getCenter().x)<2*32)
            Vview.move(Speed/2,0);
        else
            Vview.move(Speed,0);

        cout<<"distanza tra pos cavaliere e pos visuale in x: "<<abs(Vsprite.getPosition().x-Vview.getCenter().x)<<endl;

        cout <<"centro visuale:"<< Vview.getCenter().x << " , " << Vview.getCenter().y << endl;
        cout <<"posizione cavaliere: "<< Vsprite.getPosition().x << " , " << Vsprite.getPosition().y << endl;

    }

    if(dir=="up") {

        Vsprite.move(0, -Speed);

        if(abs(Vsprite.getPosition().y-Vview.getCenter().y)<2*32)
            Vview.move(0,-Speed/2);
        else
            Vview.move(0,-Speed);

        cout<<"distanza tra pos cavaliere e pos visuale in y: "<<abs(Vsprite.getPosition().y-Vview.getCenter().y)<<endl;

        cout <<"centro visuale:"<< Vview.getCenter().x << " , " << Vview.getCenter().y << endl;
        cout <<"posizione cavaliere: "<< Vsprite.getPosition().x << " , " << Vsprite.getPosition().y << endl;

    }
    if(dir=="down") {

        Vsprite.move(0, Speed);

        if(abs(Vsprite.getPosition().y-Vview.getCenter().y)<2*32)
            Vview.move(0,Speed/2);
        else
            Vview.move(0,Speed);

        cout<<"distanza tra pos cavaliere e pos visuale in y: "<<abs(Vsprite.getPosition().y-Vview.getCenter().y)<<endl;

        cout <<"centro visuale:"<< Vview.getCenter().x << " , " << Vview.getCenter().y << endl;
        cout <<"posizione cavaliere: "<< Vsprite.getPosition().x << " , " << Vsprite.getPosition().y << endl;

    }
}


