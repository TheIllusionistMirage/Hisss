#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <exception>
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include "Constants.hpp"
#include "Player.hpp"
#include "Object.hpp"

class Game
{
    private:
        sf::RenderWindow m_window;
        sf::Image m_gameIcon;
        sf::Texture m_groundTexture;
        sf::RectangleShape m_ground;

        sf::Texture m_playerTexture;
        sf::Texture m_foodTexture;
        sf::Texture m_rockTexture;
        sf::Texture m_wallTexture;

        std::vector <Object> m_objects;
        Player m_snake;

        Direction m_direction;
        std::list<tile> m_snakeTiles;
        std::list<tile>::iterator itr;

        bool foodEaten;
        bool foodRequired;
        bool putFood;

        int foodSpawnedX;
        int foodSpawnedY;

        sf::Font globalFont;

        tgui::Gui m_gameGUI;
        tgui::Label::Ptr scoreInfo;

        int cScore;
        std::string currentScore;
        tgui::Label::Ptr currentScoreLabel;

        tgui::Label::Ptr livesInfo;
        int cLives;
        std::string currentLives;
        tgui::Label::Ptr currentLivesLabel;

        tgui::Picture::Ptr foodIcon;
        tgui::Label::Ptr foodValue;
        tgui::Label::Ptr quitMsg;
        tgui::Button::Ptr playAgainButton;
        tgui::Button::Ptr quitButton;
        tgui::Label::Ptr totalScoreLabel;

        sf::Clock timer;
        float timeSurvived;

    public:
        Game();
        //void handleEvents();
        void run();
        void update();
        void draw();
        bool isGameRunning();
        ~Game();
};

#endif // GAME_HPP
