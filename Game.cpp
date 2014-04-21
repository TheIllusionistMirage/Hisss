#include "Game.hpp"

Game::Game()
{
    try
    {
        m_window.create(sf::VideoMode(WIDTH, HEIGHT, BPP), TITLE, sf::Style::Close);
        m_window.setFramerateLimit(FRAME_RATE_EASY);
        m_gameIcon.loadFromFile(GAME_ICON);
        m_window.setIcon(m_gameIcon.getSize().x, m_gameIcon.getSize().y, m_gameIcon.getPixelsPtr());

        m_groundTexture.loadFromFile(BACKGROUND_IMAGE);
        m_ground.setSize(sf::Vector2f(730.f, 630.f));
        m_ground.setTexture(&m_groundTexture);
        m_ground.setPosition(sf::Vector2f(5.f, 5.f));

        m_playerTexture.loadFromFile(SNAKE_TILE_IMAGE);
        m_foodTexture.loadFromFile(FOOD_TILE_IMAGE);
        //m_rockTexture.loadFromFile()
        //m_wallTexture.loadFromFile()
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    m_direction = Direction::DOWN;

    foodEaten = true;
    foodRequired = true;
    putFood = true;

    globalFont.loadFromFile(GLOBAL_FONT);

    m_gameGUI.setWindow(m_window);
    m_gameGUI.setGlobalFont(globalFont);

    m_gameGUI.add(scoreInfo);
    scoreInfo->load(TGUI_BLACK_THEME);
    scoreInfo->setTextFont(globalFont);
    scoreInfo->setTextSize(DEFAULT_LABEL_SIZE);
    scoreInfo->setTextColor(sf::Color::White);
    scoreInfo->setPosition(800.f, 20.f);
    scoreInfo->setText(SCORE_LABEL);

    cScore = 0;
    currentScore = "0";

    m_gameGUI.add(currentScoreLabel);
    currentScoreLabel->load(TGUI_BLACK_THEME);
    currentScoreLabel->setTextFont(globalFont);
    currentScoreLabel->setTextSize(DEFAULT_LABEL_SIZE);
    currentScoreLabel->setTextColor(sf::Color::White);
    currentScoreLabel->setPosition(900.f, 20.f);
    currentScoreLabel->setText(currentScore);

    m_gameGUI.add(livesInfo);
    livesInfo->load(TGUI_BLACK_THEME);
    livesInfo->setTextFont(globalFont);
    livesInfo->setTextSize(DEFAULT_LABEL_SIZE);
    livesInfo->setTextColor(sf::Color::White);
    livesInfo->setPosition(800.f, 50.f);
    livesInfo->setText(LIVES_LABEL);

    cLives = m_snake.getLives();
    currentLives = "3";

    m_gameGUI.add(currentLivesLabel);
    currentLivesLabel->load(TGUI_BLACK_THEME);
    currentLivesLabel->setTextFont(globalFont);
    currentLivesLabel->setTextSize(DEFAULT_LABEL_SIZE);
    currentLivesLabel->setTextColor(sf::Color::White);
    currentLivesLabel->setPosition(950.f, 50.f);
    currentLivesLabel->setText(currentLives);

    m_gameGUI.add(foodIcon);
    foodIcon->load(FOOD_TILE_IMAGE);
    foodIcon->setPosition(800.f, 100.f);

    m_gameGUI.add(foodValue);
    foodValue->load(TGUI_BLACK_THEME);
    foodValue->setTextFont(globalFont);
    foodValue->setTextSize(DEFAULT_LABEL_SIZE);
    foodValue->setTextColor(sf::Color::White);
    foodValue->setPosition(820.f, 100.f);
    foodValue->setText(" : 10 points");
    foodValue->setSize(foodValue->getSize().x, 20.f);

    m_gameGUI.add(quitMsg);
    quitMsg->load(TGUI_BLACK_THEME);
    quitMsg->setTextFont(globalFont);
    quitMsg->setTextSize(DEFAULT_LABEL_SIZE);
    quitMsg->setTextColor(sf::Color::White);
    quitMsg->setPosition(415.f, 100.f);
    quitMsg->setText("That's all for now!");

    m_gameGUI.add(playAgainButton);
    playAgainButton->load(TGUI_BLACK_THEME);
    playAgainButton->setSize(200.f, 50.f);
    playAgainButton->setTextFont(globalFont);
    playAgainButton->setTextSize(DEFAULT_LABEL_SIZE);
    playAgainButton->setTextColor(sf::Color(44, 127, 255));
    playAgainButton->setPosition(200.f, 200.f);
    playAgainButton->setText("Play Again");
    playAgainButton->setCallbackId(WidgetCallbacks::BUTTON_CALLBACK_ID);
    playAgainButton->bindCallback(tgui::Button::LeftMouseClicked);

    m_gameGUI.add(quitButton);
    quitButton->load(TGUI_BLACK_THEME);
    quitButton->setSize(200.f, 50.f);
    quitButton->setTextFont(globalFont);
    quitButton->setTextSize(DEFAULT_LABEL_SIZE);
    quitButton->setTextColor(sf::Color(44, 127, 255));
    quitButton->setPosition(650.f, 200.f);
    quitButton->setText("Exit");
    quitButton->setCallbackId(WidgetCallbacks::BUTTON_CALLBACK_ID);
    quitButton->bindCallback(tgui::Button::LeftMouseClicked);

    m_gameGUI.add(totalScoreLabel);
    totalScoreLabel->load(TGUI_BLACK_THEME);
    totalScoreLabel->setTextFont(globalFont);
    totalScoreLabel->setTextSize(DEFAULT_LABEL_SIZE);
    totalScoreLabel->setTextColor(sf::Color::White);
    totalScoreLabel->setPosition(420.f, 350.f);
    totalScoreLabel->setText("TOTAL SCORE : ");

    timeSurvived = 0.f;

    m_snake.setTexture(m_playerTexture);
    m_objects.push_back(Object());
    m_objects.back().setTexture(m_foodTexture);
    m_objects.back().setType(ObjectType::FOOD);
}

//void Game::handleEvents()
void Game::run()
{
    while(m_window.isOpen())
    {
        sf::Event m_event;
        while(m_window.pollEvent(m_event))
        {
            switch(m_event.type)
            {
                case sf::Event::Closed:
                    {
                        m_window.close();
                    } break;
                case sf::Event::KeyPressed:
                    {
                        switch(m_event.key.code)
                        {
                            case sf::Keyboard::Escape:
                                {
                                    m_window.close();
                                } break;
                            case sf::Keyboard::Up:
                                {
                                    m_direction = Direction::UP;
                                } break;
                            case sf::Keyboard::Right:
                                {
                                    m_direction = Direction::RIGHT;
                                } break;
                            case sf::Keyboard::Down:
                                {
                                    m_direction = Direction::DOWN;
                                } break;
                            case sf::Keyboard::Left:
                                {
                                    m_direction = Direction::LEFT;
                                } break;
                            // Just for testing. Delete later.
                            case sf::Keyboard::K:
                                {
                                    m_snake.addTile();
                                } break;
                        }
                    } break;
            }
            m_gameGUI.handleEvent(m_event);
        }

        tgui::Callback gameCallback;
        while(m_gameGUI.pollCallback(gameCallback))
        {
            switch(gameCallback.id)
            {
                case WidgetCallbacks::BUTTON_CALLBACK_ID:
                    {
                        if(gameCallback.text == "Exit")
                            m_window.close();
                        else if(gameCallback.text == "Play Again")
                        {
                            cScore = 0;
                            currentScore = "0";

                            m_snake.reset();
                            m_snake.resetLives();

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
        update();
        draw();
    }
}

void Game::update()
{
    if(!m_snake.isAlive())
        {
            scoreInfo->hide();
            currentScoreLabel->hide();
            livesInfo->hide();
            currentLivesLabel->hide();
            foodIcon->hide();
            foodValue->hide();
            totalScoreLabel->hide();

            playAgainButton->show();
            quitButton->show();

            std::stringstream tempTotalScore;
            tempTotalScore << "TOTAL SCORE : " << currentScore;
            std::string tempStr = tempTotalScore.str();
            totalScoreLabel->setText(tempStr);

            totalScoreLabel->show();
        }
        else
        {
            playAgainButton->hide();
            quitButton->hide();
            totalScoreLabel->hide();
        }

        if(m_snake.isAlive())
        {
            currentScoreLabel->setText(currentScore);

            cLives = m_snake.getLives();
            std::stringstream tempLives;
            tempLives << cLives;
            currentLives = tempLives.str();

            currentLivesLabel->setText(currentLives);
        }

        if(m_snake.isAlive())
        {
            while(foodRequired)
            {
                putFood = true;

                foodSpawnedX = ((rand() % 50) * 20) + 10;
                foodSpawnedY = ((rand() % 50) * 20) + 13;

                m_snakeTiles = m_snake.getplayerTiles();
                itr = m_snakeTiles.begin();
                for(; itr != m_snakeTiles.end(); itr++)
                {
                    if(itr->x == foodSpawnedX && itr->y == foodSpawnedY)
                    {
                        foodRequired = true;
                        foodEaten = true;
                        putFood = false;
                    }
                }
                if((foodSpawnedX > 25 && foodSpawnedX < 686 && foodSpawnedY > 25 && foodSpawnedY < 588) && putFood)
                {
                    foodRequired = false;
                    foodEaten = false;
                }
            }
        }
        //

        // snake crashes with himself
        if(m_snake.isAlive())
        {
            m_snakeTiles = m_snake.getplayerTiles();
            itr = m_snakeTiles.begin();
            itr++;
            for(; itr != m_snakeTiles.end(); itr++)
            {
                if((itr->x == m_snake.getXCoord()) && (itr->y == m_snake.getYCoord()))
                {
                    m_snake.reduceLife();
                    m_snake.reset();
                    bool foodEaten = true;
                    bool foodRequired = true;
                }
            }
        }

        // snake crashes boundaries
        if(m_snake.isAlive())
        {
            if(m_snake.getXCoord() < 18 || (m_snake.getXCoord() > 735 - 40) || m_snake.getYCoord() < 18 || (m_snake.getYCoord() > 630 - 20))
            {
                m_snake.reduceLife();
                m_snake.reset();
                bool foodEaten = true;
                bool foodRequired = true;
            }
        }

        // snake crashes with food
        if(m_snake.isAlive())
        {
            if((m_objects.back().getXCoord() == m_snake.getXCoord()) && (m_objects.back().getYCoord() == m_snake.getYCoord()))
            {
                foodEaten = true;
                foodRequired = true;
                m_snake.addTile();

                // update score
                // using stringstream as I need  conversion from int to string and vice-versa
                cScore += FOOD_POINTS;
                std::stringstream tempScore;
                tempScore << cScore;
                currentScore = tempScore.str();
            }
        }
}

void Game::draw()
{
    m_window.clear(sf::Color::Black);
    m_gameGUI.draw();
    if(m_snake.isAlive())
    {
        m_window.draw(m_ground);
        if(putFood)
        {
            m_objects.back().create(sf::Vector2i(foodSpawnedX, foodSpawnedY));
            m_objects.back().draw(m_window);
        }
        m_snake.move(m_direction);
        m_snake.draw(m_window);
        //m_window.draw(m_snake);
    }
    m_window.display();
}

bool Game::isGameRunning()
{
    return m_window.isOpen();
}

Game::~Game()
{
    //dtor
}
