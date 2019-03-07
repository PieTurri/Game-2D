//
// Created by piero on 9/3/18.
//

#ifndef PROJECT_GAMECHARACTER_H
#define PROJECT_GAMECHARACTER_H


#include "Weapon.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class GameCharacter {

public:

    GameCharacter();

    explicit GameCharacter(int Hp, int speed);

    virtual void draw(RenderWindow &window, TileMap &map) =0;

    ~GameCharacter();

    void setSpeed(int s);

    int getSpeed();

    void setHp(int Hp);

    int getHp() const;

    Vector2f getPosition();

    void setWeaponUse(bool statement);

    void useWeapon();

    Weapon* getWeapon();


protected:

    int Hp;

    Texture texture;
    Sprite sprite;

    int speed;

    bool usingWeapon;

    Weapon* weapon;
};


#endif //PROJECT_GAMECHARACTER_H
