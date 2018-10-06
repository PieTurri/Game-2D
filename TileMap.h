//
// Created by piero on 10/6/18.
//

#ifndef PROJECT_TILEMAP_H
#define PROJECT_TILEMAP_H

#include <iostream>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics.hpp>



class TileMap : public sf::Drawable, public sf::Transformable

{

public:



    bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);



private:



    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;



    sf::VertexArray m_vertices;

    sf::Texture m_tileset;

};

#endif //PROJECT_TILEMAP_H
