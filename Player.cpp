#include "Player.hpp"

Player::Player() : m_lives(3), m_alive(true)
{
    m_player.push_back(tile(WIDTH / 2, HEIGHT / 3));
    m_player.push_back(tile(WIDTH / 2, HEIGHT / 3 - 20));
    m_player.push_back(tile(WIDTH / 2, HEIGHT / 3 - 40));

    m_playerDirection = Direction::DOWN;
}

/*Player::Player(sf::Texture &texture, Direction direction) : m_lives(3), m_alive(true)//, m_playerTexture(nullptr)
{
    //m_playerTexture = &texture;
    //m_playerTileSprite.setTexture(*m_playerTexture);
    m_player.push_back(tile(WIDTH / 2, HEIGHT / 3));
    m_player.push_back(tile(WIDTH / 2, HEIGHT / 3 - 20));
    m_player.push_back(tile(WIDTH / 2, HEIGHT / 3 - 40));

    m_playerDirection = Direction::DOWN;
}*/

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

/*void Player::draw(sf::RenderWindow &window)
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
}*/

/*void Player::update()
{
    int temp = 0;
    for(std::list<tile>::iterator iptr = m_player.begin(); iptr != m_player.end(); iptr++)
    {
        m_playerSprite.setPosition(sf::Vector2f((int)iptr->x, (int)iptr->y));
        if(temp == 0)
        {
            m_playerSprite.setTextureRect(sf::IntRect(0, 0, 20, 20));
            temp++;
        }
        else if(temp == 1)
        {
            m_playerSprite.setTextureRect(sf::IntRect(20, 0, 20, 20));
            temp--;
        }
        if(iptr == m_player.begin())
        {
            if(m_playerDirection == Direction::UP)
                m_playerSprite.setTextureRect(sf::IntRect(80, 0, 20, 20));
            if(m_playerDirection == Direction::RIGHT)
                m_playerSprite.setTextureRect(sf::IntRect(40, 0, 20, 20));
            if(m_playerDirection == Direction::DOWN)
                m_playerSprite.setTextureRect(sf::IntRect(100, 0, 20, 20));
            if(m_playerDirection == Direction::LEFT)
                m_playerSprite.setTextureRect(sf::IntRect(60, 0, 20, 20));
        }
    }
}*/

bool Player::update()
{
    int temp = 0;
    std::list<tile>::iterator iptr = m_player.begin();

    for(std::list<tile>::iterator iptr = m_player.begin(); iptr != m_player.end(); iptr++)
    {
        m_playerSprite.setPosition(sf::Vector2f((int)iptr->x, (int)iptr->y));
        if(temp == 0)
        {
            m_playerSprite.setTextureRect(sf::IntRect(0, 0, 20, 20));
            temp++;
        }
        else if(temp == 1)
        {
            m_playerSprite.setTextureRect(sf::IntRect(20, 0, 20, 20));
            temp--;
        }
        if(iptr == m_player.begin())
        {
            if(m_playerDirection == Direction::UP)
                m_playerSprite.setTextureRect(sf::IntRect(80, 0, 20, 20));
            if(m_playerDirection == Direction::RIGHT)
                m_playerSprite.setTextureRect(sf::IntRect(40, 0, 20, 20));
            if(m_playerDirection == Direction::DOWN)
                m_playerSprite.setTextureRect(sf::IntRect(100, 0, 20, 20));
            if(m_playerDirection == Direction::LEFT)
                m_playerSprite.setTextureRect(sf::IntRect(60, 0, 20, 20));
        }
        return true;
    }
    return false;
}

void Player::draw(sf::RenderWindow &window)
{
    int temp = 0;
    for(std::list<tile>::iterator iptr = m_player.begin(); iptr != m_player.end(); iptr++)
    {
        m_playerSprite.setPosition(sf::Vector2f((int)iptr->x, (int)iptr->y));
        if(temp == 0)
        {
            m_playerSprite.setTextureRect(sf::IntRect(0, 0, 20, 20));
            temp++;
        }
        else if(temp == 1)
        {
            m_playerSprite.setTextureRect(sf::IntRect(20, 0, 20, 20));
            temp--;
        }
        if(iptr == m_player.begin())
        {
            if(m_playerDirection == Direction::UP)
                m_playerSprite.setTextureRect(sf::IntRect(80, 0, 20, 20));
            if(m_playerDirection == Direction::RIGHT)
                m_playerSprite.setTextureRect(sf::IntRect(40, 0, 20, 20));
            if(m_playerDirection == Direction::DOWN)
                m_playerSprite.setTextureRect(sf::IntRect(100, 0, 20, 20));
            if(m_playerDirection == Direction::LEFT)
                m_playerSprite.setTextureRect(sf::IntRect(60, 0, 20, 20));
        }
        window.draw(m_playerSprite);
    }
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_playerSprite, states);
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

void Player::setTexture(const sf::Texture &texture)
{
    m_playerSprite.setTexture(texture);
}

Player::~Player()
{
}
