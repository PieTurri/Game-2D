//
// Created by piero on 9/5/18.
//

#ifndef PROJECT_WEAPON_H
#define PROJECT_WEAPON_H


class Weapon {
public:
    Weapon();

    explicit Weapon(int d, bool comp=false);

    virtual ~Weapon();

    bool isCompatible() const;

    int getDemage() const;

    void setDemage(int Demage);

protected:
    int Demage;
    bool Compatibility;
};


#endif //PROJECT_WEAPON_H
