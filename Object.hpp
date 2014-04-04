#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "Constants.hpp"

class Object
{
    private:
        tile m_obj;
        sf::Texture m_texture;
        sf::Sprite m_sprite;
        std::string m_objectType;

    public:
        Object();
        Object(sf::Texture texture, std::string type);
        void setType(std::string type);
        std::string getType();
        //void create(sf::Vector2i position);
        void create(sf::RenderWindow &window, sf::Vector2i position);
        void create(sf::RenderWindow &window, sf::Vector2i position, int offsetX, int offsetY);
        //void draw(sf::RenderWindow &window);
        int getXCoord();
        int getYCoord();
        ~Object();
};

#endif // OBJECT_HPP
