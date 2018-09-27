#include <iostream>
#include <SFML/Graphics.hpp>



using namespace std;


int main() {
    sf::RenderWindow window(sf::VideoMode(1400,900), "SFML work!!");


    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Green);
    }

    window.clear();
    window.display();
}
