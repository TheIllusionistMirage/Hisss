#include <iostream>
#include <exception>
#include "Game.hpp"

int main()
{
    Game m_game;
    while(m_game.isGameRunning())
    {
        m_game.run();
    }
    return EXIT_SUCCESS;
}
