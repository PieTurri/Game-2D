//
// Created by piero on 10/10/18.
//

#include "Knight.h"
#include <SFML/Graphics.hpp>

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




    //if(!Ktexture.loadFromFile("/home/leogori/Scaricati/immagini progetto/Risorse/player1/npc3_fr1.gif"))
       // cout << "ERRORE" << endl;



    Ksprite.setTexture(Ktexture);



}

void Knight::movement(Sprite &Ksprite,string dir,View &Kview) {



    float viewLeftLimit=(Kview.getSize().x/2)+32;

    float viewUpperLimit=(Kview.getSize().y/2)+32;

    float viewRightLimit=TileMap::getMapWidth()*32-viewLeftLimit;

    float viewDownLimit=TileMap::getMapHeight()*32-viewUpperLimit;

    cout<<viewLeftLimit<<" , "<<viewUpperLimit<<" , "<<viewRightLimit<<" , "<<viewDownLimit<<endl;




    if(dir=="left") {

        if(Ksprite.getPosition().x>64) {

            Ksprite.move(-Speed, 0);
            //Kview.move(-Speed,0);

            if (Ksprite.getPosition().x >= viewLeftLimit && Ksprite.getPosition().x <=viewRightLimit) {

                if (Ksprite.getPosition().y <= viewDownLimit && Ksprite.getPosition().y >= viewUpperLimit)
                    Kview.setCenter(Ksprite.getPosition().x, Ksprite.getPosition().y);

                if (Ksprite.getPosition().y > viewDownLimit)
                    Kview.setCenter(Ksprite.getPosition().x, viewDownLimit);
                if (Ksprite.getPosition().y < viewUpperLimit)
                    Kview.setCenter(Ksprite.getPosition().x, viewUpperLimit);

            }


            cout << Kview.getCenter().x << " , " << Kview.getCenter().y << endl;
            cout << Ksprite.getPosition().x << " , " << Ksprite.getPosition().y << endl;
        }
    }

    if(dir=="right") {

        if(Ksprite.getPosition().x<(TileMap::getMapWidth()-3)*32) {
            Ksprite.move(Speed, 0);
            //Kview.move(Speed,0);


            if (Ksprite.getPosition().x <= viewRightLimit && Ksprite.getPosition().x >= viewLeftLimit){
                if (Ksprite.getPosition().y <= viewDownLimit && Ksprite.getPosition().y >= viewUpperLimit)
                    Kview.setCenter(Ksprite.getPosition().x, Ksprite.getPosition().y);
                if (Ksprite.getPosition().y > viewDownLimit)
                        Kview.setCenter(Ksprite.getPosition().x, viewDownLimit);
                if (Ksprite.getPosition().y < viewUpperLimit)
                        Kview.setCenter(Ksprite.getPosition().x, viewUpperLimit);
            }

            cout << Kview.getCenter().x << " , " << Kview.getCenter().y << endl;
            cout << Ksprite.getPosition().x << " , " << Ksprite.getPosition().y << endl;
            }
    }

    if(dir=="up") {

        if(Ksprite.getPosition().y>64) {
            Ksprite.move(0, -Speed);
            //Kview.move(0, -Speed);

            if (Ksprite.getPosition().y <= viewDownLimit && Ksprite.getPosition().y >= viewUpperLimit) {
                if (Ksprite.getPosition().x <= viewRightLimit && Ksprite.getPosition().x >= viewLeftLimit)
                    Kview.setCenter(Ksprite.getPosition().x, Ksprite.getPosition().y);
                if (Ksprite.getPosition().x > viewRightLimit)
                    Kview.setCenter(viewRightLimit, Ksprite.getPosition().y);
                if (Ksprite.getPosition().x < viewLeftLimit)
                    Kview.setCenter(viewLeftLimit, Ksprite.getPosition().y);

            }



            cout << Kview.getCenter().x << " , " << Kview.getCenter().y << endl;
            cout << Ksprite.getPosition().x << " , " << Ksprite.getPosition().y << endl;
        }
    }
    if(dir=="down") {

        if(Ksprite.getPosition().y<(TileMap::getMapHeight()-3)*32) {
            Ksprite.move(0, Speed);
            //Kview.move(0, Speed);

            if (Ksprite.getPosition().y <= viewDownLimit && Ksprite.getPosition().y >= viewUpperLimit) {

                if (Ksprite.getPosition().x <= viewRightLimit && Ksprite.getPosition().x >= viewLeftLimit)
                    Kview.setCenter(Ksprite.getPosition().x, Ksprite.getPosition().y);
                if (Ksprite.getPosition().x > viewRightLimit)
                    Kview.setCenter(viewRightLimit, Ksprite.getPosition().y);
                if (Ksprite.getPosition().x < viewLeftLimit)
                    Kview.setCenter(viewLeftLimit, Ksprite.getPosition().y);

            }

            cout << Kview.getCenter().x << " , " << Kview.getCenter().y << endl;
            cout << Ksprite.getPosition().x << " , " << Ksprite.getPosition().y << endl;
        }
    }

}




