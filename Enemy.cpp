//
// Created by piero on 9/7/18.
//

#include "Enemy.h"
#include <iostream>
using namespace std;

Enemy::Enemy(int Hp, int speed) : GameCharacter(Hp, speed) {
}

Enemy::Enemy() {}

Enemy::~Enemy() {}

void Enemy::randomDirection(Sprite &Esprite, TileMap &map) { //tirare fuori dal ctime

    srand(unsigned(time(NULL)));
    direction = rand() % 4;

    didEnemyMove=true;

    //inserito metodo piero

    timeEnemy = clockEnemy.getElapsedTime();

    if (timeEnemy.asMilliseconds() > 500) {
        float x_load=Esprite.getPosition().x;
        float y_load=Esprite.getPosition().y;

        cout<<"XLOAD E YLOAD: "<<x_load<<" , "<<y_load<<endl;

        switch(direction){
            case 0:
                if (map.getTileWalkability(Esprite.getPosition()+Vector2f(32,0))) {

                    map.setTileWalkability(sf::Vector2f(), true);
                    Esprite.move(32, 0);
                    map.setTileWalkability(sf::Vector2f(), false);

                } else
                    didEnemyMove=false;
                break;

            case 1:
                if (map.getTileWalkability(Esprite.getPosition()-Vector2f(32,0))) {

                    map.setTileWalkability(sf::Vector2f(), true);
                    Esprite.move(-32, 0);
                    map.setTileWalkability(sf::Vector2f(), false);
                } else
                    didEnemyMove=false;
                break;

            case 2:
                if (map.getTileWalkability(Esprite.getPosition()-Vector2f(0,32))) {

                    map.setTileWalkability(sf::Vector2f(), true);
                    Esprite.move(0, -32);
                    map.setTileWalkability(sf::Vector2f(), false);
                } else
                    didEnemyMove=false;
                break;

            case 3:
                if (map.getTileWalkability(Esprite.getPosition() + Vector2f(0,32))) {

                    map.setTileWalkability(sf::Vector2f(), true);
                    Esprite.move(0, 32);
                    map.setTileWalkability(sf::Vector2f(), false);
                } else
                    didEnemyMove=false;
                break;
            default:
                break;
        }

        if(didEnemyMove)
            clockEnemy.restart();
    }

}


void Enemy::setPosition(TileMap &map) {

    /*srand(unsigned(time(NULL)));
    int casualPos = rand() % 5329;
    int pos;
    int Posx = casualPos % 15;
    int Posy = (casualPos - Posx)/15;


    for(int i = 0; i < 9;i ++){

        if(map1.getFightRoomAccessibility(i)){

            pos = 2;
            Posx = pos % map1.getMapWidth()*32;
            Posy = ((pos - Posx/32)/map1.getMapWidth())*32;

            Esprite.setPosition(Posx,Posy);
            cout<<"VAFFANCUUUUUUUUUUUUUU"<<Esprite.getPosition().x<<" , "<<Esprite.getPosition().y<<endl;

            break;

        }
    }*/

    sprite.setPosition(480+16,480+16);
    map.setTileWalkability(sprite.getPosition(),false);



}



