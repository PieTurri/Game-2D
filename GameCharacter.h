//
// Created by piero on 9/3/18.
//

#ifndef PROJECT_GAMECHARACTER_H
#define PROJECT_GAMECHARACTER_H


class GameCharacter {

public:

    GameCharacter();

    explicit GameCharacter(int Hp, int speed);

    virtual ~GameCharacter();

    void setHp(int Hp);

    void setPosX(int PosX);

    void setPosY(int PosY);

    int getHp() const;

    int getPosX() const;

    int getPosY() const;

    int speedCharacter();


private:
    int Hp;
    int PosX;
    int PosY;
    int Speed;
};


#endif //PROJECT_GAMECHARACTER_H
