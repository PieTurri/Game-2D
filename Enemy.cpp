//
// Created by piero on 9/7/18.
//

#include "Enemy.h"
#include "EnemySleeping.h"
#include <cmath>

using namespace std;
using namespace sf;

Enemy::Enemy(int Hp, int speed) : GameCharacter(Hp, speed) {}

Enemy::Enemy() {
    texture.loadFromFile("enemy2cropped.png");
    sprite.setTexture(texture);
    Es = new EnemySleeping;
}


void Enemy::changeStrategy(Hero *h, TileMap &map) {

    float tmpx = h->getPosition().x;
    float tmpy = h->getPosition().y;

    tmpx = abs(tmpx-sprite.getPosition().x);
    tmpy = abs(tmpy-sprite.getPosition().y);

    r=sqrt(tmpx*tmpx+tmpy*tmpy);

    if(r<96) {
        EnemyEngaged = true;
        EnemyStrategy *Cs = Es->getState();
        delete Es;
        Es = Cs;
    }

    controlTarget();

    if(EnemyContol){
        EnemyEngaged = false;
        EnemyStrategy *Cs = Es->getState();
        delete Es;
        Es = Cs;
    }
}

void Enemy::moveEnemy(TileMap &map) {
    Es->strategyDirection(map, sprite);
}

void Enemy::setPosition(TileMap &map) {

    Posx=rand()%73;
    Posy=rand()%73;

    Vector2f pos(Posx*32,Posy*32


    );

    if(map.getTileWalkability(pos))
        sprite.setPosition(Posx, Posy);
}

void Enemy::draw(RenderWindow &window, TileMap &map) {
    window.draw(sprite);
}

void Enemy::controlTarget() {

    EnemyContol = EnemyEngaged;
}