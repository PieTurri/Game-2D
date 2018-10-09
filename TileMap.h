//
// Created by piero on 10/6/18.
//

#ifndef PROJECT_TILEMAP_H
#define PROJECT_TILEMAP_H

#include <iostream>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics.hpp>



class TileMap : public sf::Drawable, public sf::Transformable{

public:

 //   TileMap();

    ~TileMap();

    bool load(const std::string& tileset, sf::Vector2u tileSize,const int *tiles, unsigned int width, unsigned int height);
    const int level[144] =

            {

                    0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,

                    0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 120, 0, 0, 0, 0,

                    1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,

                    0, 1, 0, 0, 120, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,

                    0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 120, 0, 0,

                    0, 0, 1, 0, 3, 0, 120, 120, 0, 0, 1, 1, 1, 1, 120, 0,

                    120, 0, 1, 0, 3, 0, 120, 120, 120, 0, 1, 1, 1, 1, 1, 1,

                    0, 0, 1, 0, 3, 120, 120, 120, 0, 0, 0, 0, 1, 1, 1, 1,

                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

            };


    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;



private:

    sf::VertexArray m_vertices;

    sf::Texture m_tileset;

};



#endif //PROJECT_TILEMAP_H
