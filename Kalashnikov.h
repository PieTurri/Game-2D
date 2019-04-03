//
// Created by leogori on 09/02/19.
//

#ifndef PROJECT_KALASHNIKOV_H
#define PROJECT_KALASHNIKOV_H


#include "Weapon.h"

class Kalashnikov: public Weapon {

public:

    Kalashnikov();

    Projectile::type getProjectile() override;

private:


};


#endif //PROJECT_KALASHNIKOV_H
