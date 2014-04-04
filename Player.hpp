#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <list>
#include <SFML/Graphics.hpp>
#include "Constants.hpp"

class Player
{
    private:
        // creates a list of size 0 and element type sf::Vector2i.
        std::list<tile> m_player;
        sf::Texture m_playerTexture;
        sf::Sprite m_playerTileSprite;
        int m_lives;
        bool m_alive;
        Direction m_playerDirection;

    public:
        Player();
        Player(sf::Texture &texture, Direction direction = Direction::DOWN);
        // move the front of the list m_player as per as the key pressed
        void move(Direction direction);
        // render element by element on the screen the entire list, ie, get
        //the coordinates from the list and use sf::sprite m_playerTileSprite to render them one by one
        void draw(sf::RenderWindow &window);
        bool isAlive();
        void reduceLife();
        int getLives();
        void addTile();
        void removeTile();
        // return the x coordinate of the front element of m_player
        int getXCoord();
        // return the y coordinate of the front element of m_player
        int getYCoord();
        std::list<tile> getplayerTiles();
        void reset();
        void resetLives();
        ~Player();
};

#endif // PLAYER_HPP
