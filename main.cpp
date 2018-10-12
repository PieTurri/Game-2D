
#include "MenuLoop.h"
#include "Hero.h"
#include "Abstract_Factory.h"




using namespace std;
using namespace sf;

int main() {

    float playerMovmentSpeed=0.1;
    int passoUp=0;

    //creo la finestra...

    RenderWindow window;
    window.create(sf::VideoMode(1400, 896), "Leo&Pie Game");

    MenuLoop ml(window);
    //carico la texture...

    Texture texturePlayer;
    if(!texturePlayer.loadFromFile("/home/piero/Documents/Programmazione/Project2/Project/Risorse/SoldierWalk.png"))
        cout << "ERRORE" << endl;

    //inserisco la texure in una sprite...

    Sprite spritePlayer(texturePlayer);
    spritePlayer.setPosition(window.getSize().x/2,window.getSize().y/2);
    spritePlayer.setTextureRect(IntRect(0,64*2,64,64));



    switch (ml.k) {  //a seconda di cosa ritorna menuloop:...

        case 0:{

            Abstract_Factory*  factory = new KnightFactory;

            Hero* hero;

            hero = factory -> createHero();

            hero -> draw();

            break;
        }
        default:
            break;
    }


    while(window.isOpen()) {

        Event event;

        while(window.pollEvent(event)){

            switch (event.type){

                case Event::Closed :
                    window.close();
                    break;
                case Event::KeyPressed:
                    switch (event.key.code){
                        case Keyboard::Escape :
                            window.close();
                            break;
                        }
                    break;
            }
        }
        window.clear();



        if(Keyboard::isKeyPressed(Keyboard::Right)){

            spritePlayer.move(playerMovmentSpeed,0);
            spritePlayer.setTextureRect(IntRect(64*passoUp,64*3,64,64));


        }
        if(Keyboard::isKeyPressed(Keyboard::Left)){

            spritePlayer.move(-playerMovmentSpeed,0);
            spritePlayer.setTextureRect(IntRect(64*passoUp,64,64,64));


        }
        if(Keyboard::isKeyPressed(Keyboard::Up)){

            spritePlayer.move(0,-playerMovmentSpeed);
            spritePlayer.setTextureRect(IntRect(64*passoUp,0,64,64));


        }
        if(Keyboard::isKeyPressed(Keyboard::Down)){

            spritePlayer.move(0,playerMovmentSpeed);
            spritePlayer.setTextureRect(IntRect(64*passoUp,64*2,64,64));

        }

        passoUp++;
        if(passoUp == 9)
            passoUp = 0;

        window.draw(spritePlayer);

        window.display();
    }

    ml.~MenuLoop();

    return 0;
}



