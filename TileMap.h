//
// Created by piero on 10/6/18.
//

#ifndef PROJECT_TILEMAP_H
#define PROJECT_TILEMAP_H

#include <iostream>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

class TileMap : public sf::Drawable, public sf::Transformable{

public:

    TileMap();

    //TileMap(unsigned int h, unsigned int w);

    static unsigned int getMapHeight();

    static unsigned int getMapWidth();

    ~TileMap();

    bool load(const std::string& tileset, sf::Vector2u tileSize, int *tiles);


    void SetTileMap(int *lv,unsigned int heigth, unsigned int width);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;



private:

    sf::VertexArray m_vertices;

    sf::Texture m_tileset;

    static unsigned int height;
    static unsigned int width;

};



#endif //PROJECT_TILEMAP_H
