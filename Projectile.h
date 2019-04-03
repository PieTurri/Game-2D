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

    enum type{fire,ice};

    static Projectile *create(Projectile::type t);

    Projectile();

    ~Projectile();

    void setSpeed(float speed);

    float getSpeed();

    int getDamage();

    void setAimedPoint(Vector2f pos);

    void setPosition(Vector2f pos);

    void setOrientation();

    Vector2f getPosition();

    void move(TileMap *map);

    void draw(RenderWindow& window);

    bool isBrokeUp();

    void setDestroyed();

    FloatRect getDimension();

protected:

    float speed;
    int damage;

    bool breakUp;

    Sprite sprite;
    Texture texture;

    Vector2f aimedPoint;

    float orientation;

    //bool direction;


};


#endif //PROJECT_PROJECTILE_H
