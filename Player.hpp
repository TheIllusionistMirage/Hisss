#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include "Constants.hpp"

class Player : public sf::Drawable
{
    private:
        std::list<tile> m_player;
        sf::Sprite m_playerSprite;
        int m_lives;
        bool m_alive;
        Direction m_playerDirection;

    public:
        Player();
        void move(Direction direction);
        //void update(sf::RenderWindow &window);
        bool update();
        /* I had to use both update and draw in a single function as I couldn't figure
           out a way to render the snake tile by tile using separate update() and draw() functions. */
        void draw(sf::RenderWindow &window);
        void draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const;
        bool isAlive();
        void reduceLife();
        int getLives();
        void addTile();
        void removeTile();
        int getXCoord();
        int getYCoord();
        std::list<tile> getplayerTiles();
        void reset();
        void resetLives();
        void setTexture(const sf::Texture &texture);
        ~Player();
};

#endif // PLAYER_HPP
