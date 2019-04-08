//
// Created by piero on 10/3/18.
//

#ifndef PROJECT_CHOOSCHARACTER_H
#define PROJECT_CHOOSCHARACTER_H

#include <SFML/Graphics.hpp>
#include "GraphicState.h"

using namespace sf;

class ChooseCharacter:public GraphicState {
public:
    ChooseCharacter(RenderWindow &window);

    ChooseCharacter(float w, float h, RenderWindow &window);
    ~ChooseCharacter();

    void draw(RenderWindow &window);

    void MoveLeft(sf::Sprite *spriteC);
    void MoveRight(sf::Sprite *spriteC);

    void setScreen();
    //bool isLocked(int setindex);

    //bool setLocked(int index);
    //bool setFree();

    bool isSelected();

    GraphicState *getNextState(RenderWindow &window);
    
    void getActivities(Event event,RenderWindow &window);

    void setView(RenderWindow &window);

    //const int *getIndex() const;

    void animate(int i);


    int GetPressedItem() { return setindex; }


private:

    const float width;
    const float height;

    int setindex;


    Sprite sprite;
    Sprite spriteC[5];
    Text textC;
    Font font;

    Texture tCharacter[5];
    Text tMessage;
    Texture tBackground;

    bool valkyrieLocked;
    bool knightLocked;
    bool ninjaLocked;
    bool wizardLocked;
    bool planetarLocked;
    bool setanimation[5];

    bool Selected;

};


#endif //PROJECT_CHOOSCHARACTER_H
