#include <iostream>
#include <cstdlib> // just for testing
#include <sstream> // for using std::stringstrem
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include "Constants.hpp"
#include "Player.hpp"
#include "Object.hpp"

int main()
{
    sf::RenderWindow gameWindow(sf::VideoMode(WIDTH, HEIGHT, BPP), TITLE, sf::Style::Close);
    gameWindow.setFramerateLimit(DEFAULT_FRAME_RATE);
    //gameWindow.setFramerateLimit(1);
    sf::Image gameIcon;
    gameIcon.loadFromFile(GAME_ICON);
    gameWindow.setIcon(gameIcon.getSize().x, gameIcon.getSize().y, gameIcon.getPixelsPtr());

    /*sf::Image foodImage;
    foodImage.loadFromFile("Resources/Images/food-1.png");
    foodImage.createMaskFromColor(sf::Color::Black);*/

    sf::Texture groundTexture;
    groundTexture.loadFromFile(BACKGROUND_IMAGE);
    sf::RectangleShape ground(sf::Vector2f(730, 630));
    //ground.setFillColor(sf::Color::Black);
    ground.setTexture(&groundTexture);
    ground.setPosition(sf::Vector2f(5.0f, 5.0f));

    sf::Texture SNAKE_TEXTURE;
    sf::Texture FOOD_TEXTURE;
    SNAKE_TEXTURE.loadFromFile(SNAKE_TILE_IMAGE);
    FOOD_TEXTURE.loadFromFile(FOOD_TILE_IMAGE);

    Player snake(SNAKE_TEXTURE);
    Direction direction = Direction::DOWN;
    std::list<tile>snakeTiles;
    std::list<tile>::iterator itr;

    Object food(FOOD_TEXTURE, "Food");

    bool foodEaten = true;
    bool foodRequired = true;
    bool putFood = true;

    int foodX;
    int foodY;

    sf::Font globalFont;
    globalFont.loadFromFile(GLOBAL_FONT);

    /*sf::Text score;
    score.setFont(globalFont);
    score.setColor(sf::Color::White);
    score.setString("0")*/

    tgui::Gui gameGUI(gameWindow);
    gameGUI.setGlobalFont(globalFont);

    tgui::Label::Ptr scoreInfo(gameGUI);
    scoreInfo->load(TGUI_BLACK_THEME);
    scoreInfo->setTextFont(globalFont);
    scoreInfo->setTextSize(DEFAULT_LABEL_SIZE);
    scoreInfo->setTextColor(sf::Color::White);
    scoreInfo->setPosition(800.f, 20.f);
    scoreInfo->setText(SCORE_LABEL);

    int cScore = 0;
    std::string currentScore = "0";
    tgui::Label::Ptr currentScoreLabel(gameGUI);
    currentScoreLabel->load(TGUI_BLACK_THEME);
    currentScoreLabel->setTextFont(globalFont);
    currentScoreLabel->setTextSize(DEFAULT_LABEL_SIZE);
    currentScoreLabel->setTextColor(sf::Color::White);
    currentScoreLabel->setPosition(900.f, 20.f);
    currentScoreLabel->setText(currentScore);

    tgui::Label::Ptr livesInfo(gameGUI);
    livesInfo->load(TGUI_BLACK_THEME);
    livesInfo->setTextFont(globalFont);
    livesInfo->setTextSize(DEFAULT_LABEL_SIZE);
    livesInfo->setTextColor(sf::Color::White);
    livesInfo->setPosition(800.f, 50.f);
    livesInfo->setText(LIVES_LABEL);


    int cLives = snake.getLives();
    std::string currentLives = "3";
    tgui::Label::Ptr currentLivesLabel(gameGUI);
    currentLivesLabel->load(TGUI_BLACK_THEME);
    currentLivesLabel->setTextFont(globalFont);
    currentLivesLabel->setTextSize(DEFAULT_LABEL_SIZE);
    currentLivesLabel->setTextColor(sf::Color::White);
    currentLivesLabel->setPosition(950.f, 50.f);
    currentLivesLabel->setText(currentLives);

    tgui::Picture::Ptr foodIcon(gameGUI);
    foodIcon->load(FOOD_TILE_IMAGE);
    foodIcon->setPosition(800.f, 100.f);

    tgui::Label::Ptr foodValue(gameGUI);
    foodValue->load(TGUI_BLACK_THEME);
    foodValue->setTextFont(globalFont);
    foodValue->setTextSize(DEFAULT_LABEL_SIZE);
    foodValue->setTextColor(sf::Color::White);
    foodValue->setPosition(820.f, 100.f);
    foodValue->setText(" : 10 points");
    foodValue->setSize(foodValue->getSize().x, 20.f);

    tgui::Label::Ptr quitMsg(gameGUI);
    quitMsg->load(TGUI_BLACK_THEME);
    quitMsg->setTextFont(globalFont);
    quitMsg->setTextSize(DEFAULT_LABEL_SIZE);
    quitMsg->setTextColor(sf::Color::White);
    quitMsg->setPosition(415.f, 100.f);
    quitMsg->setText("That's all for now!");
    //quitMsg->setSize(foodValue->getSize().x, 20.f);

    tgui::Button::Ptr playAgain(gameGUI);
    playAgain->load(TGUI_BLACK_THEME);
    playAgain->setSize(200.f, 50.f);
    playAgain->setTextFont(globalFont);
    playAgain->setTextSize(DEFAULT_LABEL_SIZE);
    playAgain->setTextColor(sf::Color(44, 127, 255));
    playAgain->setPosition(200.f, 200.f);
    playAgain->setText("Play Again");
    playAgain->setCallbackId(WidgetCallbacks::BUTTON_CALLBACK_ID);
    playAgain->bindCallback(tgui::Button::LeftMouseClicked);

    tgui::Button::Ptr quit(gameGUI);
    quit->load(TGUI_BLACK_THEME);
    quit->setSize(200.f, 50.f);
    quit->setTextFont(globalFont);
    quit->setTextSize(DEFAULT_LABEL_SIZE);
    quit->setTextColor(sf::Color(44, 127, 255));
    quit->setPosition(650.f, 200.f);
    quit->setText("Exit");
    quit->setCallbackId(WidgetCallbacks::BUTTON_CALLBACK_ID);
    quit->bindCallback(tgui::Button::LeftMouseClicked);

    sf::Clock timer;
    float timeSurvived = 0.f;

    while(gameWindow.isOpen())// && snake.isAlive())
    {
        sf::Event gameEvent;
        while(gameWindow.pollEvent(gameEvent))
        {
            switch(gameEvent.type)
            {
                case sf::Event::Closed:
                    {
                        gameWindow.close();
                    } break;
                case sf::Event::KeyPressed:
                    {
                        switch(gameEvent.key.code)
                        {
                            case sf::Keyboard::Escape:
                                {
                                    gameWindow.close();
                                } break;
                            //

                            case sf::Keyboard::Up:
                                {
                                    direction = Direction::UP;
                                } break;
                            case sf::Keyboard::Right:
                                {
                                    direction = Direction::RIGHT;
                                } break;
                            case sf::Keyboard::Down:
                                {
                                    direction = Direction::DOWN;
                                } break;
                            case sf::Keyboard::Left:
                                {
                                    direction = Direction::LEFT;
                                } break;
                            // Just for testing. Delete later.
                            case sf::Keyboard::K:
                                {
                                    snake.addTile();
                                } break;

                            //
                        }
                    } break;
            }

            gameGUI.handleEvent(gameEvent);
        }

        //

        tgui::Callback gameCallback;
        while(gameGUI.pollCallback(gameCallback))
        {
            switch(gameCallback.id)
            {
                case WidgetCallbacks::BUTTON_CALLBACK_ID:
                    {
                        if(gameCallback.text == "Exit")
                            gameWindow.close();
                        else if(gameCallback.text == "Play Again")
                        {
                            snake.reset();
                            snake.resetLives();

                            bool foodEaten = true;
                            bool foodRequired = true;
                            bool putFood = true;

                            scoreInfo->show();
                            currentScoreLabel->show();
                            livesInfo->show();
                            currentLivesLabel->show();
                            foodIcon->show();
                            foodValue->show();
                        }
                    } break;
            }
        }

        //

        if(!snake.isAlive())
        {
            scoreInfo->hide();
            currentScoreLabel->hide();
            livesInfo->hide();
            currentLivesLabel->hide();
            foodIcon->hide();
            foodValue->hide();

            playAgain->show();
            quit->show();
        }

        if(snake.isAlive())
        {
            currentScoreLabel->setText(currentScore);

            cLives = snake.getLives();
            std::stringstream tempLives;
            tempLives << cLives;
            currentLives = tempLives.str();

            currentLivesLabel->setText(currentLives);

            playAgain->hide();
            quit->hide();
        }

        if(snake.isAlive())
        {
            while(foodRequired)
            {
                putFood = true;

                foodX = ((rand() % 50) * 20) + 10;
                foodY = ((rand() % 50) * 20) + 13;

                snakeTiles = snake.getplayerTiles();
                itr = snakeTiles.begin();
                for(; itr != snakeTiles.end(); itr++)
                {
                    if(itr->x == foodX && itr->y == foodY) //&& (foodX > 25 && foodX < 686 && foodY > 25 && foodY < 588))
                    {
                        foodRequired = true;
                        foodEaten = true;
                        putFood = false;
                    }
                    /*else if(foodX > 25 && foodX < 686 && foodY > 25 && foodY < 588)
                    {
                        foodRequired = false;
                        foodEaten = false;
                    }*/
                }
                if((foodX > 25 && foodX < 686 && foodY > 25 && foodY < 588) && putFood)
                {
                    foodRequired = false;
                    foodEaten = false;
                    //putFood = true;
                }
            }
            playAgain->hide();
            quit->hide();
        }

        //
        /*system("cls");
        sf::Vector2i mousePos = sf::Mouse::getPosition(gameWindow);
        std::cout << mousePos.x << ", " << mousePos.y << std::endl;*/

        gameWindow.clear(sf::Color::Black);

        gameGUI.draw();

        if(snake.isAlive())
        {
            gameWindow.draw(ground);
            if(putFood)
                food.create(gameWindow, sf::Vector2i(foodX, foodY));//, -5, -10);
            snake.move(direction);
            snake.draw(gameWindow);

            playAgain->hide();
            quit->hide();
        }

        gameWindow.display();

        //

        // snake crashes with himself
        if(snake.isAlive())
        {
            snakeTiles = snake.getplayerTiles();
            itr = snakeTiles.begin();
            itr++;
            for(; itr != snakeTiles.end(); itr++)
            {
                if((itr->x == snake.getXCoord()) && (itr->y == snake.getYCoord()))
                {
                    snake.reduceLife();
                    snake.reset();
                    bool foodEaten = true;
                    bool foodRequired = true;
                }
            }
            playAgain->hide();
            quit->hide();
        }

        // snake crashes boundaries
        //if(snake.getXCoord() < 0 || (snake.getXCoord() > WIDTH - 20) || snake.getYCoord() < 0 || (snake.getYCoord() > HEIGHT - 20))
        if(snake.isAlive())
        {
            if(snake.getXCoord() < 18 || (snake.getXCoord() > 735 - 40) || snake.getYCoord() < 18 || (snake.getYCoord() > 630 - 20))
            {
                snake.reduceLife();
                snake.reset();
                bool foodEaten = true;
                bool foodRequired = true;
            }
            playAgain->hide();
            quit->hide();
        }

        // snake crashes with food
        if(snake.isAlive())
        {
            if((food.getXCoord() == snake.getXCoord()) && (food.getYCoord() == snake.getYCoord()))
            {
                foodEaten = true;
                foodRequired = true;
                snake.addTile();

                // update score
                // using stringstream as I need  conversion from int to string and vice-versa
                cScore += FOOD_POINTS;
                std::stringstream tempScore;
                tempScore << cScore;
                currentScore = tempScore.str();
            }
            playAgain->hide();
            quit->hide();
        }
        //
    }

    return 0;
}
