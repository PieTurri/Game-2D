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

    float viewLeftLimit=(Vview.getSize().x/2)+32;

    float viewUpperLimit=(Vview.getSize().y/2)+32;

    float viewRightLimit=TileMap::getMapWidth()*32-viewLeftLimit;

    float viewDownLimit=TileMap::getMapHeight()*32-viewUpperLimit;

    cout<<"Limiti di view: "<<viewLeftLimit<<" , "<<viewUpperLimit<<" , "<<viewRightLimit<<" , "<<viewDownLimit<<endl;




    if(dir=="left") {

        if(Vsprite.getPosition().x>64) {

            Vsprite.move(-Speed, 0);
            //Vview.move(-Speed,0);

            if (Vsprite.getPosition().x >= viewLeftLimit && Vsprite.getPosition().x <=viewRightLimit) {

                if (Vsprite.getPosition().y <= viewDownLimit && Vsprite.getPosition().y >= viewUpperLimit)
                    Vview.setCenter(Vsprite.getPosition().x, Vsprite.getPosition().y);

                if (Vsprite.getPosition().y > viewDownLimit)
                    Vview.setCenter(Vsprite.getPosition().x, viewDownLimit);
                if (Vsprite.getPosition().y < viewUpperLimit)
                    Vview.setCenter(Vsprite.getPosition().x, viewUpperLimit);

            }


            cout <<"centro di view: "<< Vview.getCenter().x << " , " << Vview.getCenter().y << endl;
            cout <<"coordinate del personaggio: "<< Vsprite.getPosition().x << " , " << Vsprite.getPosition().y << endl;
        }
    }

    if(dir=="right") {

        if(Vsprite.getPosition().x<(TileMap::getMapWidth()-3)*32) {
            Vsprite.move(Speed, 0);
            //Vview.move(Speed,0);


            if (Vsprite.getPosition().x <= viewRightLimit && Vsprite.getPosition().x >= viewLeftLimit){
                if (Vsprite.getPosition().y <= viewDownLimit && Vsprite.getPosition().y >= viewUpperLimit)
                    Vview.setCenter(Vsprite.getPosition().x, Vsprite.getPosition().y);
                if (Vsprite.getPosition().y > viewDownLimit)
                    Vview.setCenter(Vsprite.getPosition().x, viewDownLimit);
                if (Vsprite.getPosition().y < viewUpperLimit)
                    Vview.setCenter(Vsprite.getPosition().x, viewUpperLimit);
            }

            cout <<"centro di view: "<< Vview.getCenter().x << " , " << Vview.getCenter().y << endl;
            cout <<"coordinate del personaggio: "<< Vsprite.getPosition().x << " , " << Vsprite.getPosition().y << endl;
        }
    }

    if(dir=="up") {

        if(Vsprite.getPosition().y>64) {
            Vsprite.move(0, -Speed);
            //Vview.move(0, -Speed);

            if (Vsprite.getPosition().y <= viewDownLimit && Vsprite.getPosition().y >= viewUpperLimit) {
                if (Vsprite.getPosition().x <= viewRightLimit && Vsprite.getPosition().x >= viewLeftLimit)
                    Vview.setCenter(Vsprite.getPosition().x, Vsprite.getPosition().y);
                if (Vsprite.getPosition().x > viewRightLimit)
                    Vview.setCenter(viewRightLimit, Vsprite.getPosition().y);
                if (Vsprite.getPosition().x < viewLeftLimit)
                    Vview.setCenter(viewLeftLimit, Vsprite.getPosition().y);

            }



            cout <<"centro di view: "<< Vview.getCenter().x << " , " << Vview.getCenter().y << endl;
            cout <<"coordinate del personaggio: "<< Vsprite.getPosition().x << " , " << Vsprite.getPosition().y << endl;
        }
    }
    if(dir=="down") {

        if(Vsprite.getPosition().y<(TileMap::getMapHeight()-3)*32) {
            Vsprite.move(0, Speed);
            //Vview.move(0, Speed);

            if (Vsprite.getPosition().y <= viewDownLimit && Vsprite.getPosition().y >= viewUpperLimit) {

                if (Vsprite.getPosition().x <= viewRightLimit && Vsprite.getPosition().x >= viewLeftLimit)
                    Vview.setCenter(Vsprite.getPosition().x, Vsprite.getPosition().y);
                if (Vsprite.getPosition().x > viewRightLimit)
                    Vview.setCenter(viewRightLimit, Vsprite.getPosition().y);
                if (Vsprite.getPosition().x < viewLeftLimit)
                    Vview.setCenter(viewLeftLimit, Vsprite.getPosition().y);

            }

            cout <<"centro di view: "<< Vview.getCenter().x << " , " << Vview.getCenter().y << endl;
            cout <<"coordinate del personaggio: "<< Vsprite.getPosition().x << " , " << Vsprite.getPosition().y << endl;
        }
    }
}


