#include "Object.hpp"

Object::Object()
{
    //ctor
}

Object::Object(sf::Texture texture, std::string type)
{
    m_texture = texture;
    m_sprite.setTexture(m_texture);
    m_sprite.setTextureRect(sf::IntRect(0, 0, 20, 20));
    m_objectType = type;
}

void Object::setType(std::string type)
{
    m_objectType = type;
}

std::string Object::getType()
{
    return m_objectType;
}

/*void Object::create(sf::Vector2i position)
{
    m_obj.x = position.x;
    m_obj.y = position.y;
    m_sprite.setPosition(sf::Vector2f(position.x, position.y));
}*/

/*void Object::draw(sf::RenderWindow &window)
{
    window.draw(m_sprite);
}*/

void Object::create(sf::RenderWindow &window, sf::Vector2i position)
{
    /*sf::Texture tempTexture;
    tempTexture.loadFromFile(FOOD_TILE_IMAGE);
    sf::Sprite tempSprite;
    tempSprite.setTexture(tempTexture);
    tempSprite.setTextureRect(sf::IntRect(200, 100, 50, 50));
    tempSprite.setPosition(sf::Vector2f(position.x - 15, position.y - 15));*/

    m_obj.x = position.x;
    m_obj.y = position.y;
    m_sprite.setPosition(sf::Vector2f(position.x, position.y));
    /*window.draw(tempSprite);*/
    window.draw(m_sprite);
}

void Object::create(sf::RenderWindow &window, sf::Vector2i position, int offsetX, int offsetY)
{
    /*sf::Texture tempTexture;
    tempTexture.loadFromFile(FOOD_TILE_IMAGE);
    sf::Sprite tempSprite;
    tempSprite.setTexture(tempTexture);
    tempSprite.setTextureRect(sf::IntRect(200, 100, 50, 50));
    tempSprite.setPosition(sf::Vector2f(position.x - 15, position.y - 15));*/

    m_obj.x = position.x;
    m_obj.y = position.y;
    m_sprite.setPosition(sf::Vector2f(position.x + offsetX, position.y + offsetY));
    /*window.draw(tempSprite);*/
    window.draw(m_sprite);
}

int Object::getXCoord()
{
    return m_obj.x;
}

int Object::getYCoord()
{
    return m_obj.y;
}

Object::~Object()
{
    //dtor
}
