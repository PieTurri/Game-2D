//
// Created by piero on 9/7/18.
//

#include "Enemy.h"
#include "EnemySleeping.h"
#include <cmath>

using namespace std;
using namespace sf;

Enemy::Enemy(int Hp, int speed) : GameCharacter(Hp, speed) {
    Es = new EnemySleeping;
    EnemyEngaged= false;
}

Enemy::Enemy(): Enemy(2,6) {}

void Enemy::changeStrategy(Hero *h, TileMap &map) {

    Vector2f distance=h->getPosition()-getPosition();

    float r=(float)sqrt(pow(distance.x,2)+pow(distance.y,2));

    EnemyContol=EnemyEngaged;

    if(r<96)
        EnemyEngaged=true;
    else
        EnemyEngaged=false;

    if(EnemyContol!=EnemyEngaged) {
        EnemyStrategy *Cs = Es->changeStrategy();
        delete Es;
        Es=Cs;
    }

}

void Enemy::moveEnemy(TileMap &map) {
    Es->strategyDirection(map,sprite);
}

void Enemy::setPosition(TileMap &map) {

    Vector2f pos(0, 0);

    while(!map.getTileWalkability(pos)) {

        float Posx = rand() % 73;
        float Posy = rand() % 73;

        pos=Vector2f(Posx*32,Posy*32);

        sprite.setPosition(pos.x+16, pos.y+16);
    }

    cout<<"pos: "<<sprite.getPosition().x<<" , "<<sprite.getPosition().y<<endl;
}

void Enemy::draw(RenderWindow &window, TileMap &map) {

    window.draw(sprite);
}

void Enemy::controlTarget() {

    EnemyContol = EnemyEngaged;
}