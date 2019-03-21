//
// Created by piero on 12/5/18.
//

#ifndef PROJECT_PROJECTILE_H
#define PROJECT_PROJECTILE_H

#include "SFML/Graphics.hpp"
#include "TileMap.h"

using namespace sf;

class Projectile  {
public:

    Projectile();

    Projectile(Vector2f pos, Vector2f aimedPos);

    ~Projectile();

    void setSpeed(float speed);

    float getSpeed();

    int getDamage();

    Vector2f getPosition();

    void move(TileMap &map);

    void draw(RenderWindow& window);

    bool isBrokeUp();

    void setDestroyed();

    FloatRect getDimension();

protected:

    float movementSpeed;
    int damage;

    bool breakUp;

    Sprite sprite;
    Texture texture;

    Vector2f aimedPoint;

    //bool direction;


};


#endif //PROJECT_PROJECTILE_H
