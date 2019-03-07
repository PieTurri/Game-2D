//
// Created by piero on 9/7/18.
//

#ifndef PROJECT_COMPANION_H
#define PROJECT_COMPANION_H


#include "GameCharacter.h"

class Companion : public GameCharacter{
public:
    Companion(int Hp, int speed, bool ability);

    virtual ~Companion();

    bool isAbility() const;

    void setAbility(bool ability);

protected:
    bool ability;
};


#endif //PROJECT_COMPANION_H
