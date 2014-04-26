#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include "Constants.hpp"

class Object //: public sf::Drawable
{
    private:
        tile m_obj;
        sf::Sprite m_objectSprite;
        int m_objectType;

    public:
        void setType(int type);
        int getType();
        void create(sf::Vector2i position);
        void create(sf::Vector2i position, int offsetX, int offsetY);
        void draw(sf::RenderWindow &window);
        //void draw(sf::RenderTarget &target, sf::RenderStates states =  sf::RenderStates::Default) const;
        int getXCoord();
        int getYCoord();
        void setTexture(const sf::Texture &texture);
};

#endif // OBJECT_HPP
