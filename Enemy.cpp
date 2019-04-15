//
// Created by piero on 9/7/18.
//

#include "Enemy.h"
#include "EnemySleeping.h"
#include <cmath>
#include "Kalashnikov.h"

using namespace std;
using namespace sf;

Enemy::Enemy(int Hp, int speed) : GameCharacter(Hp, speed) {

    Es = new EnemySleeping;
    EnemyEngaged= false;
    weapon=new Kalashnikov;
    weapon->setRateOfFire(2);
}

Enemy::Enemy(): Enemy(2,6) {}

void Enemy::changeStrategy(Hero *h, TileMap *map) {

    Vector2f distance=h->getPosition()-getPosition();

    float r=(float)sqrt(pow(distance.x,2)+pow(distance.y,2));

    bool EnemyContol=EnemyEngaged;

    if(r<320)
        EnemyEngaged=true;
    else
        EnemyEngaged=false;

    if(EnemyContol!=EnemyEngaged) {
        EnemyStrategy *Cs = Es->changeStrategy();
        delete Es;
        Es=Cs;
    }

}

void Enemy::moveEnemy(TileMap *map) {

    Es->setDirection(map, sprite);
    weapon->setPosition(sprite.getPosition());
}


void Enemy::aim(Vector2f heroPos) {

    weapon->rotate(heroPos);

}

bool Enemy::hasFiringStrategy() {

    return Es->isFiringStrategy();
}

void Enemy::draw(RenderWindow &window) {

        window.draw(sprite);
        weapon->draw(window);
}


