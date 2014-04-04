#ifndef CONSTANTS_HPP_INCLUDED
#define CONSTANTS_HPP_INCLUDED

#include <iostream>
#include <list>
#include <string>
#include <SFML/Graphics.hpp>

const int WIDTH = 1020;
const int HEIGHT = 640;
const int BPP = 32;
const std::string TITLE = "Hisss...";
const int DEFAULT_FRAME_RATE = 5;
//const int SNAKE_SPEED = 5; // speed of snake (in tiles per second)

const sf::Vector2i DEFAULT_TILE_DIMENSIONS = sf::Vector2i(20, 20);
//const std::string SNAKE_TILE_IMAGE = "Resources/Images/SnakeTile.png";
//const std::string SNAKE_TILE_IMAGE = "Resources/Images/snake.png";
const std::string SNAKE_TILE_IMAGE = "Resources/Images/snake-tileset.png";
//const std::string FOOD_TILE_IMAGE = "Resources/Images/Food.png";
const std::string FOOD_TILE_IMAGE = "Resources/Images/food (2).png";
const std::string BACKGROUND_IMAGE = "Resources/Images/bg.png";
const std::string GAME_ICON = "Resources/Images/icon.png";
const std::string GLOBAL_FONT = "Resources/Fonts/DejaVuSans.ttf";

typedef sf::Vector2i tile;

enum Direction
{
    UP,
    RIGHT,
    DOWN,
    LEFT
};

const int MAX_LIVES = 3;

enum GameStates
{
    SHOWING_MAIN_MENU,
    SHOWING_PLAY_MENU,
    SHOWING_OPTIONS,
    SHOWING_SCORES,
    SHOWING_ABOUT,
    PLAYING_EASY,
    SHOWING_PLAY_MSG,
    PLAYING_MEDIUM,
    PLAYING_HARD,
    SHOWING_QUIT_MSG,
    QUITTING
};

const std::string TGUI_BLACK_THEME = "Resources/TGUI/widgets/Black.conf";
const std::string TGUI_WHITE_THEME = "Resources/TGUI/widgets/White.conf";
const std::string TGUI_BB_THEME = "Resources/TGUI/widgets/BabyBlue.conf";
const float DEFAULT_LABEL_SIZE = 20.f;

/* Default game text labels */
const std::string SCORE_LABEL = "SCORE : ";
const std::string LIVES_LABEL = "LIVES LEFT : ";

enum WidgetCallbacks
{
    BUTTON_CALLBACK_ID = 1,
    MENU_CALLBACK_ID,
    LISTBOX_CALLBACK_ID,
    CHILDWINDOW_CALLBACK_ID,
    SLIDER_CALLBACK_ID,
    LABEL_CALLBACK_ID,
    TEXTBOX_CALLBACK_ID,
    CHECKBOX_CALLBACK_ID
};

const int FOOD_POINTS = 10;

#endif // CONSTANTS_HPP_INCLUDED
