#pragma once 
#include <string> 
const float WINDOW_WIDTH{ 800.f };
const float WINDOW_HEIGHT{ 600.f };
const std::string WINDOW_TITLE{ "SFML Mini Arcanoid" };
const unsigned int FPS{ 60 };
const float BAT_WIDTH{ 100.f };
const float BAT_HEIGHT{ 30.f };
const sf::Vector2f BAT_SIZE{ 100.f, 30.f };
const float BAT_OFFSET_X{ 350.f };
const float BAT_OFFSET_Y{ 50.f };
const sf::Color BAT_COLOR{ 18, 218, 12 };
const sf::Vector2f BAT_START_POS{ (WINDOW_WIDTH - BAT_SIZE.x) / 2, WINDOW_HEIGHT - BAT_SIZE.y - BAT_OFFSET_Y };
const float BAT_DY = 5.f;
const float BAT_SPEEDX = 5.f;
const float BALL_RADIUS = 15.f;
const sf::Color BALL_COLOR{ 250, 208, 0 };
const sf::Vector2f BALL_START_POS{ (WINDOW_WIDTH - 2 * BALL_RADIUS) / 2,WINDOW_HEIGHT - 2* BALL_RADIUS - 2*BAT_SIZE.y - BAT_OFFSET_Y };
const sf::Vector2f BALL_END_POS{ 10.f,10.f };
const unsigned int FONT_SIZE = 64;
const sf::Vector2f TEXT_POS{ 10.f,-10.f };
const sf::Vector2f END_TEXT_POS{ 300.f, 100.f };
const std::string end{ "GAME OVER" };
const float BRICK_WIDTH = 80.f;
const float BRICK_HEIGHT = 40.f;
const int ROWS = 8;
const int COLUMNS = 10;
