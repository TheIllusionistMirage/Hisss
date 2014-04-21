#include <iostream>
#include <exception>
#include "Game.hpp"

using namespace std;

int main()
{
    try
    {
        Game m_game;
        while(m_game.isGameRunning())
        {
            m_game.run();
        }
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return EXIT_SUCCESS;
}
