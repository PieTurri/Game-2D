//
// Created by piero on 10/10/18.
//

#include "Knight.h"
#include <cmath>

Knight::Knight(int Hp, int speed, bool armor) : Hero(Hp, speed, armor) {

    texture.loadFromFile("npc3_fr1.png");
    sprite.setTexture(texture);
    usingWeapon=false;
}

Knight::~Knight() = default;


void Knight::draw(RenderWindow &window, TileMap &map) {

    window.draw(sprite);
    weapon->draw(window,map);
}

void Knight::movement(RenderWindow &window) {

    View Kview=window.getView();

    if(moveL&&!moveR) {

        sprite.move(-speed, 0);
        weapon->move(-speed,0);

        if(abs(sprite.getPosition().x-Kview.getCenter().x)<2*32)
            Kview.move(-speed/2,0);
        else
            Kview.move(-speed,0);

        /*cout<<"distanza tra pos cavaliere e pos visuale in x: "<<abs(sprite.getPosition().x-Kview.getCenter().x)<<endl;

        cout <<"centro visuale:"<< Kview.getCenter().x << " , " << Kview.getCenter().y << endl;
        cout <<"posizione cavaliere: "<< sprite.getPosition().x << " , " << sprite.getPosition().y << endl;*/

    }

    if(moveR&&!moveL) {

        sprite.move(speed, 0);
        weapon->move(speed,0);

        if(abs(sprite.getPosition().x-Kview.getCenter().x)<2*32)
            Kview.move(speed/2,0);
        else
            Kview.move(speed,0);

        /*cout<<"distanza tra pos cavaliere e pos visuale in x: "<<abs(sprite.getPosition().x-Kview.getCenter().x)<<endl;

            cout <<"centro visuale:"<< Kview.getCenter().x << " , " << Kview.getCenter().y << endl;
            cout <<"posizione cavaliere: "<< sprite.getPosition().x << " , " << sprite.getPosition().y << endl;*/

    }

    if(moveU&&!moveD) {

        sprite.move(0, -speed);
        weapon->move(0,-speed);

        if(abs(sprite.getPosition().y-Kview.getCenter().y)<2*32)
            Kview.move(0,-speed/2);
        else
            Kview.move(0,-speed);

        /*cout<<"distanza tra pos cavaliere e pos visuale in y: "<<abs(sprite.getPosition().y-Kview.getCenter().y)<<endl;

            cout <<"centro visuale:"<< Kview.getCenter().x << " , " << Kview.getCenter().y << endl;
            cout <<"posizione cavaliere: "<< sprite.getPosition().x << " , " << sprite.getPosition().y << endl;*/

    }
    if(moveD&!moveU) {

        sprite.move(0, speed);
        weapon->move(0,speed);

        if(abs(sprite.getPosition().y-Kview.getCenter().y)<2*32)
            Kview.move(0,speed/2);
        else
            Kview.move(0,speed);

        /*cout<<"distanza tra pos cavaliere e pos visuale in y: "<<abs(sprite.getPosition().y-Kview.getCenter().y)<<endl;

            cout <<"centro visuale:"<< Kview.getCenter().x << " , " << Kview.getCenter().y << endl;
            cout <<"posizione cavaliere: "<< sprite.getPosition().x << " , " << sprite.getPosition().y << endl;*/

    }

    //cout<<"dim  view: "<<Kview.getSize().x<<" , "<<Kview.getSize().y<<endl;

    window.setView(Kview);

}

void Knight::setDirection() {//void useWeapon(Sprite &spriteFire, Texture &textureFire);

    if (moveD&&!moveL&&!moveR&&!moveU) {

        if (TypeFoot) {
            texture.loadFromFile("npc3_fr1.png");
            TypeFoot = false;
        }
        else{
            texture.loadFromFile("npc3_fr2.png");
            TypeFoot = true;
        }

    }

    if (moveU&&!moveL&&!moveR&&!moveD) {

        if (TypeFoot) {
            texture.loadFromFile("npc3_bk1.png");
            TypeFoot = false;
        }
        else{
            texture.loadFromFile("npc3_bk2.png");
            TypeFoot = true;
        }

    }

    if (moveL&&!moveR) {

        if (TypeFoot) {
            texture.loadFromFile("npc3_lf1.png");
            TypeFoot = false;
        }
        else{
            texture.loadFromFile("npc3_lf2.png");
            TypeFoot = true;
        }

    }

    if (moveR&&!moveL) {

        if (TypeFoot) {
            texture.loadFromFile("npc3_rt1.png");
            TypeFoot = false;
        }
        else{
            texture.loadFromFile("npc3_rt2.png");
            TypeFoot = true;
        }

    }

    sprite.setTexture(texture);
}










