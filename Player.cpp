#include "Player.hpp"

Player::Player() : m_lives(3), m_alive(true)
//Player::Player() : m_lives(3), m_alive(false)
{

}

Player::Player(sf::Texture &texture, Direction direction) : m_lives(3), m_alive(true)
//Player::Player(sf::Texture &texture, Direction direction) : m_lives(3), m_alive(false)
{
    m_playerTexture = sf::Texture(texture);
    m_playerTileSprite.setTexture(m_playerTexture);
    m_player.push_back(tile(WIDTH / 2, HEIGHT / 3));
    m_player.push_back(tile(WIDTH / 2, HEIGHT / 3 - 20));
    m_player.push_back(tile(WIDTH / 2, HEIGHT / 3 - 40));

    //m_playerTileSprite.setPosition(sf::Vector2f(WIDTH / 2, HEIGHT / 2));

    m_playerDirection = Direction::DOWN;
}

void Player::move(Direction direction)
{
    removeTile();

    if(direction == Direction::UP)
    {
        if(m_playerDirection == Direction::DOWN)
            m_player.push_front(tile(m_player.front().x, m_player.front().y + DEFAULT_TILE_DIMENSIONS.y));
        else
        {
            m_player.push_front(tile(m_player.front().x, m_player.front().y - DEFAULT_TILE_DIMENSIONS.y));
            m_playerDirection = direction;
        }
    }
    else if(direction == Direction::RIGHT)
    {
        if(m_playerDirection == Direction::LEFT)
            m_player.push_front(tile(m_player.front().x - DEFAULT_TILE_DIMENSIONS.x, m_player.front().y));
        else
        {
            m_player.push_front(tile(m_player.front().x + DEFAULT_TILE_DIMENSIONS.x, m_player.front().y));
            m_playerDirection = direction;
        }
    }
    else if(direction == Direction::DOWN)
    {
        if(m_playerDirection == Direction::UP)
            m_player.push_front(tile(m_player.front().x, m_player.front().y - DEFAULT_TILE_DIMENSIONS.y));
        else
        {
            m_player.push_front(tile(m_player.front().x, m_player.front().y + DEFAULT_TILE_DIMENSIONS.y));
            m_playerDirection = direction;
        }
    }
    else if(direction == Direction::LEFT)
    {
        if(m_playerDirection == Direction::RIGHT)
            m_player.push_front(tile(m_player.front().x + DEFAULT_TILE_DIMENSIONS.x, m_player.front().y));
        else
        {
            m_player.push_front(tile(m_player.front().x - DEFAULT_TILE_DIMENSIONS.x, m_player.front().y));
            m_playerDirection = direction;
        }
    }
}

void Player::draw(sf::RenderWindow &window)
{
    int temp = 0;
    for(std::list<tile>::iterator iptr = m_player.begin(); iptr != m_player.end(); iptr++)
    {
        m_playerTileSprite.setPosition(sf::Vector2f((int)iptr->x, (int)iptr->y));
        if(temp == 0)
        {
            m_playerTileSprite.setTextureRect(sf::IntRect(0, 0, 20, 20));
            temp++;
        }
        else if(temp == 1)
        {
            m_playerTileSprite.setTextureRect(sf::IntRect(20, 0, 20, 20));
            temp--;
        }
        if(iptr == m_player.begin())
        {
            if(m_playerDirection == Direction::UP)
                m_playerTileSprite.setTextureRect(sf::IntRect(80, 0, 20, 20));
            if(m_playerDirection == Direction::RIGHT)
                m_playerTileSprite.setTextureRect(sf::IntRect(40, 0, 20, 20));
            if(m_playerDirection == Direction::DOWN)
                m_playerTileSprite.setTextureRect(sf::IntRect(100, 0, 20, 20));
            if(m_playerDirection == Direction::LEFT)
                m_playerTileSprite.setTextureRect(sf::IntRect(60, 0, 20, 20));
            window.draw(m_playerTileSprite);
        }
        else
            window.draw(m_playerTileSprite);
    }
}

bool Player::isAlive()
{
    if(m_lives == 0)
        return false;
    return m_alive;
}

void Player::reduceLife()
{
    m_lives--;
}

int Player::getLives()
{
    return m_lives;
}

void Player::addTile()
{
    m_player.push_back(tile(m_player.back().x, m_player.back().y));
}

void Player::removeTile()
{
    m_player.pop_back();
}

int Player::getXCoord()
{
    return m_player.front().x;
}

int Player::getYCoord()
{
    return m_player.front().y;
}

std::list<tile> Player::getplayerTiles()
{
    return m_player;
}

void Player::reset()
{
    m_player.clear();
    m_player.push_back(tile(WIDTH / 2, HEIGHT / 3));
    m_player.push_back(tile(WIDTH / 2, HEIGHT / 3 - 20));
    m_player.push_back(tile(WIDTH / 2, HEIGHT / 3 - 40));
    m_playerDirection = Direction::DOWN;
}

void Player::resetLives()
{
    m_lives = 3;
    m_alive = true;
}

Player::~Player()
{
    //dtor
}
