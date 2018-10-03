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
    void MoveLeft(sf::Text *text);
    void MoveRight(sf::Text *text);

    void setChooseCharacterScreen(sf::Texture &texture,sf::Sprite &sprite,sf::Font &font,sf::Texture *texture1,sf::Sprite *spriteC);


private:
    const float width=700;
    const float height=450;
};


#endif //PROJECT_CHOOSCHARACTER_H
