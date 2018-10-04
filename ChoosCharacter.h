//
// Created by piero on 10/3/18.
//

#ifndef PROJECT_CHOOSCHARACTER_H
#define PROJECT_CHOOSCHARACTER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class ChoosCharacter {
public:
    ChoosCharacter();
    ~ChoosCharacter();

    void draw(sf::Sprite *spriteC, sf::Texture *texture1);
    void drawC(sf::RenderWindow &window,sf::Text &textC);
    void MoveLeft(sf::Texture *texture1,sf::Sprite *spriteC);
    void MoveRight(sf::Texture *texture1,sf::Sprite *spriteC);
    void setChooseCharacterScreen(sf::Texture &texture,sf::Sprite &sprite,sf::Font &font,sf::Texture *texture1,sf::Sprite *spriteC,sf::Text &textC);
    bool isLocked(int setindex);
    bool setLocked(int index);
    bool setFree();
    bool isSelected();

    const int *getIndex() const;
    bool first;


private:

    const float width=700;
    const float height=450;

    bool valkyrieLocked = false;
    bool knightLocked = false;
    bool ninjaLocked = true;
    bool wizardLocked = true;
    bool planetarLocked = true;

    int index[5];
    int setindex = 0;
    bool iselected = false;
};


#endif //PROJECT_CHOOSCHARACTER_H
