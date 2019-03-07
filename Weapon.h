//
// Created by piero on 9/5/18.
//

#ifndef PROJECT_WEAPON_H
#define PROJECT_WEAPON_H

#include "Projectile.h"
#include <vector>
#include <ctime>


using namespace std;
using namespace sf;

class Weapon {
public:
    Weapon();

    //explicit Weapon(int d, bool comp=false);

    ~Weapon();

    bool isCompatible() const;

    int getDamage() const;

    void setDamage(int Demage);

    Vector2f getPosition();

    void draw(RenderWindow &window, TileMap &map);

    void rotate(Event event, RenderWindow &window);

    void move(float x,float y);

    void flip(String dir);

    void fire();

    vector<Projectile *> getProjectile();

protected:

    int damage;
    bool compatibility;

    float aimedAngle;
    float angle;

    float rateOfFire;

    Vector2f aimedPoint;

    Sprite sprite;
    Texture texture;

    bool isFlipped;

    vector <Projectile*> projectile;

    Clock clock;
    Time times;
};


#endif //PROJECT_WEAPON_H
