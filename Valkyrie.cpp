//
// Created by piero on 10/10/18.
//

#include "Valkyrie.h"

Valkyrie::Valkyrie(int Hp, int speed, bool armor) : Hero(Hp, speed, armor) {

    texture.loadFromFile("npc4_fr1.gif");
    sprite.setTexture(texture);

}

Valkyrie::~Valkyrie() {}

void Valkyrie::draw(RenderWindow &window, TileMap &map) {

    window.draw(sprite);
    weapon->draw(window, map);
}

void Valkyrie::movement(RenderWindow &window) {

    setDirection();

    View view=window.getView();

    if(moveL) {

        sprite.move(-speed, 0);
        weapon->move(-speed,0);

        if(abs(sprite.getPosition().x-view.getCenter().x)<2*32)
            view.move(-speed/2,0);
        else
            view.move(-speed,0);

        cout<<"distanza tra pos cavaliere e pos visuale in x: "<<abs(sprite.getPosition().x-view.getCenter().x)<<endl;

        cout <<"centro visuale:"<< view.getCenter().x << " , " << view.getCenter().y << endl;
        cout <<"posizione cavaliere: "<< sprite.getPosition().x << " , " << sprite.getPosition().y << endl;


    }

    if(moveR) {


        sprite.move(speed, 0);
        weapon->move(speed,0);

        if(abs(sprite.getPosition().x-view.getCenter().x)<2*32)
            view.move(speed/2,0);
        else
            view.move(speed,0);

        cout<<"distanza tra pos cavaliere e pos visuale in x: "<<abs(sprite.getPosition().x-view.getCenter().x)<<endl;

        cout <<"centro visuale:"<< view.getCenter().x << " , " << view.getCenter().y << endl;
        cout <<"posizione cavaliere: "<< sprite.getPosition().x << " , " << sprite.getPosition().y << endl;

    }

    if(moveU) {

        sprite.move(0, -speed);
        weapon->move(0,-speed);

        if(abs(sprite.getPosition().y-view.getCenter().y)<2*32)
            view.move(0,-speed/2);
        else
            view.move(0,-speed);

        cout<<"distanza tra pos cavaliere e pos visuale in y: "<<abs(sprite.getPosition().y-view.getCenter().y)<<endl;

        cout <<"centro visuale:"<< view.getCenter().x << " , " << view.getCenter().y << endl;
        cout <<"posizione cavaliere: "<< sprite.getPosition().x << " , " << sprite.getPosition().y << endl;

    }
    if(moveD) {

        sprite.move(0, speed);
        weapon->move(0,speed);

        if(abs(sprite.getPosition().y-view.getCenter().y)<2*32)
            view.move(0,speed/2);
        else
            view.move(0,speed);

        cout<<"distanza tra pos cavaliere e pos visuale in y: "<<abs(sprite.getPosition().y-view.getCenter().y)<<endl;

        cout <<"centro visuale:"<< view.getCenter().x << " , " << view.getCenter().y << endl;
        cout <<"posizione cavaliere: "<< sprite.getPosition().x << " , " << sprite.getPosition().y << endl;

    }

    window.setView(view);
}

void Valkyrie::setDirection() {

    if (moveD&&!moveL&&!moveR&&!moveU) {

        if (TypeFoot) {
            texture.loadFromFile("npc4_fr1.gif");
            TypeFoot = false;
        }
        else{
            texture.loadFromFile("npc4_fr2.gif");
            TypeFoot = true;
        }

    }

    if (moveU&&!moveL&&!moveR&&!moveD) {

        if (TypeFoot) {
            texture.loadFromFile("npc4_bk1.gif");
            TypeFoot = false;
        }
        else{
            texture.loadFromFile("npc4_bk2.gif");
            TypeFoot = true;
        }

    }

    if (moveL&&!moveR) {

        if (TypeFoot) {
            texture.loadFromFile("npc4_lf1.gif");
            TypeFoot = false;
        }
        else{
            texture.loadFromFile("npc4_lf2.gif");
            TypeFoot = true;
        }

    }

    if (moveR&&!moveL) {

        if (TypeFoot) {
            texture.loadFromFile("npc4_rt1.gif");
            TypeFoot = false;
        }
        else{
            texture.loadFromFile("npc4_rt2.gif");
            TypeFoot = true;
        }

    }

    sprite.setTexture(texture);

}


