//
// Created by piero on 9/28/18.
//

//#include <SFML/Audio.hpp>
#include <iostream>
#include "MenuLoop.h"

//#include "Hero.h"
//#include "Abstract_Factory.h"

//#include <SFML/Graphics.hpp>
//#include "Knight.h"

using namespace std;
using namespace sf;

 MenuLoop::MenuLoop() {


}

int MenuLoop::getIndex() {
    return index;
}

void MenuLoop::generateScreen(RenderWindow &window) {

    unsigned int h=map.getMapHeight();
    unsigned int w=map.getMapWidth();

    cout<<map.getMapWidth()<<" , "<<map.getMapHeight()<<endl;

    music.openFromFile("/home/leogori/Scaricati/immagini progetto/Risorse/Excalibur.ogg");
    music.play();

    while (window.isOpen()) {


        while (window.pollEvent(event)) {

            if (getIndex() == 0) {

                menu.setMenuScreen(texture, sprite, font, text);

                switch (event.type) {

                    case sf::Event::KeyReleased:

                        switch (event.key.code) {

                            case sf::Keyboard::Up:
                                menu.MoveUp(text);
                                break;

                            case sf::Keyboard::Down:
                                menu.MoveDown(text);
                                break;

                            case sf::Keyboard::Escape:
                                window.close();
                                break;


                            case sf::Keyboard::Return:

                                switch (menu.GetPressedItem()) {

                                    case 0:
                                        index = 1;
                                        choose.setChooseCharacterScreen(texture, sprite, font,texture1,spriteC,textC);
                                        break;

                                    case 1:
                                        index = 2;
                                        rules.setRulesScreen(texture, sprite, textRules, font);
                                        break;

                                    case 2:
                                        window.close();
                                        break;
                                }
                                break;
                        }
                        break;

                    case sf::Event::Closed:
                        window.close();
                        break;
                }

            } else if (getIndex() == 1) {

                switch (event.type) {

                    case sf::Event::KeyReleased:

                        switch (event.key.code) {

                            case sf::Keyboard::Escape:
                                index = 0;
                                menu.selectedMenuIndex = 0;
                                menu.a = true;
                                menu.setMenuScreen(texture, sprite, font, text);
                                break;

                            case sf::Keyboard::Left:
                                choose.MoveLeft(texture1,spriteC);
                                break;

                            case sf::Keyboard::Right:
                                choose.MoveRight(texture1,spriteC);
                                break;

                            case sf::Keyboard::Return:

                                tilepos=new int[h*w];

                                map.SetTileMap(tilepos,h,w);


                                map.load("/home/leogori/Scaricati/immagini progetto/Risorse/Tileset1.png", sf::Vector2u(32, 32), tilepos);
                                index=3;

                                view.setCenter(sf::Vector2f(spritex+16, spritey+16));

                                view.setSize(sf::Vector2f(640 , 480));

                                view.setViewport(FloatRect(0, 0, 1, 1));

                                miniview.setCenter(Vector2f(w*16,h*16));

                                miniview.setSize(sf::Vector2f((w-2)*32, (h-2)*32));

                                miniview.setViewport(sf::FloatRect(0.75f, 0, 0.25f, 0.25f));

                                switch (choose.GetPressedItem()) {

                                    case 0 :

                                        factory= new KnightFactory;

                                        hero=factory->createHero();

                                        spritePlayer.setPosition(spritex,spritey);

                                        hero->draw(spritePlayer,texturePlayer,typeMove);

                                        break;
                                    case 1:

                                        factory= new ValkyrieFactory;

                                        hero=factory->createHero();

                                        spritePlayer.setPosition(spritex,spritey);

                                        hero->draw(spritePlayer,texturePlayer,typeMove);

                                        break;


                                }
                                break;
                        }
                        break;

                    case sf::Event::Closed:
                        window.close();
                        break;
                }

            } else if (getIndex() == 2) {
                switch (event.type) {

                    case sf::Event::KeyReleased:

                        switch (event.key.code) {

                            case sf::Keyboard::Escape:
                                index = 0;
                                menu.selectedMenuIndex = 0;
                                menu.a = true;
                                menu.setMenuScreen(texture, sprite, font, text);
                                break;
                        }
                        break;
                    case sf::Event::Closed:
                        window.close();
                        break;
                }
            }else if(getIndex()==3){



                switch (event.type) {

                    case sf::Event::KeyPressed:

                        switch (event.key.code) {

                            case Keyboard::Left:
                                hero->movement(spritePlayer, "left", view);
                                hero->draw(spritePlayer, texturePlayer, 2);

                                break;

                            case Keyboard::Right:
                                hero->movement(spritePlayer, "right",view);
                                hero->draw(spritePlayer,texturePlayer,3);
                                break;

                            case Keyboard::Up:
                                hero->movement(spritePlayer, "up",view);
                                hero->draw(spritePlayer,texturePlayer,1);
                                break;

                            case Keyboard::Down:
                                hero->movement(spritePlayer, "down",view);
                                hero->draw(spritePlayer,texturePlayer,0);
                                break;

                            case Keyboard::Escape:

                                window.close();
                                break;
                        }
                        break;

                    case sf::Event::Closed:
                        window.close();
                        break;
                }

            }
        }

        //window.clear();

        window.draw(sprite);

        if (index == 0) {

            menu.draw(window, text);

        }

        if (index == 1){
            choose.draw(spriteC, texture1);
            for(int i=0; i < 5 ; i++)
                window.draw(spriteC[i]);
            choose.drawC(window,textC);
        }

        if (index == 2)
            rules.draw(window, textRules);

        if (index == 3) {


            window.setView(view);
            window.draw(map);
            window.draw(spritePlayer);


            //spritePlayer.setScale(5,5);
            if (spritePlayer.getPosition().x <= 1056 || spritePlayer.getPosition().y >= 153) {

                //spritePlayer.getPosition().x <=((w-2)*32-miniview.getSize().x) || spritePlayer.getPosition().y >= miniview.getSize().y+64

                //cout<<miniview.getSize().x<<" , "<<miniview.getSize().y<<endl;

                window.setView(miniview);
                window.draw(map);
                window.draw(spritePlayer);
            }
            //spritePlayer.setScale(1,1);
        }

        window.display();
    }


}

MenuLoop::~MenuLoop() {

}
