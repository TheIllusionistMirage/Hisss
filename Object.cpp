#include "Object.hpp"

Object::Object() //: m_texture(nullptr)
{
}

void Object::setType(int type)
{
    m_objectType = type;
}

int Object::getType()
{
    return m_objectType;
}

//void Object::create(sf::RenderWindow &window, sf::Vector2i position)
void Object::create(sf::Vector2i position)
{
    m_obj.x = position.x;
    m_obj.y = position.y;
    m_objectSprite.setPosition(sf::Vector2f(position.x, position.y));
}

//void Object::create(sf::RenderWindow &window, sf::Vector2i position, int offsetX, int offsetY)
void Object::create(sf::Vector2i position, int offsetX, int offsetY)
{
    m_obj.x = position.x;
    m_obj.y = position.y;
    m_objectSprite.setPosition(sf::Vector2f(position.x + offsetX, position.y + offsetY));
}

void Object::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_objectSprite, states);
}

int Object::getXCoord()
{
    return m_obj.x;
}

int Object::getYCoord()
{
    return m_obj.y;
}

void Object::setTexture(const sf::Texture &texture)
{
    m_objectSprite.setTexture(texture);
}

Object::~Object()
{
    //dtor
}
