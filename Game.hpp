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

        tgui::Picture::Ptr m_gameLogo;
        tgui::Button::Ptr m_playButton;
        tgui::Button::Ptr m_playEasyButton;
        tgui::Button::Ptr m_playHardButton;
        tgui::Button::Ptr m_aboutButton;
        tgui::Button::Ptr m_quitButton;
        tgui::Button::Ptr m_goBackButton;
        tgui::Button::Ptr m_cancelButton;

        GameStates m_gameState;

    public:
        Game();
        //void handleEvents();
        void initGame(int difficulty);
        void run();
        void update();
        void draw();
        bool isGameRunning();

        void showMainMenu();
        void showPlayMenu();
        void playGameEasy();
        void playGameHard();
        void showAbout();
        void showQuitMsg();
        void showAfterGameMsg();
};

#endif // GAME_HPP
